#include <stdlib.h>
#include <stdio.h>
#include <sys/iofunc.h>
#include <sys/dispatch.h>
#include <sys/neutrino.h>
#define ATTACH_POINT "myname"
int main(int argc, char *argv[]) {
name_attach_t * ATTACH;
printf("Rozpoczynam procedure odbioru\n");
ATTACH = name_attach(NULL, ATTACH_POINT, 0);
char msg[100];
int recived;
while(1){
recived = MsgReceive(ATTACH->chid , &msg, sizeof(msg), NULL);
if(recived == -1){
break;
}
MsgReply( recived, 0, NULL, 0 );
printf("koniec programu \n");
}
MsgReply( recived, 0, NULL, 0 );
printf("koniec programu \n");
return EXIT_SUCCESS;
}