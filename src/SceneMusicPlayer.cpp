#include "SceneMusicPlayer.hpp"

void imagine::sceneMusicPlayer::musicPlayingThreadFunction(){
	while(!stopThread){
		if(playing){
			if(!playingInsideThread){
				currentTrack.play();
			}
			if(currentTrack.getStatus() == sf::SoundSource::Stopped){
				position++;
				if(position > songs-1 && repeating){
					position=0;
				}else{
					if(!currentTrack.openFromFile(musicTrackLocations[position])){
						throw imagine::exceptions::couldNotOpenMusicFile(musicTrackLocations[0]);
					}
				}

			}
		}else{
			if(currentTrack.getStatus() == sf::SoundSource::Playing){
				currentTrack.pause();
				playingInsideThread = false;
			}
		}
	}
	currentTrack.stop();
}

imagine::sceneMusicPlayer::sceneMusicPlayer(const std::vector<std::string> musicTracks, const signed int songNumber, const bool repeatSongs){
	repeating=repeatSongs;
	songs=songNumber;
	musicTrackLocations = musicTracks;
	if(!currentTrack.openFromFile(musicTrackLocations[0])){
		throw imagine::exceptions::couldNotOpenMusicFile(musicTrackLocations[0]);
	}
	musicPlayingThread = new std::thread();

}

void imagine::sceneMusicPlayer::play(){
	playing = true;
}

void imagine::sceneMusicPlayer::pause(){
	playing = false;
}
void imagine::sceneMusicPlayer::switchSongTemp(){
	//TODO: Implement temp song switching
}
