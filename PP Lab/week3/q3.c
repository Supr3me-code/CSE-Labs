#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <string.h>
int main(int argc, char* argv[])
{
	int rank,size;
	int res;
	int s;
	MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    char st[100];
    char* c=(char*)malloc(sizeof(char)*100);
    int* b=(int*)malloc(size*sizeof(int));
    if(rank==0)
    {
    	scanf("%s",st);
    	int k=strlen(st);
    	if(k%size!=0)
    	{
    		printf("String length should be divisible by the number of processes.");
    		return 0;
    	}
		s=k/size;
	}

	MPI_Bcast(&s,1,MPI_INT,0,MPI_COMM_WORLD);
	MPI_Scatter(st,s,MPI_CHAR,c,s,MPI_CHAR,0,MPI_COMM_WORLD);
	res=0;

	for(int i=0;i<s;i++)
	{
		// printf("%c",c[i]);
		if(c[i]=='a'||c[i]=='e'||c[i]=='i'||c[i]=='o'||c[i]=='u')
			continue;
		res+=1;
	}

	// printf("\nProcess[%d]: Non vowel count is %d\n",rank,res);
	MPI_Gather(&res,1,MPI_INT,b,1,MPI_INT,0,MPI_COMM_WORLD);
	if(rank==0)
	{
		res=0;
		for(int i=0;i<size;i++)
		{
			res+=b[i];
		}
		printf("The total number of non vowels is:%d\n",res);
    }	
    
    MPI_Finalize();
}	