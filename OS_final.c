#include<stdio.h>
#include<stdlib.h>
struct Queue
{
	int burst;
	int prior;
    int arrival;
    int p_id;
    int burstt;
};
int main()
{
	int process;
	printf("Enter the number of Processes: \n");
	scanf("%d",&process);
	if(process<1)
	{
		printf("Number of Processes less than 1");
		exit(0);
	}
	struct Queue *Firs_Com_serv=(struct Queue*)malloc(process*sizeof(struct Queue));
	struct Queue *Round___Robin=(struct Queue*)malloc(process*sizeof(struct Queue));
	struct Queue *Priority_Queu=(struct Queue*)malloc(process*sizeof(struct Queue));
	printf("Enter ID, Priority, Burst Time and Arrival Time of each Process: \n\n");
	printf("P.ID  Priority  Burst_time  Arrival_time\n\n");
	int Count_RR=0,Count_FF=0,Count_PR=0;
	for(int i=0;i<process;i++)
	{
		int a,b,arr,id;
		scanf("%d %d %d %d",&id,&a,&b,&arr);
	  if(b>0 && arr>-1)
	  {
		if(a>=1 && a<=10)
		{
			(Round___Robin+Count_RR)->burst=b;
			(Round___Robin+Count_RR)->burstt=b;
			(Round___Robin+Count_RR)->prior=a;
			(Round___Robin+Count_RR)->arrival=arr;
			(Round___Robin+Count_RR)->p_id=id;

			Count_RR++;
		}
		else if(a>=11 && a<=20)
		{
			(Priority_Queu+Count_PR)->burst=b;
			(Priority_Queu+Count_PR)->burstt=b;
			(Priority_Queu+Count_PR)->prior=a;
			(Priority_Queu+Count_PR)->arrival=arr;
			(Priority_Queu+Count_PR)->p_id=id;
			Count_PR++;
			
		}
		else
		{
			(Firs_Com_serv+Count_FF)->burst=b;
			(Firs_Com_serv+Count_FF)->burstt=b;
			(Firs_Com_serv+Count_FF)->prior=a;
			(Firs_Com_serv+Count_FF)->arrival=arr;
			(Firs_Com_serv+Count_FF)->p_id=id;
			Count_FF++;
		}
	  }
	  else
	  {
	  	printf("Wrong Details Entered for Processes \n");
	  	exit(0);
	  }
	}
