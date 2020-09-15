#include "main.h"
#include "find_func.h"
#include "syscmnds_func.h"


void cronjob_func(char in[])
{
	
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
		if(cnt<7)
		{
			printf("error: give input as cronjob -c <command> -t <time of one cycle> -p <total time>\n");
		}
		else
		{
			if(strcmp(arg[0],"cronjob")==0 && strcmp(arg[1],"-c")==0)
			{
				///finding length of command
				int j;
				for(int i=0;i<cnt;i++)
				{
					if(strcmp(arg[i],"-t")==0)
						{j=i;}
				}
				
				//// joining command
				char cmnd[300];cmnd[0]='\0';
				for(int i=2;i<j;i++)
				{
					strcat(cmnd,arg[i]);
					strcat(cmnd," ");
				}
				//printf("command is %s\n",cmnd);
				int t1=atoi(arg[j+1]);
				int t2=atoi(arg[cnt-1]);
				for(int i=0;i<t2/t1;i++)
				{
					find_func(cmnd);
					//syscmnds_func(cmnd);
					if(i!=t2/t1-1)
					{sleep(t1);}
				}

			}
			else
			{
				printf("error: give input as cronjob -c <command> -t <time of one cycle> -p <total time>\n");		
			}
		}

}