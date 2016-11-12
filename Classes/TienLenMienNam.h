#ifndef __TienLenMienNam_SCENE_H__
#define __TienLenMienNam_SCENE_H__

#include "cocos2d.h"

class TienLenMienNam : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    
    // implement the "static create()" method manually
    CREATE_FUNC(TienLenMienNam);
};

#endif // __TienLenMienNam_SCENE_H__
