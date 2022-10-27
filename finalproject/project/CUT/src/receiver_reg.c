#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<struct.h>
#include<functions.h>
#include<macros.h>
void receiver_reg()
{
	FILE *log,*fp;
	fp=fopen("../data/receiver.txt","a");
	
	if(fp==NULL)
	{
         	printf("\nFile does not Exist");
	        return;
	}
	else
	{

		reg r;
		r_reg *start=NULL;
		r_reg *m=(r_reg *)calloc(1,sizeof(r_reg));
	        
		printf("\n****************************************************************\n");
		printf("                        Registration Form                           ");
        	printf("\n****************************************************************\n");
		log=fopen("../data/donor.txt","r");
                while(fscanf(log,"%lld%s%d%s%s%d",&r.aadharno,r.dname,&r.age,r.bgroup,&r.phno,&r.units))
	        {
      			while(1)
			{
	       	 		printf("\nEnter your Aadhar Number : ");
	        		scanf("%lld",&m->aadharno);
		          	long temp=m->aadharno;
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
                        if(r.aadharno==m->aadharno)
				printf("\n Regstration unsuccessful");
		        else
			      break;
			fclose(log);
		}
			getchar();
		while(1)
		{
			printf("\nEnter Your Name : ");
        		fgets(m->rname,MAX,stdin);
                	m->rname[strlen(m->rname)-1]='\0';
			if(isvalidate(m->rname))
				break;
			else
			{
				printf("Invalid name");
		        	
			}
		}
		while(1)
		{
			printf("\nEnter your age : ");
        		scanf("%d",&m->age);
			if(isdigit(m->age))
					return;
			else
				break;
		}
		while(1)
		{
			printf("\nEnter your blood group:");
			scanf("%s",m->bgroup);
		       break;			

		
		}

		m->link = NULL;
		if(start == NULL)
		{
			start = m;
			fprintf(fp,"%lld %s %d %s\n",m->aadharno,m->rname,m->age,m->bgroup);	
		}
		else
		{
			r_reg *q = start;
			while(q!=NULL)
				q = q->link;
			q->link = m;
			fprintf(fp,"%lld %s %d  %s\n",m->aadharno,m->rname,m->age,m->bgroup);	
		}
		printf("\nWelcome %s !!!\n",m->rname);
		printf("Thank you for Registration with us !!!");
	}
	fclose(fp);
	menu();
}




