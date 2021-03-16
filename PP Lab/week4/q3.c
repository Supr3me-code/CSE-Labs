#include "mpi.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int rank, size, a[3][3], i,j, b[3], n, x,c =0,s=0;
    MPI_Status status;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if(rank==0)
    {
        printf("Root Process: Enter 3x3 Matrix:\n");
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        printf("Enter Number to be searched:");
        scanf("%d",&n);
        
        for(i=1;i<4;i++)
        {
            MPI_Send(a[i-1], 3, MPI_INT, i, 1, MPI_COMM_WORLD);
        }
        
    }
    MPI_Bcast(&n, 1, MPI_INT,0,MPI_COMM_WORLD);
    // printf("rank = %d, x= %d \n", rank, n);
    if(rank!=0)
    MPI_Recv(b, 3, MPI_INT, 0,1, MPI_COMM_WORLD, &status);
    // printf("rank = %d, x= %d \n", rank, n);
    // printf("rank = %d b[0] =%d%d%d\n",rank, b[0], b[1], b[2]);
    if(rank!=0)
    for(i=0;i<3;i++)
    {
        if(b[i]==n)
            c++;
    }
    MPI_Reduce(&c, &s,1,MPI_INT, MPI_SUM,0, MPI_COMM_WORLD);
    if(rank==0)
    {
        printf("Rank = %d Number of Occurences = %d\n", rank, s);
    }
    MPI_Finalize();
}