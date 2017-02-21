#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>
#include <math.h>
#include <assert.h>

float *create_rand_nums(int n)
{
  int i;
   float *randi=(float *) malloc(sizeof(float)*n);
   for(i=0;i<n;i++)
      randi[i]=5;
    return(randi);
}
// Computes the square of an array of numbers
void compute_square(float *array, int num_elements) {
  int i;
  for (i = 0; i < num_elements; i++) {
    array[i]=sqrt(array[i]);
  }
}

int main(int argc, char** argv) {

  int num_elements_per_proc = 5,i;
  // Seed the random number generator to get different results each time
  srand(time(NULL));

  MPI_Init(NULL, NULL);

  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  // Create a random array of elements on the root process. Its total
  // size will be the number of elements per process times the number
  // of processes
  float *rand_nums = NULL;
  if (world_rank == 0) {
    rand_nums = create_rand_nums(num_elements_per_proc * world_size);
  }

  // For each process, create a buffer that will hold a subset of the entire
  // array
  float *sub_rand_nums = (float *)malloc(sizeof(float) * num_elements_per_proc);
  assert(sub_rand_nums != NULL);

  // Scatter the random numbers from the root process to all processes in
  // the MPI world
  MPI_Scatter(rand_nums, num_elements_per_proc, MPI_FLOAT, sub_rand_nums,
              num_elements_per_proc, MPI_FLOAT, 0, MPI_COMM_WORLD);

  // Compute the square of your subset
  compute_square(sub_rand_nums, num_elements_per_proc);

  // Gather all partial averages down to the root process
  float *sub_avgs = NULL;
  if (world_rank == 0) {
    sub_avgs = (float *)malloc(sizeof(float) * world_size*num_elements_per_proc);
    assert(sub_avgs != NULL);
  }
  MPI_Gather(sub_rand_nums, num_elements_per_proc, MPI_FLOAT, sub_avgs, num_elements_per_proc, MPI_FLOAT, 0, MPI_COMM_WORLD);

  if (world_rank == 0) {
    for(i=0;i<world_size*num_elements_per_proc;i++)
      printf("%f  %f ",rand_nums[i],sub_avgs[i]);
  }

  MPI_Finalize();
}
