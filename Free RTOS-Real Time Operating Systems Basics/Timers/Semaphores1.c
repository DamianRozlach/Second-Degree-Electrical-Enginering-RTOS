#include <stdio.h>
#include <stdlib.h>
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#define mainTIMER_TEST_PERIOD ( 50 )
static void zadanie( void *pvParameters );
/*-----------------------------------------------------------*/
int main ( void )
{
xTaskCreate( zadanie, "Zad1", 1000, "PIERWSZE", 1, NULL );
xTaskCreate( zadanie, "Zad2", 1000, "DRUGIE" , 1, NULL );
vTaskStartScheduler();
return 0;
}
/*-----------------------------------------------------------*/
static void zadanie( void *pvParameters )
{
char *tekst;
tekst = (char*) pvParameters;
const TickType_t opoznienie = 5000/portTICK_PERIOD_MS;
int i;
for( ;; ) {
for(i=1;i<=5;i++){
printf( "Zadanie %s wypisuje %d \n",tekst, i );
vTaskDelay(opoznienie);
}
}
}