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
	//SORTING ACCORDING TO ARRIVAL TIME FOR FCFS
	for(int i=0;i<Count_FF-1;i++)
	{
		for(int j=0;j<Count_FF-i-1;j++)
		{
			if((Firs_Com_serv+j)->arrival>(Firs_Com_serv+j+1)->arrival)
			{
				int temp_prio=(Firs_Com_serv+j)->arrival;
				int temp_burst=(Firs_Com_serv+j)->burst;
				int temp_id=(Firs_Com_serv+j)->p_id;
				(Firs_Com_serv+j)->arrival=(Firs_Com_serv+j+1)->arrival;
				(Firs_Com_serv+j)->burst=(Firs_Com_serv+j+1)->burst;
				(Firs_Com_serv+j)->p_id=(Firs_Com_serv+j+1)->p_id;
				(Firs_Com_serv+j)->burstt=(Firs_Com_serv+j+1)->burst;
				(Firs_Com_serv+j+1)->arrival=temp_prio;
				(Firs_Com_serv+j+1)->p_id=temp_id;
				(Firs_Com_serv+j+1)->burst=temp_burst;
				(Firs_Com_serv+j+1)->burstt=temp_burst;
			}
		}
	}
	//SORTING COMPLETED FOR FCFS
	printf("PROCESSES IN FCFS QUEUE\n\n");
	printf("P.ID  Priority  Arrival_time  Burst_time\n\n");
	for (int i = 0; i <Count_FF; ++i)
	{
		printf("  %d      %d        %d            %d\n",(Firs_Com_serv+i)->p_id,(Firs_Com_serv+i)->prior,(Firs_Com_serv+i)->arrival,(Firs_Com_serv+i)->burst);
	}
	//SORTING STARTED FOR ROUND ROBIN
	for(int i=0;i<Count_RR-1;i++)
	{
		for(int j=0;j<Count_RR-i-1;j++)
		{
			if((Round___Robin+j)->arrival>(Round___Robin+j+1)->arrival)
			{
				int temp_prio=(Round___Robin+j)->arrival;
				int temp_burst=(Round___Robin+j)->burst;
				int temp_id=(Round___Robin+j)->p_id;
				(Round___Robin+j)->arrival=(Round___Robin+j+1)->arrival;
				(Round___Robin+j)->burst=(Round___Robin+j+1)->burst;
				(Round___Robin+j)->p_id=(Round___Robin+j+1)->p_id;
				(Round___Robin+j)->burstt=(Round___Robin+j+1)->burst;
				(Round___Robin+j+1)->arrival=temp_prio;
				(Round___Robin+j+1)->burst=temp_burst;
				(Round___Robin+j+1)->burstt=temp_burst;
				(Round___Robin+j+1)->p_id=temp_id;
			}
		}
	}
	for(int j=0;j<Count_RR;j++)
	{
			if((Round___Robin+j)->arrival==(Round___Robin+j+1)->arrival)
			{
				if((Round___Robin+j+1)->burst<(Round___Robin+j)->burst)
				{
				int temp_arr=(Round___Robin+j)->arrival;
				int temp_burst=(Round___Robin+j)->burst;
				int temp_prio=(Round___Robin+j)->prior;
				int temp_id=(Round___Robin+j)->p_id;
				(Round___Robin+j)->arrival=(Round___Robin+j+1)->arrival;
				(Round___Robin+j)->burst=(Round___Robin+j+1)->burst;
				(Round___Robin+j)->burstt=(Round___Robin+j+1)->burst;
				(Round___Robin+j)->p_id=(Round___Robin+j+1)->p_id;
				(Round___Robin+j)->prior=(Round___Robin+j+1)->prior;
				(Round___Robin+j+1)->arrival=temp_arr;
				(Round___Robin+j+1)->burst=temp_burst;
				(Round___Robin+j+1)->burstt=temp_burst;
				(Round___Robin+j+1)->prior=temp_prio;
				(Round___Robin+j+1)->p_id=temp_id;
				}
			}
	}
	//SORTING END FOR ROUND ROBIN
	printf("PROCESSES IN Round___Robin QUEUE\n\n");
	printf("P.ID  Priority  Arrival_time  Burst_time\n\n");
	for (int i = 0; i <Count_RR; ++i)
	{
		printf("  %d      %d        %d            %d\n",(Round___Robin+i)->p_id,(Round___Robin+i)->prior,(Round___Robin+i)->arrival,(Round___Robin+i)->burst);
	}
	//SORTING STARTED FOR PRIORITY QUEUE
	for(int i=0;i<Count_PR-1;i++)
	{
		for(int j=0;j<Count_PR-i-1;j++)
		{
			if((Priority_Queu+j)->arrival>(Priority_Queu+j+1)->arrival)
			{
				int temp_prio=(Priority_Queu+j)->arrival;
				int temp_burst=(Priority_Queu+j)->burst;
				int temp_arr=(Priority_Queu+j)->prior;
				int temp_id=(Priority_Queu+j)->p_id;
				(Priority_Queu+j)->arrival=(Priority_Queu+j+1)->arrival;
				(Priority_Queu+j)->burst=(Priority_Queu+j+1)->burst;
				(Priority_Queu+j)->burstt=(Priority_Queu+j+1)->burst;
				(Priority_Queu+j)->prior=(Priority_Queu+j+1)->prior;
				(Priority_Queu+j)->p_id=(Priority_Queu+j+1)->p_id;
				(Priority_Queu+j+1)->arrival=temp_prio;
				(Priority_Queu+j+1)->p_id=temp_id;
				(Priority_Queu+j+1)->burst=temp_burst;
				(Priority_Queu+j+1)->burstt=temp_burst;
				(Priority_Queu+j+1)->prior=temp_arr;
			}
		}
	}
	for(int j=0;j<Count_PR;j++)
	{
			if((Priority_Queu+j)->arrival==(Priority_Queu+j+1)->arrival)
			{
				if((Priority_Queu+j+1)->prior<(Priority_Queu+j)->prior)
				{
				int temp_arr=(Priority_Queu+j)->arrival;
				int temp_burst=(Priority_Queu+j)->burst;
				int temp_prio=(Priority_Queu+j)->prior;
				int temp_id=(Priority_Queu+j)->p_id;
				(Priority_Queu+j)->arrival=(Priority_Queu+j+1)->arrival;
				(Priority_Queu+j)->burst=(Priority_Queu+j+1)->burst;
				(Priority_Queu+j)->burstt=(Priority_Queu+j+1)->burst;
				(Priority_Queu+j)->p_id=(Priority_Queu+j+1)->p_id;
				(Priority_Queu+j)->prior=(Priority_Queu+j+1)->prior;
				(Priority_Queu+j+1)->arrival=temp_arr;
				(Priority_Queu+j+1)->burst=temp_burst;
				(Priority_Queu+j+1)->burstt=temp_burst;
				(Priority_Queu+j+1)->prior=temp_prio;
				(Priority_Queu+j+1)->p_id=temp_id;
				}
			}
	}
	//SORTING END FOR PRIORITY QUEUE
	printf("PROCESSES IN Priority QUEUE\n\n");
	printf("P.ID  Priority  Arrival_time  Burst_time\n\n");
	for (int i = 0; i <Count_PR; ++i)
	{
		printf("  %d      %d        %d            %d\n",(Priority_Queu+i)->p_id,(Priority_Queu+i)->prior,(Priority_Queu+i)->arrival,(Priority_Queu+i)->burst);
	}
	printf("\n\n");
	int temp_RR=0,temp_FF=0,temp_PQ=0,t1=0,t=0,x1,x2,x3,temp_R=0,turn_RR[Count_RR],turn_PQ[Count_PR];
	int turn_FF[Count_FF],wait_RR[Count_RR],wait_PQ[Count_PR],wait_FF[Count_FF];
	int ideal=0;
	//THESE IF CONDITIONS ARE USED FOR SATISFYING SOME CONDITIONS
	if(Count_RR==0)
	{
		(Round___Robin+Count_RR)->burst=0;
		temp_RR++;
	}
	if(Count_PR==0)
	{
		(Priority_Queu+Count_PR)->burst=0;
		temp_PQ++;
	}
	if(Count_FF==0)
	{
		(Firs_Com_serv+Count_FF)->burst=0;
		temp_FF++;
	}
