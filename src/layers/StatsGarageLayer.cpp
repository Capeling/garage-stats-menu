#include "StatsGarageLayer.h"

using namespace geode::prelude;

bool StatsGarageLayer::init() {
	if (!GJGarageLayer::init())
		return false;

	auto winSize = CCDirector::get()->getWinSize();

	m_fields->m_statsMenu = CCMenu::create();

	m_fields->m_nodeContainer.push_back(getExistingContainer("stars"));
	m_fields->m_nodeContainer.push_back(getExistingContainer("moons"));
	m_fields->m_nodeContainer.push_back(getExistingContainer("coins"));
	m_fields->m_nodeContainer.push_back(getExistingContainer("user-coins"));
	m_fields->m_nodeContainer.push_back(getExistingContainer("orbs"));
	m_fields->m_nodeContainer.push_back(getExistingContainer("diamonds"));
	m_fields->m_nodeContainer.push_back(getExistingContainer("diamond-shards"));

	for (size_t i = 0; i < m_fields->m_nodeContainer.size(); i++) {
		//m_fields->m_nodeContainer[i]->setLayout(AxisLayout::create()->setAutoScale(false)->setAxisReverse(true));
		m_fields->m_statsMenu->addChild(m_fields->m_nodeContainer[i]);
	}

	m_fields->m_statsMenu->setID("stats-menu"_spr);
	m_fields->m_statsMenu->setLayout(ColumnLayout::create()->setAutoScale(false)->setAxisReverse(true)->setAxisAlignment(AxisAlignment::End)->setCrossAxisAlignment(AxisAlignment::End)->setGap(15));
	this->addChild(m_fields->m_statsMenu);
	m_fields->m_statsMenu->setPosition(ccp(winSize.width - 18, winSize.height / 2 - 12));

	return true;
}

CCNode* StatsGarageLayer::getExistingContainer(std::string itemName) {
	auto ret = CCMenu::create(); 
	auto icon = this->getChildByID(itemName + "-icon");
	if (icon) {
		icon->removeFromParentAndCleanup(false);
		ret->addChild(icon);
		icon->setPosition({0, 0});
	}
	auto label = this->getChildByID(itemName + "-label"); 
	if (label) {	
		label->removeFromParentAndCleanup(false);
		ret->addChild(label);
		label->setPosition({-12, 0.5});
	}
	ret->setID(""_spr + itemName + "-container");
	ret->setContentSize({ 0, 0 });
	return ret;
}