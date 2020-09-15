#include "main.h"
#include "find_func.h"
#include "location_func.h"

void pipe_func(char in[])
{
	char *data[300];

/////////////////////////////////////////////////////////////////
	//separate commands by "|" delimiter
	char temp[300];
	strcpy(temp,in);


	int cnt=0;  //cnt gives no of commands 
	char *op; 
	op=strtok(temp,"|");
	while(op!=NULL)
	{
		data[cnt]=op;
		//strcpy(data[cnt],op);
		cnt++;
		op=strtok(NULL,"|");
	}
	//printf("cnt=%d\n",cnt);
///////////////////////////////////////////////////////////////
	

	int original_stdout = dup(1);
    int original_stdin = dup(0);
    int p[2];  //pipe

    //separate commands by delimiter '|'
    
    int fd = dup(0);
    for(int i=0;i<cnt;i++)
    {
        //printf("cnt=%d i=%d\n",cnt,i);
    	//////////////////////////////////////////////////////
    	//separating data[i] command by delimiter " " 
    	char arr[300][300];
    	char temp2[300];
    	strcpy(temp2,data[i]);

    	int k=0;
    	char *sub;
    	sub=strtok(temp2," ");
    	while(sub!=NULL)
    	{
    		strcpy(arr[k],sub);
    		k++;
    		sub=strtok(NULL," ");
    	}
    	//////////////////////////////////////////////////////
    
    	//checking for presence of  '>' or '<' or ">>" or "&"
    	int a=-1,b=-1,c=-1,d=-1;
    	int pos[4];	
    	pos[0]=-1;  pos[1]=-1; pos[2]=-1;  pos[3]=-1;
    	for(int j=0;j<k;j++)
    	{
    		if(strcmp(arr[j],"<")==0)
    		{  a=1;  pos[0]=j;  }
    		else if(strcmp(arr[j],">")==0)
    		{  b=1;  pos[1]=j;  }
    		else if(strcmp(arr[j],">>")==0)
    		{  c=1;  pos[2]=j;  }
    		else if(strcmp(arr[j],"&")==0)
    		{  d=1;  pos[3]=j;  }
    	}
        
    	if(dup2(fd,0)==-1)
        {perror("error:dup2 fail");}
        close(fd);

        ////////    handling redirection   ///////////
           //printf("a=%d b=%d c=%d\n",a,b,c);

    	int file_in,file_out;
    	if(a==1)
    	{
    		//printf("< present\n");
    		file_in=open(arr[pos[0]+1],O_RDONLY);
    		if(dup2(file_in,0)==-1)
            perror("error:dup2 fail in '<'");
    		close(file_in);
    	}
    	if(b==1)
    	{
    		//printf("> present\n");
    		file_out=open(arr[pos[1]+1],O_RDWR | O_CREAT | O_TRUNC,0644);
            //printf("file created with name %s\n",arr[pos[1]+1]);
    		if(dup2(file_out,1)==-1)
            perror("error:dup2 fail in '>'");
        	close(file_out);
    	}
    	if(c==1)
    	{
    		//printf(">> present\n");
    		file_out=open(arr[pos[2]+1], O_WRONLY | O_APPEND);
    		if(dup2(file_out,1)==-1)
            perror("error:dup2 fail in '>>'");
        	close(file_out);
		}
	    
       
        ////// handling piping //////
        if(i==cnt-1)
        {   //printf("i==cnt-1\n");
            if(a==-1 && b==-1 && c==-1)
            {
                //printf("in a==-1 && b==-1 && c==-1\n");
                if(dup2(original_stdout,1)==-1)
                perror("error:dup2 fail");
                close(original_stdout);
            }
        }
        else
        {
            //printf("i!=%d\n",i);

            pipe(p);
            fd=p[0];
            if(dup2(p[1],1)==-1)
                perror("error:dup2 fail");
            close(p[1]);
        }
        ///////// PIPING DONE  ///////
        
        


        //join all the discrete words to form the complete command
        char command[300];
        command[0]='\0';
        if(a==1 && b==-1 && c==-1)  //only <
        {
        	for(int x=0;x<pos[0];x++)
        	{
        		strcat(command,arr[x]);
        		strcat(command," ");
        	}
        }
        else if(a==-1 && b==1 && c==-1)  //only >
        {
        	for(int x=0;x<pos[1];x++)
        	{
        		strcat(command,arr[x]);
        		strcat(command," ");
        	}
        }
        else if(a==-1 && b==-1 && c==1)  //only >>
        {
        	for(int x=0;x<pos[2];x++)
        	{
        		strcat(command,arr[x]);
        		strcat(command," ");
        	}
        }
        else if(a==1 && b==1 && c==-1) // sort < file1.txt > file2.txt
        {
        	for(int x=0;x<pos[0];x++)
        	{
        		strcat(command,arr[x]);
        		strcat(command," ");
        	}
        }
        else if(a==1 && b==-1 && c==1) // sort < file1.txt >> file2.txt
        {
        	for(int x=0;x<pos[0];x++)
        	{
        		strcat(command,arr[x]);
        		strcat(command," ");
        	}
        }
        else
        {
            strcpy(command,data[i]);
        }
        /*
        if(strcmp(arr[0],"echo")==0)
        {
            printf("match\n");
        }*/
    
        //printf("func=%s\n",command);
        find_func(command);
    }

    
    dup2(original_stdout,1);
    dup2(original_stdin,0);
    close(original_stdout);
    close(original_stdin);

	//location_func();
    return ;
}