_host.exe : host_main.o host_func.o low_Level_Func.o
	gcc -o _host host_main.c host_func.c low_Level_Func.c
host_main.o : host_main.c
	gcc -c host_main.c
host_func.o : host_main.c
	gcc -c host_main.c
low_Level_Func.o : low_Level_Func.c
	gcc -c low_Level_Func.c
	

