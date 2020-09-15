#include "main.h"

void fg_func(char in[])
{
	for(int i=0;i<10;i++)	
	{
		int x=strlen(in);

		in[x]=' ';  //adding space at last
		in[x+1]='\0';
	}
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
				foreground_id=bg[i].pid_no;
				//strcpy(foreground_name,bg[i].process_name);
				strcpy(foreground_name,bg[i].process_name);
				printf("%s %d\n",foreground_name,foreground_id );

				int status;
				printf("changing process from background to foreground\n");
				int x=kill(bg[i].pid_no,SIGCONT);
				pid_t pid = waitpid(bg[i].pid_no,&status,WUNTRACED);	

				if(x==0)  //kill was successful
				{bg[i].fl=-1;}
				
				bg[i].status=1;
				check=1;

				break;
			}
		}
		if(check==-1)
		{printf("error: No background process with job_id=%s\n",arg[1]);}
	}


}