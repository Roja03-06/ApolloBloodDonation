#include<stdio.h>
#include<stdlib.h>
#include<functions.h>
#include<macros.h>
#include<struct.h>
#include<string.h>
int view_receiver()
{
	
	FILE *fr;
	fr=fopen("../data/receiver.txt","r");
	if(fr==NULL)
	{
		printf("File doesnot exist ");
		 return EXIT_FAILURE;
	}
	else
	{
		char rname[MAX],bgroup[MAX];
		int age,phno;
		long long aadharno;
		printf("\n*****************************************\n");
		printf("            DETAILS OF RECEIVER                  ");
		printf("\n*****************************************\n");
	        r_reg *start=NULL;
	 	printf("\n%-10s%-10s%-10s%-20s%-10s","Aadharno","Receiver Name","Age","Blood Group");
		fscanf(fr,"%lld%s%d%s",&aadharno,rname,&age,bgroup);
		while(!feof(fr))
		{
			r_reg *temp = (r_reg *) calloc(1,sizeof(r_reg));
			temp->aadharno = aadharno;
			strcpy(temp->rname,rname);
			temp->age = age;
			strcpy(temp->bgroup,bgroup);
			temp->link = NULL;
			if(start == NULL)
			{
				start = temp;
			}
			else
			{
				r_reg *q = start;
				while(q->link != NULL)
					q = q->link;
				q->link = temp;
			}
			fscanf(fr,"%lld%s%d%s",&aadharno,rname,&age,bgroup);

		}
		
		r_reg *q = start;
		while(q!=NULL)
		{
			printf("\n%-lld %-20s %-10d %-10s ",&q->aadharno,q->rname,&q->age,q->bgroup);

			q=q->link;
		}
		fclose(fr);
	}
	menu_admin();
}

	




	         
                
