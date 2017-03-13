#include "ImagineCore.hpp"

#ifndef __IMAGINEHUD_HPP__
#define __IMAGINEHUD_HPP__

namespace imagine{
	class HUD{
	public:
		virtual void display(sf::RenderWindow *window) = 0;
	};
}
#endif // __IMAGINEHUD_HPP
