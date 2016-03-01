#include "DomoUI.h"

namespace DomoUI
{

ResourceMgr ResourceMgr::Unique_Instance=ResourceMgr();
	
ResourceMgr::ResourceMgr()
{
}

ResourceMgr::~ResourceMgr()
{
}

ResourceMgr& ResourceMgr::Get()
{
	return Unique_Instance;
}

Texture *ResourceMgr::GetTexture(const std::string TexFileName)
{
	for(std::vector<Texture>::iterator it=Texture_Array.begin(); it!=Texture_Array.end();it++)
	{
		if( (*it).GetFileName() == TexFileName ) return &(*it);
	}
	
	Texture NewTex(TexFileName);
	Texture_Array.push_back(NewTex);
	return &Texture_Array.back();
}

Mesh *ResourceMgr::GetMesh(const std::string MeshFileName)
{
	for(std::vector<Mesh>::iterator it=Mesh_Array.begin(); it!=Mesh_Array.end();it++)
	{
		if( (*it).GetFileName() == MeshFileName ) return &(*it);
	}
	
	Mesh NewMesh(MeshFileName);
	Mesh_Array.push_back(NewMesh);
	return &Mesh_Array.back();
}

}