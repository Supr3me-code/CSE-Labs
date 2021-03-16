#include <stdio.h>
#include "mpi.h"

int main(int argc, char *argv[])
{
    int rank,size,i;
    float rect,pi;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

 

    float x=(rank+0.5)/size;
    float x2=x*x;
    rect=(4/(1+x2))*(1/(float)size);

 

    MPI_Reduce(&rect,&pi,1,MPI_FLOAT,MPI_SUM,0,MPI_COMM_WORLD);

 

    if(rank==0)
        printf("Value of pi=%f\n",pi);

 

    MPI_Finalize();
    return 0;
}