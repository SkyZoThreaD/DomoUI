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
	Vertex *Data();
	Mesh(const std::string);
	~Mesh();
	const std::string GetFileName();
	Vertex *g_quadVertices;
private:
	
	std::string FileName;
};

}

#endif // MESH_H
