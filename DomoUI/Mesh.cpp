#include "DomoUI.h"

namespace DomoUI
{

Vertex *Mesh::Data()
{
	return g_quadVertices;
}
	
const std::string Mesh::GetFileName()
{
	return FileName;
}
	
void Mesh::LoadMesh()
{
	std::ifstream File(FileName.c_str());
	if(!File.is_open()) throw NewFileNotFoundExcept(FileName);
	std::vector<Vertex> VertexList;
	std::string line;
	int linenb = 0;
	
	while(std::getline(File, line))
	{
		Vertex NewVert;
		char *pch = strtok ((char*)line.c_str(),":");
		if(pch != NULL){NewVert.tu = atof(pch); pch = strtok (NULL, ":");}
		else throw NewCorruptFileExcept(FileName, linenb);
		if(pch != NULL){NewVert.tv = atof(pch); pch = strtok (NULL, ":");}
		else throw NewCorruptFileExcept(FileName, linenb);
		if(pch != NULL){NewVert.x = atof(pch); pch = strtok (NULL, ":");}
		else throw NewCorruptFileExcept(FileName, linenb);
		if(pch != NULL){NewVert.y = atof(pch); pch = strtok (NULL, ":");}
		else throw NewCorruptFileExcept(FileName, linenb);
		if(pch != NULL){NewVert.z = atof(pch);}
		else throw NewCorruptFileExcept(FileName, linenb);
		VertexList.push_back(NewVert);
		linenb++;
	}
	
	g_quadVertices = new Vertex[linenb];
	memcpy(g_quadVertices, &VertexList[0], sizeof(Vertex)*linenb );
	File.close();
}

Mesh::Mesh(const std::string _FileName):FileName(_FileName)
{
	LoadMesh();
}

Mesh::~Mesh()
{
}

}