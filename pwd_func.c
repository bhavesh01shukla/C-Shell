#include "main.h"
#include "prompt_func.h"
#include "location_func.h"
#include "find_func.h"
#include "echo_func.h"
#include "cd_func.h"
#include "ls_func.h"
#include "pinfo_func.h"
#include "relative_path_func.h"
#include "syscmnds_func.h"



void pwd_func()  //check pwd after completing cd
{ 
    char dir[500];  //for finding pwd
    //int len=strlen(home);

    if (getcwd(dir, sizeof(dir))!= NULL)
    {
        printf("%s\n",dir);
        //location_func(); 
    } 
    else 
    {
       perror("getcwd() error");
       return ;
    }

}
