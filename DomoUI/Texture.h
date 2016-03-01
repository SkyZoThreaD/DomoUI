#ifndef TEXTURE_H
#define TEXTURE_H

#include "DomoUI.h"

namespace DomoUI
{

class Texture
{
public:

	struct BMPImage
	{
		int   width;
		int   height;
		char *data;
	};
	
	const std::string GetFileName();
	unsigned int GetGLID();
	
	Texture(std::string);
	~Texture();
private:
	void loadTexture();
	void getBitmapImageData( const std::string pFileName, BMPImage *pImage );
	std::string FileName;
	GLuint   g_textureID;
};

}

#endif // TEXTURE_H
