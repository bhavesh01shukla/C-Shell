#include "main.h"

void bg_func(char in[])
{
	for(int i=0;i<10;i++)	
	{
		int x=strlen(in);

		in[x]=' ';  //adding space at last
		in[x+1]='\0';
	}

	printf("here in  bg func\n");
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

	if(cnt<2)
	{
		printf("error: give arg as bg <job no>\n");
	}
	else if(cnt>2)
	{
		printf("error:too many arguments in input\n");
	}
	else
	{
		int index_no=atoi(arg[1]);
		int yes=0;
		int check=-1;
		for(int i=0;i<50;i++)
		{
			if(bg[i].fl==1)
				{yes++;}
			if(yes==index_no)
			{

				printf("changing status to running\n");
				bg[i].status=1;
				int x=kill(bg[i].pid_no,SIGCONT);
				check=1; //to check if process if running or not
				break;
			}
		}
		if(check==-1)
		{printf("error: No background process with job_id=%s\n",arg[1]);}

	}

}
