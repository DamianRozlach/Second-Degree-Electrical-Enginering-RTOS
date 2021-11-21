#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include <queue.h>
#define mainTIMER_TEST_PERIOD ( 50 )
TaskHandle_t uchwytzadanie2;
void zadanie1(void *pvParameters);
void zadanie2(void *pvParameters);
/////////////////////////////////////////////
int main ( void ){
xTaskCreate(zadanie1, "zadanie1", 1000, NULL, 2, NULL);
vTaskStartScheduler();
for (;; );
}
/////////////////////////////////////////////
void zadanie2(void *pvParameters)
{
( void ) pvParameters;
int counter = 0;
int x = 0;
UBaseType_t Priorytet2;
Priorytet2 = uxTaskPriorityGet(NULL);
printf("Wystartowano zadanie 2 \n");
for ( ; ; )
{
for(x = 0;x<100000;x++){
;
}
Priorytet2 = uxTaskPriorityGet(NULL);
counter++;
if(counter==100){
printf("zadanie DRUGIE dziala z priorytetem = %lu\n",Priorytet2);
counter=0;
}
}
}
void zadanie1(void *pvParameters)
{
( void ) pvParameters;
UBaseType_t Priorytet1;
Priorytet1 = uxTaskPriorityGet(NULL);
int counter = 0;
int x = 0;
printf("Wystartowano zadanie 1 \n");
for ( ; ; )
{
for( x = 0;x<100000;x++){
;
}
xTaskCreate(zadanie2, "zadanie2", 1000, NULL, 3, &uchwytzadanie2);
counter++;
if(counter==100){
printf("zadanie PIERWSZE dziala z priorytetem = %lu\n",Priorytet1);
counter=0;
}
}
}