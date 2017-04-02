/*Copyright (C) 2017 Bobby Youstra

This file is part of TouristTycoon2.

TouristTycoon2 is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

TouristTycoon2 is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with TouristTycoon2.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ImagineCore.hpp"
#include <thread>

namespace imagine{
	class sceneMusicPlayer{
	public:
		bool repeating;
		bool stopThread = false;

		sceneMusicPlayer(const std::vector<std::string> musicTracks, const signed int songNumber, const bool repeatSongs = true);

		void play();
		void switchSongTemp(); //switches to a certain song ONCE
		void pause();
	protected:
		int position = 0;
		signed int songs;
		bool playingInsideThread = false;
		std::thread *musicPlayingThread;
		void musicPlayingThreadFunction();
		std::vector<std::string> musicTrackLocations;
		sf::Music currentTrack;
		bool playing = false;
	};
}
