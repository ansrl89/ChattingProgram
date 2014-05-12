#include "clnt_header.h"

// socket variables
int sock_Listen = -1, sock_Send = -1, sock_Recv = -1;
struct sockaddr_in sock_Listen_addr, sock_Send_addr, sock_Recv_addr;
struct sockaddr_in peer_addr;

// select variables
fd_set reads, temp;
int fd_max;

// character variables
char message[BUFSIZE];
char buf[BUFSIZE];
char* myPortNum;

char command[10], ip[20], port[10], nick[20];

// invited variables
char invited_Ip[20], invited_Port[10];

// peer variables
clntInfo* peerList;
int mirror_Flag = FALSE;
char peer_Nick[20];
char peer_Ip[20];
char peer_Port[10];

// state variables
STATE state = IDLE;
int quit_Flag = FALSE;



int main(int argc, char* argv[])
{
    myPortNum = argv[1];
	initClnt();

	idle_Prompt();
	while(1)
	{
		init_varaibles();
		copy_n_select();

		if (state == IDLE) {
			state = handleEvent_Idle();
		} else if (state == CONNECTED) {
			state = handleEvent_Connected();
		}
	}

	return 0;
}
