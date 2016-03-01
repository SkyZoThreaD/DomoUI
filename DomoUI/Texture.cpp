#include "DomoUI.h"

namespace DomoUI
{

unsigned int Texture::GetGLID()
{
	return g_textureID;
}
	
const std::string Texture::GetFileName()
{
	return FileName;
}
	
void Texture::getBitmapImageData( const std::string pFileName, BMPImage *pImage )
{
    FILE *pFile = NULL;
    unsigned short nNumPlanes;
    unsigned short nNumBPP;
	int i;

    if( (pFile = fopen(pFileName.c_str(), "rb") ) == NULL )
		throw NewFileNotFoundExcept(pFileName);

    // Seek forward to width and height info
    fseek( pFile, 18, SEEK_CUR );

    if( (i = fread(&pImage->width, 4, 1, pFile) ) != 1 )
		throw NewCorruptFileExcept(pFileName, 0);

    if( (i = fread(&pImage->height, 4, 1, pFile) ) != 1 )
		throw NewCorruptFileExcept(pFileName, 1);

    if( (fread(&nNumPlanes, 2, 1, pFile) ) != 1 )
		throw NewCorruptFileExcept(pFileName, 2);
	
    if( nNumPlanes != 1 )
		throw NewCorruptFileExcept(pFileName, 3);

    if( (i = fread(&nNumBPP, 2, 1, pFile)) != 1 )
		throw NewCorruptFileExcept(pFileName, 4);
	
    if( nNumBPP != 24 )
		throw NewCorruptFileExcept(pFileName, 5);

    // Seek forward to image data
    fseek( pFile, 24, SEEK_CUR );

	// Calculate the image's total size in bytes. Note how we multiply the 
	// result of (width * height) by 3. This is becuase a 24 bit color BMP 
	// file will give you 3 bytes per pixel.
    int nTotalImagesize = (pImage->width * pImage->height) * 3;

    pImage->data = (char*) malloc( nTotalImagesize );
	
    if( (i = fread(pImage->data, nTotalImagesize, 1, pFile) ) != 1 )
		throw NewCorruptFileExcept(pFileName, 6);

    //
	// Finally, rearrange BGR to RGB
	//
	
	char charTemp;
    for( i = 0; i < nTotalImagesize; i += 3 )
	{ 
		charTemp = pImage->data[i];
		pImage->data[i] = pImage->data[i+2];
		pImage->data[i+2] = charTemp;
    }
}
	
void Texture::loadTexture()	
{
	BMPImage textureImage;
	
    getBitmapImageData( FileName.c_str(), &textureImage );

	glGenTextures( 1, &g_textureID );
	glBindTexture( GL_TEXTURE_2D, g_textureID );

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );

	glTexImage2D( GL_TEXTURE_2D, 0, 3, textureImage.width, textureImage.height, 
	               0, GL_RGB, GL_UNSIGNED_BYTE, textureImage.data );
}

Texture::Texture(std::string _FileName):FileName(_FileName), g_textureID(0)
{
	loadTexture();
}

Texture::~Texture()
{
}

}