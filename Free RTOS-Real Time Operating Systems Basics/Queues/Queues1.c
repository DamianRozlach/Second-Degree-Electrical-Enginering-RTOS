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
const TickType_t oczekiwanie_kolejka = pdMS_TO_TICKS(100);
const uint32_t opoznienie = pdMS_TO_TICKS(200);
printf("Wystartowano zadanie 1 - Nadawca\r\n");
for ( ; ; )
{
xQueueSend(xQueue, &counter, oczekiwanie_kolejka);
counter++;
vTaskDelay(opoznienie);
}
}
static void odbiorca(void *pvParameters)
{
int Received;
( void ) pvParameters;
const TickType_t oczekiwanie_kolejka = pdMS_TO_TICKS(200);
const uint32_t opoznienie = pdMS_TO_TICKS(200);
printf("Wystartowano zadanie 2 - Odbiorca\r\n");
for ( ; ; )
{
xQueueReceive(xQueue, &Received, oczekiwanie_kolejka);
printf("From Sender = %d\n", Received);
vTaskDelay(opoznienie);
}
}
int main(void)
{
int ilosc_elementow = 3;
xQueue = xQueueCreate(ilosc_elementow, sizeof(int));
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
