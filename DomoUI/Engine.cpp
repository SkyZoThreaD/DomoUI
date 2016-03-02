#include "DomoUI.h"

namespace DomoUI
{

Engine Engine::Unique_Instance=Engine();

Engine& Engine::Get()
{
	return Unique_Instance;
}
	
void Engine::RenderAll()
{
	for(std::vector<Renderable>::iterator it = Renderable_Array.begin(); it != Renderable_Array.end(); ++it)
	{
		RenderBit(&(*it));
	}
}
	
Renderable *Engine::CreateRenderable(const std::string MeshFileN, const std::string TextFileN)
{
	Renderable NewRenderable(MeshFileN, TextFileN);
	Renderable_Array.push_back(NewRenderable);
	return &Renderable_Array.back();
}

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
	
    glBindTexture( GL_TEXTURE_2D, theOne->GetTexture()->GetGLID() );
    glInterleavedArrays( GL_T2F_V3F, 0, theOne->GetMesh()->Data() );
    glDrawArrays( GL_QUADS, 0, 4 );
}
	
Engine::Engine()
{
}

Engine::~Engine()
{
}

}