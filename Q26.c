/**
name:Q26.c
Author:Pavan
Description:Program to send messages to the message queue. Check $ipcs -q
Date:20th September 2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
} message;

int main() {
    key_t key;
    int msgid;

    key = ftok("msgqueuefile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);

    message.msg_type = 1;

    printf("Enter message: ");
    fgets(message.msg_text, sizeof(message.msg_text), stdin);

    if (msgsnd(msgid, &message, sizeof(message.msg_text), 0) == -1) {
        perror("msgsnd failed");
        exit(EXIT_FAILURE);
    }

    printf("Message sent: %s", message.msg_text);

    return 0;
}
/**
Output:
Enter message: Hello World
Message sent: Hello World
pavan@pavan-HP-Pavilion-Laptop-14-dv0xxx:~/.ssh/MT2024171_Second$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x410708e0 1          pavan      666        100          1        
**/
