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
