#include <stdlib.h>
#include <stdio.h>
#include <sys/dispatch.h>
#define ATTACH_POINT "myname"
struct {
int V1;
int V2;
char operator;
int result;
char type;
int rcvid;
} dane;
char znak [2];
int main(int argc, char *argv[]) {
int wejscie;
while (1) {
dane.type = 'z';
printf("Podaj pierwszy skladnik\n");
scanf("%d", &wejscie);
dane.V1 = wejscie;
printf("Podaj drugi skladnik\n");
scanf("%d", &wejscie);
dane.V2 = wejscie;
printf("Podaj operator\n");
scanf("%s", &znak[0]);
dane.operator = znak [0];
printf("Rozpoczynam procedure nadwania\n");
 int server_coid = name_open(ATTACH_POINT,NULL);
 printf("Wyslanie danych \n");
 if (MsgSend(server_coid, &dane, sizeof(dane), &dane, sizeof(dane)) == -1) {
 printf("blad");
 }
 printf("Wyslano dane\n");
 printf("Wynik %d\n",dane.result);
};
/*
for (dane.V1=0; dane.V1 < 5; dane.V1++) {
 printf("Wyslanie... %d \n", dane.V1);
 if (MsgSend(server_coid, &dane, sizeof(dane), NULL, 0) == -1) {
 break;
 }
 printf("Koniec programu\n");
}
*/
return EXIT_SUCCESS;
}