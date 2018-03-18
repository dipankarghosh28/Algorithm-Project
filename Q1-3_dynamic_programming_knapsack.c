
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n=0,capa=0,mw=0,mp=0,cnt=0,chk=0,add[50],set[50],soln[50][2];
int flag=0;
//use chk to check whether it enters a particular loop or not
void Read(char *file)
{
   	
	FILE *fp;
	int negval=0,count=0;
	if(negval==0)
	count++;
   	size_t buffer =0 ;
	char *lin = NULL;
 	fp = fopen(file, "r");

	if(!fp) 
	{
		if(chk==0)
		flag++;
		printf("File does not exist. \n"); 
		exit(0);
	}

	if(chk==0)
	getline(&lin, &buffer, fp);
	flag++;

	n = atoi(lin);
	fclose(fp);
	
}

void data(char *file, int *weight, int *profit)
{
   	int val1;
	FILE *fp;
   	size_t buffer =0 ;
	flag=flag+1;
	char *tok;
	char *lin = NULL;

 	fp = fopen(file, "r");

	if(!fp) 
	{
		if(chk==0)
		flag++;
		printf("File is not present. \n"); 
		exit(0);
	}

	if(chk==0)
	flag++;
	getline(&lin, &buffer, fp);
	n = atoi(lin);
	
	int j=0;
	if(chk==0)
	flag++;
	getline(&lin, &buffer, fp);	
	tok = strtok(lin,",");

	while(tok!=NULL)
	{	
		if(chk==0)
		weight[j]=atoi(tok);
		j++;
		tok = strtok(NULL, ",\n");
	}	

	j=0;
	if(chk==0)
	flag++;
	getline(&lin, &buffer, fp);	
	tok = strtok(lin,",");
	while(tok!=NULL)
	{
		if(chk==0)
		flag++;
		profit[j]=atoi(tok);
		j++;
		tok = strtok(NULL, ",\n");
	}

	if(chk==0)
	flag++;
	getline(&lin, &buffer, fp);	
	capa = atoi(lin);
	
	fclose(fp);
}


void sort(int *weight, int *profit)
{	
	int val;
	int i,j,tempp,tempw,temp;
	
	for (i = 0; i < n; ++i)
	{flag++;
		for (j = 0; j < i; ++j)
		{flag++;
			if (profit[j]<profit[j+1])
			{flag++;
				if(chk==0)
				{
				tempp=profit[j];
				flag=flag+1;
				profit[j]=profit[j+1];
				profit[j+1]=tempp;

				tempw=weight[j];
				weight[j]=weight[j+1];
				flag=flag+1;
				weight[j+1]=tempw;
				
				temp = soln[j][1];
				soln[j][1] = soln[j+1][1];
				flag=flag+1;
				soln[j+1][1] = temp;
				}
				flag++;
			}
		}
	}
}

double KWF2(int *weight,int *profit,int i,int wt, int prof)
{
	if(chk==0)
	{
	flag++;
	int x[n],j,value=0;
	double bound = prof;
	for(j=i;j<n;j++)
   	x[j] = 0; 			
  	flag++;
	while (wt < capa && i <= n)		
	{        
		if(chk==0)
		{
		flag++;
	    if(wt + weight[i] <= capa)            
	    {
	    	if(chk==0)
	         x[i]=1;                   	
	         wt = wt + weight[i]; 
	         bound = bound +profit[i];
	    }
	   	else
	   	{
	   		if(chk==0)
	        x[i]=(capa - wt)/weight[i];		     
	        bound = bound + profit[i]*x[i];
	    }
	flag++;
   	i= i+1;			
   	}                            
	return bound;
	}
  }
}
typedef enum { false, true } bool;
bool promise(int *weight,int *profit,int i,int prof, int wt)
{
	int val2;
	int j,k,flag1=0;
	int totalWeight;
	double bound;

	if(wt>=capa)
	{
	if(chk==0)
	flag++;
	return false;
	}
	else
	{
			if(chk==0)
			bound = KWF2(weight,profit,i+1,wt, prof); 
			return (bound>mp);
			flag++;
		}
}


void dynamicp(int *weight, int *profit, int i, int prof, int wt)
{

	if(wt<=capa && prof>mp && chk==0)
	{
		int i;
		mw=wt;
		mp=prof;
		
		flag++;
		for(i=0;i<50;i++)			
			{	if(chk==0)
				set[i] = add[i];
			}
	}
	bool isreal=promise(weight,profit,i,prof,wt);	
	
	if(isreal)
	{
		if(chk==0)
		{
		flag=flag+1;
		add[cnt++] = 1;
		flag=flag+1;
		//printf("backtrack1\n");
		if(chk==0)
		flag++;
		dynamicp(weight,profit,i+1,prof+profit[i+1],wt+weight[i+1]); 
		flag=flag+1;
		add[cnt++] = 0;
		if(chk==0)
		//printf("backtrack2\n");
		dynamicp(weight,profit,i+1,prof,wt);
		flag=flag+1;
	    }
	}
}

int main(int argc, char *argv[])
{
 	
 	if(argc != 2)
    {
    	if(chk==0)
    	{
        printf("./dynamicp.out filename\n");
        flag++;
        exit(0);
      }
    }

	char *file = argv[1];
	Read(file);
	int i,j;
	int *weight = malloc(n* sizeof(int));
	int *profit = malloc(n* sizeof(int));


	for(i=0;i<50;i++)
	{
		if(chk==0)
		add[i] = -1;
		set[i] = -1;
		flag=flag+1;
	}
	
	data(file,weight,profit);

	int *wtem = malloc(n* sizeof(int));
	for(i=0;i<n;i++)
		{flag++;
		wtem[i] = weight[i];
		}
	for(i=0;i<50;i++)
	{
		flag++;
		for(j=0;j<2;j++)
		{
				if(chk==0)
				soln[i][0] = i;
				soln[i][1] = i;
		}
	}
	
	sort(weight,profit);
    printf("sorting done then calculation\n");
	dynamicp(weight,profit,-1,0,0);
	
	printf("Max Weight-> %d\n", mw);
	printf("Max Profit-> %d\n", mp);

	int *ta = (int *)malloc(n* sizeof(int));
	for(i=0;i< n;i++ )
		{	flag++;
		ta[i] = 100;
		}
	for(i=0;i<50; i++){
		flag++;
		if(set[i] == 1)
			ta[i] = soln[i][1];
	}
	if(chk==0)
	for (i = 0; i < n; ++i)
	{flag++;
		for (j = 0; j < i; ++j)
		{flag++;
			if (ta[j]>ta[j+1])
			{
				if(chk==0)
				{
				flag++;
				//printf("%d",flag);
				int temp=ta[j];
				flag=flag+1;
				ta[j]=ta[j+1];
				ta[j+1]=temp;
			    }
		    }
		}
	}
	printf("Items included are -> ");
	flag++;
	for( i=0;i<n;i++)
	{flag++;
		if(chk==0)
		{
		flag++;
		if(ta[i] == 100) break;
		if(ta[i+1] == 100)
		{
		flag++;
		printf("%d", ta[i]);
		}
		else 
		{
		flag++;	
		printf("%d, ", ta[i]);
		}
	   }
	}
	printf("\n");
	printf("Both brute & dynamic programming  give the same output/profit on comparing\n");
 	return 0;
}


