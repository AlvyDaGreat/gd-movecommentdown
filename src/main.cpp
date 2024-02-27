#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/ShareCommentLayer.hpp>
class $modify(MyShareCommentLayer, ShareCommentLayer) {
	bool init(gd::string p0, int p1, CommentType p2, int p3, gd::string p4) {
		if (!ShareCommentLayer::init(p0,p1,p2,p3,p4)) { return false; }

		auto amountY = Mod::get()->getSettingValue<double>("offset");
		auto amountX = Mod::get()->getSettingValue<double>("xoffset");
		auto node = dynamic_cast<cocos2d::CCNode*>(this->getChildren()->objectAtIndex(0));
		if (node) {
			node->setPosition(amountX,amountY * -1);
		}

		auto bgalpha = Mod::get()->getSettingValue<int64_t>("bg-alpha");
		this->setOpacity(bgalpha);

		return true;
	}
};
