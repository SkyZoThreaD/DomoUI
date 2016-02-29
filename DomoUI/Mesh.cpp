#include "DomoUI.h"

namespace DomoUI
{

void DomoUI::Mesh::LoadMesh()
{
	std::ifstream File(FileName.c_str());
	if(!File.is_open()) throw DomoUI::NewFileNotFoundExcept(FileName);
	std::vector<Vertex> VertexList;
	std::string line;
	int linenb = 0;
	
	while(std::getline(File, line))
	{
		Vertex NewVert;
		char *pch = strtok ((char*)line.c_str(),":");
		if(pch != NULL){NewVert.tu = atof(pch); pch = strtok (NULL, ":");}
		else throw DomoUI::NewCorruptFileExcept(FileName, linenb);
		if(pch != NULL){NewVert.tv = atof(pch); pch = strtok (NULL, ":");}
		else throw DomoUI::NewCorruptFileExcept(FileName, linenb);
		if(pch != NULL){NewVert.x = atof(pch); pch = strtok (NULL, ":");}
		else throw DomoUI::NewCorruptFileExcept(FileName, linenb);
		if(pch != NULL){NewVert.y = atof(pch); pch = strtok (NULL, ":");}
		else throw DomoUI::NewCorruptFileExcept(FileName, linenb);
		if(pch != NULL){NewVert.z = atof(pch);}
		else throw DomoUI::NewCorruptFileExcept(FileName, linenb);
		VertexList.push_back(NewVert);
		linenb++;
	}
	
	g_quadVertices = new Vertex[linenb];
	memcpy(g_quadVertices, &VertexList[0], sizeof(Vertex)*linenb );
	File.close();
}

DomoUI::Mesh::Mesh(const std::string _FileName):FileName(_FileName)
{
	LoadMesh();
}

DomoUI::Mesh::~Mesh()
{
}

}