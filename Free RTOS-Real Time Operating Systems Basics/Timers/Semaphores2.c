#include <stdio.h>
#include <stdlib.h>
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#define mainTIMER_TEST_PERIOD ( 50 )
static void zadanie( void *pvParameters );
SemaphoreHandle_t semafor;
/*-----------------------------------------------------------*/
int main ( void )
{
 semafor=xSemaphoreCreateMutex();
 if(semafor != NULL)
 {
xTaskCreate( zadanie, "Zad1", 1000, "PIERWSZE", 1, NULL );
xTaskCreate( zadanie, "Zad2", 1000, "DRUGIE" , 1, NULL );
vTaskStartScheduler();
 }
return 0;
}
/*-----------------------------------------------------------*/
static void zadanie( void *pvParameters )
{
char *tekst;
tekst = (char*) pvParameters;
const TickType_t opoznienie = 1000/portTICK_PERIOD_MS;
int i;
for( ;; ) {
xSemaphoreTake(semafor,portMAX_DELAY);
for(i=1;i<=5;i++){
printf( "Zadanie %s wypisuje %d \n",tekst, i );
vTaskDelay(opoznienie);
}
xSemaphoreGive(semafor);
vTaskDelay(opoznienie/100);
 }
}