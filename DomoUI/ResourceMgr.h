#ifndef RESOURCEMGR_H
#define RESOURCEMGR_H

#include "DomoUI.h"

namespace DomoUI
{

class ResourceMgr
{
public:
	static ResourceMgr& Get();
	
	Texture *GetTexture(const std::string);
	Mesh *GetMesh(const std::string);
	
	ResourceMgr();
	~ResourceMgr();
private:
	std::vector<Texture> Texture_Array;
	std::vector<Mesh> Mesh_Array;
	static ResourceMgr Unique_Instance;
};

}

#endif // RESOURCEMGR_H
