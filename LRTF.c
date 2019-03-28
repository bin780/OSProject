#include<unistd.h>
#include<stdio.h>

struct student     // structure for details of each student
{
	int student_id;
	int arrivalTime;
	int FoodTime;
};
student input()
{
	                                           
	int n,i;
	printf("\nenter the number of students\n");
	scanf("%d",n);
	struct student s[n];   
	for(i=0;i<n;++i)                                                             //function to take custom input
	{
		printf("\nenter the student id of student %d : ",i+1);
		scanf("%d",s[i].student_id);
		printf("\nenter the arrival time of student %d :",i+1);
		scanf("%d",s[i].arrivalTime);
		printf("\nenter the food taking time of student %d :",i+1);
		scanf("%d",s[i].FoodTime);
	}
	return s;
}
student init()
{
    struct student s;
    int i;
    s[0].student_id=2132;  
    s[1].student_id=2102;                                                      //function to initialise the values
    s[2].student_id=2453;
	for(i=2;i<=8;i*2)
	{
		s[i].arrivalTime=0;
		s[i].FoodTime=i;
	}	
} 
int main()
{
	
}
