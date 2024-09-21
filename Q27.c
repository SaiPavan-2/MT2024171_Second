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

struct msg_buffer {
    long msg_type;
    char msg_text[100];
} message;

int main() {
    key_t key;
    int msgid;

    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);

    msgrcv(msgid, &message, sizeof(message.msg_text), 0, 0);

    printf("Received message: %s\n", message.msg_text);

    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}

/**
Output:
Received message: Hello from sender!
**/
