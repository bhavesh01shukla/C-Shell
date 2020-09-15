#include "main.h"
#include "prompt_func.h"
#include "pwd_func.h"
#include "location_func.h"
#include "echo_func.h"
#include "cd_func.h"
#include "ls_func.h"
#include "pinfo_func.h"
#include "relative_path_func.h"
#include "syscmnds_func.h"
#include "history_func.h"
#include "setenv_func.h"
#include "unsetenv_func.h"
#include "jobs_func.h"
#include "kjobs_func.h"
#include "bg_func.h"
#include "fg_func.h"
#include "overkill_func.h"
#include "quit_func.h"
#include "cronjob_func.h"

void find_func(char in[])
{

		char temp2[300];
		int l=strlen(in);
		strcpy(temp2,in);

		
		char *subpart;
		subpart=strtok(temp2," ");
		while(subpart!=NULL)
		{
			if(strcmp(subpart,"pwd")==0)
			{
				pwd_func();
				break;  //break the while loop if we got name of the command
			}
			else if(strcmp(subpart,"cd")==0)
			{
				cd_func(in);  //send the whole cd input.separate it later
				break;  //break the while loop if we got name of the command
			}
			
			else if(strcmp(subpart,"ls")==0)
			{
				ls_func(in);
				break;  //break the while loop if we got name of the command
			}
			else if(strcmp(subpart,"pinfo")==0)
			{
				pinfo_func(in);
				break;
			}
			else if(strcmp(subpart,"history")==0)
			{
				history_func(times);
				break;
			}
			else if(strcmp(subpart,"setenv")==0)
			{
				setenv_func(in);
				break;
			}
			else if(strcmp(subpart,"unsetenv")==0)
			{
				unsetenv_func(in);
				break;
			}
			else if(strcmp(subpart,"jobs")==0)
			{
				jobs_func(in);
				break;
			}
			else if(strcmp(subpart,"kjobs")==0)
			{
				kjobs_func(in);
				break;
			}
			else if(strcmp(subpart,"bg")==0)
			{
				bg_func(in);
				break;
			}
			else if(strcmp(subpart,"fg")==0)
			{
				fg_func(in);
				break;
			}
			else if(strcmp(subpart,"overkill")==0)
			{
				overkill_func();
				break;
			}
			else if(strcmp(subpart,"quit")==0)
			{
				quit_func();
				break;
			}
			else if(strcmp(subpart,"cronjob")==0)
			{
				cronjob_func(in);
				break;
			}
			else
			{
				syscmnds_func(in);
				break;
			}
			subpart=strtok(NULL," ");
				
		}

	//location_func();
}