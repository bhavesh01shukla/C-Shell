#include "main.h"
#include "prompt_func.h"
#include "pwd_func.h"
#include "location_func.h"
#include "find_func.h"
#include "cd_func.h"
#include "ls_func.h"
#include "pinfo_func.h"
#include "relative_path_func.h"
#include "syscmnds_func.h"



void echo_func(char arr[])
{
	
	for(int k=0;k<2;k++)
	{
		strcat(arr," ");
	}
	strcat(arr,"\0");

	char hold[200];
	strcpy(hold,arr);
	int l=strlen(hold);

	int start;
	for(int i=0;i<l;i++)
	{
		if(hold[i]=='o')
		{
			start=i+2;  //check. echo "bhavesh shukla"
			break;
		}
	}
	//printf("%s\n",hold+start);
	
	char add[200];
	int spaces=1;
	int quotes=-1;  //off initially
	int index=0;
	char check=' ';

	for(int i=start;i<l;i++)
	{
		if(hold[i]=='"')
		{quotes=quotes*(-1);}

		else if(hold[i]!=check)  //check==' '
		{
			add[index]=hold[i];
			index++;
			spaces=0;
		}
		else if(hold[i]==check)  //check=' '
		{
			if(quotes==1)  //double quote is open,thus include spaces
			{
				add[index]=hold[i];
				index++;
				spaces=0;
			}
			else if(quotes==-1)  //outside double quotes
			{
				if(spaces==0)
				{
					add[index]=hold[i];
					index++;
					spaces=1;
				}
				else if(spaces==1)
				{continue;}
			}
		}
	}
	add[index]='\0';
	printf("%s\n",add);
	

	//location_func();
	



	//printf("%s\n",arr);
}
