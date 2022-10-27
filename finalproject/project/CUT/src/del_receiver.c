#include<stdlib.h>
#include<stdio.h>
#include<functions.h>
#include<struct.h>
void del_receiver()
{
	
	int found=0;
	long long aadharno;
	FILE *fp=fopen("../data/receiver.txt","r");
	printf("enter the aadhar number to delete the record");
	scanf("%lld",&aadharno);
	reg *head=NULL,*current=NULL;
	current=head;
	if(current->aadharno==aadharno)
	{
		head=current->link;
		free(current);
		found=1;
	}
	while(current->link!=NULL)
	{
		reg *tmp=current->link;
	        if(tmp->aadharno==aadharno)
		{
			current->link=tmp->link;
			free(tmp);
			found=1;
			break;
		}
		current=current->link;
	}
	if(found)
	{
		printf("\n\nThe Record is deleted Successfully");
	}
	else
	{
		printf("\nrecords Not found");
	}
	menu_admin();
	fclose(fp);
}
