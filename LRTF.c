#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

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
    printf("press :\n");
	printf("1 :-> to enter  manually(for test cases) \n\n2 :-> to take default values(given in question)\n");
	scanf("%d",&ch);
	switch(ch)
	{case 1: input();
	         display(0);
	       break;
	case 2: init();
	         display(0);
	        break;
   default:printf("\nwrong input\n");
            exit(1);
	}
	
	sort();
	totalTime+=s[0].arrivalTime;
	
	time+=s[0].arrivalTime;
	printf("\n------------------------------Food Taking Order------------------------------------------------------\n");
	findCompletionTime();
	calculate();
	display(1);	
}

void init()
{   system("cls"); 
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
	  system("cls");                                         
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
	system("cls");
}

void display(int f)
{
	int i;
	printf("\n------------------------------Values-------------------------------------------------------------");
	for(i=0;i<n;++i)
	{   
		printf("\n\nstudent_id: %d",s[i].student_id);
		printf("\nstudent foodtime: %d ms",s[i].backUp);                                             //function to display values
		printf("\nstudent arrival time: %d ms" ,s[i].arrivalTime);
		if(f==0)
		continue;
		printf("\nstudent completion time: %d ms",s[i].completionTime);
		printf("\nstudent waiting time: %d ms",s[i].waitingTime);
		printf("\nstudnt turn around time: %d ms\n\n",s[i].turnAroundTime);
		
	}
	if(f==1)
	{
	printf("\naverage total TAT: %.3f ms",totalTAT/(float)n);
    printf("\naverage waiting time: %.3f ms",totalWT/(float)n);
    }
	
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
    
    
	int index;
	int flag=0;
	int i =s[0].arrivalTime;

	
	while(1)
	{
		index = findBiggest(i);
		if(index!=-1)
	     {
		 printf("\nAt time t = %d :=> student %d is taking food\n",i,s[index].student_id);
		 //printf("%d:",s[index].student_id);
	     s[index].FoodTime-=1;
	     totalTime+=1;
	     
	     i++;}
	     else
	      {
		  i++;
	      }
	     
	     if(s[index].FoodTime==0 && index!=-1)
	     {  
	     	s[index].completionTime=i;
	     	printf("\n==>student %d has completed taking his food\n",s[index].student_id);
	     	
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
