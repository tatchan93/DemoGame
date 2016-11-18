#include "Phom.h"
#include "ui/CocosGUI.h"
#include "PhongCho.h"
USING_NS_CC;
using namespace ui;
Scene* Phom::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Phom::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Phom::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backgroundMenu = Sprite::create("backgruond.png");
	backgroundMenu->setPosition(visibleSize / 2);
	this->addChild(backgroundMenu, 0);

	auto back = Button::create("iconback.png");
	back->setPosition(Vec2(origin.x + back->getContentSize().width / 2,
		origin.y + visibleSize.height - back->getContentSize().height / 2));
	back->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type){
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			Director::getInstance()->replaceScene(PhongCho::createScene());
			break;
		}
	});
	this->addChild(back);

	auto phone = Button::create("icon-phone.png");
	phone->setPosition(Vec2(origin.x + phone->getContentSize().width*1.5,
		origin.y + visibleSize.height - phone->getContentSize().height / 2));
	phone->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type){
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			auto dienthoai = Scene::create();
			Director::getInstance()->pushScene(dienthoai);
			break;
		}
	});
	this->addChild(phone);

	auto menu = Sprite::create("menu.png");
	menu->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + menu->getContentSize().height / 2));
	this->addChild(menu);

	auto DoiThuong = Button::create("DOI-THUONG.png");
	DoiThuong->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + DoiThuong->getContentSize().height / 2));
	this->addChild(DoiThuong);

	auto caidat = Button::create("CAI-DAT.png");
	caidat->setPosition(Vec2(origin.x + visibleSize.width - caidat->getContentSize().width / 2,
		origin.y + caidat->getContentSize().height / 2));
	this->addChild(caidat);

	auto banbe = Button::create("banbe.png");
	banbe->setPosition(Vec2(origin.x + visibleSize.width - caidat->getContentSize().width - banbe->getContentSize().width,
		origin.y + banbe->getContentSize().height / 2));
	this->addChild(banbe);

	auto xephang = Button::create("XEP-HANG.png");
	xephang->setPosition(Vec2(origin.x + visibleSize.width - caidat->getContentSize().width - banbe->getContentSize().width
		- xephang->getContentSize().width*1.2, origin.y + xephang->getContentSize().height / 2));
	this->addChild(xephang);

	auto napxu = Button::create("NAP-XU.png");
	napxu->setPosition(Vec2(origin.x + visibleSize.width - caidat->getContentSize().width - banbe->getContentSize().width
		- xephang->getContentSize().width - napxu->getContentSize().width*1.7, origin.y + napxu->getContentSize().height / 2));
	this->addChild(napxu);

	auto khungavatar = Button::create("khungavataa.png");
	khungavatar->setPosition(Vec2(origin.x + khungavatar->getContentSize().width / 2,
		origin.y + khungavatar->getContentSize().height / 2));
	this->addChild(khungavatar);

	auto label1 = Label::createWithTTF("NganNguyen", "fonts/Marker Felt.ttf", 30);
	label1->setPosition(Vec2(origin.x + khungavatar->getContentSize().width + label1->getContentSize().width / 1.5,
		origin.y + khungavatar->getContentSize().height - label1->getContentSize().height));
	this->addChild(label1,100);

	auto label2 = Label::createWithTTF("ID: 25251325", "fonts/Marker Felt.ttf", 25);
	label2->setPosition(Vec2(origin.x + khungavatar->getContentSize().width + label1->getContentSize().width / 1.5,
		origin.y + label2->getContentSize().height));
	this->addChild(label2,100);

	auto vip = Sprite::create("vip1.png");
	vip->setPosition(Vec2(origin.x + khungavatar->getContentSize().width + label1->getContentSize().width / 1.5,
		origin.y + label2->getContentSize().height*2.4));
	this->addChild(vip);

	auto tienken = Button::create("xu.png");
	tienken->setPosition(Vec2(origin.x + visibleSize.width / 2 - tienken->getContentSize().width / 1.1,
		origin.y + tienken->getContentSize().height * 2));
	tienken->setScale(0.8);
	this->addChild(tienken);

	auto tienxu = Button::create("xu.png");
	tienxu->setPosition(Vec2(origin.x + visibleSize.width / 2 - tienxu->getContentSize().width / 1.1,
		origin.y + tienxu->getContentSize().height / 1.5));
	tienxu->setScale(0.8);
	this->addChild(tienxu);

	auto taoban = Button::create("taoban.png");
	taoban->setPosition(Vec2(origin.x + taoban->getContentSize().width / 2,
		origin.y + taoban->getContentSize().height*1.2 + menu->getContentSize().height));
	taoban->setScale(0.8);
	this->addChild(taoban);

	auto choingay = Button::create("choingay.png");
	choingay->setPosition(Vec2(origin.x + taoban->getContentSize().width / 2,
		origin.y + visibleSize.height / 2 + choingay->getContentSize().height / 1.8));
	choingay->setScale(0.8);
	this->addChild(choingay);
    return true;
}