#include<stdio.h>
#include<stdlib.h>
#include<functions.h>
#include<macros.h>
#include<struct.h>

void donate( )
{
	long long dadno , radno ;
	int no;
	FILE *fw1 = fopen("donate.txt","a");
	printf("\nEnter Aadhar number of donor ");
	scanf("%lld",&dadno);
	printf("\nEnter Aadhar number of reciever ");
	scanf("%lld",&radno);
	printf("\nEnter number of units to be donated ");
	scanf("%d",&no);
	if(dadno != radno)
	{	
	FILE *fr = fopen("donor.txt","r");
	FILE *fw = fopen("temp2.txt","w");

	long long adno;
	int units , ag;
	char name[20],bg[20];
	fscanf(fr,"%lld%s%d%s%d",&adno,name,&ag,bg,&units);
	
	while(!feof(fr))
	{
		if(dadno == adno)
		{
			units = units-no;
			fprintf(fw,"%lld %s %d %s %d\n",adno,name,ag,bg,units);			
		}
		else
			fprintf(fw,"%lld %s %d %s %d\n",adno,name,ag,bg,units);					
		fscanf(fr,"%lld%s%d%s%d",&adno,name,&ag,bg,&units);
	}
	fclose(fr);
	fclose(fw);
	remove("../data/donor.txt");
	rename("../data/temp2.txt","../data/donor.txt");	
	fprintf(fw1,"\n%lld %lld %d",dadno,radno,no);
	fclose(fw1);
	}
	else
		printf("Aadhar number of reciever and donor cannot be same ");	
}
