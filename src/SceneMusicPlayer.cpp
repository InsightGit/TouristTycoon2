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
