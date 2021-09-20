#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/timers.h"

QueueHandle_t messageq;


void task_t1(void *data)
{
while(1)
{
long start = xTaskGetTickCount();
printf("t1 task started\n");
//----//
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
//    //
printf("t2 task ended\n");
vTaskDelay(2000 / portTICK_PERIOD_MS);
long end = xTaskGetTickCount()-start;
printf("timestamp for temperature task_t2 is :%lu\n",end);//gitter timestamp
}
}
void *const pt_timerid;
TimerHandle_t timer_handle;
void task_t3(void *data)
{
while(1)
{
long start = xTaskGetTickCount();
printf("task_t3 started\n");
pt_handle = xTimerCreate("pt_timer", pdMS_TO_TICKS(10000), pdFLASE, &pt_timerid, callback_handler);
xTimerStart(pt_handle, 0);
printf("task_t3 ended\n");
vTaskDelay(5000 / portTICK_PERIOD_MS);
long end = xTaskGetTickCount()-start;
printf("timestamp for temperature task_t3 is :%lu\n",end);//gitter timestamp
}
}

void callback_handler(TimerHandle_t xTimer)
{
printf("Timer fired\n");
}

void app_main(void)
{
    xTaskCreate(task_t1, "task1", 2048, NULL, 3, NULL);
    xTaskCreate(task_t2, "task2", 2048, NULL, 3, NULL);
    xTaskCreate(task_t3, "task3", 2048, NULL, 3, NULL);
}