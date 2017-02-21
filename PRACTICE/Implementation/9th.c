#include <stdio.h>
#include "mpi.h"
#define n_size 5 

int main(int argc , char **argv)
{
 int   Myrank, Numprocs;
 int   In_Matrix[n_size][n_size],i=0,in=0,inc=0,j=0,k=0;
 int   low_Matrix[n_size][n_size],col,row;
 int   blocklen[n_size],displacement[n_size];
 MPI_Datatype  new_index_t; 
 MPI_Status    status;
 
/*.......Initialize MPI.............................*/
 MPI_Init(&argc,&argv);
 MPI_Comm_rank(MPI_COMM_WORLD,&Myrank);
 MPI_Comm_size(MPI_COMM_WORLD,&Numprocs);
 
/*................Read Input Matrix......................*/

 if(Numprocs == 2)
 {
   if(Myrank==0)
    {
       for(row=0; row < n_size; row++)
        {
           for(col=0;col < n_size;col++)
              In_Matrix[row][col]=in++; 
         }
  
        printf("\n Input Matrix\n");
    for(row=0; row < n_size; row++)
      { 
         for(col=0;col < n_size;col++)
           printf("%d\t",In_Matrix[row][col]);
   
         printf("\n");
     } 
  }
 
/*........Compute blocklen & displacement for lower triangular matrix........*/
    for(i=n_size;i>=0;i--)
    {
        blocklen[j++]=(n_size+1)-i;
        displacement[k++]=n_size*inc++;
     }

/*........Define the MPI index type & commit it..............................*/
 
   MPI_Type_indexed(n_size,blocklen,displacement,MPI_INT,&new_index_t);
   MPI_Type_commit(&new_index_t);
 
/*........Send the data to process 1.....................*/
  if(Myrank == 0)
  { 
  MPI_Send(In_Matrix,1,new_index_t,1,0,MPI_COMM_WORLD);
  }


  else
  {
/*....Intialize the output matrix to 0.....................*/
    for(row=0;row < n_size;row++)
     {
       for(col=0;col < n_size;col++)
       low_Matrix[row][col]=0;
      }

/*...........Receive the data & print the lower triangular matrix...........*/
     MPI_Recv(low_Matrix,1,new_index_t,0,0,MPI_COMM_WORLD,&status);
  
     printf("\nOUTPUT LOWER TRIANGULAR MATRIX ON PROCESS %d\n",Myrank);
     for(row=0;row < n_size;row++)
     {
       for(col=0;col < n_size;col++)
         printf("%d\t",low_Matrix[row][col]);
  
        printf("\n");
      }
 
   }  
 } 

/*....If No. of process is not equal to 2...................*/
  else
  {
    if(Myrank==0)
     printf("\nThe No. of process should be 2\n");
  }

  free(In_Matrix);
  free(low_Matrix);
/*...MPI finalizing..........................................*/
  MPI_Finalize();
} 

