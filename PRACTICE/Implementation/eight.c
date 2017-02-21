#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define int_buff 2
#define float_buff 4
#define maxbuff_size 100
 int main(int argc,char *argv[])
 {
       int tasks,ids,value,i,provided,ret;
       int A[int_buff];
       int A_recv[int_buff];
       float B[float_buff];
       float B_recv[float_buff];
       char *buffer;
       int pos;
       MPI_Status status;

      
	   ret = MPI_Init_thread(&argc, &argv,  MPI_THREAD_MULTIPLE, &provided);
		if (ret != MPI_SUCCESS) {
			printf("Error initializing MPI with threads\n");
			exit(1);
		}


       MPI_Comm_size(MPI_COMM_WORLD,&tasks);
       MPI_Comm_rank(MPI_COMM_WORLD,&ids);
//       printf("%d \n",tasks);

       buffer=(char *) malloc(sizeof(char)*maxbuff_size);
       value=10;
       for(i=0;i<int_buff;i++)
       	A[i]=10;
       
       for(i=0;i<float_buff;i++)
       	B[i]=10;
       pos=0;
       	MPI_Pack(&value,1,MPI_INT,buffer,maxbuff_size,&pos,MPI_COMM_WORLD);
       	MPI_Pack(A,int_buff,MPI_INT,buffer,maxbuff_size,&pos,MPI_COMM_WORLD);
       	MPI_Pack(B,float_buff,MPI_FLOAT,buffer,maxbuff_size,&pos,MPI_COMM_WORLD);
       	MPI_Send(buffer,pos,MPI_PACKED,0,2,MPI_COMM_WORLD);
       // recieve
       MPI_Recv(buffer,maxbuff_size,MPI_PACKED,0,2,MPI_COMM_WORLD,&status);

       // unpack
       pos=0;
       MPI_Unpack(buffer,maxbuff_size,&pos,&i,1,MPI_INT,MPI_COMM_WORLD);
       MPI_Unpack(buffer,maxbuff_size,&pos,A_recv,int_buff,MPI_INT,MPI_COMM_WORLD);
       MPI_Unpack(buffer,maxbuff_size,&pos,B_recv,float_buff,MPI_FLOAT,MPI_COMM_WORLD);

       printf("Integer value recieved by is:%d\n",i);

       printf("Integer values recieved:\n");
       for(i=0;i<int_buff;i++)
       	printf("%d ",A_recv[i]);
       printf("\n");
      printf("FLoat values recieved :\n");
		for(i=0;i<float_buff;i++)
       	printf("%f ",B_recv[i]);
       MPI_Finalize();
       return(0);
 }