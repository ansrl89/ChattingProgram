#include "low_Level_Header.h"



void error_handling(char *message)
{
    fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

char* itoa(int val, int base) {
    static char buffer[32] = {0, };
	int i = 30;

	for(; val && i ; --i, val /= base)
		buffer[i] = "0123456789abcdef"[val % base];

	return &buffer[i+1];
}

void _Input_(char str[])
{
    char tmp[1024];
    fgets(tmp, sizeof(tmp), stdin);
    tmp[strlen(tmp)-1] = '\0';  // 마지막 \n 제거
    strcpy(str, tmp);
}

