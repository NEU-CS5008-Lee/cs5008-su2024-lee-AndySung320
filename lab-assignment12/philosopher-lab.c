// name: Di-En Sung
// email: sung.di@northeastern.edu.tw

// gcc -IC:/MinGW/include/ philosopher.c -pthread
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
pthread_mutex_t chopstick[5];//lock variable
#define THINK_TIME 2 // Time to think (in seconds)
#define EAT_TIME 2   // Time to eat (in seconds)

// Thread to be executed
void *philosopher(void *x)
{
    //Treat variable x as a pointer to an int and then extract the value into n
    int* a=(int*)x;
    int n=*a;
    
    /*-----Insert your code here----*/
    
    int left = n;
    int right = (n + 1) % 5;

    while (1) {

        printf("Philosopher %d is thinking.\n", n+1);
        sleep(THINK_TIME);

        pthread_mutex_lock(&chopstick[left]);
        pthread_mutex_lock(&chopstick[right]);

        printf("Philosopher %d is eating using chopstick[%d] and chopstick[%d].\n", n+1, left, right);
        sleep(EAT_TIME);

        pthread_mutex_unlock(&chopstick[right]);
        pthread_mutex_unlock(&chopstick[left]);
        printf("Philosopher %d finished eating.\n", n+1);
        break;
    }

    return NULL;
}


/*------------ Main Program---------*/
int main()
{
    int i,val[5];
    pthread_t threads[5];
    //initializing the mutex (for chopsticks)
    for(i=0;i<5;i++){
        pthread_mutex_init(&chopstick[i],NULL);
    }   

    //create and run the thread
    for(i=0;i<5;i++){
        val[i]=i;
        pthread_create(&threads[i],NULL,(void *)philosopher,&val[i]);
    }
    
    //wait until all the threads are done
    for(i=0;i<5;i++){
        pthread_join(threads[i],NULL);
    }
    
    // Destroying the mutex
    for(i=0;i<5;i++){
        pthread_mutex_destroy(&chopstick[i]);
    }
    
    return 0;
}