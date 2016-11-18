#include "profile.h"
#include "ui/CocosGUI.h"
#include "PhongCho.h"
#include "XocDiaBan1.h"
USING_NS_CC;
using namespace ui;
Scene* profile::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = profile::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool profile::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto thongtin = Label::createWithTTF("&hienthongtin(&avatar1)", "fonts/Makers Fell.tff", 30);
	addChild(thongtin, 100);

    return true;
}