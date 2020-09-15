#include "main.h"

void kjobs_func(char in[])
{
	for(int i=0;i<10;i++)	
	{
		int x=strlen(in);

		in[x]=' ';
		in[x+1]='\0';
	}
	//printf("%s\n",in);


	char temp[300];
	strcpy(temp,in);

	int cnt=0;
	char arg[10][100];
	char *op=strtok(temp," ");
	while(op!=NULL)
	{
		strcpy(arg[cnt],op);
		cnt++;
		op=strtok(NULL," ");
	}

	if(cnt-1!=2)  //no of kjobs arguments
	{
		printf("error: less num of arguments passed in kjobs function\n");
		return ;
	}
	else
	{
		//printf("pid=%s sig=%s\n",arg[1],arg[2]);

		int job_id=atoi(arg[1]);
		int sig=atoi(arg[2]);
		int val=-1;
		int yes=0;
		//printf("pid=%d sig=%d\n",pid,sig);

		for(int i=0;i<50;i++)
		{
			if(bg[i].fl==1)
			{yes++;}

			if(yes==job_id && bg[i].pid_no>0)
			{
				int x=kill(bg[i].pid_no,sig);
				if(sig==19)
				{bg[i].status=-1;}
				if(sig==18)
				{bg[i].status=1;}
				else if(sig==9)
				{
					printf("%s %d exited with code 0\n",bg[i].process_name,bg[i].pid_no);
					bg[i].fl=-1;
				}
				val=1;
				break;
			}	
		}
		if(val==-1)
		{
			printf("error: No process exists with given pid\n");
		}
	}
	
}
