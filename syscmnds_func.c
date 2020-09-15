#include "main.h"
#include "prompt_func.h"
#include "pwd_func.h"
#include "location_func.h"
#include "find_func.h"
#include "echo_func.h"
#include "cd_func.h"
#include "ls_func.h"
#include "relative_path_func.h"
#include "pinfo_func.h"


void syscmnds_func(char arr[])
{
	//printf("inside syscmnds_func:%s\n",arr);
	char *arg[300];

	char hold[300],last[300];
	strcpy(hold,arr);

//////////////////////    tokenizing    ///////////////////
	int cnt=0;	
	char *token=strtok(hold," ");
	while(token!=NULL)
	{
		strcpy(last,token);
		arg[cnt]=token;	
		cnt++;
		
		token=strtok(NULL," ");
	}
	//printf("last token=%s\n",last);

	int bg_present=0;
	char str[300];
	int val;

	////////////////////     fiding if bg or fg   ////////////////////

	if(strcmp(last,"&")==0) //run the process as background process
	{
		bg_present=1;
		arg[cnt-1]=NULL;
		val=cnt-1;
	}
	else  //else run as foreground
	{
		arg[cnt]=NULL;
		val=cnt;
	}
 
 //////////////////////    getting name of process ////////////////////////
	str[0]='\0';
	for(int i=0;i<val;i++)
	{
		strcat(str,arg[i]);
		strcat(str," ");
	}
	//printf("%s\n",str);


///////////////////////    forking for fg or bg process  //////////////////
	int pid=fork();
	if(pid==0)
	{
		//if(bg_present==1)
		//{setpgid(0,0);}

		int res=execvp(arg[0],arg);
		if(res==-1)
		{
			//printf("%s %s\n",arg[0],arg[1]);
			printf("Error: Wrong Command\n");
			return ;
		}
	}
	else if(pid>0)
	{

		if(bg_present==1)  //process is background process
		{

			//printf("pid of parent=%d\n",x);
			for(int i=0;i<50;i++)  //search for an empty spot on bg struct array
			{
				if(bg[i].fl==-1)
				{
					strcpy(bg[i].process_name,str);
					bg[i].pid_no=pid;
					bg[i].fl=1;  //flag==1 => process is running 
					bg[i].status=1;
					break;
				}
			}
		}
		else if(bg_present==0)  //process is foreground process
		{
			foreground_id=pid;
			strcpy(foreground_name,str);
			int status;
			waitpid(pid,&status,WUNTRACED);
		}
	}

}
