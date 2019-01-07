#include<stdio.h>
main()
{
FILE *ptr;	     //this is file pointer to access the below used files
char arr[100];	//this array is to store the complaints
int n;	        //this will take the prefrence
pin=12345;	    //the default password
int x;	//this will take the password input
int a;

printf("\n\n\n\n\n\n\n");
printf("\n\t\t1.Account Details");
printf("\n\t\t2.Eligibility criteria");
printf("\n\t\t3.Card Holders");
printf("\n\t\t4.Customser Support");
printf("\n\t\tEnter the prefrence : ");

scanf("%d",&n);
switch(n)
{
case 1:
{
int roll;	  //to store roll
int cibil;	//to store CIBIL
int x;	    //to store password
char name[20];

printf("\n\t\t****1.Account Details****");
printf("\n\t\tEnter the pin : ");
scanf("%d",&x);

if(x==pin)
{
ptr=fopen("database.txt","r");
while(fscanf(ptr,"%d %s %d",&roll,name,&cibil)!=EOF) //scans the every roll,name of account holder and their respected cibil values from the databse
{
printf("%d %s %d",roll,name,cibil);                  //prints the same
}
}

else
{
	printf("\n\t\tOOPS Wrong pin!");                    //if the pin fails
}	
break;		
}

case 2:		
{		
FILE *ptr;		
struct emp{		
char accno[15];	    //to store the acc.no	
char name[20];    	//to store acc. holder's name	
int cibil;	        //to store CIBIL	
char ifsc[50];	    //to store the ifsc	
char type[20];	    //to store the type of account	
float bal;	        //to store the balance	
char credicardstatus[5];
}e;
ptr=fopen("selected.txt","r");
if(ptr==NULL)
{
 printf("Cannot open file");
}

else
{
printf("\n\n\n\n\n\n");
printf("**********THE BELOW MENTIONED ARE THE SELECTED CUSTOMERS FOR CREDIT CARD**********\n\n");
while(fscanf(ptr,"%s %s %d %s %s %f %s",e.accno,e.name,&e.cibil,e.ifsc,&e.type,&e.bal,e.credica rdstatus)!=EOF) //this will scan for the entire information
 {
  if(e.cibil>400&&!strcmp(e.credicardstatus,"no")   //our criteria
  {
   printf("%s %s %d %s %d %f\n",e.accno,e.name,e.cibil,e.ifsc,e.type,e.bal);
}
}
}
fclose(ptr);
printf("\n**********For the above mentioned customers the auto generanted msg has been sent***********");
break;
}

case 3:
{
 FILE *ptr;
 long	int p;
 score=0;
 int flag=0;
 struct emp{
 char accno[15];
 int cb_score;   //to store the points
 long int salary;
 char job[5];
}e,*q;
char account[15];
ptr=fopen("interest.txt","r");
if(ptr==NULL){
printf("Cannot open file");
}
printf("\n\t\tEnter the account number: ");
scanf("%s",account);
while(fscanf(ptr,"%s %d",e.accno,&e.cb_score)!=EOF) //here the scanf reads nly the accno and corresponding cibil score
{
if(strcmp(account,e.accno)==0)
{
printf("\n\t\tThe CIBIL Score is: %d",e.cb_score);
printf("\n\t\tEnter the salary : ");
scanf("%ld",&e.salary);
printf("\n\t\tEnter the job : ");
scanf("%s",e.job);
e.salary=e.salary/100;	
p=e.salary+e.cb_score;
if(strcmp(e.job,"govt")==0)
{
 p+=100;
}

else
{
p+=50;
}

score=p*100;
printf("\n\t\tThe Credit limit will be: %ld",score);
flag=1;
break;
}
}

if(flag==0)
printf("\n\t\tINVALID ACCOUNT NUMBER!");

if(flag==1)
{
if(score>50000&&score<=100000)
printf("\n******Silver Card******");
else if(score>100000&&score<=200000)
printf("\n******Gold Card******");

else
printf("\n******Platinum Card******");
fclose(ptr);
break;
}

case 4:
{
printf("\n\t\t*****4.Customser Support*****");
printf("\n\t\tYour issues: ");
gets(arr);
printf("******Your issues are recorded and our team working on it and will update you soon*******");
break;
}

default:
{
printf("\nSorry You entered wrong input!")	;
}
}
}
