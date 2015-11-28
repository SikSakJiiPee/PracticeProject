#pragma once
#include "GLTexture.h"

#include <string>

class ImageLoader
{
public:
	GLTexture loadPNG(std::string filePath);
};

