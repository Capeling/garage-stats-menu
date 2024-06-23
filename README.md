# Stats Display API
Allows mods to easily add custom stats into the icon kit
## Developer usage
Make sure to declare Stats Display API as a dependency in your 'mod.json'
## Setting up Stats Display API for mod usage
```json
"dependencies": [
	{
		"id": "capeling.garage-stats-menu",
		"version": ">=v1.0.0",
		"importance": "required"
	}
]
```

Then include the API in your source file

`#include <capeling.garage-stats-menu/include/StatsDisplayAPI.h>`

## Usage
`StatsDisplayAPI::getNewItem` Has 4 things you need to pass through it

- The ID of the item (always use _spr!)
- The CCNode used for the icon
- How much of the item you have
- The scale of the icon

This will return a `CCNode` which you should add to stats menu!

## Example
To add a displayed stat you simply need to create a item through the API and then add it to the menu

This code adds your current fire shards to the display
```cpp
class $modify(GJGarageLayer) {
	bool init() {
		if (!GJGarageLayer::init())
			return false;

		auto statMenu = this->getChildByID("capeling.garage-stats-menu/stats-menu");

		auto myStatItem = StatsDisplayAPI::getNewItem("demons"_spr, CCSprite::createWithSpriteFrameName("fireShardSmall_001.png"), GameStatsManager::sharedState()->getStat("16"), 0.8f);

		if (statMenu) {
			statMenu->addChild(myStatItem);
			statMenu->updateLayout();
		}

		return true;
	}
};
```

If in any case the stats menu does not exist, you should check to make sure that it is not nullptr before adding your item
```cpp
auto statMenu = this->getChildByID("capeling.garage-stats-menu/stats-menu");
if (statMenu) {
	statMenu->addChild(myStatItem);
	statMenu->updateLayout();
}
```
