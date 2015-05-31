/* Sample program to add a group of numbers stored in an array */

#include "mpi.h"
#include <stdio.h>
#include <math.h>
#define MAXSIZE 1000

int main(int argc, char *argv[])
{
	int myid, numprocs;
	int data[MAXSIZE], i, x, low, high, myresult, result;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    	for (i = 0; i < MAXSIZE; i++)                  
        	data[i] = 1;
      
	/* broadcast data */
	MPI_Bcast(data, MAXSIZE, MPI_INT, 0, MPI_COMM_WORLD);

	/* Add my portion of data */
	x = MAXSIZE/numprocs; 
	low = myid * x;
	high = low + x;
 	for (i = low; i < high; i++)
		myresult += data[i];
	
	/*  Compute global sum */
	MPI_Reduce(&myresult, &result, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

	if (myid == 0) printf("The sum is %d.\n",result);

	MPI_Finalize();
}
