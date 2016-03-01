#include "DomoUI.h"

namespace DomoUI
{

void Engine::RenderBit(Renderable *theOne)
{
	float x=theOne->getPX();
	float y=theOne->getPY();
	float z=theOne->getPZ();
	
	glLoadIdentity();
	glTranslatef( x,y,z );
    glRotatef( theOne->getRX(), 1.0f, 0.0f, 0.0f );
    glRotatef( theOne->getRY(), 0.0f, 1.0f, 0.0f );
	glRotatef( theOne->getRZ(), 0.0f, 0.0f, 1.0f );
	
	Texture *mt = theOne->GetTexture();
	GLuint mid = mt->GetGLID();
	
    glBindTexture( GL_TEXTURE_2D, theOne->GetTexture()->GetGLID() );
    //glInterleavedArrays( GL_T2F_V3F, 0, theOne->GetMesh()->Data() );
    glDrawArrays( GL_QUADS, 0, 4 );
}
	
Engine::Engine()
{
}

Engine::~Engine()
{
}

}