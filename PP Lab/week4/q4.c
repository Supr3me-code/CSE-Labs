#include <stdio.h>
#include "mpi.h"


int main(int argc,char*argv[])
{
	int rank,size,res;
	int errclass,resultlen,ierr;
	char err_buffer[MPI_MAX_ERROR_STRING];
	int mat[4][4];
	int row[4];

	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Errhandler_set(MPI_COMM_WORLD,MPI_ERRORS_RETURN);

	if(rank==0)
	{
		printf("Enter the elements of the matrix:\n");
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				scanf("%d",&mat[i][j]);
			}
		}
	}
	int recv[4];
	
	ierr=MPI_Scatter(&mat,4,MPI_INT,recv,4,MPI_INT,0,MPI_COMM_WORLD);
	if (ierr != MPI_SUCCESS) 
	{
         MPI_Error_class(ierr,&errclass);
         if (errclass== MPI_ERR_RANK) 
         {
           		fprintf(stderr,"Invalid rank used in MPI send call\n");
           		MPI_Error_string(ierr,err_buffer,&resultlen);
           		printf(stderr,err_buffer);
           		MPI_Finalize();             
        }
    }

    ierr=MPI_Scan(recv,&res,4,MPI_INT,MPI_SUM,MPI_COMM_WORLD);
    if (ierr != MPI_SUCCESS) 
	{
         MPI_Error_class(ierr,&errclass);
         if (errclass== MPI_ERR_RANK) 
         {
           		fprintf(stderr,"Invalid rank used in MPI send call\n");
           		MPI_Error_string(ierr,err_buffer,&resultlen);
           		printf(stderr,err_buffer);
           		MPI_Finalize();             
        }
    }


	ierr=MPI_Gather(&res,4,MPI_INT,mat,4,MPI_INT,0,MPI_COMM_WORLD);
	if (ierr != MPI_SUCCESS) 
	{
         MPI_Error_class(ierr,&errclass);
         if (errclass== MPI_ERR_RANK) 
         {
           		fprintf(stderr,"Invalid rank used in MPI send call\n");
           		MPI_Error_string(ierr,err_buffer,&resultlen);
           		printf(stderr,err_buffer);
           		MPI_Finalize();             
        }
    }

	if(rank==0)
	{
		printf("the elements of the modified matrix is\n");
		//fflush(stdout);
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
				printf("%d\t",mat[i][j]);
			printf("\n");
		}
	}
	MPI_Finalize();
	return 0;
}
