#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[]){
	int rank,size;
	char word[10];
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Status status;

	if(rank==0){
		printf("enter a word:");
		// scanf("%d",&x);
		scanf("%s",word);
		MPI_Ssend(word,5,MPI_INT,1,1,MPI_COMM_WORLD);
		fprintf(stdout,"sent to 1: %s\n",word);
		MPI_Recv(word,5,MPI_INT,1,1,MPI_COMM_WORLD,&status);
		fprintf(stdout, "finally recieved from 1: %s\n",word );
		fflush(stdout);
	}

	else if(rank==1){
		MPI_Recv(word,5,MPI_INT,0,1,MPI_COMM_WORLD,&status);
		fprintf(stdout,"recieved from 0: %s\n",word);

		for(int i=0;i<5;i++){
			if(word[i] >= 'a' && word[i] <= 'z'){
				word[i] = word[i]-32;
			}
			else{
				word[i] = word[i]+32;
			}
		}

		MPI_Ssend(word,5,MPI_INT,0,1,MPI_COMM_WORLD);	
		fprintf(stdout,"again sent to 0: %s\n",word);
		fflush(stdout);
	}
	MPI_Finalize();
	return 0;
}