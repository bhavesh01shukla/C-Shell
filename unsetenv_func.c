#include "main.h"

void unsetenv_func(char in[])
{
	for(int k=0;k<7;k++)
	{
		strcat(in," ");
	}
	char temp[300];
	char arr[100][100];

	strcpy(temp,in);

	int cnt=0;  //cnt gives no of commands 
	char *op; 
	op=strtok(temp," ");
	while(op!=NULL)
	{
		strcpy(arr[cnt],op);
		cnt++;
		op=strtok(NULL," ");
	}
	//printf("cnt=%d\n",cnt);
	int args=cnt-1;
	int val=0;
	//printf("before unsetenv %s\n",getenv(arr[1]));
	if(args<=0)
	{
		printf("error: less num of  arguments in setenv\n");
	}
	else if(args>=2)
	{
		printf("error: too many arguments in setenv\n");
	}
	else
	{
		val=unsetenv(arr[1]);
	}

	if(val<0)
	{		
		perror("error in setenv:");
		return ;
	}
	//printf("after unsetenv %s\n",getenv(arr[1]));

	
}
