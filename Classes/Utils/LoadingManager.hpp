//
//  LoadingManager.hpp
//  MyCards
//
//  Created by hungle on 6/20/16.
//
//

#ifndef LoadingManager_hpp
#define LoadingManager_hpp
#include "cocos2d.h"

USING_NS_CC; 

class LoadingManager : public Node {
    
public:
    LoadingManager();
    ~LoadingManager();
    CREATE_FUNC(LoadingManager);
    bool init();
    void showLoading(); 
    void hideLoading();
};

#endif 
