#include "mpi.h"
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]){
	int rank;
	int a = 7, b=3;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	//calculator functions
	if(rank == 0){
		printf("multiplication: %d\n",a*b);
	}
	else if(rank == 1){
		printf("addition: %d\n",a+b);
	}
	else if(rank == 2){
		printf("division: %d\n",a/b);
	}
	else{
		printf("subtraction: %d\n",a-b);
	}
	MPI_Finalize();
		return 0;
}