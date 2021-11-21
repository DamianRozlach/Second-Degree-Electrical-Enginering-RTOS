#include <stdlib.h>
#include <stdio.h>
#include <sys/dispatch.h>
#include <time.h>
#include <sys/netmgr.h>
#include <sys/neutrino.h>
#include <math.h>
#define ATTACH_POINT "myname"
#define ATTACH_POINT_SINUS "s"
#define MY_PULSE_CODE _PULSE_CODE_MINAVAIL
typedef union {
 struct _pulse pulse;
 /* your other message structures would go
 here too */
} my_message_t;
char znak = 's';
struct {
int V1;
int V2;
char operator;
double result;
char type;
int rcvid;
} dane;
int main(int argc, char *argv[]) {
name_attach_t * ATTACH_SINUS;
ATTACH_SINUS = name_attach(NULL, ATTACH_POINT_SINUS, 0);
struct sigevent event;
 struct itimerspec itime;
 timer_t timer_id;
 int chid;
 int rcvid;
 my_message_t msg;
 //chid = ChannelCreate(0);
 event.sigev_notify = SIGEV_PULSE;
 event.sigev_coid = ConnectAttach(ND_LOCAL_NODE, 0,
 ATTACH_SINUS ->chid,
 _NTO_SIDE_CHANNEL, 0);
 event.sigev_priority = getprio(0);
 event.sigev_code = MY_PULSE_CODE;
 timer_create(CLOCK_REALTIME, &event, &timer_id);
 itime.it_value.tv_sec = 1;
 /* 500 million nsecs = .5 secs */
 itime.it_value.tv_nsec = 500000000;
 itime.it_interval.tv_sec = 1;
 /* 500 million nsecs = .5 secs */
 itime.it_interval.tv_nsec = 500000000;
 timer_settime(timer_id, 0, &itime, NULL);
dane.type = 's';
dane.operator = znak;
printf("sinus uruchomiony\n");
 int server_coid = name_open(ATTACH_POINT,NULL);
 printf("Rejestracja \n");
 if (MsgSend(server_coid, &dane, sizeof(dane), &dane, sizeof(dane)) == -1) {
 printf("blad");
 }
 printf("zarejestrowano\n");
double x = 0;
double sinus= 0;
 for (;;) {
 rcvid = MsgReceive(ATTACH_SINUS ->chid, &msg, sizeof(msg), NULL);
 if (rcvid == 0) { printf(" pulse \n");
 if (msg.pulse.code == MY_PULSE_CODE) {
 x=x+1.0;
 sinus = sin(x);
 printf("we got a pulse sinus: %f\n ", sinus);
 } else {
 dane.type = 'w';
 dane.result = sinus;
 dane.operator='s';
 if (MsgSend(server_coid,&dane, sizeof(dane), &dane, sizeof(dane)) == -1) {
 printf("blad");
 }
 printf("wyslano wynik\n");
 };
 } /* else other messages ... */
 }
r