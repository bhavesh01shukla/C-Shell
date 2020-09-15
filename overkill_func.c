#include "main.h"

void overkill_func()
{
	for(int i=0;i<50;i++)
	{
		if(bg[i].fl==1)
		{
			int x=kill(bg[i].pid_no,9);				
			printf("%s with pid=%d terminated\n",bg[i].process_name,bg[i].pid_no);
			bg[i].fl=-1;	
		}
	}
}