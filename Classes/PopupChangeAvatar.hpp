//
//  PopupChangeAvatar.hpp
//  BigKen
//
//  Created by hungle on 10/11/16.
//
//

#ifndef PopupChangeAvatar_hpp
#define PopupChangeAvatar_hpp

#include "cocos2d.h"
#include "Popup.hpp"
class PopupChangeAvatar : public Popup {
    
public:
    
    CREATE_FUNC(PopupChangeAvatar);
    
    bool init();
    virtual void onExit();
    void menuPopupCallBack(Ref *sender, ui::Widget::TouchEventType type);
    void avatarCallBack(Ref *sender, ui::Widget::TouchEventType type);
    int avatar_tag = -1;
private:
    Sprite* touched;
    float padding;
    Size avatarSize;
    Size containerSize;
    ui::ScrollView* scrollView;
    
};

#endif /* PopupChangeAvatar_hpp */
