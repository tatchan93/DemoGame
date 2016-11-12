#ifndef __Sam_SCENE_H__
#define __Sam_SCENE_H__

#include "cocos2d.h"

class Sam : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(Sam);
};

#endif // __Sam_SCENE_H__
