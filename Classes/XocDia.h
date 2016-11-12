#ifndef __XocDia_SCENE_H__
#define __XocDia_SCENE_H__

#include "cocos2d.h"

class XocDia : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(XocDia);
};

#endif // __XocDia_SCENE_H__
