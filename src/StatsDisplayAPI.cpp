#include "../include/StatsDisplayAPI.h"

using namespace geode::prelude;

CCNode* StatsDisplayAPI::getNewItem(std::string ID, cocos2d::CCNode* displayNode, int displayedNum, float nodeScale) {
	auto ret = CCMenu::create();

	displayNode->setID(ID + "-icon");
	displayNode->setScale(nodeScale);
	displayNode->removeFromParentAndCleanup(false);
	displayNode->setPosition({ 0, 0 });
	ret->addChild(displayNode);

	auto label = CCLabelBMFont::create(std::to_string(displayedNum).c_str(), "bigFont.fnt");
	label->setID(ID + "-label");
	label->setScale({ 0.34 });
	label->setAnchorPoint({ 1, 0.5 });
	label->removeFromParentAndCleanup(false);
	label->setPosition({ -12, 0.5 });
	ret->addChild(label);

	ret->setID(ID + "-container");
	ret->setContentSize({ 0, 0 });
	return ret;
}