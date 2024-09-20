/**
Name:Q27.c
Author:Pavan
Description:Program to receive messages from the message queue.
a. with 0 as a flag
b. with IPC_NOWAIT as a flag
Date:20th September 2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_data {
    long msg_type;
    char msg_text[100];
} msg;

int main() {
    key_t queue_key;
    int queue_id;

    queue_key = ftok("msgqueuefile", 65);
    queue_id = msgget(queue_key, 0666 | IPC_CREAT);

    if (msgrcv(queue_id, &msg, sizeof(msg.msg_text), 0, IPC_NOWAIT) == -1) {
        perror("msgrcv failed");
        exit(EXIT_FAILURE);
    }

    printf("Message received: %s", msg.msg_text);

    return 0;
}
/**Output:
msgrcv failed: No message of desired type
**/
