#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[]){
	int rank,size,number;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Status status;

	if(rank == 0){
		printf("enter a number: ");
		scanf("%d\n",&number);
		for(int i=1;i<=3;i++){
			MPI_Send(&number,1,MPI_INT,i,1,MPI_COMM_WORLD);
			fprintf(stdout,"process(0): sent to process %d\n",i);
		}
		fflush(stdout);
	}

	else if(rank==1){
		MPI_Recv(&number,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
		fprintf(stdout,"process(1): recieved from root: %d\n",number);
		fflush(stdout);
	}

	else if(rank==2){
		MPI_Recv(&number,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
		fprintf(stdout,"process(2): recieved from root: %d\n",number);
		fflush(stdout);
	}

	else if(rank==3){
		MPI_Recv(&number,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
		fprintf(stdout,"process(3): recieved from root: %d\n",number);
		fflush(stdout);
	}
	MPI_Finalize();
	return 0;
}