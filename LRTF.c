#include<unistd.h>
#include<stdio.h>

struct student                       // structure for details of each student
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
void calculate();                                  //function declaration
void findCompletionTime();
void input();
void init();


struct student s[50];                //global variables
int totalTime=0;                                   
int time=0;
int totalWT;
int totalTAT;
int n=3;                           //total no of student by default 3


 
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
	
	sort();
	totalTime+=s[0].arrivalTime;
	
	time+=s[0].arrivalTime;
	findCompletionTime();
	calculate();
	display();	
}

void init()
{   printf("first here");
    int i,j;
    s[0].student_id=2132;  
    s[1].student_id=2102;                                                      //function to initialise with default values
    s[2].student_id=2453;
	for(i=2,j=0;i<=8;i=i*2,j++)
	{
		s[j].arrivalTime=0;
		s[j].FoodTime=i;
		s[j].backUp=s[j].FoodTime;
		time+=s[j].FoodTime;
	}
	
}

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

void display()
{
	int i;
	for(i=0;i<n;++i)
	{
		printf("\nstudent_id %d",s[i].student_id);
		printf("\nstudent foodtime %d",s[i].backUp);                                             //function to display values
		printf("\nstudent arrival time %d",s[i].arrivalTime);
		printf("\nstudent completion time %d",s[i].completionTime);
		printf("\nstudent waiting time %d",s[i].waitingTime);
		printf("\nstudnt turn around time %d\n\n",s[i].turnAroundTime);
	}
	printf("\naverage total TAT %.3f ms",totalTAT/(float)n);
    printf("\naverage waiting time %.3f ms",totalWT/(float)n);
	
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
   
    
	for(i=0;i<n-1;++i)
	{
		for(j=0;j<n-i-1;j++)
		{   
			if(s[j].arrivalTime>s[j+1].arrivalTime)
			{
				temp=s[j+1];
				s[j+1]=s[j];
				s[j]=temp;
				
			}
		}
	}

}




void findCompletionTime()
{  

    //printf("here");
	int index;
	int flag=0;
	int i =s[0].arrivalTime;
	int t=totalTime;
	
	while(1)
	{
		index = findBiggest(i);
		if(index!=-1)
	     {
		 printf("\nstudent taking food at time %d is : student_id %d\n",i,s[index].student_id);
	     s[index].FoodTime-=1;
	     totalTime+=1;
	     //t+=1;
	     i++;}
	     else
	      {
		  i++;
	      }
	     
	     if(s[index].FoodTime==0 && index!=-1)
	     {  printf("%d\n",index);
	     	s[index].completionTime=i;
	     	printf("\nstudent %d has completed taking his food at time %d\n",s[index].student_id,i);
	     	
		 }
		 if(totalTime == time)
		   break;
	     
	}
}

int findBiggest(int t)
{  int max=0,i;
	for(i=0;i<n;i++)
	{
		if(s[i].arrivalTime<=t &&(s[i].FoodTime!=0))
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
	if(s[max].FoodTime!=0)
	return max;
	else
	return -1;
}
