#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#define N_THREADS 4 

int MATRICA[N_THREADS][N_THREADS]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}; 

void *SumOfRow(void* rowNumber) { 

int i; 
long row,sum=0; 
row= (long)rowNumber; 

for(i=0;i<N_THREADS;i++) { 
   sum = sum + MATRICA[row][i]; 
} 

return (void*)sum; 
} 

int main () { 

pthread_t threads[N_THREADS]; 
int rc,sum=0; 
long i; 
void* retval; 

for(i=0; i<N_THREADS; i++){ 
   rc = pthread_create(&threads[i], NULL, SumOfRow, (void *)i);
   pthread_join(threads[i],&retval); 
   sum=sum+(long)retval; 

} 

printf("SUMA UKUPNA JE:%d\n",sum); 
pthread_exit(NULL); 

} 
