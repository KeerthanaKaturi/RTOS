#include<stdio.h>
#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
TaskHandle_t serial_task1_handle;
TaskHandle_t serial_task2_handle;
const TickType_t xDelay = 500/portTICK_PERIOD_MS;

void serial_task1(void *data)
{
    printf("serial task1 : started\n");
    vTaskDelay(xDelay);
    printf("serial task1 : again\n");
    printf("serial task1 : again\n");
    printf("serial task1 : again\n");
    vTaskDelay(xDelay);
    printf("serial task1 : again\n");
    printf("serial task1 : again\n");
    printf("serial task1 : again\n");
    vTaskDelay(xDelay);
    printf("serial task1 : again\n");

    //vTaskDelete(serial_task1_handle);
}

void serial_task2(void *data)
{
    printf("serial task2 : started\n");
    vTaskDelay(xDelay);
    printf("serial task2 : again\n");
    printf("serial task2 : again\n");
    printf("serial task2 : again\n");
    vTaskDelay(xDelay);
    printf("serial task2 : again\n");
    printf("serial task2 : again\n");
    printf("serial task2 : again\n");
    vTaskDelay(xDelay);
    printf("serial task2 : again\n");
    //vTaskDelete(serial_task2_handle);
}

void app_main()
{
    BaseType_t res;
    UBaseType_t prio,mt_prio;
    printf("DESD RTOS\n");
    res = xTaskCreate(serial_task1,"serialtask1",2048,NULL,5,&serial_task1_handle);
    if(res == pdPASS)
    {
        printf("task 1 successfully created.\n");
    }
    res = xTaskCreate(serial_task2,"serialtask2",2048,NULL,8,&serial_task2_handle);
    if(res == pdPASS)
    {
        printf("task 2 successfully created.\n");
    }
    prio = uxTaskPriorityGet(serial_task1_handle);
    mt_prio = uxTaskPriorityGet(serial_task2_handle);
    printf("Priority of serial task1: %d\n",prio);
    printf("Priority of serial task2: %d\n",mt_prio);
}