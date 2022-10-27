#include<stdio.h>
#include<stdlib.h>
#include<struct.h>
#include<functions.h>
#include<string.h>
#include<macros.h>
r_reg *r1=NULL;
void search()
{
	FILE *fp;
	fp=fopen("../data/donor.txt","r");
	r_reg *r1=(r_reg *)calloc(1,sizeof(r_reg));
	reg r;
	char bgroup[MAX];
	printf("\nEnter the blood group:");
	/*fgets(r1->bgroup,MAX,stdin);
	r1->bgroup[strlen(r1->bgroup)-1]='\0';
	*/
	scanf("%s",r1->bgroup);
	if(strcmp(r1->bgroup,r.bgroup)==0)
	{
		printf("%lld %s %d %s %d",r.aadharno,r.dname,r.age,r.bgroup,r.phno);
	}
	else
		printf("\nEnter valid blood group");
}


