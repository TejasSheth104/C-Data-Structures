#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5
#define len 25

char queue[MAX][MAX][len];
void enqueue();
void dequeue();
void initialising();
void circularqueue();
void Display();
int front[MAX],rear[MAX];



int main()
{
	initialising();
	int option;
	do
	{
		
		printf("**********MAIN MENU**********\n");
		printf("1.Add a patient to queue\n");
		printf("2.Check the next patient\n");
		printf("3.Display the waiting room queue\n");
		
		scanf("%d",&option);

		switch(option)
		{
			case 1:
			{
				enqueue();
				break;
			}
			case 2:
			{
				dequeue();
				break;
			}
			case 3:
			{
				Display();
			}

		}
	}while(option!=4);
}

void initialising()
{
	for(int i=0;i<=MAX-1;i++)
	{
		front[i]=rear[i]=-1;
	}
}


void enqueue()
{
	char name[MAX];
	int prio;
	printf("Enter patient name\n");
	scanf("%s",name);
	printf("%s\n",name);
	printf("Enter priority\n");
	scanf("%d",&prio);
	printf("%d\n",prio);
	
	if ((front[prio-1] == 0 && rear[prio-1] == MAX -1) || (rear[prio-1] == front[prio-1] -1))
	{
		printf("OVER FLOW\n");
	}
	else
	{
		if(front[prio-1] == -1 && rear[prio-1] == -1)
		{
			front[prio-1]=rear[prio-1] = 0;
			strcpy(&queue[prio-1][rear[prio-1]][0],name);
		}
		else if(front[prio-1]!=0 && rear[prio-1] == MAX-1)
		{
			rear[prio-1] = 0;
			strcpy(&queue[prio-1][rear[prio-1]][0],name);
		}
		else 
		{
			rear[prio-1] = rear[prio-1] + 1;
			strcpy(&queue[prio-1][rear[prio-1]][0],name);
		}
	}

}


void dequeue()
{
	bool breakinnerloop = false;
	bool breakloop = false ;
	int temp = 0;
	 for(int i = 0;i<=MAX-1;i++)
	    {
	    	
	    	
	    	if(front[i]<=rear[i])
	    	{
	        for(int j = front[i];j<=rear[i];j++)
        		{
	            if(queue[i][j][0]!='\0')
	            {
	                int k=0;
	                printf("%s\n",&queue[i][j][0] );
                	int x = strlen(&queue[i][j][0]);
	                for(k = 0; k<=x-1;k++)
	                {
	                strcpy(&queue[i][j][k],"\0"); 
	            	}
	              
	        		circularqueue(i);
	                breakloop =true;
					break;
				}    
	      		}
	      	}
	      	else
	      	{
	      		for(int j = front[i];j<=MAX-1;j++)
        		{
	            if(queue[i][j][0]!='\0')
	            {
	                int k=0;
	                printf("%s\n",&queue[i][j][0] );
                	int x = strlen(&queue[i][j][0]);
	                for(k = 0; k<=x-1;k++)
	                {
	                strcpy(&queue[i][j][k],"\0"); 
	            	}
	              	circularqueue(i);
	                
	                breakloop =true;
	                breakinnerloop = true;

	               	break;
	             }
	      		}
	      		for(int j = 0;j<=rear[i];j++)
        		{
	            if(queue[i][j][0]!='\0')
	            {
	            	if(breakinnerloop)
	            	{
	            		break;
	            	}
	                int k=0;
	                printf("%s\n",&queue[i][j][0] );
                	int x = strlen(&queue[i][j][0]);
	                for(k = 0; k<=x-1;k++)
	                {
	                strcpy(&queue[i][j][k],"\0"); 
	            	}
	              	circularqueue(i);	              
	                breakloop =true;
	               	break;
	             }
	      		}
	      	}



	      	if(breakloop)
	      	{
	      		break;
	      	}
	      	else if(i == MAX-1 && breakloop == false)
	      	{
	      		printf("Queue is empty\n");
	      	}
	      	

	      	
	    }  	 
}



void circularqueue(int i)
{
	if (front[i] == rear[i])
		{
			front[i] = rear[i] = -1;
		}
	else
		{
			if(front[i] == MAX -1)
				{
					front[i] = 0;
				}
			else
				{
					front[i] = front[i] + 1;
							
				}
		}
}

void Display()
{
	for(int i=0;i<=MAX-1;i++)
	{
		for(int j=0;j<=MAX-1;j++)
		{
			if(queue[i][j][0]!='\0')
			{
			printf("%s\n",&queue[i][j][0] );
			}
		}
	}
}