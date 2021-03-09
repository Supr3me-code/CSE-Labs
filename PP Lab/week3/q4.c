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
    char st1[100];

    char* a=(char*)malloc(sizeof(char)*100);
    char* b=(char*)malloc(100*sizeof(char));
    char* c=(char*)malloc(199*sizeof(char));
    char* fst=(char*)malloc(sizeof(char)*200);

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
		scanf("%s",st1);
	}

	MPI_Bcast(&s,1,MPI_INT,0,MPI_COMM_WORLD);
	MPI_Scatter(st,s,MPI_CHAR,a,s,MPI_CHAR,0,MPI_COMM_WORLD);
	res=0;
	MPI_Scatter(st1,s,MPI_CHAR,b,s,MPI_CHAR,0,MPI_COMM_WORLD);

	for(int i=0;i<s;i++)
	{
		c[i*2]=a[i];
		c[i*2+1]=b[i];
	}

	MPI_Gather(c,2*s,MPI_CHAR,fst,2*s,MPI_CHAR,0,MPI_COMM_WORLD);

	if(rank==0)
	{
		printf("%s\n",fst);
    }	
    
    MPI_Finalize();
}	