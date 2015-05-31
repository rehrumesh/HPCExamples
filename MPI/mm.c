/* mm.c -  Matrix Multiplication */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <assert.h>

#define RANDLIMIT	5	/* Magnitude limit of generated randno.*/
#define N		4  	/* Matrix Size */
#define NUMLIMIT 70.0

float a[N][N];
float b[N][N];
float c[N][N];

int main(int argc, char *argv[])
{
    struct timeval start, stop;	
    int i,j,k;

	
    /* generate mxs  */
    for (i=0; i<N; i++)
        for (j=0; j<N; j++) {
            a[i][j] = 1+(int) (NUMLIMIT*rand()/(RAND_MAX+1.0)); 
            /*a[i][j] = 1.0; 
            b[i][j] = 2.0;*/
            b[i][j] = (double) (rand() % RANDLIMIT);
            /*c[i][j] = 0.0;*/
        }

#ifdef PRINT
        /* print matrices */
        printf("Matrix A:\n");           
        for (i=0; i<N; i++){      
           for (j=0; j<N; j++)  
              printf("%.3f\t",a[i][j]); 
           printf("\n");  
        }        

        printf("Matrix B:\n");       
        for (i=0; i<N; i++){  
           for (j=0; j<N; j++)
              printf("%.3f\t",b[i][j]);
           printf("\n");
        }   

        printf("Matrix C:\n");       
        for (i=0; i<N; i++){  
           for (j=0; j<N; j++)
              printf("%.3f\t",c[i][j]);
           printf("\n");
        }   
#endif

    gettimeofday(&start, 0);

    for (i=0; i<N; i++) {
	for (j=0; j<N; j++) {
           c[i][j] = 0.0;
	   for (k=0; k<N; k++)
              c[i][j] = c[i][j] + a[i][k]*b[k][j]; /* Working;standard way */
							     /*c[j][i] = c[j][i] + a[j][k]*b[k][i];*/ /* Working; Makes C column by col */
        } /* end j loop */
    }

    gettimeofday(&stop, 0);

#ifdef PRINT
    /* print results*/
    printf("Answer c:\n");
    for (i=0; i<N; i++){
        for (j=0; j<N; j++) 
           printf("%.3f\t",c[i][j]);
        printf("\n");
    }
#endif

    fprintf(stdout,"Time = %.6f\n\n",
         (stop.tv_sec+stop.tv_usec*1e-6)-(start.tv_sec+start.tv_usec*1e-6));
    return(0);
}
