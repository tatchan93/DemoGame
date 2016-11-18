//
//  SoundConfig.h
//  MyCards
//
//  Created by hungle on 6/18/16.
//
//

#ifndef SoundConfig_h
#define SoundConfig_h

#include "cocos2d.h"
#include "Utils/TLMNConfig.hpp"
//#include "Handler/TLMNCardHandler.h"

//inline int getSound(int tag,std::vector<int> values){
//    switch (tag) {
//        case NO_CARD:
//            return cocos2d::RandomHelper::random_int(0,5);
//            break;
//        case CARD_SERIAL:
//            return cocos2d::RandomHelper::random_int(10,15);
//            break;
//        case CARD_COUPLE:
//            if(values.size() == 3){
//                return cocos2d::RandomHelper::random_int(10,11);
//            }else if(TLMNCardHandler::getInstance()->isHavingTwoCard(values)){
//                return cocos2d::RandomHelper::random_int(32,33);
//            }else {
//                return cocos2d::RandomHelper::random_int(16,21);
//            }
//            break;
//        case CARD_SINGLE:
//            if(TLMNCardHandler::getInstance()->isHavingTwoCard(values)){
//                return cocos2d::RandomHelper::random_int(28,31);
//            }else{
//                return cocos2d::RandomHelper::random_int(22,27);
//            }
//            
//            break;
//        default:
//            return -1;
//            break;
//    }
//}

inline int getPhomSound(int tag){
    switch (tag) {
        case 1:
            return cocos2d::RandomHelper::random_int(0,3); // anquan
            break;
        case 2:
            return cocos2d::RandomHelper::random_int(4,7); // an2quan
            break;
        case 3:
            return cocos2d::RandomHelper::random_int(8,11); // anchot
            break;
        case 4:
            return cocos2d::RandomHelper::random_int(12,15); // u
            break;
        case 5:
            return cocos2d::RandomHelper::random_int(16,18); // uden
            break;
        default:
            return -1;
    }
}

#endif /* SoundConfig_h */
