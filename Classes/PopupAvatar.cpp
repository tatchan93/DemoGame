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

	auto label = Label::createWithTTF("Cuong", "fonts/Marker Felt.ttf", 45);
	label->setPosition(Vec2(origin.x + label->getContentSize().width*1.2,
		origin.y + visibleSize.height - label->getContentSize().height * 1.2));
	label->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
	m_popupLayer->addChild(label, 100);

	auto level = Label::createWithTTF("Level:", "fonts/Marker Felt.ttf", 45);
	level->setPosition(Vec2(origin.x + label->getContentSize().width*1.2,
		origin.y + visibleSize.height - level->getContentSize().height * 2.4));
	level->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
	m_popupLayer->addChild(level, 100);

	auto level1 = Label::createWithTTF("10", "fonts/Marker Felt.ttf", 45);
	level1->setPosition(Vec2(origin.x + label->getContentSize().width * 2.4,
		origin.y + visibleSize.height - level->getContentSize().height * 2.4));
	level1->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
	m_popupLayer->addChild(level1, 100);

	auto Id = Label::createWithTTF("ID:", "fonts/Marker Felt.ttf", 45);
	Id->setPosition(Vec2(origin.x + label->getContentSize().width * 1.2,
		origin.y + visibleSize.height - level->getContentSize().height * 3.6));
	Id->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
	m_popupLayer->addChild(Id, 100);

	auto Id1 = Label::createWithTTF("24101995", "fonts/Marker Felt.ttf", 45);
	Id1->setPosition(Vec2(origin.x + label->getContentSize().width * 1.8,
		origin.y + visibleSize.height - level->getContentSize().height * 3.6));
	Id1->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
	m_popupLayer->addChild(Id1, 100);

	auto vip = Label::createWithTTF("Vip:", "fonts/Marker Felt.ttf", 45);
	vip->setPosition(Vec2(origin.x + label->getContentSize().width*1.2,
		origin.y + visibleSize.height - level->getContentSize().height * 4.8));
	vip->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
	m_popupLayer->addChild(vip, 100);

	auto vip1 = Label::createWithTTF("0/10", "fonts/Marker Felt.ttf", 45);
	vip1->setPosition(Vec2(origin.x + label->getContentSize().width * 2,
		origin.y + visibleSize.height - level->getContentSize().height * 4.8));
	vip1->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
	m_popupLayer->addChild(vip1, 100);

	auto soDT = Label::createWithTTF("SDT:", "fonts/Marker Felt.ttf", 45);
	soDT->setPosition(Vec2(origin.x + label->getContentSize().width*1.2,
		origin.y + visibleSize.height - level->getContentSize().height * 6));
	soDT->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
	m_popupLayer->addChild(soDT, 100);

	auto soDT1 = Label::createWithTTF("01675934956", "fonts/Marker Felt.ttf", 45);
	soDT1->setPosition(Vec2(origin.x + label->getContentSize().width * 2,
		origin.y + visibleSize.height - level->getContentSize().height * 6));
	soDT1->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
	m_popupLayer->addChild(soDT1, 100);

	auto sovanchoi = Label::createWithTTF("So van choi", "fonts/Marker Felt.ttf", 45);
	sovanchoi->setPosition(Vec2(origin.x + sovanchoi->getContentSize().width * 1.2,
		origin.y + visibleSize.height / 2 - sovanchoi->getContentSize().height * 2));
	m_popupLayer->addChild(sovanchoi, 100);

	auto sovanchoi1 = Label::createWithTTF("2000", "fonts/Marker Felt.ttf", 45);
	sovanchoi1->setPosition(Vec2(origin.x + sovanchoi->getContentSize().width * 1.2,
		origin.y + visibleSize.height / 2 - sovanchoi->getContentSize().height * 3.5));
	m_popupLayer->addChild(sovanchoi1, 100);

	auto sovanthang = Label::createWithTTF("So van thang", "fonts/Marker Felt.ttf", 45);
	sovanthang->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2 - sovanchoi->getContentSize().height * 2));
	m_popupLayer->addChild(sovanthang, 100);

	auto sovanthang1 = Label::createWithTTF("1000", "fonts/Marker Felt.ttf", 45);
	sovanthang1->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2 - sovanchoi->getContentSize().height * 3.5));
	m_popupLayer->addChild(sovanthang1, 100);

	auto sovanthua = Label::createWithTTF("So van thua", "fonts/Marker Felt.ttf", 45);
	sovanthua->setPosition(Vec2(origin.x + visibleSize.width - sovanchoi->getContentSize().width * 1.2,
		origin.y + visibleSize.height / 2 - sovanchoi->getContentSize().height * 2));
	m_popupLayer->addChild(sovanthua, 100);

	auto sovanthua1 = Label::createWithTTF("1000", "fonts/Marker Felt.ttf", 45);
	sovanthua1->setPosition(Vec2(origin.x + visibleSize.width - sovanchoi->getContentSize().width * 1.2,
		origin.y + visibleSize.height / 2 - sovanchoi->getContentSize().height * 3.5));
	m_popupLayer->addChild(sovanthua1, 100);

	auto avatar = Sprite::create("avatar.png");
	avatar->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - avatar->getContentSize().height / 2));
	m_popupLayer->addChild(avatar, 100);

	auto chisoTN = Label::createWithTTF("Chi so tin nhiem:", "fonts/Marker Felt.ttf", 40);
	chisoTN->setPosition(Vec2(origin.x + visibleSize.width - chisoTN->getContentSize().width*1.5,
		origin.y + visibleSize.height - label->getContentSize().height * 1.2));
	chisoTN->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
	m_popupLayer->addChild(chisoTN, 100);

	auto chisoTN1 = Label::createWithTTF("0", "fonts/Marker Felt.ttf", 40);
	chisoTN1->setPosition(Vec2(origin.x + visibleSize.width - chisoTN->getContentSize().width/2,
		origin.y + visibleSize.height - label->getContentSize().height * 1.2));
	chisoTN1->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
	m_popupLayer->addChild(chisoTN1, 100);

	auto tienken = Sprite::create("xu.png");
	tienken->setPosition(Vec2(origin.x + visibleSize.width - chisoTN->getContentSize().width*1.5,
		origin.y + visibleSize.height - level->getContentSize().height * 2.6));
	tienken->setScale(1.2f);
	tienken->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
	m_popupLayer->addChild(tienken, 100);

	auto tienxu = Button::create("xu.png");
	tienxu->setPosition(Vec2(origin.x + visibleSize.width - chisoTN->getContentSize().width*1.5,
		origin.y + visibleSize.height - level->getContentSize().height * 4.8));
	tienxu->setScale(1.2f);
	tienxu->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
	m_popupLayer->addChild(tienxu, 100);

	auto ken = Label::createWithTTF("10000", "fonts/Marker Felt.ttf", 30);
	ken->setPosition(Vec2(origin.x + visibleSize.width - chisoTN->getContentSize().width*1.3,
		origin.y + visibleSize.height - level->getContentSize().height * 2.6));
	ken->setScale(1.2f);
	ken->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
	m_popupLayer->addChild(ken, 100);

	auto xu = Label::createWithTTF("10000", "fonts/Marker Felt.ttf", 30);
	xu->setPosition(Vec2(origin.x + visibleSize.width - chisoTN->getContentSize().width*1.3,
		origin.y + visibleSize.height - level->getContentSize().height * 4.8));
	xu->setScale(1.2f);
	xu->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
	m_popupLayer->addChild(xu, 100);

    return true;
}
void PopupAvatar::onExit()
{
	Popup::onExit();
}