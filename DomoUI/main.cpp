#include <DomoUI.h>

Display *g_pDisplay = NULL;
Window   g_window;
bool     g_bDoubleBuffered = GL_TRUE;

float g_fSpinX           = 0.0f;
float g_fSpinY           = 0.0f;
int   g_nLastMousePositX = 0;
int   g_nLastMousePositY = 0;
bool  g_bMousing         = false;

int main(int argc, char **argv);
void render(void);
void init(void);

DomoUI::Renderable *object;

//-----------------------------------------------------------------------------
// Name: main()
//-----------------------------------------------------------------------------
int main( int argc, char **argv )
{	
    XSetWindowAttributes windowAttributes;
    XVisualInfo *visualInfo = NULL;
    XEvent event;
    Colormap colorMap;
    GLXContext glxContext;
    int errorBase;
	int eventBase;

    // Open a connection to the X server
    g_pDisplay = XOpenDisplay( NULL );

    if( g_pDisplay == NULL )
    {
        fprintf(stderr, "glxsimple: %s\n", "could not open display");
        exit(1);
    }

    // Make sure OpenGL's GLX extension supported
    if( !glXQueryExtension( g_pDisplay, &errorBase, &eventBase ) )
    {
        fprintf(stderr, "glxsimple: %s\n", "X server has no OpenGL GLX extension");
        exit(1);
    }

    // Find an appropriate visual

    int doubleBufferVisual[]  =
    {
        GLX_RGBA,           // Needs to support OpenGL
        GLX_DEPTH_SIZE, 16, // Needs to support a 16 bit depth buffer
        GLX_DOUBLEBUFFER,   // Needs to support double-buffering
        None                // end of list
    };

    int singleBufferVisual[] =
    {
        GLX_RGBA,           // Needs to support OpenGL
        GLX_DEPTH_SIZE, 16, // Needs to support a 16 bit depth buffer
        None                // end of list
    };

    // Try for the double-bufferd visual first
    visualInfo = glXChooseVisual( g_pDisplay, DefaultScreen(g_pDisplay), doubleBufferVisual );

    if( visualInfo == NULL )
    {
    	// If we can't find a double-bufferd visual, try for a single-buffered visual...
        visualInfo = glXChooseVisual( g_pDisplay, DefaultScreen(g_pDisplay), singleBufferVisual );

        if( visualInfo == NULL )
        {
            fprintf(stderr, "glxsimple: %s\n", "no RGB visual with depth buffer");
            exit(1);
        }

        g_bDoubleBuffered = false;
    }

    // Create an OpenGL rendering context
    glxContext = glXCreateContext( g_pDisplay, 
                                   visualInfo, 
                                   NULL,      // No sharing of display lists
                                   GL_TRUE ); // Direct rendering if possible
                           
    if( glxContext == NULL )
    {
        fprintf(stderr, "glxsimple: %s\n", "could not create rendering context");
        exit(1);
    }

    // Create an X colormap since we're probably not using the default visual 
    colorMap = XCreateColormap( g_pDisplay, 
                                RootWindow(g_pDisplay, visualInfo->screen), 
                                visualInfo->visual, 
                                AllocNone );

    windowAttributes.colormap     = colorMap;
    windowAttributes.border_pixel = 0;
    windowAttributes.event_mask   = ExposureMask           |
                                    VisibilityChangeMask   |
                                    KeyPressMask           |
                                    KeyReleaseMask         |
                                    ButtonPressMask        |
                                    ButtonReleaseMask      |
                                    PointerMotionMask      |
                                    StructureNotifyMask    |
                                    SubstructureNotifyMask |
                                    FocusChangeMask;
    
    // Create an X window with the selected visual
    g_window = XCreateWindow( g_pDisplay, 
                              RootWindow(g_pDisplay, visualInfo->screen), 
                              0, 0,     // x/y position of top-left outside corner of the window
                              640, 480, // Width and height of window
                              0,        // Border width
                              visualInfo->depth,
                              InputOutput,
                              visualInfo->visual,
                              CWBorderPixel | CWColormap | CWEventMask,
                              &windowAttributes );

    XSetStandardProperties( g_pDisplay,
                            g_window,
                            "GLX Sample",
                            "GLX Sample",
                            None,
                            argv,
                            argc,
                            NULL );

    // Bind the rendering context to the window
    glXMakeCurrent( g_pDisplay, g_window, glxContext );

    // Request the X window to be displayed on the screen
    XMapWindow( g_pDisplay, g_window );

    // Init OpenGL...
    init();
	
	
	try
	{
		object = DomoUI::Engine::Get().CreateRenderable( "../Media/Plane.dmesh" , "../Media/test.bmp");
		object->setPZ(-5);
	}
	catch(DomoUI::Exception *e)
	{
		std::cout<<"Except:"<<e->getComment()<<std::endl;
	}
 
    //
    // Enter the render loop and don't forget to dispatch X events as
    // they occur.
    //

    while(1)
    {
        do
        {
            XNextEvent( g_pDisplay, &event );

            switch( event.type )
            {
                case ButtonPress:
                {
            	    if( event.xbutton.button == 1 )
            		{
						g_nLastMousePositX = event.xmotion.x;
				        g_nLastMousePositY = event.xmotion.y;
						g_bMousing = true;
					}
                }
                break;

                case ButtonRelease:
                {
                	if( event.xbutton.button == 1 )
                		g_bMousing = false;
                }
                break;
                
                case KeyPress:
                {
                    fprintf( stderr, "KeyPress event\n" );
                }
                break;

                case KeyRelease:
                {
                    fprintf( stderr, "KeyRelease event\n" );
                }
                break;

                case MotionNotify:
                {
                    if( g_bMousing )
                    {
	                    g_fSpinX -= (event.xmotion.x - g_nLastMousePositX);
						g_fSpinY -= (event.xmotion.y - g_nLastMousePositY);
					
						g_nLastMousePositX = event.xmotion.x;
					    g_nLastMousePositY = event.xmotion.y;
                    }
                }
                break;

                case Expose:
                {
                    fprintf( stderr, "Expose event\n" );
                }
                break;

                case ConfigureNotify:
                {
                    glViewport( 0, 0, event.xconfigure.width, event.xconfigure.height );
                }
            }
        }
        while( XPending(g_pDisplay) ); // Loop to compress events

        render();
    }
}

//-----------------------------------------------------------------------------
// Name: init()
// Desc: Init OpenGL context for rendering
//-----------------------------------------------------------------------------
void init( void )
{
	glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
	glEnable( GL_TEXTURE_2D );

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective( 45.0f, 640.0f / 480.0f, 0.1f, 100.0f);
}

//-----------------------------------------------------------------------------
// Name: render()
// Desc: Called when the GLX window is ready to render
//-----------------------------------------------------------------------------
void render( void )
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	
    glMatrixMode( GL_MODELVIEW );
	
	DomoUI::Engine::Get().RenderAll();
	
	object->setRX( object->getRX() + 0.1f );

    if( g_bDoubleBuffered ) glXSwapBuffers( g_pDisplay, g_window ); // Buffer swap does implicit glFlush
    else glFlush(); // Explicit flush for single buffered case 
}
