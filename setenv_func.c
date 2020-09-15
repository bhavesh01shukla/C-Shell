#include "main.h"

void setenv_func(char in[])
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

	int val=0;
	int args=cnt-1;


	if(args==0)
	{
		printf("error: less num of  arguments in setenv\n");
	}
	else if(args>2)
	{
		printf("error: too many arguments in setenv\n");
	}
	else
	{
		// input format is : setenv var [value] or setenv var

		if(args==1)
		{
			char s[6];  s[0]='\0';
			//printf("num of arg=%d %s\n",args,arr[1]);
			val=setenv(arr[1],s,1);
			//printf("getenv output is=%s\n",getenv(arr[1]));

		}
		else if(args==2)
		{
			//printf("num of arg=%d %s %s\n",args,arr[1],arr[2]);

			val=setenv(arr[1],arr[2],1);
			//printf("val=%d\n",val);

			//printf("doing getenv\n");
			//printf("getenv output is=%s\n",getenv(arr[1]));
		}
	}

	if(val<0)
	{
		perror("error in setenv:");
		return ;
	}
}
