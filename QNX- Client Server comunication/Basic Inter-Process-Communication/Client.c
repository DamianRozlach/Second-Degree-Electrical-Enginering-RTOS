#include <stdlib.h>
#include <stdio.h>
#include <sys/dispatch.h>
#define ATTACH_POINT "myname"
typedef struct _pulse msg_header_t;
typedef struct _my_data {
 msg_header_t hdr;
 int data;
} my_data_t;
int main(int argc, char *argv[]) {
printf("Rozpoczynam procedure nadwania\n");
 int server_coid = name_open(ATTACH_POINT,NULL);
my_data_t msg;
for (msg.data=0; msg.data < 5; msg.data++) {
 printf("Wyslanie... %d \n", msg.data);
 if (MsgSend(server_coid, &msg, sizeof(msg), NULL, 0) == -1) {
 break;
 }
 printf("Koniec programu\n");
}
return EXIT_SUCCESS;
}
