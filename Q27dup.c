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

    message.msg_type = 1;
    sprintf(message.msg_text, "Hello from sender!");

    msgsnd(msgid, &message, sizeof(message.msg_text), 0);

    printf("Message sent.\n");

    return 0;
}
