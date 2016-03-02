#ifndef ENGINE_H
#define ENGINE_H

#include "DomoUI.h"

namespace DomoUI
{

class Engine
{
public:
	static Engine& Get();

	void RenderBit(class Renderable*);
	Renderable *CreateRenderable(const std::string MeshFileN, const std::string TextFileN);
	void RenderAll();
	Engine();
	~Engine();
private:
	std::vector<Renderable> Renderable_Array;
	static Engine Unique_Instance;
};

}

#endif // ENGINE_H
