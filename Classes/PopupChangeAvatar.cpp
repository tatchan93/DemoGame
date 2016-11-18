//
//  PopupChangeAvatar.cpp
//  BigKen
//
//  Created by hungle on 10/11/16.
//
//

#include "PopupChangeAvatar.hpp"
#include "cocos2d.h"

bool PopupChangeAvatar::init() {
    if (!Popup::init())
        return false;
    
    backgroundPopup = MSprite::create(IMAGE_BG_POPUP_SETTING);
    backgroundPopup->setPosition(Vec2(visibleSize.width / 2 - backgroundPopup->getWidth() / 2,
                                      visibleSize.height / 2 - backgroundPopup->getHeight() / 2));
    
    backgroundContentSize = background->getContentSize();
    
    m_popupLayer->addChild(backgroundPopup);
    
    auto contentBackground = MSprite::create("content_cai_dat.png");
    contentBackground->setAnchorPoint(Point::ANCHOR_MIDDLE);
    contentBackground->setPosition(Vec2(backgroundPopup->getWidth() / 2,backgroundPopup->getHeight() / 2));
    backgroundPopup->addChild(contentBackground);
    
    auto bg_title_popup = MSprite::create(RS_TITLE_POPUP);
    bg_title_popup->setPosition(Vec2(backgroundPopup->getWidth() / 2 - bg_title_popup->getWidth() / 2,
                                     backgroundPopup->getHeight() - bg_title_popup->getHeight() / 2));
    backgroundPopup->addChild(bg_title_popup);
    
    auto title = MLabel::createTitle("Thay Avatar",bg_title_popup->getHeight()*0.6f);
    title->setColor(Color3B::BLACK);
    title->setPosition(bg_title_popup->getWidth() / 2 - title->getWidth() / 2,
                       bg_title_popup->getHeight() / 2 - title->getHeight() / 2);
    bg_title_popup->addChild(title);
    
    auto btn_save = MButton::create(BUTTON_SAVE, "OK", 30, TAG_EDIT_AVATAR);
    btn_save->setPosition(Vec2(backgroundPopup->getWidth() / 2 - btn_save->getWidth() / 2,
                               btn_save->getHeight()/2));
    btn_save->addTouchEventListener(CC_CALLBACK_2(PopupChangeAvatar::menuPopupCallBack, this));
    
    Size scollFrameSize = Size(contentBackground->getWidth(),
                               backgroundPopup->getHeight() - btn_save->getHeight()*2.5f);
    scrollView = ui::ScrollView::create();
    scrollView->setInnerContainerPosition(Vec2(0,scollFrameSize.height*4));
    scrollView->setContentSize(scollFrameSize);
    scrollView->setPosition(Vec2(contentBackground->getPosition().x - contentBackground->getWidth()/2,
                                 btn_save->getHeight()*1.6f));
    scrollView->setDirection(ui::ScrollView::Direction::VERTICAL);
    scrollView->setScrollBarEnabled(true);
    scrollView->setBounceEnabled(true);
    scrollView->setInertiaScrollEnabled(true);
    scrollView->setTouchEnabled(true);
    
    auto spriteT = MSprite::create("avatar100000.png");
    avatarSize = spriteT->getSize();
    containerSize = Size(scollFrameSize.width ,spriteT->getHeight()*(6*1.5f + 0.5f));
    scrollView->setInnerContainerSize(containerSize);
    backgroundPopup->addChild(scrollView);
    
    padding = scollFrameSize.width - 4*spriteT->getWidth();
    for(int i = 0 ;i < 21 ; i++){
        auto btn_avatar = MButton::create(StringUtils::format("avatar1000%02d.png",i),TAG_EDIT_AVATAR+i+1);
        btn_avatar->setZoomScale(0.05f);
        btn_avatar->setPosition(Vec2((avatarSize.width)* (i%4) + (1+i%4)* padding/5,
                                     containerSize.height - 1.5f*avatarSize.height* (int)(i /4 +1)));
        btn_avatar->addTouchEventListener(CC_CALLBACK_2(PopupChangeAvatar::avatarCallBack, this));
        scrollView->addChild(btn_avatar);
    }
    
    //button close
    auto btn_back = MButton::create(IMAGE_CLOSE);
    btn_back->setPosition(Vec2(backgroundPopup->getWidth() - btn_back->getWidth() *0.6f,
                               backgroundPopup->getHeight() - btn_back->getHeight() *0.6f));
    btn_back->setTag(TAG_POPUP_BTN_BACK);
    btn_back->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type) {
            case ui::Widget::TouchEventType::ENDED:
                this->disappear();
                break;
            default:
                break;
        }
    });
    
    touched = MSprite::create("round_avatar_touched.png");
    avatar_tag = Common::getInstance()->getAvatarId() - 100000;
    touched->setPosition(Vec2(avatarSize.width* (avatar_tag%4) + (1+avatar_tag%4)* padding/5
                              + avatarSize.width/2 - touched->getWidth()/2,
                              containerSize.height - 1.5f*avatarSize.height* (int)(avatar_tag /4 +1)
                              + 0.5f*avatarSize.height- touched->getHeight()/2));
    scrollView->addChild(touched);
    
    auto blur = MSprite::create("line_blur_setting.png");
    blur->setPosition(Vec2(backgroundPopup->getWidth()/2 - blur->getWidth()/2,
                           btn_save->getHeight()*1.6f));
    backgroundPopup->addChild(blur);
    
    /*auto blur_up = MSprite::create("line_blur_setting.png");
     blur_up->setPosition(Vec2(backgroundPopup->getWidth()/2 - blur->getWidth()/2,
     btn_save->getHeight()*1.6f - blur_up->getHeight()));
     blur_up->setFlippedY(true);
     backgroundPopup->addChild(blur_up);*/
    
    backgroundPopup->addChild(btn_back);
    backgroundPopup->addChild(btn_save);
    
    return true;
}

void PopupChangeAvatar::menuPopupCallBack(cocos2d::Ref *sender, Widget::TouchEventType type){
    if (type == Widget::TouchEventType::ENDED){
        if(avatar_tag >= 0){
            Common::getInstance()->setAvatarId(100000+avatar_tag);
            BINEditingInfo* editInfo = new BINEditingInfo[1];
            editInfo[0].set_infofield(5);
            editInfo[0].set_newvalue(StringUtils::format("1000%02d",avatar_tag));
            NetworkManager::getInstance()->getUpdateUserInfoMessageFromServer(editInfo,1);
            this->disappear();
        }
    }
}

void PopupChangeAvatar::avatarCallBack(cocos2d::Ref *sender, Widget::TouchEventType type){
    if (type == Widget::TouchEventType::ENDED){
        auto button = (MButton*)sender;
        int tag = button->getTag();
        
        avatar_tag = tag - 1 - TAG_EDIT_AVATAR;
        touched->setPosition(Vec2(avatarSize.width* (avatar_tag%4) + (1+avatar_tag%4)* padding/5
                                  + avatarSize.width/2 - touched->getWidth()/2,
                                  containerSize.height - 1.5f*avatarSize.height* (int)(avatar_tag /4 +1)
                                  + 0.5f*avatarSize.height- touched->getHeight()/2));
    }
}

void PopupChangeAvatar::onExit() {
    Popup::onExit();
}
