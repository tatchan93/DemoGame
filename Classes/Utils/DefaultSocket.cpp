#include "DefaultSocket.h"
#include "cocos2d.h"
#include "NetworkManager.h"

#if WIN32
	#include <WinSock2.h>
	#include <WS2tcpip.h>
	#pragma comment(lib, "WS2_32.LIB")
#else
	#include <sys/types.h>
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <arpa/inet.h>
	#include <netdb.h> 
	#include <unistd.h>
	#include <fcntl.h>
	#include <sys/select.h>
	#include <sys/time.h>
#endif
#define TIME_OUT 30



USING_NS_CC;

void error(char *msg) {
    perror(msg);
    exit(0);
}

DefaultSocket::DefaultSocket()
{
}

DefaultSocket::~DefaultSocket()
{
}
//khoi tao cho win32
#if WIN32
bool DefaultSocket::initWinSock2_0()
{
	WSADATA wsaData ;
	WORD wVersion = MAKEWORD( 2, 0 ) ;
	if ( ! WSAStartup( wVersion, &wsaData ) )
		return true ;
	return false ;
}
#endif
//Mo ket noi
bool DefaultSocket::connectSocket(const char* serverIP, const char* serverPort)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	if(!initWinSock2_0())
		return false;
#endif
//        hClientSocket = socket(AF_INET, SOCK_STREAM, 0);
//
//        if ( hClientSocket < 0 )
//        {
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
//            WSACleanup( ) ;
//#endif
//            return false ;
//        }
    
    struct addrinfo hints, *servinfo, *p;
    
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	hClientSocket = socket(AF_INET, SOCK_STREAM, 0);

	if (hClientSocket < 0) {
		WSACleanup();
		return false;
	}

	struct hostent *server = gethostbyname(serverIP);
	if (server == NULL) {
		return false;
	}

	struct sockaddr_in serverAddr ;
	serverAddr . sin_family = AF_INET ;     // The address family. MUST be AF_INET
	serverAddr . sin_addr . s_addr = inet_addr(serverIP);
	serverAddr . sin_port = htons(Common::getInstance()->convertStringToInt(std::string(serverPort)));

	if (connect(hClientSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0)
	{
		CCLOG("Unable to connect to server ");

		closeSocket();
		return false;
	}

	peerSocket = hClientSocket;
#else
	int rv;
	if ((rv = getaddrinfo(serverIP, serverPort, &hints, &servinfo) != 0)) {
		return false;
	}

	for (p = servinfo; p != NULL; p = p->ai_next) {
		if ((hClientSocket = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
			continue;
		}

		if (connect(hClientSocket, p->ai_addr, p->ai_addrlen) == -1) {
			closeSocket();
			continue;
		}
		peerSocket = hClientSocket;
		CCLOG("%d", peerSocket);
		break;
	}

	if (p == NULL) {
		CCLOG("failed to connect");
		return false;
	}
#endif
        
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
        // Cleanup the environm	ent initialized by WSAStartup()
        DWORD timeout = TIME_OUT * 1000;
        
        optval = 1;
        optlen = sizeof(optval);
        
        if (setsockopt(peerSocket, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, sizeof(timeout)) < 0) {
            CCLOG("Receiving timeout Error");
        }
#else
        struct timeval timeout;
        timeout.tv_sec = TIME_OUT;
        timeout.tv_usec = 0;
        
        optval = 1;
        optlen = sizeof(optval);
        
        if (setsockopt(peerSocket, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, sizeof(timeout)) < 0) {
            CCLOG("Receiving timeout Error");
        }
#endif
    return true;
}
//Gui du lieu
int DefaultSocket::sendData(const char* data, int nLength)
{
    return send(peerSocket, data, nLength, 0);
}

int	DefaultSocket::readData(vector <char> &vectorBuffer, int len)
{
	/*FD_ZERO(&fds);
	FD_SET(peerSocket, &fds);

	select(peerSocket + 1, &fds, NULL, NULL, &tv);

	if (FD_ISSET(peerSocket, &fds)) {
		
	}*/

	char *test = reinterpret_cast<char*>(&vectorBuffer[0]);
	//memset(test, 0, sizeof(test));

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	return recv(peerSocket, test, len, 0);
#else
	return recv(peerSocket, test, len, 0);

	//return read(peerSocket,vectorBuffer.data(), len);
#endif
	
}

void DefaultSocket::closeSocket(){
	// CCLog("connectSocket---hClientSocket:%d", hClientSocket);
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		shutdown(hClientSocket, 2);
		closesocket(hClientSocket);
		WSACleanup();
	#else
		shutdown(hClientSocket,2);
		close(hClientSocket);
	#endif
}

DefaultSocket *DefaultSocket::_instance = 0;

DefaultSocket *DefaultSocket::getInstance() {
	if (!_instance)
		_instance = new DefaultSocket(); 
	return _instance;
}
