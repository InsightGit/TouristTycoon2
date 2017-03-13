#ifndef ROAD_HPP
#define ROAD_HPP
#include "Tile.hpp"
//Including road image resource files
#include "Resources/roadIcon.h"
#include "Resources/roadturn.h"

namespace imagine{
	namespace sim{
		namespace types{
			enum roadDirection{
				straight,
				leftToDown,
				rightToDown,
				leftToUp,
				rightToUp
			};
		}
		class road : public tile{
		public:
			static const int cost = 100;
			static const int xSize = 1;
			static const int ySize = 1;
			sf::Texture roadTexture;

			road(const imagine::sim::types::roadDirection roadDirectionToUse,sf::Vector2f tilePosition);
			virtual ~road();

			imagine::sim::types::roadDirection getRoadDirection() { return roadDirection; }
			void spawn();
		protected:
			imagine::sim::types::roadDirection roadDirection;
		};
	}
}

#endif // ROAD_HPP
