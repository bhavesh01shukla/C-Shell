//this function give pwd in relative form to add in form of ~/abc/def/ 
//to match display requirements,whereas pwd_func function prints absolute
//path of cwd and then gives cwd in realtive form
#include "main.h"
#include "prompt_func.h"
#include "pwd_func.h"
#include "find_func.h"
#include "echo_func.h"
#include "cd_func.h"
#include "ls_func.h"
#include "pinfo_func.h"
#include "relative_path_func.h"
#include "syscmnds_func.h"



void location_func()  //check pwd after completing cd
{ 
    char cwd[500];  //for finding pwd
    //int len=strlen(home);

    if (getcwd(cwd, sizeof(cwd))!= NULL)
    {
        int len_home=strlen(home);
        int len_cwd=strlen(cwd);

        printf("\033[1;33m");  //print in bold green
        printf("%s",me);

        printf("\033[0m"); printf(":");
    
            
        if(len_home==len_cwd)
        {
            printf("\033[1;34m");  //print in bold blue
            printf("~");
        }
        else if(len_cwd>len_home)
        {
            //printf("<%s~%s>",me,cwd+len_home);
            printf("\033[1;34m");  //print in bold blue
            printf("~%s",cwd+len_home);
        }
        else
        {
            //printf("<%s%s>",me,cwd);
            printf("\033[1;34m");  //print in bold blue            
            printf("%s",cwd);
        }  
        printf("\033[0m");   //back to normal print color
        printf("$ ");   
    } 
    else 
    {
       perror("getcwd() error");
       return ;
    }

}

/*char* location_func()  //check pwd after completing cd
{ 
    char cwd[500];  //for finding pwd
    //int len=strlen(home);
    char *out2;
    char out[300]; out[0]='\0';

    if (getcwd(cwd, sizeof(cwd))!= NULL)
    {
        int len_home=strlen(home);
        int len_cwd=strlen(cwd);
        
        //printf("\033[1;33m");  //print in bold green
        //printf("%s",me);
        strcat(out,"<<<");
        strcat(out,me); //adding
        //printf("%s",out);

        //printf("\033[0m"); //printf(":");
        strcat(out,":");

        if(len_home==len_cwd)
        {
          //  printf("\033[1;34m");  //print in bold blue
            //printf("~");
            strcat(out,"~");
        }
        else if(len_cwd>len_home)
        {
            //printf("\033[1;34m");  //print in bold blue
            //printf("~%s",cwd+len_home);
            strcat(out,cwd+len_home);
        }
        else
        {     
            //printf("\033[1;34m");  //print in bold blue            
            //printf("%s",cwd);
            strcat(out,cwd);

        }     
        //printf("\033[0m");   //back to normal print color
        //printf("$ ");
        strcat(out,"$ ");
        out2=out;
        return out2;
    } 
    else 
    {
       perror("getcwd() error");
       return NULL;
    }

}*/