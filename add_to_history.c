#include "main.h"

void add_to_history(char arr[])
{
	char temp[300];
	char new[30];
	strcpy(new,"\n");
	strcpy(temp,arr);

	//char his_data[20][100];
	FILE *file1 = fopen("foo.txt","wx");
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

	FILE *file3=fopen("foo.txt","w");  	
  	if(strcmp(arr,str)!=0)  //write
    {
    	if(i<20)
    	{
    		strcat(temp,"\n");
    		strcpy(his_data[i],temp);   //temp==arr
            
    		for(int j=0;j<=i;j++)
    		{fprintf( file3, "%s",his_data[j] );}
    	}
    	else
    	{
    		strcat(temp,"\n");
    		strcpy(his_data[i%20],temp);
    		
    		for(int k=(i%20)+1;k<20;k++)
    		{fprintf( file3, "%s",his_data[k] );}

    		int j=i%20;
    		while(j>=0)
    		{
    			fprintf(file3, "%s", his_data[j%20]);
    			j--;
    		}
    	}

    }
      	
fclose(file3);


}