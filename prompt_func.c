#include "main.h"
#include "pwd_func.h"
#include "location_func.h"
#include "find_func.h"
#include "echo_func.h"
#include "cd_func.h"
#include "ls_func.h"
#include "pinfo_func.h"
#include "relative_path_func.h"
#include "syscmnds_func.h"



void prompt_func()
{	
	//system name
	struct utsname buf;
	errno = 0;
	int a=uname(&buf);
	if (a!=0)
	{
		perror("uname");
		return ;
	}
	//printf("system name=%s\n", buf.sysname); //system name==Linux

	//username
	char *username;  //username==bhavesh
	//username=(char *)malloc(10*sizeof(char));
	username=getlogin();

	///making username@system_name:
	strcpy(me,username);
	int len=strlen(username);
	me[len]='@';me[len+1]='\0';
	strcat(me,buf.sysname);
	//int len2=strlen(me);
	//me[len2]=':';me[len2+1]='\0';
	//printf("me=%s\n",me);
	
}
