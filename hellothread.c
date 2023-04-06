#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>


void *run_threads(void *thread_id){
    
    for(int i = 0; i < 5; i++){
        printf("%s: %d\n", (char *) thread_id, i);
    }

    return NULL;
}




int main(void){

    pthread_t thread1;
    pthread_t thread2;

    printf("Launching threads\n");

    pthread_create(&thread1, NULL, run_threads, "thread 1");
    pthread_create(&thread2, NULL, run_threads, "thread 2");

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Threads complete!\n");

    return 0;
}
