#include <stdlib.h>
#include <stdio.h>
#include <sys/iofunc.h>
#include <sys/dispatch.h>
#include <sys/neutrino.h>
#define ATTACH_POINT "myname"
int i = 0;
int zleceniodawca = 0 ;
int rejestracja[10];
char operator [10];
struct {
int V1;
int V2;
char operator;
int result;
char type;
int rcvid;
} dane;
int main(int argc, char *argv[]) {
int j;
name_attach_t * ATTACH;
printf("Rozpoczynam procedure odbioru\n");
ATTACH = name_attach(NULL, ATTACH_POINT, 0);
int recived;
while(1){
recived = MsgReceive(ATTACH->chid , &dane, sizeof(dane), NULL);
if(recived == -1){
break;
}
switch (dane.type) {
case 'r':
rejestracja[i] = recived;
operator[i] = dane.operator ;
i=i+1;
printf("zarejestrowano usluge\n");
break;
case 'z':
zleceniodawca = recived;
for(j=0;j<=i;j++){
if(operator[j]==dane.operator){
recived = rejestracja[j];
break;
}
else;
}
MsgReply( recived, 0, &dane, sizeof(dane));
printf("wyslano zlecenie do uslugi\n");
break;
case 'w':
printf("Wysylam wynik\n");
MsgReply( zleceniodawca, 0, &dane, sizeof(dane) );
printf("Wyslalem wynik\n");
break;
}
}
//MsgReply( recived, 0, NULL, 0 );
printf("pierwszy skladnik %d \n drugi skladnik %d \n operator %c \n typ %c \n
",dane.V1,dane.V2,dane.operator, dane.type);
return EXIT_SUCCESS;
}
