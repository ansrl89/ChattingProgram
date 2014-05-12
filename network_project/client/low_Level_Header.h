#ifndef _low_Level_Header_
#define _low_Level_Header_

#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE	1
#define FALSE	0

// low level function
void error_handling(char *message);
char* itoa(int val, int base);

void _Input_(char str[]);




#endif




