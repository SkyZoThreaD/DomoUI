#ifndef RENDERABLE_H
#define RENDERABLE_H

#include "DomoUI.h"

namespace DomoUI
{

class Renderable
{
	public:
	float getPX();
	float getPY();
	float getPZ();
	void setPX(float);
	void setPY(float);
	void setPZ(float);
	float getRX();
	float getRY();
	float getRZ();
	void setRX(float);
	void setRY(float);
	void setRZ(float);
	class Texture *GetTexture();
	Mesh *GetMesh();
	Renderable(const std::string mesh, const std::string texture);
	~Renderable();
private:
	class Texture *mTexture;
	class Mesh *mMesh;
	Vector3f Position;
	Vector3f Rotation;
};

}

#endif // RENDERABLE_H
