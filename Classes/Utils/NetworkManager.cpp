#include "NetworkManager.h"
#include "Common.h"
#include "TLMNConfig.hpp"

#if WIN32
    #pragma comment(lib, "libprotobuf.lib")
#endif

#include "cocos2d.h"
#include <thread>
#include <string>
#include <sstream>
#include <stdexcept>
#include <string.h>
#include <vector>
#include <queue>
//#include "zlib.h"
#include "Utils/DefaultSocket.h"
#include "Utils/LoadingManager.hpp"
//#include "Popups/PopupReconnect.hpp"
//#include "Popups/PopupMessageBox.hpp"
//#include "UI/MToast.hpp"

#define MAX_SIZE 1024 * 1024
#define DEBUG 0

USING_NS_CC;
using namespace std;

void NetworkManager::callNetwork(char* ackBuf, int size) {
    DefaultSocket::getInstance()->sendData(ackBuf, size);
    Common::getInstance()->sleep(NetworkManager::SEND_MESSAGE_DELAY);
}

NetworkManager *NetworkManager::getInstance() {
    if (!_instance)
        _instance = new NetworkManager();
    return _instance;
}

void NetworkManager::setInitialize(bool is_initialized) {
    _initialized = is_initialized;
}

bool NetworkManager::isInitialized() {
    return _initialized;
}

//google::protobuf::Message* getTypeMessage(google::protobuf::Message* msg, int messageid) {
//    switch (messageid) {
//    case NetworkManager::INITIALIZE:
//        msg = new BINInitializeResponse();
//        break;
//    case NetworkManager::REGISTER:
//        msg = new BINRegisterResponse();
//        break;
//    case NetworkManager::LOGIN:
//        msg = new BINLoginResponse();
//        break;
//    case NetworkManager::EXPIRED_SESSION:
//        msg = new BINSessionExpiredResponse();
//        break;
//    case NetworkManager::ENTER_ROOM:
//        msg = new BINEnterRoomResponse();
//        break;
//	case NetworkManager::ENTER_GROUP_ROOM:
//		msg = new BINEnterRoomResponse();
//		break;
//    case NetworkManager::PLAYER_ENTER_ROOM:
//        msg = new BINPlayerEnterRoomResponse();
//        break;
//    case NetworkManager::ENTER_ZONE:
//        msg = new BINEnterZoneResponse();
//        break;
//    case NetworkManager::PING:
//        msg = new BINPingResponse();
//        break;
//    case NetworkManager::FILTER_ROOM:
//        msg = new BINFilterRoomResponse();
//        break;
//    case NetworkManager::START_MATCH:
//        msg = new BINStartMatchResponse();
//        break;
//    case NetworkManager::CREATE_ROOM:
//        msg = new BINCreateRoomResponse();
//        break;
//    case NetworkManager::TURN:
//        msg = new BINTurnResponse();
//        break;
//    case NetworkManager::MATCH_BEGIN:
//        msg = new BINMatchBeginResponse();
//        break;
//    case NetworkManager::MATCH_END:
//        msg = new BINMatchEndResponse();
//        break;
//    case NetworkManager::PLAYER_EXIT_AFTER_MATCH_END:
//        msg = new BINPlayerExitAfterMatchEndResponse();
//        break;
//    case NetworkManager::PLAYER_EXIT_ROOM:
//        msg = new BINPlayerExitRoomResponse();
//        break;
//    case NetworkManager::UPDATE_MONEY:
//        msg = new BINUpdateMoneyResponse();
//        break;
//    case NetworkManager::EXIT_ROOM:
//        msg = new BINExitRoomResponse();
//        break;
//    case NetworkManager::PREPARE_NEW_MATCH:
//        msg = new BINPrepareNewMatchResponse();
//        break;
//    case NetworkManager::ROOM_OWNER_CHANGED:
//        msg = new BINRoomOwnerChangedResponse();
//        break;
//    case NetworkManager::CANCEL_EXIT_ROOM:
//        msg = new BINCancelExitAfterMatchEndResponse();
//        break;
//    case NetworkManager::READY_TO_PLAY:
//        msg = new BINReadyToPlayResponse();
//        break;
//    case NetworkManager::UPDATE_USER_INFO:
//        msg = new BINUpdateUserInfoResponse();
//        break;
//    case NetworkManager::LOGOUT:
//        msg = new BINLogoutResponse();
//        break;
//    case NetworkManager::KICK_USER:
//        msg = new BINKickPlayerOutResponse();
//        break;
//    case NetworkManager::LOCK_ROOM:
//        msg = new BINLockRoomResponse();
//        break;
//    case NetworkManager::FILTER_TOP_USER:
//        msg = new BINFilterTopUserResponse();
//        break;
//    case NetworkManager::FILTER_FRIEND:
//        msg = new BINFilterFriendResponse();
//        break;
//    case NetworkManager::ADD_FRIEND:
//        msg = new BINAddFriendResponse();
//        break;
//    case NetworkManager::FILTER_ADD_FRIEND:
//        msg = new BINFilterAddFriendResponse();
//        break;
//    case NetworkManager::APPROVE_ADD_FRIEND:
//        msg = new BINApproveAddFriendResponse();
//        break;
//    case NetworkManager::FIND_USER:
//        msg = new BINFindUserResponse();
//        break;
//    case NetworkManager::VIEW_USER_INFO:
//        msg = new BINViewUserInfoResponse();
//        break;
//    case NetworkManager::REMOVE_FRIEND:
//        msg = new BINRemoveFriendResponse();
//        break;
//    case NetworkManager::CHANGE_RULE:
//        msg = new BINChangeRuleResponse();
//        break;
//    case NetworkManager::LOOKUP_MONEY_HISTORY:
//        msg = new BINLookUpMoneyHistoryResponse();
//        break;
//    case NetworkManager::SEND_TEXT_EMOTICON:
//        msg = new BINSendTextEmoticonResponse();
//        break;
//    case NetworkManager::INSTANT_MESSAGE:
//        msg = new BINInstantMessageResponse();
//        break;
//    case NetworkManager::UPDATE_USER_SETTING:
//        msg = new BINUpdateUserSettingResponse();
//        break;
//    case NetworkManager::FILTER_MAIL:
//        msg = new BINFilterMailResponse();
//        break;
//    case NetworkManager::SEND_MAIL:
//        msg = new BINSendMailResponse();
//        break;
//    case NetworkManager::DELETE_MAIL:
//        msg = new BINDeleteMailResponse();
//        break;
//    case NetworkManager::READED_MAIL:
//        msg = new BINReadedMailResponse();
//        break;
//    case NetworkManager::CLAIM_ATTACH_ITEM:
//        msg = new BINClaimAttachItemResponse();
//        break;
//    case NetworkManager::LEVEL_UP: 
//        msg = new BINLevelUpResponse();
//        break;
//    case NetworkManager::MEDAL_UP:
//        msg = new BINMedalUpResponse(); 
//        break;
//    case NetworkManager::CAPTCHA:
//        msg = new BINCaptchaResponse();
//        break;
//    case NetworkManager::PURCHASE_MONEY:
//        msg = new BINPurchaseMoneyResponse();
//        break;
//    case NetworkManager::KILL_ROOM: 
//        msg = new BINKillRoomResponse(); 
//        break;
//    case NetworkManager::EXIT_ZONE:
//        msg = new BINExitZoneResponse();
//        break;
//    case NetworkManager::BET:
//        msg = new BINBetResponse();
//        break;
//    case NetworkManager::CHANGE_HOST: 
//        msg = new BINChangeHostResponse(); 
//        break;
//    case NetworkManager::EXTRA_BET:
//        msg = new BINExtraBetResponse();
//        break;
//    case NetworkManager::HOST_REGISTRATION:
//        msg = new BINHostRegistrationResponse();
//        break;
//	case NetworkManager::LOOKUP_USER_TO_INVITE:
//		msg = new BINLookUpUserToInviteResponse();
//		break;
//	case NetworkManager::INVITE_TO_ROOM:
//		msg = new BINInviteToRoomResponse();
//		break;
//	case NetworkManager::CANCEL_INVITE:
//		msg = new BINCancelInvitationResponse();
//		break;
//	case NetworkManager::RELY_INVITE:
//		msg = new BINRelyInvitationResponse();
//		break;
//	case NetworkManager::REDEEM_GIFT_CODE:
//		msg = new BINRedeemGiftCodeResponse();
//		break;
//	case NetworkManager::REDEEM_GIFT_CODE_HISTORY:
//		msg = new BINRedeemGiftCodeHistoryResponse();
//		break;
//	case NetworkManager::ASSET_CONFIG:
//		msg = new BINAssetConfigResponse();
//		break;
//	case NetworkManager::EXCHANGE_ASSET:
//		msg = new BINExchangeAssetResponse();
//		break;
//	case NetworkManager::EXCHANGE_CASH_TO_GOLD:
//		msg = new BINExchangeCashToGoldResponse();
//		break;
//	case NetworkManager::EXCHANGE_ASSET_HISTORY:
//		msg = new BINExchangeAssetHistoryResponse();
//		break;
//	case NetworkManager::PURCHASE_CASH_HISTORY:
//		msg = new BINPurchaseCashHistoryResponse();
//		break;
//	case NetworkManager::EXCHANGE_GOLD_HISTORY:
//		msg = new BINExchangeGoldHistoryResponse();
//		break;
//	case NetworkManager::SMS_CONFIG:
//		msg = new BINSmsConfigResponse();
//		break;
//	case NetworkManager::USER_VERIFY_CONFIG:
//		msg = new BINUserVerifyConfigResponse();
//		break;
//	case NetworkManager::USER_VERIFY:
//		msg = new BINUserVerifyResponse();
//		break;
//	case NetworkManager::CASH_TRANSFER:
//		msg = new BINCashTransferResponse();
//		break;
//	case NetworkManager::CASH_TRANSFER_CONFIG:
//		msg = new BINCashTransferConfigResponse();
//		break;
//    case NetworkManager::RESET_PASSWORD:
//        msg = new BINResetPasswordResponse();
//        break;
//	case NetworkManager::FIND_USER_BY_ID:
//		msg = new BINFindUserByIdResponse();
//		break;
//	case NetworkManager::EXCHANGE_C2G_CONFIG:
//		msg = new BINExchangeC2GConfigResponse();
//		break;
//	case NetworkManager::CARD_CONFIG:
//		msg = new BINCardConfigResponse();
//		break;
//	case NetworkManager::HEAD_LINE:
//		msg = new BINHeadLineResponse();
//		break;
//	case NetworkManager::EMERGENCY_NOTIFICATION:
//		msg = new BINEmergencyNotificationResponse();
//		break;
//	case NetworkManager::LUCKY_WHEEL_CONFIG:
//		msg = new BINLuckyWheelConfigResponse(); 
//		break;
//	case NetworkManager::BUY_TURN:
//		msg = new BINBuyTurnResponse(); 
//		break;
//	case NetworkManager::JAR_REQUEST: 
//		msg = new BINJarResponse(); 
//		break;
//    default:
//        msg = 0;
//        break;
//    }
//    return msg;
//}
//
//std::vector<std::pair<google::protobuf::Message*, int>> NetworkManager::parseFrom(
//    std::vector<char> read_str, int len)
//{
//    vector<std::pair<google::protobuf::Message*, int>> listMessages;
//	bool debug = false; 
//    try {
//        if (read_str.size() == 0)
//            throw std::runtime_error("message byte: 0");
//        char* chars_from_read = &read_str[0];
//        int lenPacket = len; 
//		if (DEBUG) {
//			CCLOG("len: %d, read str length: %d", len, read_str.size());
//			string readStr = "";
//			for (int i = 0; i < len - 1; i++) {
//				//	CCLOG("%i", read_str[i]);
//				readStr += StringUtils::format("%i,", read_str[i]);
//			}
//			readStr += StringUtils::format("%i", read_str[read_str.size() - 1]);
//			CCLOG("len packet: %d, packet: %s", len, readStr.c_str());
//		}
//		
//        google::protobuf::io::ArrayInputStream arrayIn(chars_from_read, lenPacket);
//        google::protobuf::io::CodedInputStream codedIn(&arrayIn);
//
//        while (lenPacket > 0) {
//            char *data_size_chars = new char[4];
//            codedIn.ReadRaw(data_size_chars, 4);
//
//            int bytes_size = ((data_size_chars[0] & 0xFF) << 24)
//                + ((data_size_chars[1] & 0xFF) << 16)
//                + ((data_size_chars[2] & 0xFF) << 8)
//                + ((data_size_chars[3] & 0xFF) << 0);
//            delete[] data_size_chars;
//
//            //read compress
//            char *is_compress_chars = new char[1];
//            codedIn.ReadRaw(is_compress_chars, 1);
//
//            int is_compress = is_compress_chars[0];
//
//            delete[] is_compress_chars;
//
//            int left_byte_size = bytes_size - 1;
//            lenPacket -= (bytes_size + 4);
//
//            google::protobuf::Message *response = 0;
//
//            /*if is_compress = 1 */
//            if (is_compress == 1) {
//                google::protobuf::io::CodedInputStream::Limit msgLimit = 
//                    codedIn.PushLimit(left_byte_size); //limit compressed size
//                //read data compressed
//                char *data_compressed = new char[left_byte_size];
//
//                codedIn.ReadRaw(data_compressed, left_byte_size);
//                codedIn.PopLimit(msgLimit);
//                vector<char> result = Common::getInstance()->decompress_gzip2(
//                    data_compressed, (int)left_byte_size);
//                char* data_uncompressed = reinterpret_cast<char*>(result.data());
//
//                int length = (int)result.size();
//                int index = 0;
//                while (index < length) {
//                    //read datablocksize
//                    int data_size_block = ((data_uncompressed[index] & 0xFF) << 8) + ((data_uncompressed[index + 1] & 0xFF) << 0);
//                    //read messageid
//                    int messageid = ((data_uncompressed[index + 2] & 0xFF) << 8) + ((data_uncompressed[index + 3] & 0xFF) << 0);
//                    //read protobuf message
//
//                    response = getTypeMessage(response, messageid);
//
//                    if (response == 0) {
//                        CCLOG("unknown message");
//						throw std::runtime_error("");
//					}
//
//                    bool isRead = response->ParseFromArray(&data_uncompressed[index + 4], data_size_block - 2);
//                    index += (data_size_block + 2);
//                    if (isRead)
//                        listMessages.push_back(std::make_pair(response, messageid));
//                }
//            }
//            else {
//                /* if is_compression = 0 */
//                while (left_byte_size > 0) {
//                    //read protobuf + data_size_block + mid
//                    //read datasizeblock
//                    char *data_size_block_chars = new char[2];
//
//                    codedIn.ReadRaw(data_size_block_chars, 2);
//
//                    int data_size_block = ((data_size_block_chars[0] & 0xFF) << 8) + ((data_size_block_chars[1] & 0xFF) << 0);
//
//                    delete[] data_size_block_chars;
//
//                    // read messageid
//
//                    char *mid_chars = new char[2];
//
//                    codedIn.ReadRaw(mid_chars, 2);
//
//                    int messageid = ((mid_chars[0] & 0xFF) << 8) + ((mid_chars[1] & 0xFF) << 0);
//
//                    delete[] mid_chars;
//
//                    google::protobuf::io::CodedInputStream::Limit msgLimit = codedIn.PushLimit(data_size_block - 2);
//
//                    response = getTypeMessage(response, messageid);
//                    if (response != 0) {
//                        bool isRead = response->ParseFromCodedStream(&codedIn);
//                        codedIn.PopLimit(msgLimit);
//                        left_byte_size -= (data_size_block + 2);
//                        if (isRead)
//                            listMessages.push_back(std::make_pair(response, messageid));
//					}
//					else {
//						CCLOG("unknown message");
//						throw std::runtime_error("");
//					}
//						
//                }
//            }
//        }
//
//        if (lenPacket > 0) {
//            CCLOG("NetworkManager: error packet length = 0");
//        }
//      
//        //read data size  
//    }
//    catch (...) {
//       // CCLOG("error: %s", e.what());
//        CCLOG("NetworkManager: error packet");
//        // listMessages.clear();
//    }
//
//    return listMessages;
//}

//google::protobuf::Message* NetworkManager::initLoginMessage(string username, string password) {
//    auto request = new BINLoginRequest();
//    request->set_username(username);
//    request->set_password(password);
//    return request;
//}
//google::protobuf::Message* NetworkManager::initLogoutMessage(bool doLogout) {
//    auto request = new BINLogoutRequest();
//    request->set_dologout(doLogout);
//    return request;
//}
//
//google::protobuf::Message* NetworkManager::initOpenIdLoginMessage(
//    int channelId, string openId, string firstname, string lastname) {
//    auto request = new BINOpenIdLoginRequest();
//    request->set_channel(channelId);
//    request->set_openid(openId);
//    request->set_firstname(firstname);
//    request->set_lastname(lastname);
//
//    return request;
//}

//google::protobuf::Message* NetworkManager::initExitRoomLoginMessage(int room_index) {
//    auto request = new BINExitRoomRequest();
//    request->set_roomindex(room_index);
//    return request;
//}
//google::protobuf::Message* NetworkManager::initCancelExitRoomLoginMessage(int room_index) {
//  auto request = new BINCancelExitAfterMatchEndRequest();
//  request->set_roomindex(room_index);
//  return request;
//}
char* NetworkManager::initData(google::protobuf::Message* request, int os, int messid,
    std::string _session, int &len)
{
    std::vector<char> bytes(_session.begin(), _session.end());
    bytes.push_back('\0');
    //N byte session
    char *session = &bytes[0];
    //2 byte lenSession
    int lenSession = (int)strlen(session);
    int size = request->ByteSize() + 11 + lenSession;
    char* ackBuf = new char[size];
    
    google::protobuf::io::ArrayOutputStream arrayOut(ackBuf, size);
    google::protobuf::io::CodedOutputStream codedOut(&arrayOut);

    char* buf = new char[1];
    buf[0] = os;
    codedOut.WriteRaw(buf, 1); //write os
    char* dataSize = new char[4];
    //data size: protobuf + eot + messageid

    int data_size = request->ByteSize() + 4;
    dataSize[0] = (data_size >> 24) & 0xFF;
    dataSize[1] = (data_size >> 16) & 0xFF;
    dataSize[2] = (data_size >> 8) & 0xFF;
    dataSize[3] = (data_size >> 0) & 0xFF;

    //4 byte data size
    codedOut.WriteRaw(dataSize, 4);
    //write data size
    char* char_len_session = new char[2];
    char_len_session[0] = (lenSession >> 8) & 0xFF;
    char_len_session[1] = (lenSession >> 0) & 0xFF;
    //2 byte length session
    codedOut.WriteRaw(char_len_session, 2);
    //n byte session
    codedOut.WriteRaw(session, lenSession);
    // loginRequest->SerializeToCodedStream(&codedOut);
    //2 byte messid
    char* mid = new char[2];
    mid[0] = (messid >> 8) & 0xFF;
    mid[1] = (messid >> 0) & 0xFF;

    codedOut.WriteRaw(mid, 2);
    //protobuf
    request->SerializeToCodedStream(&codedOut);

    /*char *eot = new char[2];
    eot[0] = '\r';
    eot[1] = '\n';*/

    codedOut.WriteRaw("\r\n", 2);
    len = size;
    return ackBuf;

}

//google::protobuf::Message* NetworkManager::initInitializeMessage(string cp, string appversion,
//    string country, string language, string device_id, string device_info,  
//    string packageName) {
//    auto request = new BINInitializeRequest();
//	request->set_cp(cp);
//	request->set_appversion(appversion);
//	request->set_country(country);
//	request->set_language(language);
//	request->set_deviceid(device_id);
//	request->set_deviceinfo(device_info);
//    request->set_pakagename(packageName);
//  
//    return request;
//}
//
//google::protobuf::Message* NetworkManager::initRegisterMessage(string username, 
//    string password, string confirm_password, string full_name, string sdt)
//{
//    BINRegisterRequest *request = new BINRegisterRequest();
//
//    request->set_username(username);
//    request->set_password(password);
//    request->set_confirmpassword(confirm_password);
//    request->set_displayname(full_name);
//	request->set_mobile(sdt);
//
//    return request;
//}
//
//google::protobuf::Message* NetworkManager::initEnterZoneMessage(int zoneId) {
//    BINEnterZoneRequest *request = new BINEnterZoneRequest();
//    request->set_zoneid(zoneId);
//    return request;
//}
//
///*lookup money history message*/
//
//google::protobuf::Message* NetworkManager::initLookupMoneyHistoryMessage(int 
//    firstResult, int maxResult, int filterType) {
//    auto request = new BINLookUpMoneyHistoryRequest();
//    request->set_firstresult(firstResult);
//    request->set_maxresult(maxResult);
//    request->set_filtertype(filterType);
//    return request; 
//}

//filterType
//1: lich su dong cash
//2: lich su dong gold
//3: lich su nap cash
//4: lich su nap gold
//5: lich su doi cash
void NetworkManager::getLookupMoneyHistoryMessage(int firstResult, int 
    maxResult, int filterType) {
    google::protobuf::Message *request = initLookupMoneyHistoryMessage(
        firstResult, maxResult, filterType);
    requestMessage(request, Common::getInstance()->getOS(), 
        NetworkManager::LOOKUP_MONEY_HISTORY, Common::getInstance()
        ->getSessionId());
}

/*end*/

//google::protobuf::Message* NetworkManager::initFilterRoomMessage(int zone_id,
//	int roomType, int first_result, int max_result, int orderByField, bool asc) {
//    auto request = new BINFilterRoomRequest();
//    request->set_zoneid(zone_id);
//	request->set_roomtype(roomType);
//    request->set_firstresult(first_result);
//    request->set_maxresult(max_result);
//	request->set_orderbyfield(orderByField);
//    request->set_asc(asc);
//    return request;
//}


//google::protobuf::Message* NetworkManager::initQuickPlayMessage(string
//    device_id, string device_info) {
//    BINQuickPlayRequest *request = new BINQuickPlayRequest();
//    request->set_deviceid(device_id);
//    request->set_deviceinfo(device_info);
//    return request;
//}
//
//google::protobuf::Message* NetworkManager::initMatchEndRequest(int roomIndex) {
//	auto request = new BINMatchEndRequest();
//	request->set_roomindex(roomIndex);
//	return request;
//}

void NetworkManager::getMatchEndRequest(int roomIndex) {
	auto request = initMatchEndRequest(roomIndex);
	CCLOG("match end request message:%s", request->DebugString().c_str());
	requestMessage(request, Common::getInstance()->getOS(), 
		NetworkManager::MATCH_END, Common::getInstance()->getSessionId());
}

void NetworkManager::connect() {
    try {
        mtx.lock();
        NetworkManager::_disconnected = false;
        if (!NetworkManager::getInstance()->isConnected()) {
            NetworkManager::getInstance()->connectServer(SERVER_NAME, SERVER_PORT);
        }
        
        mtx.unlock();
    }
    catch (...) {
        CCLOG("Can not connected server, try again!");
        mtx.unlock();
    }
    
}

bool NetworkManager::connectServer(const char* ip, const char* port) {
    _connected = DefaultSocket::getInstance()->connectSocket(ip, port);
    return _connected;
}

//google::protobuf::Message* NetworkManager::initPingMessage(int disconnectTime) {
//    auto request = new BINPingRequest();
//    request->set_disconecttime(disconnectTime);
//    return request;
//}

void NetworkManager::sendPing(char* ackBuf, int size) {
    // NetworkManager::getInstance()->connect();
	long long current_time = Common::getInstance()->getCurrentTime();
	int count = 0; 
	_isPing = true; 
    while (NetworkManager::isListening()) {
        Common::getInstance()->sleep(SEND_PING_DELAY - 5000);
		if (!NetworkManager::getInstance()->isConnected())
			break;
		if (!NetworkManager::getInstance()->isDisconnected()) {			
			if (Common::getInstance()->isIdle()) {
				count++;
				if (count < 4) 
					DefaultSocket::getInstance()->sendData(ackBuf, size);
			}
			else {
				count = 0; 
				DefaultSocket::getInstance()->sendData(ackBuf, size);
			}
        }
		
		CCLOG("ping duration: %lld", Common::getInstance()->getCurrentTime() - current_time);
		current_time = Common::getInstance()->getCurrentTime();
    }
	_isPing = false;
	CCLOG("send ping message");
}

void NetworkManager::getPingMessageFromServer(int disconnect_time) {
    google::protobuf::Message* request = initPingMessage(disconnect_time);
    int size;
    char* ackBuf = initData(request, Common::getInstance()->getOS(), 
        NetworkManager::PING, "", size);

	if (!_isPing) {
		std::thread *t = new std::thread(&NetworkManager::sendPing, this, ackBuf, size);
		if (t->joinable())
			t->detach();
	}
    
}

void NetworkManager::sendPingAndReceiveMessage(int disconnect_time) {
    google::protobuf::Message* request = initPingMessage(disconnect_time);
    requestMessage(request, Common::getInstance()->getOS(),
        NetworkManager::PING, Common::getInstance()->getSessionId());
}

void NetworkManager::getInitializeMessageFromServer(string cp, string
    appversion , string country, string language, string device_id, string
    device_info, string packageName) {
    google::protobuf::Message *request = initInitializeMessage(cp, appversion,
        country, language, device_id, device_info, packageName);
    requestMessage(request, Common::getInstance()->getOS(),
        NetworkManager::INITIALIZE, "");
}

//void NetworkManager::getEnterZoneMessageFromServer(int zoneId) {
//    auto request = new BINEnterZoneRequest();
//    request->set_zoneid(zoneId);
//    requestMessage(request, Common::getInstance()->getOS(),
//        NetworkManager::ENTER_ZONE, Common::getInstance()->getSessionId());
//}

void NetworkManager::getFilterRoomMessageFromServer(int zone_id, int roomType,
	int first_result, int max_result, int orderByField, bool asc) {
    google::protobuf::Message *request = initFilterRoomMessage(zone_id,
		roomType, first_result, max_result, orderByField, asc);
    requestMessage(request, Common::getInstance()->getOS(),
        NetworkManager::FILTER_ROOM, Common::getInstance()->getSessionId());
}

//google::protobuf::Message* NetworkManager::initJarRequest(int zone_id) {
//	auto request = new BINJarRequest(); 
//	request->set_zoneid(zone_id);
//	return request; 
//}

void NetworkManager::getJarRequest(int zone_id) {
	auto request = initJarRequest(zone_id);
	requestMessage(request, Common::getInstance()->getOS(), 
		NetworkManager::JAR_REQUEST, Common::getInstance()->getSessionId());
}

void NetworkManager::requestMessage(google::protobuf::Message *request, int os,
    int message_id, string session_id) {
    int size;

	if (message_id != NetworkManager::CHANGE_HOST && message_id != NetworkManager::INITIALIZE 
		&& message_id != NetworkManager::TURN && message_id != NetworkManager::INSTANT_MESSAGE
		&& message_id != NetworkManager::LOOKUP_MONEY_HISTORY && message_id != NetworkManager::FILTER_FRIEND
        && message_id != NetworkManager::FILTER_MAIL && message_id != NetworkManager::BET 
		&& message_id != NetworkManager::JAR_REQUEST ) {
        
        //=========
        auto scene = cocos2d::Director::getInstance()->getRunningScene();
        if(scene->getChildByTag(TAG_POPUP_LOADING) == nullptr){
            auto loading = LoadingManager::create();
            scene->addChild(loading);
            loading->showLoading();
        }else{
            auto loading = (LoadingManager*)scene->getChildByTag(TAG_POPUP_LOADING);
            loading->showLoading();
        }
        //=========
    }

    char* ackBuf = initData(request, os, message_id, session_id, size);
    if(NetworkManager::getInstance()->_disconnected) {
        Director::getInstance()->getScheduler()->performFunctionInCocosThread([&]{
            /*MToast* toast = MToast::create();
            toast->show("Kết nối chậm,vui lòng chờ trong giây lát...",1);
            auto visibleSize = Director::getInstance()->getVisibleSize();
            auto origin = Director::getInstance()->getVisibleOrigin();
            toast->setPosition(Vec2(origin + visibleSize/2));
            auto scene = cocos2d::Director::getInstance()->getRunningScene();
            if (scene != nullptr) {
                scene->addChild(toast,INDEX_TOAST);
            }*/
        });
    } else {
        std::thread *t = new std::thread(&NetworkManager::callNetwork, this, ackBuf, size);
        
        if (t->joinable())
            t->detach();
        delete t;
    }
}

void NetworkManager::getQuickPlayMessageFromServer(string device_id, string
    device_info) {
    google::protobuf::Message *request = initQuickPlayMessage(device_id,
        device_info);
    requestMessage(request, Common::getInstance()->getOS(),
        NetworkManager::QUICK_PLAY, "");
}

void NetworkManager::getLoginMessageFromServer(string username, string password)
{
    google::protobuf::Message *request = initLoginMessage(username, password);
    requestMessage(request, Common::getInstance()->getOS(),
        NetworkManager::LOGIN, "");
}
void NetworkManager::getLogoutMessageFromServer(bool doLogout)
{
  google::protobuf::Message *request = initLogoutMessage(doLogout);
    requestMessage(request, Common::getInstance()->getOS(),
        NetworkManager::LOGOUT, Common::getInstance()->getSessionId());
}

void NetworkManager::getRegisterMessageFromServer(string username, string
    password, string confirm_password, string full_name, string sdt) {
    google::protobuf::Message *request = initRegisterMessage(username, password,
		confirm_password, full_name, sdt);
    requestMessage(request, Common::getInstance()->getOS(),
        NetworkManager::REGISTER, "");
}

void NetworkManager::getOpenIdLoginMessageFromServer(int channelId, string
    openId, string firstname, string lastname) {
    google::protobuf::Message *request = initOpenIdLoginMessage(channelId,
        openId, firstname, lastname);
    CCLOG("open id: %s", openId.c_str());
    requestMessage(request, Common::getInstance()->getOS(),
        NetworkManager::OPEN_ID_LOGIN, "");
}
void NetworkManager::getExitRoomMessageFromServer(int roomIndex) {
    google::protobuf::Message *request = initExitRoomLoginMessage(roomIndex);
    CCLOG("exit room request message: %s", request->DebugString().c_str());
    requestMessage(request, Common::getInstance()->getOS(),
        NetworkManager::EXIT_ROOM, Common::getInstance()->getSessionId());
}
void NetworkManager::getCancelExitRoomMessageFromServer(int roomIndex) {
  google::protobuf::Message *request = initCancelExitRoomLoginMessage(roomIndex);
  requestMessage(request, Common::getInstance()->getOS(),
    NetworkManager::CANCEL_EXIT_ROOM, Common::getInstance()->getSessionId());
}

void NetworkManager::closeConnection() {
    setListening(false);
	_connected = false; 
    DefaultSocket::getInstance()->closeSocket();
    //setConnected(false);
    setDisconnected(true);
}


void NetworkManager::initConnection() {
    mtx.lock();
    NetworkManager::getInstance()->closeConnection();
    setListening(true);
    setDisconnected(false);
    NetworkManager::getInstance()->listenData();
    NetworkManager::getInstance()->getPingMessageFromServer(0);
    mtx.unlock();
}

void NetworkManager::handlerMessage(){
	_isHandleMessage = true; 
    while (NetworkManager::isListening()) {
        mtx.lock();
        while (!lstBuffer.empty()) {
            vector<char> buffer = lstBuffer.front(); 
            if (buffer.size() > 0) {
                vector<pair<google::protobuf::Message*, int>> listMessages = NetworkManager::parseFrom(buffer, (int)buffer.size());
                if (listMessages.size() > 0) {
                    for (int i = 0; i < listMessages.size(); i++) {
                        listEvent.push(listMessages[i]);
                    }
                }
            }
            lstBuffer.pop();
        }
        mtx.unlock();
		Common::getInstance()->sleep(DATA_DELAY);
        
    }
    listEvent.clear();
	_isHandleMessage = false;
}

bool NetworkManager::reconnect() {
   
    bool canReconnect = false;
    
    //========
    auto scene = cocos2d::Director::getInstance()->getRunningScene();
    if(scene->getChildByTag(TAG_POPUP_LOADING) == nullptr){
        auto loading = LoadingManager::create();
        scene->addChild(loading);
        loading->showLoading();
    }else{
        auto loading = (LoadingManager*)scene->getChildByTag(TAG_POPUP_LOADING);
        loading->showLoading();
    }
    //========
    
    if (NetworkManager::getInstance()->isConnected()) {
        NetworkManager::getInstance()->closeConnection();
    }
   // cocos2d::Director::getInstance()->getEventDispatcher()->setEnabled(false);
    NetworkManager::getInstance()->connect();
    
    if (NetworkManager::getInstance()->isConnected()) {        
        auto scene = cocos2d::Director::getInstance()->getRunningScene();
        if(scene->getChildByTag(TAG_POPUP_LOADING) != nullptr){
            scene->removeChildByTag(TAG_POPUP_LOADING);
        }
        NetworkManager::setListening(true);
        NetworkManager::getInstance()->listenData();

        if (!NetworkManager::isInitialized()) {
            NetworkManager::getInstance()->getInitializeMessageFromServer(
                Common::getInstance()->getCp(),
                Common::getInstance()->getAppVersion(),
                Common::getInstance()->getCountry(),
                Common::getInstance()->getLanguage(),
                Common::getInstance()->getDeviceId(),
                Common::getInstance()->getDeviceInfo(),
                Common::getInstance()->getPackageName()
                );
        }

        //send ping and receive message
        NetworkManager::getInstance()->sendPingAndReceiveMessage((int)disconnect_time);
        NetworkManager::getInstance()->getPingMessageFromServer(0);
        canReconnect = true; 
    } else {
        auto scene = cocos2d::Director::getInstance()->getRunningScene();
        if(scene->getChildByTag(TAG_POPUP_LOADING) != nullptr){
            scene->removeChildByTag(TAG_POPUP_LOADING);
        }
        canReconnect = false;
    }
    return canReconnect;
}

//void NetworkManager::recvMessage() {
//    vector<pair<google::protobuf::Message*, int>> listMessages;
//    firstTimeDisconnect = -1;
//	_isRecvMessage = true; 
//
//    while (NetworkManager::isListening()) {
//		vector<char> bufferRead(4096);
//		if (!NetworkManager::getInstance()->isConnected())  {
//			break;
//		}
//        int canRead = DefaultSocket::getInstance()->readData(bufferRead, 4096);
//		CCLOG("message byte: %d", canRead);
//        if (canRead > 0) {
//			_disconnected = false;
//            connectTime = Common::getInstance()->getCurrentTime();
//            bufferRead.resize(canRead);
//            lstBuffer.push(bufferRead);
//            firstTimeDisconnect = -1;
//        }
//        else {
//			_disconnected = true;
//            long long current_time = Common::getInstance()->getCurrentTime();
//            disconnect_duration =  current_time - connectTime;
//            CCLOG("disconnect duration :%lld", disconnect_duration);
//
//			if (disconnect_duration + NetworkManager::EPS <= NetworkManager::MAX_CONNECTION) {
//				
//                if(firstTimeDisconnect == -1)
//                    firstTimeDisconnect = current_time;
//                
//                if(current_time - firstTimeDisconnect >= NetworkManager::MAX_LAG_TIME) {
//
//                    if (isConnected()) {
//                        closeConnection();
//                    }
//                    //run in UI thread
//                    Director::getInstance()->getScheduler()->performFunctionInCocosThread([&]{
//                        auto scene = cocos2d::Director::getInstance()->getRunningScene();
//                        if(scene->getChildByTag(TAG_POPUP_RECONNECT) == nullptr){
//                            auto reconnect = PopupReconnect::create();
//                            scene->addChild(reconnect);
//                            reconnect->showPopup();
//                        }else{
//                            auto reconnect = (PopupReconnect*)scene->getChildByTag(TAG_POPUP_RECONNECT);
//                            reconnect->showPopup();
//                        }
//                    });
//                }
//                
//			}
//
//            if ((disconnect_duration + NetworkManager::EPS > NetworkManager::MAX_CONNECTION)) {
//				//handle packet loss, timeout
//				if (isConnected()) {
//					closeConnection();
//				}
//
//				//run in UI thread
//				Director::getInstance()->getScheduler()->performFunctionInCocosThread([&]{
//                    auto scene = cocos2d::Director::getInstance()->getRunningScene();
//                    if(scene->getChildByTag(TAG_POPUP_RECONNECT) == nullptr){
//                        auto reconnect = PopupReconnect::create();
//                        scene->addChild(reconnect);
//                        reconnect->showPopup();
//                    }else{
//                        auto reconnect = (PopupReconnect*)scene->getChildByTag(TAG_POPUP_RECONNECT);
//                        reconnect->showPopup();
//                    }
//				});
//            }
//            disconnect_time = current_time;
//        }
//		Common::getInstance()->sleep(DATA_DELAY); 
//    }
//	_isRecvMessage = false; 
//
//	CCLOG("recv message");
//}

//google::protobuf::Message* NetworkManager::initEnterRoomMessage(int room_index,
//    std::string password) {
//    auto request = new BINEnterRoomRequest();
//    request->set_roomindex(room_index);
//    request->set_password(password);
//    return request;
//}

void NetworkManager::getEnterRoomMessageFromServer(int room_index, std::string
    password) {
    google::protobuf::Message *request = initEnterRoomMessage(room_index, password);
    requestMessage(request, Common::getInstance()->getOS(),
        NetworkManager::ENTER_ROOM,
        Common::getInstance()->getSessionId());
}

//google::protobuf::Message* NetworkManager::initCreateRoomMessage(int zone_id,
//    int room_group_id, bool vip_room, int min_bet, int player_size, std::string
//    password) {
//    auto request = new BINCreateRoomRequest();
//    request->set_zoneid(zone_id);
//    request->set_roomgroupid(room_group_id);
//    request->set_viproom(vip_room);
//    request->set_minbet(min_bet);
//    request->set_playersize(player_size);
//    request->set_password(password);
//    return request;
//}

void NetworkManager::getCreateRoomMessageFromServer(int zone_id, int
    room_group_id, bool vip_room, int min_bet, int player_size, std::string
    password) {
    google::protobuf::Message *request = initCreateRoomMessage(zone_id,
        room_group_id, vip_room, min_bet, player_size, password);
    CCLOG("create room message:%s", request->DebugString().c_str());
    requestMessage(request, Common::getInstance()->getOS(),
        NetworkManager::CREATE_ROOM, Common::getInstance()->getSessionId());
}

//google::protobuf::Message* NetworkManager::initStartMatchMessage(int room_index) {
//    auto request = new BINStartMatchRequest();
//    request->set_roomindex(room_index);
//    return request;
//}
//
///* Turn Message */
//
//google::protobuf::Message* NetworkManager::initTurnMessage(int room_index,
//    vector<BINMapFieldEntry> entries) {
//    BINTurnRequest *request = new BINTurnRequest();
//    request->set_roomindex(room_index);
//    for (vector<BINMapFieldEntry>::iterator it = entries.begin(); it != entries.end(); it++) {
//        BINMapFieldEntry *map_field = request->add_args();
//        map_field->set_key(it->key());
//        map_field->set_value(it->value());
//    }
//    return request;
//}
//
//void NetworkManager::getTurnMessageFromServer(int room_index, vector<BINMapFieldEntry> entries) {
//    google::protobuf::Message* request = initTurnMessage(room_index, entries);
//    CCLOG("turn request message: %s", request->DebugString().c_str());
//    requestMessage(request, Common::getInstance()->getOS(),
//        NetworkManager::TURN, Common::getInstance()->getSessionId());
//}
//
//
//google::protobuf::Message* NetworkManager::initReadyMessage(int roomIndex, int tableIndex){
//    BINReadyToPlayRequest* request = new BINReadyToPlayRequest();
//    request->set_roomindex(roomIndex);
//    request->set_tableindex(tableIndex);
//    return request;
//}
//
//google::protobuf::Message* NetworkManager::initFilterTopUserMessage(
//    int firstResult, int maxResult, int orderByField) {
//    BINFilterTopUserRequest* request = new BINFilterTopUserRequest();
//    request->set_firstresult(firstResult);
//    request->set_maxresult(maxResult);
//    request->set_orderbyfield(orderByField);
//    return request;
//}

void NetworkManager::getReadyToPlayMessageFromServer(int roomIndex, int tableIndex){
    auto request = initReadyMessage(roomIndex, tableIndex);

    requestMessage(request, Common::getInstance()->getOS(),
        NetworkManager::READY_TO_PLAY, Common::getInstance()->getSessionId());
}

void NetworkManager::getFilterTopUserMessageFromServer(int firstResult, 
    int maxResult, int orderByField) {
    auto request = initFilterTopUserMessage(firstResult, maxResult, 
        orderByField);

    requestMessage(request, Common::getInstance()->getOS(), 
        NetworkManager::FILTER_TOP_USER, Common::getInstance()->getSessionId());
}

//google::protobuf::Message* NetworkManager::initUpdateUserInfoMessage(
//    BINEditingInfo *user_infos, int n) {
//    auto request = new BINUpdateUserInfoRequest(); 
//    for (int i = 0; i < n; i++) {
//        BINEditingInfo *edit_info = request->add_userinfos();
//        edit_info->set_infofield(user_infos[i].infofield());
//        edit_info->set_oldvalue(user_infos[i].oldvalue());
//        edit_info->set_newvalue(user_infos[i].newvalue());
//        edit_info->set_confirmvalue(user_infos[i].confirmvalue());
//    }
//
//    CCLOG("entries byte size: %d", request->ByteSize());
//    CCLOG("update user info message: %s", request->DebugString().c_str());
//    return request; 
//    
//}
//
//void NetworkManager::getUpdateUserInfoMessageFromServer(BINEditingInfo *user_infos, int n) {
//    auto request = initUpdateUserInfoMessage(user_infos, n);
//    requestMessage(request, Common::getInstance()->getOS(), NetworkManager::UPDATE_USER_INFO,
//        Common::getInstance()->getSessionId());
//}

/* End turn Message */

void NetworkManager::getStartMatchMessageFromServer(int room_index) {
    auto request = initStartMatchMessage(room_index);
    requestMessage(request, Common::getInstance()->getOS(),
        NetworkManager::START_MATCH, Common::getInstance()->getSessionId());
}

void NetworkManager::listenData() {
    CCLOG("Listen data");
	if (!_isRecvMessage) {
		std::thread *tListen = new std::thread(&NetworkManager::recvMessage, this);
		if (tListen->joinable())
			tListen->detach();
	}

    CCLOG("handle data");
	if (!_isHandleMessage) {
		std::thread *tHandlerData = new std::thread(&NetworkManager::handlerMessage, this);
		if (tHandlerData->joinable())
			tHandlerData->detach();
	}
}

NetworkManager::NetworkManager() {
    _connected = false;
    _disconnected = false; 
	_isPing = false;
	_isHandleMessage = false;
	_isRecvMessage = false;
    connectTime = Common::getInstance()->getCurrentTime(); 
}

NetworkManager::~NetworkManager() {
}

bool NetworkManager::_initialized = false;

NetworkManager *NetworkManager::_instance = 0;

bool NetworkManager::listening = true;

int NetworkManager::receiver_number = 0;

std::queue<std::vector<char>> NetworkManager::lstBuffer;
Queue<std::pair<google::protobuf::Message*, int>> NetworkManager::listEvent;

//google::protobuf::Message* NetworkManager::initBuyTurnRequest(int roomIndex, int turnNumber) {
//	auto request = new BINBuyTurnRequest();
//	request->set_roomindex(roomIndex);
//	request->set_turnnumber(turnNumber);
//	return request; 
//}

void NetworkManager::getBuyTurnRequest(int roomIndex, int turnNumber) {
	auto request = initBuyTurnRequest(roomIndex, turnNumber);
	requestMessage(request, Common::getInstance()->getOS(),
		NetworkManager::BUY_TURN, Common::getInstance()->getSessionId());
}

//google::protobuf::Message* NetworkManager::initKichPlayerOutMessage(int roomIndex, int kickedUser) {
//    auto request = new BINKickPlayerOutRequest;
//    request->set_roomindex(roomIndex);
//    request->set_kickeduserid(kickedUser);
//    return request;
//}

void NetworkManager::getKichPlayerOut(int roomIndex, int kickedUserId) {
    requestMessage(initKichPlayerOutMessage(roomIndex, kickedUserId),
                   Common::getInstance()->getOS(), NetworkManager::KICK_USER,
                   Common::getInstance()->getSessionId());
}

//google::protobuf::Message* NetworkManager::initLockRoomMessage(int roomIndex, bool isLock, std::string pass) {
//    auto request = new BINLockRoomRequest;
//    request->set_roomindex(roomIndex);
//    request->set_lock(isLock);
//    request->set_password(pass);
//    return request;
//}

void NetworkManager::getLockRoom(int roomIndex, bool isLock, std::string password) {
    requestMessage(initLockRoomMessage(roomIndex, isLock, password),
                   Common::getInstance()->getOS(), NetworkManager::LOCK_ROOM,
                   Common::getInstance()->getSessionId());
}

//google::protobuf::Message* NetworkManager::initListFriendMessage(int firstResult, int maxResult) {
//    auto request = new BINFilterFriendRequest;
//    request->set_firstresult(firstResult);
//    request->set_maxresult(maxResult);
//    return request;
//}

void NetworkManager::getListFriendFromServer(int firstResult, int maxResult) {
    requestMessage(initListFriendMessage(firstResult, maxResult),
                   Common::getInstance()->getOS(), NetworkManager::FILTER_FRIEND,
                   Common::getInstance()->getSessionId());
}

//google::protobuf::Message* NetworkManager::initAddFriendMessage(int targetUserId) {
//    auto request = new BINAddFriendRequest;
//    request->set_targetuserid(targetUserId);
//    return request;
//}
//
//void NetworkManager::getAddFriend(int targetUserId) {
//    requestMessage(initAddFriendMessage(targetUserId),
//                   Common::getInstance()->getOS(), NetworkManager::ADD_FRIEND,
//                   Common::getInstance()->getSessionId());
//}
//
//google::protobuf::Message* NetworkManager::initFilterFriendMessage(int firstResult, int maxResult) {
//    auto request = new BINFilterFriendRequest;
//    request->set_firstresult(firstResult);
//    request->set_maxresult(maxResult);
//    return request;
//}
//google::protobuf::Message* NetworkManager::initFilterAddFriendMessage(int firstResult, int maxResult) {
//  auto request = new BINFilterAddFriendRequest;
//  request->set_firstresult(firstResult);
//  request->set_maxresult(maxResult);
//  return request;
//}
//
//google::protobuf::Message* NetworkManager::initRedeemGiftCodeMessage(string giftcode){
//	auto request = new BINRedeemGiftCodeRequest();
//	request->set_giftcode(giftcode);
//	return request;
//}
//
//google::protobuf::Message* NetworkManager::initRedeemGiftCodeHistoryMessage(int firstResult, int maxResult){
//	auto request = new BINRedeemGiftCodeHistoryRequest();
//	request->set_firstresult(firstResult);
//	request->set_maxresult(maxResult);
//	return request;
//}
//
//google::protobuf::Message* NetworkManager::initAssetConfigMessage(int type){
//	auto request = new BINAssetConfigRequest();
//	request->set_type(type);
//	return request;
//}
//
//google::protobuf::Message* NetworkManager::initExchangeAssetMessage(int assetId, int amount, string userSecurityKey, string captchaSecurityKey, string captcha){
//	auto request = new BINExchangeAssetRequest();
//	request->set_assetid(assetId);
//	request->set_amount(amount);
//	if (!userSecurityKey.empty()){
//		request->set_usersecuritykey(userSecurityKey);
//	}
//	if (!captchaSecurityKey.empty()){
//		request->set_captchasecuritykey(captchaSecurityKey);
//	}
//	if (!captcha.empty()){
//		request->set_captcha(captcha);
//	}
//	
//	return request;
//}
//
//google::protobuf::Message* NetworkManager::initExchangeCashToGoldMessage(long long cashValue){
//	auto request = new BINExchangeCashToGoldRequest();
//	request->set_cashvalue(cashValue);
//	return request;
//}
//
//google::protobuf::Message* NetworkManager::initExchangeAssetHistoryRequest(int firstResult, int maxResult){
//	auto request = new BINExchangeAssetHistoryRequest();
//	request->set_firstresult(firstResult);
//	request->set_maxresult(maxResult);
//	return request;
//}
//
//google::protobuf::Message* NetworkManager::initPurchaseCashHistoryRequest(int firstResult, int maxResult){
//	auto request = new BINPurchaseCashHistoryRequest();
//	request->set_firstresult(firstResult);
//	request->set_maxresult(maxResult);
//	return request;
//}
//
//google::protobuf::Message* NetworkManager::initExchangeGoldHistoryRequest(int firstResult, int maxResult){
//	auto request = new BINExchangeGoldHistoryRequest();
//	request->set_firstresult(firstResult);
//	request->set_maxresult(maxResult);
//	return request;
//}
//
//google::protobuf::Message* NetworkManager::initSmsConfigRequest(int type){
//	auto request = new BINSmsConfigRequest();
//	request->set_type(type);
//	return request;
//}
//
//google::protobuf::Message* NetworkManager::initUserVerifyConfigRequest(int type){
//	auto request = new BINUserVerifyConfigRequest();
//	request->set_type(type);
//	return request;
//}
//
//google::protobuf::Message* NetworkManager::initUserVerifyRequest(string otp){
//	auto request = new BINUserVerifyRequest();
//	request->set_otp(otp);
//	return request;
//}
//
//google::protobuf::Message* NetworkManager::initCashTransferConfigRequest(int type){
//	auto request = new BINCashTransferConfigRequest();
//	request->set_type(type);
//	return request;
//}
//
//google::protobuf::Message* NetworkManager::initCashTransferRequest(long long cashValue, long long targetUserId, string userSecurityKey, string captchaSecurityKey, string captcha){
//	auto request = new BINCashTransferRequest();
//	request->set_cashvalue(cashValue);
//	request->set_targetuserid(targetUserId);
//	if (!userSecurityKey.empty()){
//		request->set_usersecuritykey(userSecurityKey);
//	}
//	if (!captchaSecurityKey.empty()){
//		request->set_captchasecuritykey(captchaSecurityKey);
//	}
//	if (!captcha.empty()){
//		request->set_captcha(captcha);
//	}
//	return request;
//}
//
//google::protobuf::Message* NetworkManager::initFindUserByIdRequest(long long targetUserId){
//	auto request = new BINFindUserByIdRequest();
//	request->set_targetuserid(targetUserId);
//	return request;
//}
//
//google::protobuf::Message* NetworkManager::initExchangeC2gConfigRequest(int type){
//	auto request = new BINExchangeC2GConfigRequest();
//	request->set_type(type);
//	return request;
//}
//
//google::protobuf::Message* NetworkManager::initCardConfigRequest(int type){
//	auto request = new BINCardConfigRequest();
//	request->set_type(type);
//	return request;
//}

void NetworkManager::getCardConfigRequest(int type){
	requestMessage(initCardConfigRequest(type),
		Common::getInstance()->getOS(), NetworkManager::CARD_CONFIG, Common::getInstance()->getSessionId());
}

//exchangeC2GConfigRequest
void NetworkManager::getExchangeC2gConfigRequest(int type){
	requestMessage(initExchangeC2gConfigRequest(type),
		Common::getInstance()->getOS(), NetworkManager::EXCHANGE_C2G_CONFIG, Common::getInstance()->getSessionId());
}

//find user by id
void NetworkManager::getFindUserByIdRequest(long long targetUserId){
	requestMessage(initFindUserByIdRequest(targetUserId),
		Common::getInstance()->getOS(), NetworkManager::FIND_USER_BY_ID, Common::getInstance()->getSessionId());
}

//cash transfer
void NetworkManager::getCashTransferRequest(long long cashValue, long long targetUserId, string userSecurityKey, string captchaSecurityKey, string captcha){
	requestMessage(initCashTransferRequest(cashValue, targetUserId, userSecurityKey, captchaSecurityKey, captcha), 
		Common::getInstance()->getOS(), NetworkManager::CASH_TRANSFER, Common::getInstance()->getSessionId());
}

//cash transfer config
void NetworkManager::getCashTransferConfigRequest(int type){
	requestMessage(initCashTransferConfigRequest(type), Common::getInstance()->getOS(), NetworkManager::CASH_TRANSFER_CONFIG,
		Common::getInstance()->getSessionId());
}

//verify config request
void NetworkManager::getUserVerifyConfigRequest(int type){
	requestMessage(initUserVerifyConfigRequest(type), Common::getInstance()->getOS(), NetworkManager::USER_VERIFY_CONFIG,
		Common::getInstance()->getSessionId());
}

//verify request
void NetworkManager::getUserVerifyRequest(string otp){
	requestMessage(initUserVerifyRequest(otp), Common::getInstance()->getOS(), NetworkManager::USER_VERIFY,
		Common::getInstance()->getSessionId());
}

void NetworkManager::getSmsConfigRequest(int type){
	requestMessage(initSmsConfigRequest(type), Common::getInstance()->getOS(), NetworkManager::SMS_CONFIG,
		Common::getInstance()->getSessionId());
}

void NetworkManager::getExchangeGoldHistoryRequest(int firstResult, int maxResult){
	requestMessage(initExchangeGoldHistoryRequest(firstResult, maxResult),
		Common::getInstance()->getOS(), NetworkManager::EXCHANGE_GOLD_HISTORY,
		Common::getInstance()->getSessionId());
}

void NetworkManager::getPurchaseCashHistoryRequest(int firstResult, int maxResult){
	requestMessage(initPurchaseCashHistoryRequest(firstResult, maxResult),
		Common::getInstance()->getOS(), NetworkManager::PURCHASE_CASH_HISTORY,
		Common::getInstance()->getSessionId());
}

void NetworkManager::getExchangeAssetHistoryRequest(int firstResult, int maxResult){
	requestMessage(initExchangeAssetHistoryRequest(firstResult, maxResult),
		Common::getInstance()->getOS(), NetworkManager::EXCHANGE_ASSET_HISTORY,
		Common::getInstance()->getSessionId());
}

void NetworkManager::getExchangeCashToGold(long long cashValue){
	requestMessage(initExchangeCashToGoldMessage(cashValue),
		Common::getInstance()->getOS(), NetworkManager::EXCHANGE_CASH_TO_GOLD,
		Common::getInstance()->getSessionId());
}

void NetworkManager::getAssetConfigFromServer(int type){
	requestMessage(initAssetConfigMessage(type),
		Common::getInstance()->getOS(), NetworkManager::ASSET_CONFIG,
		Common::getInstance()->getSessionId());
}

void NetworkManager::getExchangeAssetFromServer(int assetId, int amount, string userSecurityKey, string captchaSecurityKey, string captcha){
	requestMessage(initExchangeAssetMessage(assetId, amount, userSecurityKey, captchaSecurityKey, captcha),
		Common::getInstance()->getOS(), NetworkManager::EXCHANGE_ASSET,
		Common::getInstance()->getSessionId());
}

void NetworkManager::getRedeemGiftCodeFromServer(string giftcode){
	requestMessage(initRedeemGiftCodeMessage(giftcode),
		Common::getInstance()->getOS(), NetworkManager::REDEEM_GIFT_CODE,
		Common::getInstance()->getSessionId());
}

void NetworkManager::getRedeemGiftCodeHistoryFromServer(int firstResult, int maxResult){
	requestMessage(initRedeemGiftCodeHistoryMessage(firstResult, maxResult),
		Common::getInstance()->getOS(), NetworkManager::REDEEM_GIFT_CODE_HISTORY,
		Common::getInstance()->getSessionId());
}

void NetworkManager::getFilterFriendFromServer(int firstResult, int maxResult) {
    requestMessage(initFilterFriendMessage(firstResult, maxResult),
                   Common::getInstance()->getOS(), NetworkManager::FILTER_FRIEND,
                   Common::getInstance()->getSessionId());
}
void NetworkManager::getFilterAddFriendFromServer(int firstResult, int maxResult) {
  auto request = initFilterAddFriendMessage(firstResult, maxResult);
  CCLOG("filter add firend request: %s", request->DebugString().c_str());
  requestMessage(request, Common::getInstance()->getOS(), NetworkManager::FILTER_ADD_FRIEND,
    Common::getInstance()->getSessionId());
}
//void NetworkManager::getApproveAddFriendFromServer(int userId, bool accepted) {
//    auto request = new BINApproveAddFriendRequest;
//    request->set_senderuserid(userId);
//    request->set_accepted(accepted);
//    requestMessage(request, Common::getInstance()->getOS(),
//                   NetworkManager::APPROVE_ADD_FRIEND,
//                   Common::getInstance()->getSessionId());
//}
//
//void NetworkManager::getFindUserFromServer(std::string userNameQuery) {
//    auto request = new BINFindUserRequest;
//    request->set_usernamequery(userNameQuery);
//    requestMessage(request, Common::getInstance()->getOS(),
//                   NetworkManager::FIND_USER,
//                   Common::getInstance()->getSessionId());
//}
//
//void NetworkManager::getViewUserInfoFromServer(int targetUserId) {
//    auto request = new BINViewUserInfoRequest;
//    request->set_targetuserid(targetUserId);
//    requestMessage(request, Common::getInstance()->getOS(),
//                   NetworkManager::VIEW_USER_INFO,
//                   Common::getInstance()->getSessionId());
//}
//
//void NetworkManager::getRemoveFriendFromServer(int targetUserId) {
//    auto request = new BINRemoveFriendRequest;
//    request->set_targetuserid(targetUserId);
//    requestMessage(request, Common::getInstance()->getOS(),
//                   NetworkManager::REMOVE_FRIEND,
//                   Common::getInstance()->getSessionId());
//}
//
//void NetworkManager::getChangeRuleFromServer(int roomIndex, vector<BINMapFieldEntry> entries) {
//    auto request = new BINChangeRuleRequest;
//    request->set_roomindex(roomIndex);
//
//	for (vector<BINMapFieldEntry>::iterator it = entries.begin(); it != entries.end(); it++) {
//		BINMapFieldEntry *map_field = request->add_args();
//		map_field->set_key(it->key());
//		map_field->set_value(it->value());
//	}
//    requestMessage(request, Common::getInstance()->getOS(),
//                   NetworkManager::CHANGE_RULE, Common::getInstance()->getSessionId());
//}
//
//void NetworkManager::getSendTextEmoticonFromServer(int textEmoticonId, int targetUserId) {
//    auto request = new BINSendTextEmoticonRequest;
//    request->set_textemoticonid(textEmoticonId);
//    request->set_targetuserid(targetUserId);
//    requestMessage(request, Common::getInstance()->getOS(),
//                   NetworkManager::SEND_TEXT_EMOTICON,
//                   Common::getInstance()->getSessionId());
//}
//
//void NetworkManager::sendMessageToServer(int scope, int emoticonId, std::string message,
//                                         std::string receiverUserName,
//                                         int receiverUserId) {
//    if (scope > 0 && scope < 4) {
//        auto request = new BINInstantMessageRequest;
//        request->set_scope(scope);
//		request->set_textemoticonid(emoticonId);
//        request->set_instantmessage(message);
//        if (scope == 3) {
//            request->set_receiverusername(receiverUserName);
//            request->set_receiveruserid(receiverUserId);
//        }
//        requestMessage(request, Common::getInstance()->getOS(),
//                       NetworkManager::INSTANT_MESSAGE,
//                       Common::getInstance()->getSessionId());
//    } else {
//        CCLOG("check lai scope di em");
//    }
//}
//
//void NetworkManager::sendMessageToServer(int scope, int emoticonId, std::string message) {
//	sendMessageToServer(scope, emoticonId, message, "hehe", 001);
//}
//
//void NetworkManager::getEnterRoomGroupFromServer(int roomGroupId, bool vipRoom) {
//    auto request = new BINEnterRoomGroupRequest;
//    request->set_roomgroupid(roomGroupId);
//    request->set_viproom(vipRoom);
//    requestMessage(request, Common::getInstance()->getOS(), NetworkManager::ENTER_GROUP_ROOM,
//                   Common::getInstance()->getSessionId());
//}
//
//void NetworkManager::getUpdateUserSettingFromServer(bool autoReady, bool autoDenyInvitation) {
//    auto request = new BINUpdateUserSettingRequest;
//    request->set_autoready(autoReady);
//    request->set_autodenyinvitation(autoDenyInvitation);
//    requestMessage(request, Common::getInstance()->getOS(), NetworkManager::UPDATE_USER_SETTING,
//                   Common::getInstance()->getSessionId());
//}
//
//void NetworkManager::getFilterMailFromServer(int firstResult, int maxResult, long lastRequestTime){
//    auto request = new BINFilterMailRequest();
//    request->set_firstresult(firstResult);
//    request->set_maxresult(maxResult);
//    request->set_lastrequesttime(lastRequestTime);
//    requestMessage(request, Common::getInstance()->getOS(), NetworkManager::FILTER_MAIL,
//        Common::getInstance()->getSessionId());
//}
//
//void NetworkManager::sendMail(vector<char*> lst_recipientuser, std::string title, std::string body, long parent_id){
//    auto request = new BINSendMailRequest();
//
//    for (int i = 0; i < lst_recipientuser.size(); i++){
//        char* user_name = lst_recipientuser[i];
//        request->add_recipientusernames(user_name);
//    }
//
//    request->set_title(title);
//    request->set_body(body);
//    request->set_parentid(parent_id);
//    requestMessage(request, Common::getInstance()->getOS(), NetworkManager::SEND_MAIL,
//        Common::getInstance()->getSessionId());
//}
//
//void NetworkManager::deleteMail(vector<long> selectedMailIds){
//	if (!selectedMailIds.empty()){
//		auto request = new BINDeleteMailRequest();
//		for (int i = 0; i < selectedMailIds.size(); i++){
//			request->add_selectedmailids(selectedMailIds[i]);
//		}
//		requestMessage(request, Common::getInstance()->getOS(), NetworkManager::DELETE_MAIL,
//			Common::getInstance()->getSessionId());
//	}
//}
//
//void NetworkManager::readMail(long readedMailId, bool getContent){
//    auto request = new BINReadedMailRequest();
//    request->set_readedmailid(readedMailId);
//    request->set_getcontent(getContent);
//    requestMessage(request, Common::getInstance()->getOS(), NetworkManager::READED_MAIL,
//        Common::getInstance()->getSessionId());
//}
//
//void NetworkManager::claimAttachMail(long mailId){
//    auto request = new BINClaimAttachItemRequest();
//    request->set_mailid(mailId);
//    requestMessage(request, Common::getInstance()->getOS(), NetworkManager::CLAIM_ATTACH_ITEM,
//        Common::getInstance()->getSessionId());
//}
//
//void NetworkManager::changeAutoReady(bool autoReady) {
//    getUpdateUserSettingFromServer(autoReady, Common::getInstance()->isAutoDenyInvitation());
//}
//
//void NetworkManager::changeAutoDenyInvitation(bool autoDenyInvitation) {
//    getUpdateUserSettingFromServer(Common::getInstance()->isAutoRead(), autoDenyInvitation);
//}
//
///*Captcha message*/
//
//google::protobuf::Message* NetworkManager::initCaptchaMessage(bool refresh) {
//    BINCaptchaRequest *request = new BINCaptchaRequest();
//    request->set_refresh(refresh);
//    return request;
//}
//
//void NetworkManager::getCaptchaMessageFromServer(bool refresh) {
//    auto request = initCaptchaMessage(refresh);
//    requestMessage(request, Common::getInstance()->getOS(),
//        NetworkManager::CAPTCHA, Common::getInstance()->getSessionId());
//}
///*End captcha*/
//
///*purchase money*/
//
//google::protobuf::Message* NetworkManager::initPurchaseMoneyMessage(string provider,
//    string cardSerial, string cardPin, string securityKey, string captcha,
//    bool toCash) {
//    auto request = new BINPurchaseMoneyRequest();
//    request->set_provider(provider);
//    request->set_cardserial(cardSerial);
//    request->set_cardpin(cardPin);
//    request->set_securitykey(securityKey);
//    request->set_captcha(captcha);
//    request->set_tocash(toCash);
//    return request;
//}
//
//google::protobuf::Message* NetworkManager::initChangeHostMessage(int roomIndex, long long userId, bool isAccept, int requestType){
//	auto request = new BINChangeHostRequest();
//	request->set_roomindex(roomIndex);
//	request->set_userid(userId);
//	request->set_isaccept(isAccept);
//	request->set_requesttype(requestType);
//	return request;
//}
//
//google::protobuf::Message* NetworkManager::initLookupUserToInviteMessage(int room_index, int max_result){
//	auto request = new BINLookUpUserToInviteRequest();
//	request->set_roomindex(room_index);
//	request->set_maxresult(max_result);
//	return request;
//}
//
//google::protobuf::Message* NetworkManager::initInviteToRoomMessage(int room_index, vector<long> target_user_ids){
//	auto request = new BINInviteToRoomRequest();
//	request->set_roomindex(room_index);
//
//	for (int i = 0; i < target_user_ids.size(); i++){
//		request->add_targetuserids(target_user_ids[i]);
//	}
//	
//	return request;
//}
//
//google::protobuf::Message* NetworkManager::initCancelInviteMessage(int room_index, long long target_user_id){
//	auto request = new BINCancelInvitationRequest();
//	request->set_roomindex(room_index);
//	request->set_targetuserid(target_user_id);
//	return request;
//}
//
//google::protobuf::Message* NetworkManager::initRelyInviteMessage(int zone_id, int room_index, bool accept){
//	auto request = new BINRelyInvitationRequest();
//	request->set_zoneid(zone_id);
//	request->set_roomindex(room_index);
//	request->set_accept(accept);
//	return request;
//}

void NetworkManager::getLookupUserToInviteFromServer(int room_index, int max_result){
	auto request = initLookupUserToInviteMessage(room_index, max_result);
	requestMessage(request, Common::getInstance()->getOS(),
		NetworkManager::LOOKUP_USER_TO_INVITE, Common::getInstance()->getSessionId());
}

void NetworkManager::getInviteToRoomFromServer(int room_index, vector<long> target_user_ids){
	auto request = initInviteToRoomMessage(room_index, target_user_ids);
	requestMessage(request, Common::getInstance()->getOS(),
		NetworkManager::INVITE_TO_ROOM, Common::getInstance()->getSessionId());
}

void NetworkManager::getCancelInviteFromServer(int room_index, long long target_user_id){
	auto request = initCancelInviteMessage(room_index, target_user_id);
	requestMessage(request, Common::getInstance()->getOS(),
		NetworkManager::CANCEL_INVITE, Common::getInstance()->getSessionId());
}

void NetworkManager::getRelyInviteFromServer(int zone_id, int room_index, bool accept){
	auto request = initRelyInviteMessage(zone_id, room_index, accept);
	requestMessage(request, Common::getInstance()->getOS(),
		NetworkManager::RELY_INVITE, Common::getInstance()->getSessionId());
}

void NetworkManager::getPurchaseMoneyMessageFromServer(string provider,
    string cardSerial, string cardPin, string securityKey, string captcha,
    bool toCash) {
    auto request = initPurchaseMoneyMessage(provider, cardSerial, cardPin,
        securityKey, captcha, toCash);
    requestMessage(request, Common::getInstance()->getOS(),
        NetworkManager::PURCHASE_MONEY, Common::getInstance()->getSessionId());
}
/*end purchase money*/

/*begin kill room*/

//google::protobuf::Message* NetworkManager::initKillRoomMessage(int zoneid, int roomIndex) {
//    auto request = new BINKillRoomRequest();
//    request->set_zoneid(zoneid);
//    request->set_roomindex(roomIndex);
//    return request;
//}
//
//void NetworkManager::getKillRoomMessageFromServer(int zoneId, int roomIndex) {
//    auto request = initKillRoomMessage(zoneId, roomIndex);
//    requestMessage(request, Common::getInstance()->getOS(),
//        NetworkManager::KILL_ROOM, Common::getInstance()->getSessionId());
//}
///*end kill room*/
///*begin exit zone */
//google::protobuf::Message* NetworkManager::initExitZoneMessage(int zoneId) {
//    auto request = new BINExitZoneRequest(); 
//    request->set_zoneid(zoneId);
//    return request; 
//}
//
//void NetworkManager::getExitZoneMessageFromServer(int zoneId) {
//    auto request = initExitZoneMessage(zoneId);
//    requestMessage(request, Common::getInstance()->getOS(), 
//        NetworkManager::EXIT_ZONE, Common::getInstance()->getSessionId());
//}
///*end exit zone */
//
//google::protobuf::Message* NetworkManager::initBetMessage(int roomIndex, int betType, int
//    betMoney, BINPrivateBet* privatebets, int size) {
//    auto request = new BINBetRequest(); 
//    request->set_roomindex(roomIndex);
//    request->set_bettype(betType);
//    request->set_betmoney(betMoney);
//    
//    for (int i = 0; i < size; i++) {
//        auto private_bet = request->add_privatebets(); 
//        private_bet->set_betmoney(privatebets[i].betmoney());
//        private_bet->set_targetuserid(privatebets[i].targetuserid());
//    }
//    CCLOG("bet request: %s", request->DebugString().c_str());
//    return request; 
//}
//
///*bet message*/
////1- đặt cược bàn, 2- góp gà, 3- gui yeu cau solo giữa 2 người (ví dụ đánh biên trong 3 cây), 4 - dong y yeu cau solo
//
//void NetworkManager::getBetByTable(int roomIndex, int betMoney) {
//    auto request = initBetMessage(roomIndex, 1, betMoney, NULL, 0);
//    requestMessage(request, Common::getInstance()->getOS(), NetworkManager::BET,
//        Common::getInstance()->getSessionId());
//}
//
//void NetworkManager::getBetByUnion(int roomIndex, int betMoney) {
//    auto request = initBetMessage(roomIndex, 2, betMoney, NULL, 0);
//    requestMessage(request, Common::getInstance()->getOS(), NetworkManager::BET,
//        Common::getInstance()->getSessionId());
//}
//
//void NetworkManager::getBetByBarier(int roomIndex, std::vector<std::pair<int, int>> lstBets) {
//    BINPrivateBet *privatebets = new BINPrivateBet[lstBets.size()];
//    for (int i = 0; i < lstBets.size(); i++) {
//        //first = targetuserid, second = betmoney
//        privatebets[i].set_betmoney(lstBets[i].second);
//        privatebets[i].set_targetuserid(lstBets[i].first);
//    }
//    auto request = initBetMessage(roomIndex, 3, 0, privatebets, lstBets.size());
//    requestMessage(request, Common::getInstance()->getOS(), NetworkManager::BET,
//        Common::getInstance()->getSessionId());
//}
//
//void NetworkManager::getConfirmBetByBarier(int roomIndex, std::vector<std::pair<int, int>> lstBet){
//	BINPrivateBet *privatebets = new BINPrivateBet[lstBet.size()];
//	for (int i = 0; i < lstBet.size(); i++) {
//		//first = targetuserid, second = betmoney
//		privatebets[i].set_betmoney(lstBet[i].second);
//		privatebets[i].set_targetuserid(lstBet[i].first);
//	}
//	auto request = initBetMessage(roomIndex, 4, 0, privatebets, lstBet.size());
//	requestMessage(request, Common::getInstance()->getOS(), NetworkManager::BET,
//		Common::getInstance()->getSessionId());
//}

void NetworkManager::getConfirmChangeHostRequest(int roomIndex, long long userId, bool isAccept, int requestType){
	auto request = initChangeHostMessage(roomIndex, userId, isAccept, requestType);
	requestMessage(request, Common::getInstance()->getOS(), NetworkManager::CHANGE_HOST,
		Common::getInstance()->getSessionId());
}

//xóc đĩa

//void NetworkManager::getBetXocDia(int roomIndex, int betMoney, int betType) {
//    auto request = initBetMessage(roomIndex, betType, betMoney, NULL, 0);
//    requestMessage(request, Common::getInstance()->getOS(), NetworkManager::BET,
//                   Common::getInstance()->getSessionId());
//}

//void NetworkManager::getExtraBetRequest(int roomIndex, int action) {
//    auto request = new BINExtraBetRequest();
//    request->set_roomindex(roomIndex);
//    request->set_action(action);
//    requestMessage(request, Common::getInstance()->getOS(), NetworkManager::EXTRA_BET,
//                   Common::getInstance()->getSessionId());
//}
//
///*end message*/
//
//void NetworkManager::getHostRegistration(int roomIndex, bool cancle) {
//    auto request = new BINHostRegistrationRequest();
//    request->set_roomindex(roomIndex);
//    if (cancle) {
//        request->set_cancelregistration(cancle);
//    }
//    requestMessage(request, Common::getInstance()->getOS(), NetworkManager::HOST_REGISTRATION,
//                   Common::getInstance()->getSessionId());
//}
//
//void NetworkManager::getResetPassFromServer(string usernam, string OTP, string password) {
//    auto request = new BINResetPasswordRequest();
//    request->set_otp(OTP);
//    request->set_password(password);
//    request->set_username(usernam);
//    requestMessage(request, Common::getInstance()->getOS(), NetworkManager::RESET_PASSWORD,
//                   Common::getInstance()->getSessionId());
//}
//
//void NetworkManager::getCloseConnection(int closeTime) {
//    auto request = new BINCloseConnectionRequest();
//    request->set_closetime(closeTime);
//    requestMessage(request, Common::getInstance()->getOS(), NetworkManager::CLOSE_CONNECTION,
//                   Common::getInstance()->getSessionId());
//	CCLOG("NetworkManager::getCloseConnection");
//}
