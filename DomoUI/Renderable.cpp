#include "DomoUI.h"

namespace DomoUI
{
	
float Renderable::getPX() { return Position.getX(); }
float Renderable::getPY() { return Position.getY(); }
float Renderable::getPZ() { return Position.getZ(); }
void Renderable::setPX(float v) { Position.setX(v); }
void Renderable::setPY(float v) { Position.setY(v); }
void Renderable::setPZ(float v) { Position.setZ(v); }
float Renderable::getRX() { return Rotation.getX(); }
float Renderable::getRY() { return Rotation.getY(); }
float Renderable::getRZ() { return Rotation.getZ(); }
void Renderable::setRX(float v) { Rotation.setX(v); }
void Renderable::setRY(float v) { Rotation.setY(v); }
void Renderable::setRZ(float v) { Rotation.setZ(v); }

Texture *Renderable::GetTexture()
{
	return mTexture;
}

Mesh *Renderable::GetMesh()
{
	return mMesh;
}
	
Renderable::Renderable(const std::string _Mesh, const std::string _Texture):Position(0), Rotation(0)
{
	mTexture = ResourceMgr::Get().GetTexture(_Texture);
	mMesh = ResourceMgr::Get().GetMesh(_Mesh);
}

Renderable::~Renderable()
{
}

}