#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<unistd.h> 
#include <errno.h>
#include <sys/utsname.h>
#include <limits.h>
#include<signal.h> 
#include<wait.h> 
#include <dirent.h> 
#include <sys/stat.h>
#include <sys/types.h>
#include<time.h>
#include<pwd.h>
#include <grp.h>
#include<fcntl.h> 
#include<sys/wait.h> 
#include<readline/readline.h>
#include<readline/history.h>
struct background_process
{
	int pid_no;
	char process_name[300];
	int fl;  //flag to ccheck if the process id finished or not 
	int status; // to check for stopped or running
};

struct background_process bg[50];

char home[500]; //for finding new home path
char me[500];  //for prompt function
char store[100][200];  //after using strtok,it will store all commands
int ind;  //index variable

char mat[20][200];
int times; //for finding history
char his_data[20][100];
int foreground_id;
char foreground_name[300];

char out[300];
