#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[]){
	int rank,size,n[5];
	int buf[100];
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Status status;
	MPI_Buffer_attach(buf,100);
	if(rank==0){
		printf("enter 5 numbers: ");
		for(int i=0;i<5;i++){
			scanf("%d",&n[i]);
		}
		for(int i=1;i<5;i++){
			MPI_Bsend(&n[i],1,MPI_INT,i,1,MPI_COMM_WORLD);
			fprintf(stdout,"(root) Send %d to process %d\n",n[i],i);
		}
	}

	else if(rank == 1){
		MPI_Recv(&n[1],1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
		fprintf(stdout,"process(1): recieved from root: %d\t Cube: %d\n",n[1],n[1]*n[1]*n[1]);
		fflush(stdout);		
	}

	else if(rank == 2){
		MPI_Recv(&n[2],1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
		fprintf(stdout,"process(2): recieved from root: %d\t Square: %d\n",n[2],n[2]*n[2]);
		fflush(stdout);		
	}

	else if(rank == 3){
		MPI_Recv(&n[3],1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
		fprintf(stdout,"process(3): recieved from root: %d\t Cube: %d\n",n[3],n[3]*n[3]*n[3]);
		fflush(stdout);		
	}

	else if(rank == 4){
		MPI_Recv(&n[4],1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
		fprintf(stdout,"process(4): recieved from root: %d\t Square: %d\n",n[4],n[4]*n[4]);
		fflush(stdout);		
	}
	MPI_Finalize();
	return 0;
}