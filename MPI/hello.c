/*
 * Open Systems Laboratory
 * http://www.lam-mpi.org/tutorials/
 * Indiana University
 *
 * MPI Tutorial
 * Lab 1: Hello world
 *
 * Mail questions regarding tutorial material to lam at lam dash mpi dot org

Malik's note:
This can be run correctly on our SweLanka grid for example by
mpirun -np 2 a.out 2
 */

#include <stdio.h>
#include <mpi.h>


int 
main(int argc, char *argv[])
{
  int rank, size;

  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  printf("Hello world! I am %d of %d\n", rank, size);

  MPI_Finalize();

  return 0;
}
