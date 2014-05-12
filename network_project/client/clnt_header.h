#ifndef _CLNT_HEADER_
#define _CLNT_HEADER_

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>

#include "low_Level_Header.h"

#define BUFSIZE 1024
#define OK		"Kero"


typedef struct _clntInfo {
	struct _clntInfo* nextLink;
	char nick[20];
	char ip[20];
	char port[10];
} clntInfo;

typedef enum{
	OK_CONNECTION = 200,
	OK_LIST		= 201,
	OK_DISCONNECTION = 204,
	OK_MSG = 300,
	END = 0
} RESPONSE;

typedef enum {
	IDLE = 0,
	CONNECTED
} STATE;

typedef enum {
    MESSAGE = 0,
    INVITE, // /invite ip host
    COMMAND, // /cmd
} INPUTTYPE;

typedef enum {
    UNDEFINED = 0,
    JOIN, // connect to server
    LEAVE, // disconnect from server
    QUIT, // exit program
    LIST
} CMDTYPE;

// socket variables
extern int sock_Listen, sock_Send, sock_Recv;
extern struct sockaddr_in sock_Listen_addr, sock_Send_addr, sock_Recv_addr;
extern struct sockaddr_in peer_addr;

// select variables
extern fd_set reads, temp;
extern int fd_max;

// character variables
extern char message[BUFSIZE];
extern char buf[BUFSIZE];
extern char* myPortNum;
extern char command[10], ip[20], port[10], nick[20];

// invited variables
extern char invited_Ip[20], invited_Port[10];

// peer variables
extern clntInfo* peerList;
extern int mirror_Flag;
extern char peer_Nick[20];
extern char peer_Ip[20];
extern char peer_Port[10];

// state variables
extern STATE state;
extern int quit_Flag;

// prompt
void idle_Prompt();
void connected_Prompt();

// group of operation
void initClnt();
void init_varaibles();
inline void copy_n_select();
void analyze_Input(STATE tmp_state);
RESPONSE analyze_Response();
void printWrongCommand(STATE tmp_state);
void printNoConnection();
void print_Already_Connection();
void exclude_Sock_Input_n_Message();
void include_Sock_Input_n_Message();
void disable_Sock_Send();
char* domainService(char* __ip);

void tryToConnect(char* _var_Ip, char* _var_Port);
void processConnectionRequest();
void quitProgram();

// list management
void recvList();
void printList();
void removeList(clntInfo* obj);
void msgtok(char* first, char* second, char* third);


// request management & state management
STATE handleEvent_Idle();
STATE handleEvent_Connected();
void request_Message_Connect_2_Server();
void request_Message_Disconnect_Connection();
void request_Message_List();
STATE process_Response_Msg_Connection();
STATE process_Response_Msg_List();
STATE process_Response_Msg_Disconnection();
void process_MsgLen_Is_Zero();
STATE process_Chatting_Msg();

// Message & Invite
void sendMsg();
void popPeer();
void send_Msg_2_peer();
void handle_Inviting();

INPUTTYPE detInputType();
CMDTYPE detCommandType();

#endif




