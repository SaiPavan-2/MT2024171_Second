/**
Name:Q31b.c
Author:Pavan
Description:Program to create a semaphore and initialize value to the semaphore.
b. create a counting semaphore
Date:21th September 2024
**/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

union semun {
    int val;                
    struct semid_ds *buf;    
    unsigned short *array;   
};

int main() {
    key_t key;
    int semid;
    union semun sem_union;
    
    key = ftok("semfile", 66);  
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }
    semid = semget(key, 1, 0666 | IPC_CREAT);
    if (semid == -1) {
        perror("semget");
        exit(EXIT_FAILURE);
    }
    
    sem_union.val = 5;  
    if (semctl(semid, 0, SETVAL, sem_union) == -1) {
        perror("semctl");
        exit(EXIT_FAILURE);
    }
    
    printf("Counting semaphore created and initialized to 5.\n");

    return 0;
}
/**
Output:Counting semaphore created and initialized to 5.
**/

