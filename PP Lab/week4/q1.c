#include "mpi.h"
#include <stdio.h>
#include <string.h>

int main(int argc,char* argv[])
{
	int rank, size,ierr;
	int i = 0;
	int res = 0,fact = 1;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Errhandler_set(MPI_COMM_WORLD,MPI_ERRORS_RETURN);

	for (i = 1;i <= rank+1;i++) 
    {
		fact = fact*i;
	}
	MPI_Scan(&fact,&res,1,MPI_INT,MPI_SUM,MPI_COMM_WORLD);
	if (rank == size-1) 
    {
	    printf("%d\n",res);
	}
	MPI_Finalize();
	return 0;
}