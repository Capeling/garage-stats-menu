#pragma once

#ifndef STATSGARAGELAYER_H
#define STATSGARAGELAYER_H

#include <Geode/Geode.hpp>
#include <Geode/modify/GJGarageLayer.hpp>
#include "../Macros.h"

class StatsGarageLayer : public geode::Modify<StatsGarageLayer, GJGarageLayer> {
public:
	struct Fields {
		cocos2d::CCMenu* m_statsMenu = nullptr;
		std::vector<cocos2d::CCNode*> m_nodeContainer = {};
	};
	$override
	bool init();

	cocos2d::CCNode* getExistingContainer(std::string itemName);

	EARLY_MODIFY(GJGarageLayer::init);
};
#endif