#include "AssetManager.hpp"
#include <iostream>

AssetMan::AssetMan()
{
}

AssetMan::~AssetMan()
{
}

void AssetMan::AddTexture(int id, const std::string &filePath, bool wantRepeated)
{
    auto texture = std::make_unique<sf::Texture>();

    if (texture->loadFromFile(filePath))
    {
        texture->setRepeated(wantRepeated);
        m_textures[id] = std::move(texture);
    }
}

void AssetMan::AddFont(int id, const std::string &filePath)
{
    try {
        auto font = std::make_unique<sf::Font>();

        if (font->loadFromFile(filePath))
        {
            m_fonts[id] = std::move(font);
        }
    }
    catch (std::exception ex) {
        std::cerr << ex.what() << std::endl;
    }
}

const sf::Texture &AssetMan::GetTexture(int id) const
{
    return *(m_textures.at(id).get());
}

const sf::Font &AssetMan::GetFont(int id) const
{
    return *(m_fonts.at(id).get());
}
