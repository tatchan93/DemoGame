#ifndef __PopupAvatar_SCENE_H__
#define __PopupAvatar_SCENE_H__

#include "cocos2d.h"
#include "Popup.hpp"

class PopupAvatar : public Popup
{
public:
	CREATE_FUNC(PopupAvatar);

	virtual void onExit();
    bool init();
    
    // implement the "static create()" method manually
};

#endif // __PopupAvatar_SCENE_H__
