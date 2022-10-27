#include<stdlib.h>
#include<stdio.h>
#include<functions.h>
#include<struct.h>
#include<string.h>
#include<macros.h>
typedef struct node1
{
	long long aadharnum;
}n;
void update_receiver()
{
	r_reg *start=NULL;
    FILE *fw=fopen("../data/receiver.txt","a");
    long long aadharnum;
    n *temp=(n *)calloc(1,sizeof(n));
    r_reg *current=(r_reg *)calloc(1,sizeof(r_reg));
    r_reg r1;
    n n1;
    printf("enter your aadhar number ");
    scanf("%lld",&n1.aadharnum);
    current=start;
    void updateReceiverName()
    {
               while(current!=NULL)
               {
                	if(n1.aadharnum==r1.aadharno)
                	{
               			printf("\nEnter First Name:");
               			fgets(current->rname,MAX,stdin);
			        current->rname[strlen(current->rname)-1]='\0';
			}
               }
               current=current->link;
    }
    void updateage()
    {
                while(current!=NULL)
                 {
                    	if(n1.aadharnum==r1.aadharno)
                        {
                           	printf("\nEnter age:");
                           	scanf("%d",&current->age);
                          
                        }
                 }
                 current=current->link;
    }
    void updatePhno()
    {
	    while(current!=NULL)
	    {
		    if(n1.aadharnum==r1.aadharno)
		    {
			    printf("\nEnter the contact Numer:");
			    scanf("%d",&current->phno);
		    }
	    }
    }

       /*void updateGender()
    {
                while(current!=NULL)
                 {
                    	if(n1.aadharnum==r1.aadharno)
                        {
                    		      printf("\nEnter Gender : ");
			              scanf("%s",current->gender);
                        }
                 }
                 current=current->link;
    }
    */
    while(current!=NULL)
    {
      		if(n1.aadharnum==r1.aadharno)
      		{
        		int choice;
        		printf("\n1:update the Receiver Name\n 2:update the age\n 3:update the contact number\n");
        		printf("enter your choice to be update");
        		scanf("%d",&choice);
        		switch(choice)
        		{
           			case 1: updateReceiverName();
                   			break;
           			case 2: updateage();
                    			break;
           			case 3: updatePhno();
                     			break;
                   		
			}
		}
      			current=current->link;
    }
    fwrite(current,1,sizeof(current),fw);
    menu_admin();
}  
