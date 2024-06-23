#pragma once

#include <Geode/Geode.hpp>

#ifdef GEODE_IS_WINDOWS
	#ifdef CAPELING_STATS_API_EXPORTING
		#define STATS_API_DLL __declspec(dllexport)
	#else
		#define STATS_API_DLL __declspec(dllimport)
	#endif
	#else
		#define STATS_API_DLL
#endif

class STATS_API_DLL StatsDisplayAPI {
public:
	static cocos2d::CCNode* getNewItem(std::string ID, cocos2d::CCNode* displayNode, int displayedNum, float nodeScale = 0.5f);

};