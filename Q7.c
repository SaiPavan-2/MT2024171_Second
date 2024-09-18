/**
Name:Q7.c
Author:Pavan
Description:Program to create three threads.
Date:12th September 2024
**/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
void* thread_function(void* arg) {
    printf("First thread id is %lu.\n", pthread_self());
    return NULL;
}

int main() {
    pthread_t t[3];
    for (int i = 0; i < 3; i++) {
        if (pthread_create(&t[i], NULL, thread_function, NULL) != 0) {
            perror("Error creating thread");
            return 1;
        }
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(t[i], NULL);
    }

    printf("All threads have completed their execution.\n");
    return 0;
}
/*
Output:
First thread id is 139770254587584.
First thread id is 139770246194880.
First thread id is 139770237802176.
All threads have completed their execution.
*/

