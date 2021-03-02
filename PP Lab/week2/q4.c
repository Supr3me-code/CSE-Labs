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
		scanf("%d",&number);
		MPI_Ssend(&number,1,MPI_INT,1,1,MPI_COMM_WORLD);
		fprintf(stdout,"process(0): sent %d to process(1)\n",number);
		MPI_Recv(&number,1,MPI_INT,3,1,MPI_COMM_WORLD,&status);
		fprintf(stdout,"process(0): Recieved %d from process(3)\n",number);
		fflush(stdout);
	}

	else if(rank == 1){
		MPI_Recv(&number,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
		fprintf(stdout,"process(1): Recieved %d from process(0)\n",number);
		number += 1;
		MPI_Ssend(&number,1,MPI_INT,2,1,MPI_COMM_WORLD);
		fprintf(stdout,"process(1): sent %d to process(2)\n",number);
		fflush(stdout);
	}

	else if(rank == 2){
		MPI_Recv(&number,1,MPI_INT,1,1,MPI_COMM_WORLD,&status);
		fprintf(stdout,"process(2): Recieved %d from process(1)\n",number);
		number += 1;
		MPI_Ssend(&number,1,MPI_INT,3,1,MPI_COMM_WORLD);
		fprintf(stdout,"process(2): sent %d to process(3)\n",number);
		fflush(stdout);
	}

	else if(rank == 3){
		MPI_Recv(&number,1,MPI_INT,2,1,MPI_COMM_WORLD,&status);
		fprintf(stdout,"process(3): Recieved %d from process(2)\n",number);
		number += 1;
		MPI_Ssend(&number,1,MPI_INT,0,1,MPI_COMM_WORLD);
		fprintf(stdout,"process(3): sent %d to process(0)\n",number);
		fflush(stdout);
	}
	MPI_Finalize();
	return 0;
}