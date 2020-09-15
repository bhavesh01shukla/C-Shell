#include "main.h"
#include "prompt_func.h"
#include "pwd_func.h"
#include "location_func.h"
#include "find_func.h"
#include "echo_func.h"
#include "ls_func.h"
#include "pinfo_func.h"
#include "relative_path_func.h"
#include "syscmnds_func.h"


void cd_func(char arr[])
{
	char path[100];
	char arr2[100];
	strcpy(arr2,arr);

	int cnt=0;
	char *t;
	t=strtok(arr," ");
	while(t!=NULL)
	{
		cnt++;
		if(cnt==2)
		{strcpy(path,t);}
		
		t=strtok(NULL," ");
	}

	if(cnt==1) //only cd command is possible;
	{
		//chdir(home); 
		//printf("<%s~>",me);
	    if (chdir(home) != 0)
    	perror("chdir() to new_home failed");
	}
	else if(cnt==2)  //cd . , cd .. , cd ~ , cd /path/
	{
		if(strcmp(path,"~")==0)
		{
			if (chdir(home) != 0)
    		perror("chdir() to new_home failed");
			//chdir(home);
			//printf("<%s~>",me);	 
	   	 	
		}
		else
		{
			//chdir(path);
			if(path[0]=='~' && strcmp(path,"~")!=0)
			{
				char str[200];
				strcpy(str,home);
				//strcat(str,"/");
				strcat(str,path+1);
				//printf("%s\n",str);
				strcpy(path,str);

			}

			if (chdir(path) != 0)
    		perror("chdir() to path failed");

    		//location_func();
		}
	}

}