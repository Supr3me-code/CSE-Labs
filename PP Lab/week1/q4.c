#include "mpi.h"
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]){
	int rank;
	char str[] = "HeLLo";
	// printf("initial string: %s\n",str);

	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	if(rank == 0){
		if(str[0] >= 'a' && str[0] <= 'z'){
			printf("%c",str[0]-32);
		}
		else{
			printf("%c",str[0]+32);
		}
	}
	else if(rank == 1){
		if(str[1] >= 'a' && str[1] <= 'z'){
			printf("%c",str[1]-32);
		}
		else{
			printf("%c",str[1]+32);
		}
	}
	else if(rank == 2){
		if(str[2] >= 'a' && str[2] <= 'z'){
			printf("%c",str[2]-32);
		}
		else{
			printf("%c",str[2]+32);
		}
	}
	else if(rank == 3){
		if(str[3] >= 'a' && str[3] <= 'z'){
			printf("%c",str[3]-32);
		}
		else{
			printf("%c",str[3]+32);
		}
	}
	else{
		if(str[4] >= 'a' && str[4] <= 'z'){
			printf("%c",str[4]-32);
		}
		else{
			printf("%c",str[4]+32);
		}
	}
	MPI_Finalize();
	return 0;
}