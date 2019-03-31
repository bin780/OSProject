#include<unistd.h>
#include<stdio.h>

struct student     // structure for details of each student
{
	int student_id;
	int arrivalTime;
	int FoodTime;
	int completionTime;
	int turnAroundTime;
	int waitingTime;
	int backUp;
};
int findBiggest(int);
void sort();
void display();
void calculate();
void findCompletionTime();



struct student s[50];                //global variables

int totalTime=0;                                   
int time=0;
int totalWT;
int totalTAT;
int n=3;                           //total no of student by default 3

void input()
{
	                                           
	int i;
	printf("\nenter the number of students\n");
	scanf("%d",&n);   
	for(i=0;i<n;++i)                                                             //function to take custom input
	{
		printf("\nenter the student id of student %d : ",i+1);
		scanf("%d",&s[i].student_id);
		printf("\nenter the arrival time of student %d :",i+1);
		scanf("%d",&s[i].arrivalTime);
		printf("\nenter the food taking time of student %d :",i+1);
		scanf("%d",&s[i].FoodTime);
		s[i].backUp=s[i].FoodTime;
		time+=s[i].FoodTime;
	}
}
struct student init()
{   printf("first here");
    //struct student s;
    int i,j;
    s[0].student_id=2132;  
    s[1].student_id=2102;                                                      //function to initialise the values
    s[2].student_id=2453;
	for(i=2,j=0;i<=8;i=i*2,j++)
	{
		s[j].arrivalTime=0;
		s[j].FoodTime=i;
		s[j].backUp=s[j].FoodTime;
		time+=s[j].FoodTime;
	}
	
} 
int main()
{    int ch;
	printf("1.custom input \n\n2.deafult values\n");
	scanf("%d",&ch);
	switch(ch)
	{case 1: input();
	       break;
	case 2: init();
	        break;
   default:printf("\nworng input\n");
	}
	//init();
	sort();
	totalTime+=s[0].arrivalTime;
	
	time+=s[0].arrivalTime;
	findCompletionTime();
	calculate();
	display();
	
	
	
	
}
void display()
{
	int i;
	for(i=0;i<n;++i)
	{
		printf("\nstudent_id %d",s[i].student_id);
		printf("\nstudent foodtime %d",s[i].backUp);
		printf("\nstudent arrival time %d",s[i].arrivalTime);
		printf("\nstudent completion time %d",s[i].completionTime);
		printf("\nstudent waiting time %d",s[i].waitingTime);
		printf("\nstudnt turn around time %d\n\n",s[i].turnAroundTime);
	}
	printf("\naverage total TAT %f",totalTAT/(float)n);
    printf("\naverage waiting time %f",totalWT/(float)n);
	
}

void calculate()
{
	totalWT=0;
	totalTAT =0;
	int i;
	for(i=0;i<n;i++)
	{
	       s[i].turnAroundTime=s[i].completionTime-s[i].arrivalTime;
	       s[i].waitingTime=s[i].turnAroundTime-s[i].backUp;
		totalWT+=s[i].waitingTime;
		totalTAT+=s[i].turnAroundTime;
	}
}
void sort()
{  int i,j;
  struct student temp;
    //printf("loo started");
    
	for(i=0;i<n-1;++i)
	{
		for(j=0;j<n-i-1;j++)
		{   //printf("hi");
			if(s[j].arrivalTime>s[j+1].arrivalTime)
			{
				temp=s[j+1];
				s[j+1]=s[j];
				s[j]=temp;
				
			}
		}
	}
	//printf("loop finished");
}



void findCompletionTime()
{  

    //printf("here");
	int index;
	int flag=0;
	int i =s[0].arrivalTime;
	
	while(1)
	{
		index = findBiggest(i);
		
	     printf("student taking food at time %d is : student_id %d\n",totalTime,s[index].student_id);
	     s[index].FoodTime-=1;
	     totalTime+=1;
	     i++;
	     
	     if(s[index].FoodTime==0)
	     {
	     	s[index].completionTime=totalTime;
	     	printf("\nstudent %d has completed taking his food at time %d\n",s[index].student_id,totalTime);
	     	
		 }
		 if(totalTime == time)
		   break;
	     
	}
}

int findBiggest(int t)
{  int max=0,i;
	for(i=0;i<n;i++)
	{
		if(s[i].arrivalTime<=t)
		{
			if(s[i].FoodTime>s[max].FoodTime)
			    max=i;
			else
			if(s[i].FoodTime==s[max].FoodTime)
			    {
				if(s[i].student_id<s[max].student_id)
			            max=i;}
		}
	}
	return max;
}
