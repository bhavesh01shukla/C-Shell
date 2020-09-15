#include "main.h"

void jobs_func(char in[])
{

	int k=1;
	for(int i=0;i<50;i++)
	{
		if(bg[i].fl==1)
		{
			if(bg[i].status==1)
			{printf("[%d]+\t running\t %s\t%d\n",k,bg[i].process_name,bg[i].pid_no);}
			if(bg[i].status==-1)
			{printf("[%d]+\t stopped\t %s\t%d\n",k,bg[i].process_name,bg[i].pid_no);}
			
			k++;
		}
	}
}