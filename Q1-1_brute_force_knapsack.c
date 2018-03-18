#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 int n=0;				
 int cap=0;			
 int last[100];
 int chk =0,flag=0;
 int power(int x, int n)
 {
 	if(chk==0)
 	{
 	flag++;
 	int result = 1;
 	int i;
 	for(i=0;i<n;++i)
 	if(chk==0)
 	{
 		flag++;
 		result *= x;
 	}
 	return result;
   }
 }
void data(char *file, int *weight, int *profit)
{
   	if(chk==0)
   	{
   	flag++;
	FILE *fp;
   	size_t buffer =0 ;
	char *tok;
	char *line = NULL;
 	fp = fopen(file, "r");

	if(!fp) {
		if(chk==0)
		flag++;
		printf("File does not exist. \n"); 
		exit(0);
	}

	if(chk==0) 
	flag++;
	//printf("%d",flag);
	getline(&line, &buffer, fp);
	n = atoi(line);

	int j=0;
	if(chk==0)
	flag++;
	getline(&line, &buffer, fp);	
	tok = strtok(line,",");
	while(tok!=NULL)
	{
		if(chk==0)
		flag++;
		weight[j]=atoi(tok);
		j++;
		tok = strtok(NULL, ",\n");
	}
	

	//Profits of n items.
	j=0;
	if(chk==0)
	flag++;// checking if 0 or not then incrementing the value of flag
	getline(&line, &buffer, fp);	
	tok = strtok(line,",");
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
	getline(&line, &buffer, fp);	
	cap = atoi(line);

	fclose(fp);
  }
}
void read(char *file)
{
	FILE *fp;
   	size_t buffer =0 ;
	char *line = NULL;
 	fp = fopen(file, "r");

	if(!fp) {
		if(chk==0)
		flag++;
		printf("File does not exist. \n"); 
		exit(0);
	}
	if(chk==0)
	flag++;
	getline(&line, &buffer, fp);
	n = atoi(line);
	
	fclose(fp);
	
}

void result(int weight, int profit, int *last)
{
	int k, stack = 0;
	printf("Max Weight-> %d\n", weight);
	printf("Max Profit-> %d\n", profit);
	printf("Items included-> ");
if(chk==0)
flag++;
{
	for (k = 0; k < n; k++) 
	{
        if (last[k] == 1 && stack == 0) 
        {	if(chk==0)
        	flag++;
            printf("%d",k);
            stack = 1;
        }else if(last[k] == 1 )
        {
        	if(chk==0)
        	flag++;
        	printf(", %d",k);
        }
	}
	printf("\n");
}	
}

void brute(int *weight, int *profit)
{	
	int posval;
    int i,mw=0,mp=0,k,brut[n];
    last[n];

    if(chk==0)
    flag++;
	for (i = 0; i < n; ++i)
	{
		if(chk==0)
		flag++;
		brut[i]=0;
	}
	if(chk==0)
	flag++;
    for (i = 0;i<power(2,(n+1)); i++) 
    {
        int j = n,tw = 0,tp = 0,value=0;
		if(value==0)
		j = 0;
		while(brut[j] != 0 && j<n)
		{
			if(chk==0) 
			flag++;  // checking whether it enters here or not
			brut[j] = 0;
			j++;			
		}
		brut[j] = 1;
	if(chk==0)
		flag++;
        for (k = 0; k < n; k++) 
        {	if(chk==0)
        	flag++;
            if (brut[k] == 1) 
            {
            	if(chk==0)
            	flag++;
                tw = tw + weight[k];
                tp = tp + profit[k];
            }
        }

        if (tp > mp && tw <= cap) 
        {
        	if(chk==0)
        	flag++;
            mw = tw;
            mp = tp;            
            for (k = 0; k < n; k++) 
        	 	last[k]=brut[k];	        
        }
    }

result(mw, mp, last);
   
}
int main(int argc, char *argv[])
{
	
	if(argc != 2)
	{
		if(chk==0)
		flag++;
	    printf(" Use -> ./brute.out <filename>\n");
	    exit(0);
	}
if(chk==0)
{
	flag++;
	char *file = argv[1];
	read(file);
	int negval;
	int *weight = malloc(n* sizeof(int));
	int *profit = malloc(n* sizeof(int));
	if(chk==0)
	flag++;
	data(file,weight,profit);
	brute(weight,profit);
	return 0;
}
}



