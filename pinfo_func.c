#include "main.h"
#include "prompt_func.h"
#include "pwd_func.h"
#include "location_func.h"
#include "find_func.h"
#include "echo_func.h"
#include "ls_func.h"
#include "cd_func.h"
#include "relative_path_func.h"
#include "syscmnds_func.h"

extern int errno; 

void pinfo_func(char arr[])
{
	int cnt=0;
	char str[300];
	char *token=strtok(arr," ");
	while(token!=NULL)
	{
		cnt++;
		if(cnt==2)
		{strcpy(str,token);}
		token=strtok(NULL," ");
	}

	char loc[300],temp[300],path[300],temp2[300];
	char *data;

	char state[200],proc_id[200],memory[200];


	loc[0]='\0';path[0]='\0';
	int pid=getpid();
	//printf("pid=%d\n",pid);
	if(cnt==1)
	{sprintf(temp,"%d",pid);}
	else if(cnt==2)
	{strcpy(temp,str);}

	//path to /proc/pid/status file
	strcat(loc,"/proc/");
	strcat(loc,temp);
	strcat(loc,"/status");

	//path to /proc/pid/exe file
	strcat(path,"/proc/");
	strcat(path,temp);
	strcat(path,"/exe");
	//printf("location=%s\n",loc);
	

	FILE *file=fopen(loc,"r");
	if(file==NULL)
	{
		perror(loc);
		return;
	}  
	else
	{
		size_t size=0;
		int i=0;
		while(getline(&data,&size,file)!=-1)
		{
			if(i==2)
			{strcpy(state,data);}
			else if(i==5)
			{strcpy(proc_id,data);}
			else if(i==17)
			{strcpy(memory,data);}
			i++;
		}
		printf("%s",proc_id);
		printf("%s",state);
		printf("%s",memory);
	}
	fclose(file);  //modified

	int res=readlink(path,temp2,63);
	if(res==-1)
	{
		printf("Error:Cannot open executable:%s\n",path);
		return;
	}
	temp2[res]='\0';
	printf("Executable Path: %s\n",temp2);
}