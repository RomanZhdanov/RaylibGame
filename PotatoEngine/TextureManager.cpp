#include "TextureManager.h"

void TextureManager::loadTexture(const char* textureId, const char* path)
{
    Texture2D texture = LoadTexture(path);
    textureStorage.insert(std::make_pair(textureId, texture));
}

Texture2D* TextureManager::get(const char* textureId)
{
    return &textureStorage[textureId];
}

TextureManager::~TextureManager()
{
    for (auto const& item : textureStorage)
    {
        UnloadTexture(item.second);
    }
}