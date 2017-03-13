#include <jsoncpp/json/value.h>
#include <SFML/Graphics.hpp>
namespace imagine{
	namespace RPG{
		class tile{
		public:
			sf::Sprite tileSprite;
			bool isHarmful;
			tile(const Json::Value dataForTile, const int id);
			tile(const Json::Value dataForTile, const int id,const std::string customTextureLocation);
		protected:
			Json::Value tileData;
			sf::Texture tileTexture;
			const int id;
		};
	}
}
