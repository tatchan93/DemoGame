#ifndef __Phom_SCENE_H__
#define __Phom_SCENE_H__

#include "cocos2d.h"

class Phom : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(Phom);
};

#endif // __Phom_SCENE_H__
