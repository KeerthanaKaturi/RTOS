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
    printf("suspended task2\n");
    printf("serial task1 : again\n");
    printf("serial task1 : again\n");
    printf("serial task1 : again\n");
    
    vTaskResume(serial_task2_handle);

    printf("serial task1 : again\n");
    printf("serial task1 : again\n");
    printf("serial task1 : again\n");
    
    vTaskDelete(serial_task1_handle);
}

void serial_task2(void *data)
{
    printf("serial task2 : started\n");
    
    printf("serial task2 : again\n");
    printf("serial task2 : again\n");
    vTaskSuspend(serial_task2_handle);
    printf("Resumed task2 : again\n");
    printf("serial task2 : again\n");
    printf("serial task2 : again\n");
    printf("serial task2 : again\n");
    printf("serial task2 : again\n");
    vTaskDelay(xDelay);
    vTaskDelete(serial_task2_handle);
}

void app_main()
{
    printf("DESD RTOS\n");
    xTaskCreate(serial_task1,"serialtask1",2048,NULL,8,&serial_task1_handle);
    xTaskCreate(serial_task2,"serialtask2",2048,NULL,5,&serial_task2_handle);
}