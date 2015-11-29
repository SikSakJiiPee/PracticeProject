#include "TextureCache.h"
#include "ImageLoader.h"
#include <iostream>

TextureCache::TextureCache()
{
}


TextureCache::~TextureCache()
{
}


GLTexture TextureCache::getTexture(std::string texturePath)
{
	//Lookup the texture and see if in the map
	//(std::map<std::string, GLTexture>::iterator) mit = _textureMap.find(texturePath);  (=auto, m‰‰ritt‰‰ tyypin esittelyn mukaan)
	auto mit = _textureMap.find(texturePath);

	//check if its not in the map
	if (mit == _textureMap.end())
	{
		//Load the texture
		GLTexture newTexture = ImageLoader::loadPNG(texturePath);

		//Insert it into the map
		_textureMap.insert(make_pair(texturePath, newTexture));

		std::cout << "Loaded Texture!\n";
		return newTexture;
	}
	std::cout << "Used Cached Texture!\n";
	return mit->second;
}