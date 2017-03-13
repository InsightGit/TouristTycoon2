#ifndef _IMAGINECORE_HPP
#define _IMAGINECORE_HPP
#include <string>
#if _WIN32
#include <windows.h>
#include <io.h> //not sure if this is redundant; currently using linux
#define access    _access_s
#else
#include <unistd.h> //oh how thy adore you UN*X
#include <limits.h>
#include <exception>
#include <stdexcept>
typedef unsigned int DWORD;
#define MAX_PATH 0
//DWORD GetModuleFileName(DWORD size){
	//return NULL;
//}
#endif
#include <exception>
#include <stdexcept>
#include <SFML/Graphics.hpp>
extern const char *__progname;


namespace imagine{
	namespace exceptions{
		class saveFileMotdNotFoundException : public std::runtime_error {
		public:
			saveFileMotdNotFoundException(const std::string fileName) : std::runtime_error("Could not read save file motd in "+fileName) {}
		};
		class couldNotOpenSaveFile : public std::runtime_error{
		public:
			couldNotOpenSaveFile(const std::string fileName) : std::runtime_error("Could not read save file "+fileName){}
		};
		class couldNotOpenMusicFile : public std::runtime_error{
		public:
			couldNotOpenMusicFile(const std::string fileName) : std::runtime_error("Could not read music file "+fileName){}
		};
		class couldNotOpenFontFileException : public std::runtime_error{
		public:
			couldNotOpenFontFileException(const std::string fileName) : std::runtime_error("Could not read font file "+fileName){}
		};
		class invalidDateException : public std::runtime_error {
		public:
			invalidDateException() : std::runtime_error("Invalid date entered"){}
		};
		class invalidSaveFileException : public std::runtime_error{
		public:
			invalidSaveFileException(std::string where) : std::runtime_error("Could not parse Save File JSON at "+where){}
		};
	}
	class types {
	public:
		enum menuDirection {
			Up,
			Down
		};
		enum event{
			none,
			newGame,
			loadGame,
			options,
			exit
		};
		enum platform{
			win32,
			win64,
			macos,
			lin32,
			lin64,
			unknown
		};
		class rgbColor{ //use this when you have a set transparency value in SFML for colors
		public:
			int r;
			int g;
			int b;

			rgbColor(const int red, const int green, const int blue);
		};
		class arrayLocation{
		public:
			std::string arrayName;
			signed int location;

			arrayLocation(const std::string arrayIn,const signed int locationIn);
		};
	};
	class core{
	public:
		static std::string getImagineInfo();
		static types::platform getPlatform(); //the linux preprocessor directions ONLY WORK using GCC/G++; NO CLANG
		static std::string getPlatformString();
		static std::string getExecutablePath();
		static std::string getApplicationDataDir();
		static bool isDebugBuild();
		static bool doesFileExist(const std::string fileLocation);
		//static bool doesDirectoryExist();
	};
}
#endif
