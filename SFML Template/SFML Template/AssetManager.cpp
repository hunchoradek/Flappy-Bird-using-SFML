#include "AssetManager.hpp"

namespace huncho
{
	void AssetManager::LoadTexture(std::string name, std::string fileName) {
		sf::Texture tex;

		if (tex.loadFromFile(fileName)) {
			this->_textures[name] = tex;
		}
	}
	void AssetManager::LoadFont(std::string name, std::string fileName) {
		sf::Font font;

		if (font.loadFromFile(fileName)) {
			this->_fonts[name] = font;
		}
	}
	sf::Texture &AssetManager::GetTexture(std::string name) {
		return this->_textures.at(name);
	}
	sf::Font &AssetManager::GetFont(std::string name) {
		return this->_fonts.at(name);
	}
}