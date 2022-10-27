#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<struct.h>
#include<functions.h>
#include<macros.h>
int donor_reg()

{
	FILE *log;
	log=fopen("../data/donor.txt","a");
	if(log==NULL)
	{
         	printf("\nFile does not Exist");
	        return EXIT_FAILURE;
	}
	else
	{
	        reg *start = NULL;
		reg *node=(reg *)calloc(1,sizeof(reg));
		printf("\n****************************************************************\n");
		printf("                        Registration Form                           ");
        	printf("\n****************************************************************\n");

      		while(1)
		{
	       	 	printf("\nEnter your Aadhar Number : ");
	        	scanf("%ld",&node->aadharno);
		          long temp=node->aadharno;
			  int d=0;
                          while(temp>0)
		       	  {
			  temp=temp/10;
	        	  d++;
        	          }
			  if(d<12 || d>12)
			   {
		
	               		 printf("\nAadhar is not valid !!!Please try Again ");
				continue;
			   }
			  else
				break;
		}
		getchar();
                while(1)
		{
			printf("\nEnter Your Name : ");
	                fgets(node->dname,MAX,stdin);
			node->dname[strlen(node->dname)-1]='\0';
			if(isvalidate(node->dname))
				
				break;
			else
			{
				printf("\nName is not valid !!! ");
			
			}
		}
		while(1)
		{
			printf("\nEnter your age : ");
        		scanf("%d",&node->age);
			if(node->age < 18)
			{
				printf("\nYou are Not eligible for the registration!! ");
				return 0;
			}
			else if(isdigit(node->age))

				return 0;
			else
				break;
		}
   		while(1)
   		{
   			printf("\nEnter your blood group: ");
   			scanf("%s",node->bgroup);
 			/*if(node->bgroup=="A+" || node->bgroup=="B+" || node->bgroup=="O+" || node->bgroup=="AB+" || node->bgroup=="A-" || node->bgroup=="B-" || node->bgroup=="AB-" || node->bgroup=="O-")
                                     break;
                        else
                        {
                               printf("\nInvalid Blood Group Please Try Again!!!");
                                  continue;
			}
		*/
		break;	
  		}

   				
	      
	
	
	
	        while(1)
   		{
    			printf("\nEnter the number of units you need to donate:");
    			scanf("%d",&node->units);
			if(node->units>5)
			{
				printf("You are not allowed to donate 5 units");
	       		        continue;
			}
			else
				break;
    
  		}

		node->link = NULL;
		if(start == NULL)
		{
			start = node;
			fprintf(log,"%lld %s %d %s  %d\n",node->aadharno,node->dname,node->age,node->bgroup,node->units);	
		}
		else
		{
			reg *q = start;
			while(q!=NULL)
			q = q->link;
			q->link = node;
			fprintf(log,"%lld %s %d %s  %d \n",node->aadharno,node->dname,node->age,node->bgroup,node->units);	
		}

		printf("\nWelcome %s !!!\n",node->dname);
		printf("Thank you for Registration with us !!!");
		
	}
	fclose(log);
	menu();
}
