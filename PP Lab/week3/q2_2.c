#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc,char* argv[]){
    int rank,size,*a=NULL,*c=NULL;
    float res,*b=NULL;
    if(argc<1){
        printf("Enter m as command line argument");
        exit(EXIT_FAILURE);
    }
    MPI_Init(&argc,&argv);
    int m=atoi(argv[1]);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    a=(int*)malloc(m*size*sizeof(int));
    b=(float*)malloc(size*sizeof(float));
    c=(int*)malloc(m*sizeof(int));
    if(rank==0){
        printf("Enter %d numbers.\n",m*size);
        for(int i=0;i<m*size;i++)
            scanf("%d",&a[i]);
    }
    MPI_Scatter(a,m,MPI_INT,c,m,MPI_INT,0,MPI_COMM_WORLD);
    res=0;
    for(int i=0;i<m;i++){
        res+=c[i];
    }
    res/=m;
    printf("Process[%d]: Average is %f\n",rank,res);
    MPI_Gather(&res,1,MPI_FLOAT,b,1,MPI_FLOAT,0,MPI_COMM_WORLD);
    if(rank==0){
        res=0;
        for(int i=0;i<size;i++) res+=b[i];
        res/=size;
        printf("Process[%d]: The overall average is %f\n",rank,res);
    }
    MPI_Finalize();
    return 0;
}