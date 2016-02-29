#include "DomoUI.h"

namespace DomoUI
{

void DomoUI::Mesh::LoadMesh()
{
	std::ifstream File(FileName.c_str());
	if(!File.is_open()) throw DomoUI::NewFileNotFoundExcept(FileName);
	
	
	std::string line;
	int linenb = 0;
	
	while(std::getline(File, line))
	{
		char *pch = strtok ((char*)line.c_str(),":");
		
		Vertex NewVert;
		
		if(pch != NULL){
			NewVert.tu = atof(pch);
		}
		else throw DomoUI::NewCorruptFileExcept(FileName, linenb);
		/*while (pch != NULL)
		{
			printf ("%s\n",pch);
			pch = strtok (NULL, " ,.-");
		}*/
		
		linenb++;
	}
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