#include <stdio.h>
#include <pthread.h>
#define ARRAYSIZE 1000
#define THREADS 2
 
void *slave(void *myid);
 
/* shared data */
int data[ARRAYSIZE];
/* Array of numbers to sum */
int sum = 0;
pthread_mutex_t mutex;
/* mutually exclusive lock variable */
int wsize;
/* size of work for each thread */
/* end of shared data */
void *slave(void *myid)
{
  int i, low,high,myresult=0; 
  low = (int) myid * wsize;
  high = low + wsize;
  
  for(i =low;i<high;i++)
    myresult += data[i];
  pthread_mutex_lock(&mutex);
  sum += myresult;
  /* add partial sum to local sum */
  pthread_mutex_unlock(&mutex);
  return;
}
 
main()
{
  int i;
  pthread_t tid[THREADS];
  pthread_mutex_init(&mutex,NULL); /* initialize mutex */
  wsize = ARRAYSIZE/THREADS;
  /* wsize must be an integer */
  for (i=0;i<ARRAYSIZE;i++)
  /*initialize data[] */
    data[i]= i+1;
  
  for (i =0;i<THREADS;i++) /* create threads */
    if(pthread_create(&tid[i],NULL,slave,(void*)i) != 0)
      perror("Pthread_create fails");
  
  for(i=0;i<THREADS;i++)/* join threads */
    if(pthread_join(tid[i],NULL) != 0)
      perror("Pthread_join fails");
 
  printf("The sum from 1 to %i is %d\n",ARRAYSIZE,sum);
}