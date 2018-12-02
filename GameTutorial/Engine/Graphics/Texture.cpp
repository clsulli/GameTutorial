#include "Texture.h"


Texture::~Texture()
{
}

Texture::Texture()
{
	this->id = -1;
}

Texture::Texture(int _id)
{
	this->id = _id;
	if (!GetTextureParams())
	{
		cout << "Error loading image with ID: " << _id << endl;
	}
}

Texture::Texture(string path)
{
	this->id = SOIL_load_OGL_texture(path.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MULTIPLY_ALPHA | SOIL_FLAG_INVERT_Y);
	if (!GetTextureParams())
	{
		cout << "Error loading image: " << path << endl;
	}
}

void Texture::Cycle(string path)
{
	/*cout << path << endl;*/
	this->id = SOIL_load_OGL_texture(path.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MULTIPLY_ALPHA | SOIL_FLAG_INVERT_Y);
	if (!GetTextureParams())
	{
		cout << "Error loading image: " << path << endl;
	}
}

int Texture::GetID()
{
	return this->id;
}

int Texture::GetWidth()
{
	return this->width;
}

int Texture::GetHeight()
{
	return this->height;
}


bool Texture::GetTextureParams()
{
	if (this->id > 0)
	{
		int mipLevel = 0;
		glBindTexture(GL_TEXTURE_2D, this->id);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_WIDTH, &this->width);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_HEIGHT, &this->height);
		return true;
	}
	return false;
}
