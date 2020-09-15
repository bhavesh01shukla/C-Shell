#include "main.h"
#include "prompt_func.h"
#include "pwd_func.h"
#include "find_func.h"
#include "echo_func.h"
#include "cd_func.h"
#include "ls_func.h"
#include "pinfo_func.h"
#include "location_func.h"
#include "syscmnds_func.h"


void relative_path_func(char arr[])
{
	//function to convert a given path of file or directory
	// to a relative path in terms of new home
	char str[300];

	int len=strlen(home);
	int len2=strlen(arr);

	printf("home=%s\n",home);
	if(len==len2)
    {strcpy(str,"~");}
    else if(len2>len)
    {
    	//printf("arr+len=%s\n",arr+len);
    	strcpy(str,"~/");
    	strcat(str,arr+len);
    }
    else
    {strcpy(str,arr);}
    printf("%s\n",str);  
}