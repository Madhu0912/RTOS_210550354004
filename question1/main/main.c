#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

QueueHandle_t messageq;


void task_t1(void *data)
{
while(1)
{
long start = xTaskGetTickCount();
printf("t1 task started\n");

printf("t1 task ended\n");
vTaskDelay(1000 / portTICK_PERIOD_MS);
long end = xTaskGetTickCount()-start;
printf("timestamp for temperature task_t1 is :%lu\n",end);  //gitter timestamp
}
}

void task_t2(void *data)
{
while(1)
{
long start = xTaskGetTickCount();
printf("t2 task started\n");
printf("t2 task ended\n");
vTaskDelay(2000 / portTICK_PERIOD_MS);
long end = xTaskGetTickCount()-start;
printf("timestamp for temperature task_t2 is :%lu\n",end);//gitter timestamp
}
}

void task_t3(void *data)
{
while(1)
{
long start = xTaskGetTickCount();
printf("t3 task started\n");

printf("t3 task ended\n");
vTaskDelay(5000 / portTICK_PERIOD_MS);
long end = xTaskGetTickCount()-start;
printf("timestamp for temperature task_t3 is :%lu\n",end);//gitter timestamp
}
}

void task_t4(void *data)
{
int count=0;
while(1)
{
long start = xTaskGetTickCount();
printf("t4 task started\n");
count++;
xQueueSend(messageq,&count,0);  //send data to task_t5
printf("t4 task ended\n");
vTaskDelay(2000 / portTICK_PERIOD_MS);
long end = xTaskGetTickCount()-start;
printf("timestamp for temperature task_t4 is :%lu\n",end);//gitter timestamp
}
}

void task_t5(void *data)
{
int buff=0;
while(1)
{
long start = xTaskGetTickCount();
printf("t5 task started\n");
xQueueReceive(messageq,&buff,0);    //received data from task_t4
printf("received from t4 Buff=%d\n",buff);
printf("t5 task ended\n");
vTaskDelay(2000 / portTICK_PERIOD_MS);
long end = xTaskGetTickCount()-start;
printf("timestamp for temperature task_t5 is :%lu\n",end);//gitter timestamp
}
}

void app_main(void)
{
    messageq = xQueueCreate(5, sizeof(int));
    xTaskCreate(task_t1, "task1", 2048, NULL, 3, NULL);
    xTaskCreate(task_t2, "task2", 2048, NULL, 3, NULL);
    xTaskCreate(task_t3, "task3", 2048, NULL, 3, NULL);
    xTaskCreate(task_t4, "task4", 2048, NULL, 3, NULL);
    xTaskCreate(task_t5, "task5", 2048, NULL, 3, NULL);
    vTaskDelay(5000 / portTICK_PERIOD_MS);
}