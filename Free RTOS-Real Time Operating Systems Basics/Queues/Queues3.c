#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include <queue.h>
#define mainTIMER_TEST_PERIOD ( 50 )
QueueHandle_t xQueue;
static void nadawca(void *pvParameters)
{
int counter = 0;
( void ) pvParameters;
int tablica[3];
const TickType_t oczekiwanie_kolejka = pdMS_TO_TICKS(100);
const uint32_t opoznienie = pdMS_TO_TICKS(200);
printf("Wystartowano zadanie 1 - Nadawca\r\n");
for ( ; ; )
{
for(int i=0;i<3;i++){
tablica[i]=i*counter;
}
xQueueSend(xQueue, &tablica, oczekiwanie_kolejka);
counter++;
if(counter==13){
counter=0;
}
vTaskDelay(opoznienie);
}
}
static void odbiorca(void *pvParameters)
{
( void ) pvParameters;
int tablica[3];
const TickType_t oczekiwanie_kolejka = pdMS_TO_TICKS(200);
const uint32_t opoznienie = pdMS_TO_TICKS(200);
printf("Wystartowano zadanie 2 - Odbiorca\r\n");
for ( ; ; )
{
xQueueReceive(xQueue, &tablica, oczekiwanie_kolejka);
printf("tablica odebrana: \n element I : %d \n element II: %d \n elementIII:
%d\n",tablica[0],tablica[1],tablica[2]);
vTaskDelay(opoznienie);
}
}
int main(void)
{
int ilosc_elementow = 3;
xQueue = xQueueCreate(ilosc_elementow, 3*sizeof(int));
if (xQueue != NULL)
{
xTaskCreate(nadawca, "nadawca", 1000, NULL, 2, NULL);
xTaskCreate(odbiorca, "odbiorca", 1000, NULL, 1, NULL);
vTaskStartScheduler();
}
else
{
}
for (;; );
}