#ifndef MESH_H
#define MESH_H

namespace DomoUI
{

struct Vertex
{
    float tu, tv;
    float x, y, z;
};
	
class Mesh
{
public:
	void LoadMesh();
	Mesh(const std::string);
	~Mesh();
	
	Vertex *g_quadVertices;
private:
	
	std::string FileName;
};

}

#endif // MESH_H
