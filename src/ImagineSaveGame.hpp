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
#ifndef __IMAGINESAVEGAME_HPP
#define __IMAGINESAVEGAME_HPP

#include <jsoncpp/json/value.h>
#include <jsoncpp/json/writer.h>
#include "ImagineCore.hpp"
#include <fstream>
#include <sstream>
#ifdef _WIN32
   #include <windows.h>

   #typedef S_IRWXU "holder"
   int mkdir(const std::string place,const std::string holder){
	   //placeholder for Windows compilers
   }
#else
   #include <sys/stat.h>

   /*void CreateDirectory(const std::string place,const int holder){
	   //placeholder for UN*X compilers
   }*/
#endif

//#include <filesystem> when c++17 comes right along


namespace imagine{
	class saveGame{
	public:
		bool isLoaded = false;
		Json::Value saveFileRoot;
		Json::Value motd;

		saveGame();
		saveGame(const std::string saveFileLocation); //initing loads file for you

		bool isOverwritingExistingSave();
		virtual void save(); //uses internal class saveFile value
		void save(Json::Value newSaveFile);
	//protected:
		std::string saveFileLoc;
	};
}
#endif
