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
#include "syscmnds_func.h"
#include "history_func.h"
#include "add_to_history.h"
#include "pipe_func.h"


void new_home()
{
	char t[500];
	if (getcwd(t, sizeof(t)) != NULL)
    {	
       strcpy(home,t);	
       //printf("new home is: %s\n",home);
    } 
   else 
   {
       perror("getcwd() error");
       return ;
   }

}

void sigint_handler(int sig)
{
	printf("\nUsing Ctrl -C\n"); 
}

void sigquit_handler(int sig)
{}

void sigchld_handler(int sig)
{
		int status;
    	pid_t pid;
    	/* waitpid() returns a PID on success */
    	if((pid = waitpid(-1, &status, WNOHANG)) > 0)
     	{
        	/* here you can remove the pid from your jobs list */

        	for(int i=0;i<50;i++)
        	{
        		if(pid==bg[i].pid_no && bg[i].fl==1)
        		{
        			bg[i].fl=-1;
        			printf("\n[%s%d exited with code %d]\n",bg[i].process_name,pid,WEXITSTATUS(status));
        			//fflush(stdout);
        			return ;
        		}
        	}
    	}

}

void sigtstp_handler(int sig)
{
	printf("foreground_id=%d\n",foreground_id);
	
    //kill(foreground_id ,SIGCONT);    
   		//printf("some fg process\n");
   		for(int i=0;i<50;i++)  //search for an empty spot on bg struct array
		{
			if(bg[i].fl==-1)
			{
				strcpy(bg[i].process_name,foreground_name);
				bg[i].pid_no=foreground_id;
				bg[i].fl=1;  //flag==1 => process is running 
				bg[i].status=-1;
				break;
			}
		}
		if (foreground_id == 0)
   	 	{
    		//printf("main shell\n");
        	return;
    	}	 
		foreground_id=0;   
    	return;
    

}

char* temp_func()  //check pwd after completing cd
{ 
    char cwd[500];  //for finding pwd
    //int len=strlen(home);
    char *out2;
    out[300]; out[0]='\0';

       out2=out;
    if (getcwd(cwd, sizeof(cwd))!= NULL)
    {
        int len_home=strlen(home);
        int len_cwd=strlen(cwd);
        
      
        strcpy(out,me); //adding
        
        strcat(out,":");

        if(len_home==len_cwd)
        {
         
            strcat(out,"~");
        }
        else if(len_cwd>len_home)
        {
            strcat(out,cwd+len_home);
        }
        else
        {strcat(out,cwd);}     
        
        strcat(out,"$ ");
       
        //return out2;
    } 
    else 
    {
       perror("getcwd() error");
       //return NULL;
    }

}

int main(void)
{
	times=0;

	for(int i=0;i<20;i++)
	{
		bg[i].fl=-1;  //process is finished or terminated => overwrite
		bg[i].status=0;
	}

	prompt_func();
	new_home();
	//pwd_func();
	/*
	printf("\033[1;33m");  //print in bold green
    printf("%s",me);
    printf("\033[0m"); printf(":");
    printf("\033[1;34m");  //print in bold blue
    printf("~");
    printf("\033[0m"); printf("$ ");
	*/
	//=char *y=location_func();
		signal(SIGINT,sigint_handler); 
		signal(SIGCHLD,sigchld_handler);//signal sent if a child process gets terminated
		signal(SIGTSTP,sigtstp_handler); 
		signal(SIGQUIT,sigquit_handler);
		
	while(1)
	{
		
		//char in[300];
		//fgets(in,300,stdin);
			//printf("hahah\n");

		char *in;
		//char *y=help_func();

        //printf("\033[1;33m");  //print in bold green
        char take[300]; take[0]='\0';
        strcpy(take,me);
        strcat(take,":");
        take[strlen(take)+1]='\0';

        temp_func();

  		
		in=readline(out);	
        //printf("\033[0m");  //print in bold green
		
		int l=strlen(in);
		//printf("%d\n",l);
		if(l==0 )
		{
			//location_func();
			continue;
		}
		//printf("input string=%s\n",in);

			//in[l-1]='\0';
			add_to_history(in); //made by me
			add_history(in); //made by readlink
			//store_cmnds(times,in);
			times++;

		

		char *part;  //every 2 parts are divided by a ';'
		part=strtok(in,";");  //first part

		ind=0;
		while(part!=NULL)
		{
			strcpy(store[ind],part);
			//printf("store[ind]=%s\n",store[ind]);
			pipe_func(store[ind]);
			ind++;
			part=strtok(NULL,";");
		}
		//find_func();
		//location_func();
		
	}
	return 0;
}

