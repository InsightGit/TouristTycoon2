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
