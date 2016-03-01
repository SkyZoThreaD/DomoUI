#ifndef VECTOR3F_H
#define VECTOR3F_H

namespace DomoUI
{

class Vector3f
{
public:
	float getX();
	float getY();
	float getZ();
	void setX(float);
	void setY(float);
	void setZ(float);
	Vector3f();
	Vector3f(const float);
	~Vector3f();

private:
	float x, y, z;
};
	
}

#endif