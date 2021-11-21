#include <stdlib.h>
#include <stdio.h>
#include <sys/dispatch.h>
#define ATTACH_POINT "myname"
char znak = '+';
struct {
int V1;
int V2;
char operator;
int result;
char type;
int rcvid;
} dane;
int main(int argc, char *argv[]) {
dane.type = 'r';
dane.operator = znak;
printf("plus uruchomiony\n");
 int server_coid = name_open(ATTACH_POINT,NULL);
 printf("Rejestracja \n");
 if (MsgSend(server_coid, &dane, sizeof(dane), &dane, sizeof(dane)) == -1) {
 printf("blad");
 }
 printf("zarejestrowano\n");
 while (1) {
 dane.type = 'w';
 dane.result = dane.V1 + dane.V2 ;
 if (MsgSend(server_coid,&dane, sizeof(dane), &dane, sizeof(dane)) == -1) {
 printf("blad");
 }
 printf("wyslano wynik\n");
};
return EXIT_SUCCESS;
}