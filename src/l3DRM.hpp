/*
 * l3DRM.hpp
 *
 *  Created on: Feb 6, 2017
 *      Author: newbobby
 */
#include <boost/python.hpp>
#include <python3.5/Python.h>
//#include <>
#ifndef L3DRM_HPP_
#define L3DRM_HPP_

namespace imagine{
	class DRM{
		bool verified = false;
		int argec;
		char **argev;

		DRM();

		bool initalVerify(int argc,char **argv);
	};
}



#endif /* L3DRM_HPP_ */
