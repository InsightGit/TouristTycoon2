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

#ifndef __CORE_CPP_
#define __CORE_CPP_
#include "ImagineCore.hpp"
#include <stdexcept>
#include <sstream>
#include <stdio.h>
#include <string>
#include <iostream>

imagine::types::rgbColor::rgbColor(const int red, const int green, const int blue){
	r = red;
	g = green;
	b = blue;
}

imagine::types::arrayLocation::arrayLocation(const std::string arrayIn,const signed int locationIn){
	arrayName=arrayIn;
	location=locationIn;
}

static imagine::types::platform imagine::core::getPlatform(){
#if _WIN32
#if _WIN64
	return imagine::types::platform::win64;
#else
	return imagine::types::platform::win32;
#endif
#endif
#if __linux
#if __GNUC__
#if __x86_64__
	return imagine::types::platform::lin64;
#else
	return imagine::types::platform::lin32;
#endif
#endif
#endif
#if __APPLE__ || __MACH__
	return imagine::types::platform::macos;
#endif
	return imagine::types::platform::unknown;
}
static std::string imagine::core::getPlatformString(){
	switch(imagine::core::getPlatform()){
		case imagine::types::platform::win64:
			return "Windows 64-bit";
		case imagine::types::platform::win32:
			return "Windows 32-bit";
		case imagine::types::platform::lin64:
			return "Linux 64-bit";
		case imagine::types::platform::lin32:
			return "Linux 32-bit";
		case imagine::types::platform::macos:
			return "macOS";
		case imagine::types::platform::unknown:
			return "Unknown";
	}
}

static bool imagine::core::isDebugBuild(){
#ifdef _DEBUG
	return true;
#else
	return false;
#endif
}

static std::string imagine::core::getExecutablePath(){

	/*if(getPlatform() == imagine::types::platform::win64 || getPlatform() == imagine::types::platform::win32){
		/*DWORD buffer[PATH_MAX];
		DWORD exeFileNameDWORD = GetModuleFileName(99);
		std::ostringstream exeFileNameStream;
		exeFileNameStream << exeFileNameDWORD;
		return exeFileNameStream.str();
	}
	else{
	    char buff[PATH_MAX];
	    ssize_t len = ::readlink("/proc/self/exe", buff, sizeof(buff)-1);
	    if (len != -1) {
	      buff[len] = '\0';
	      rename(buff,"zoing");
	      ssize_t len = ::readlink("/proc/self/exe", buff, sizeof(buff)-1);
	      buff[len] = '\0';
	      std::string stringBuff = buff;
	      stringBuff.erase(stringBuff.end()-6,stringBuff.end());

	      return stringBuff;
	    }
	    else{
	    	throw std::runtime_error("Could not find excecutable path. (UN*X method)");
	    }
	    /*char szTmp[32];
	    sprintf(szTmp, "/proc/%d/exe", getpid());
	    int bytes = MIN(readlink(szTmp, pBuf, len), len - 1);
	    if(bytes >= 0)
	        pBuf[bytes] = '\0';
	    return bytes;
	}*/
	return "";
}

static std::string imagine::core::getApplicationDataDir(){
	if(getPlatform()==imagine::types::lin32 || getPlatform()==imagine::types::lin64){
		char *USER = getenv("USER");
		std::string USERSTRING = USER;
		return "/home/"+USERSTRING+"/.";
	}else if(getPlatform()==imagine::types::win32 || getPlatform()==imagine::types::win64){
		return "%APPDATA%/"; //use forward slashes because they cause no difference in Windows and cause less internal errors
	}else if(getPlatform()==imagine::types::macos){
		char *USER = getenv("USER");
		std::string USERSTRING = USER;
		return "/Users/"+USERSTRING+"/Library/Application Support/";
	}
}

static bool imagine::core::doesFileExist(const std::string fileLocation){
	return access(fileLocation.c_str(),0) == 0;
}

//static bool doesDirectoryExist()

#endif
