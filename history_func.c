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

void history_func()
{
	FILE *file2 = fopen("foo.txt","r");  
	if(file2==NULL)
	{
		perror("error");
		return ;
	}

    char *line=NULL;
    size_t len=0;
    ssize_t read;

    char str[300];
    str[0]='\0';
    int i=0;
    while(read=getline(&line,&len,file2)!=-1) 
    {
     	//printf("%s", line);
     	strcpy(str,line);  //copy each linr into str array
     	strcpy(his_data[i],str);
     	//printf("his_data[i]=%s",his_data[i]);
     	i++;
    }
    fclose(file2);  //closing read mode

    
	FILE *file3 = fopen("foo.txt","r");  
	if(file3==NULL)
	{
		perror("error");
		return ;
	}

    if(i<=10)  //print from 0 to i
    {
	    int j=0;
	    while(read=getline(&line,&len,file2)!=-1) 
	    {
	     	//printf("%s", line);
	     	strcpy(str,line);  //copy each linr into str array
	     	strcpy(his_data[j],str);
	     	printf("%s",his_data[j]);
	     	j++;
	    }
	    fclose(file3);  //closing read mode
    }
    else  //print from 10 till i
    {
    	int j=0;
	    while(read=getline(&line,&len,file2)!=-1) 
	    {
	     	//printf("%s", line);
	     	strcpy(str,line);  //copy each linr into str array
	     	strcpy(his_data[j],str);
	     	if(j>=i-10)
	     	{printf("%s",his_data[j]);}
	     	j++;
	    }
	    fclose(file3);  //closing read mode
    }
}
