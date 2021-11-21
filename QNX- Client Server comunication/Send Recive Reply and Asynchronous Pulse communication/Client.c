#include <stdlib.h>
#include <stdio.h>
#include <sys/dispatch.h>
#define ATTACH_POINT "myname"
struct {
int V1;
int V2;
char operator;
double result;
char type;
int rcvid;
} dane;
char znak [2];
int main(int argc, char *argv[]) {
int wejscie;
while (1) {
 printf("Podaj operator\n jezeli chcesz wybrac sinus wpisz s \n");
 scanf("%s", &znak[0]);
dane.operator = znak [0];
dane.type = 'z';
if(dane.operator != 's'){
printf("Podaj pierwszy skladnik\n");
scanf("%d", &wejscie);
dane.V1 = wejscie;
printf("Podaj drugi skladnik\n");
scanf("%d", &wejscie);
dane.V2 = wejscie;
};
printf("Rozpoczynam procedure nadwania\n");
 int server_coid = name_open(ATTACH_POINT,NULL);
 printf("Wyslanie danych \n");
 if (MsgSend(server_coid, &dane, sizeof(dane), &dane, sizeof(dane)) == -1) {
 printf("blad");
 }
 printf("Wyslano dane\n");
 printf("Wynik %lf\n",dane.result);
};
return EXIT_SUCCESS;
}