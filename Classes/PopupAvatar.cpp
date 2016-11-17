#include "PopupAvatar.h"
#include "ui/CocosGUI.h"
#include "PhongCho.h"
USING_NS_CC;
using namespace ui;

// on "init" you need to initialize your instance
bool PopupAvatar::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Popup::init() )
    {
		return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto label = Label::createWithTTF("Cuong", "fonts/Marker Felt.ttf", 30);
	label->setPosition(Vec2(origin.x + label->getContentSize().width,
		origin.y + visibleSize.height - label->getContentSize().height));
	m_popupLayer->addChild(label, 100);

	auto level = Label::createWithTTF("Level:", "fonts/Marker Felt.ttf", 30);
	level->setPosition(Vec2(origin.x + label->getContentSize().width,
		origin.y + visibleSize.height - level->getContentSize().width * 2));
	m_popupLayer->addChild(level, 100);

	auto level1 = Label::createWithTTF("10", "fonts/Marker Felt.ttf", 30);
	level1->setPosition(Vec2(origin.x + label->getContentSize().width * 2,
		origin.y + visibleSize.height - level->getContentSize().width * 2));
	m_popupLayer->addChild(level1, 100);


    return true;
}
void PopupAvatar::onExit()
{
	Popup::onExit();
}