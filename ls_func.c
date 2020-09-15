#include "main.h"
#include "prompt_func.h"
#include "pwd_func.h"
#include "location_func.h"
#include "find_func.h"
#include "echo_func.h"
#include "cd_func.h"
#include "pinfo_func.h"
#include "relative_path_func.h"
#include "syscmnds_func.h"


void f_one(int val,DIR *mydir,char path[],char fl[]) // for finding ls,ls -a and ls /path
{
	//printf("for ls or ls -a\n");
	struct dirent *dir_entry;
	
	if(mydir!=NULL)
	{
		if( val==2 && (strcmp(fl,"-a")==0) )  //ls -a command
		{
			while((dir_entry=readdir(mydir))!=NULL)
			{printf("%s\n",dir_entry->d_name);}

			closedir(mydir);
		}	
		else  //ls command,ls .., ls. , ls /path/
		{	
			while((dir_entry=readdir(mydir))!=NULL)
			{	
				if(strcmp(dir_entry->d_name,".")==0 || strcmp(dir_entry->d_name,"..")==0)
				{continue;}
				else
				{printf("%s\n",dir_entry->d_name);}
			}
			closedir(mydir);
		}	
	}

	else  // opendir returns NULL if couldn't open directory 
   	{ 
       	printf("Unable to open current directory\n"); 
   		return ; 
   	} 
}

void f_two(int val,DIR *mydir,char fl[],char path[])  //for ls -l; ls-al; ls-la
{
    struct passwd *pw;
    struct group *gp;
    char *c;
    int i;
  
    struct stat fileStat; 
    stat(path,&fileStat);

    struct dirent *myfile;

	while((myfile=readdir(mydir))!=NULL)
	{
	    stat(myfile->d_name,&fileStat);  

		//if command is ls -l,then dont print the hidden files
		if(strcmp(fl,"-l")==0)
		{
			if((strcmp(myfile->d_name,".")==0)||(strcmp(myfile->d_name,"..")==0))
			continue;
		}
	    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
	    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
	    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
	    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
	    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
	    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
	    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
	    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
	    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
	    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-"); 
	    printf(" ");
	    printf("%ld ",fileStat.st_nlink);
	    pw=getpwuid(fileStat.st_uid);
	    printf("%s ",pw->pw_name);
	    gp=getgrgid(fileStat.st_gid);
	    printf("%s ",gp->gr_name);
	    printf("%8ld ",fileStat.st_size);  
	    c=ctime(&fileStat.st_mtime);
	    for(i=4;i<=15;i++)
	    {printf("%c",c[i]);}
	    
	    printf(" ");
	    printf("%s\n",myfile->d_name);
	}
	closedir(mydir);
}

void ls_func(char arr[])
{
	char hold[200];
	strcpy(hold,arr);

	int cnt=0;
	char *token;
	char flag[200];  //flag with ls
	char file_path[200];  //to store path of file or folder
	token=strtok(arr," ");
	while(token!=NULL)
	{
		cnt++;
		if(cnt==2) //if cnt==2,flag can be a flag like -a,-l etc or be a path
		{strcpy(flag,token);}
		if(cnt==3)
		{strcpy(file_path,token);}

		token=strtok(NULL," ");
	}

	DIR *mydir;//check

	if(cnt==1) // ls command
  	{
  	 	mydir=opendir(".");
		f_one(cnt,mydir,".","nothing");  //flag=nothing
	}

	else if(cnt==2)
	{
		if( (cnt==2) && (strcmp(flag,"-a")==0) )     //ls -a command
		{
  			mydir=opendir(".");
			f_one(cnt,mydir,".",flag);  //flag==variable_flag==-a
		}

		else if( (cnt==2) && (strcmp(flag,"-l")==0) )   //ls -l command
		{
			mydir=opendir(".");
			f_two(cnt,mydir,flag,".");
		}
		
		else if( (cnt==2) && (strcmp(flag,"-al")==0) )  //ls -al command
		{
			mydir=opendir(".");
			f_two(cnt,mydir,flag,".");
		}

		else if( (cnt==2) && (strcmp(flag,"-la")==0) )  //ls -la command
		{
			mydir=opendir(".");
			f_two(cnt,mydir,flag,".");
		}
		else if( (cnt==2) && (strcmp(flag,"~")==0) )  //ls ~ command
		{
			mydir=opendir(home);  //imported home from main.c
			f_one(cnt,mydir,home,"nothing");
		}
		else  //ls /path/ command
		{
			mydir=opendir(flag);//since in cnt==2,2nd input can be flag or path
			f_one(cnt,mydir,flag,"nothing"); //3rd input is for path and 4th input is for flag
		}
	}
}
