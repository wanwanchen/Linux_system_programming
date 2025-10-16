#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* myThreadFunc(void* arg) {
    while(1) {
        printf("Thread is running...\n");
        sleep(1);
    }
    return NULL;
}

void* foo(void* arg) {
    
    // Get current thread ID
    pthread_t thisThread = pthread_self();
	while(1){
    	printf("Current thread ID: %lu\n",
        	(unsigned long)thisThread);
		sleep(1);
	}
    return NULL;
}

int main() {
    pthread_t thread;
	pthread_t thread1;
    pthread_create(&thread1, NULL, foo, NULL);
    pthread_create(&thread, NULL, myThreadFunc, NULL);
    sleep(5);
    //Requesting to cancel the thread after 5 seconds. 
    pthread_cancel(thread);
    // Wait for the thread to terminate
    pthread_join(thread, NULL);  
	

    pthread_cancel(thread1);
    pthread_join(thread1, NULL);

    printf("Main thread finished.\n");
    return 0;
}
