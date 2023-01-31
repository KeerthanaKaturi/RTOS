#include<stdio.h>
#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
TaskHandle_t serial_task1_handle;
TaskHandle_t serial_task2_handle;
TaskHandle_t serial_task3_handle;
const TickType_t xDelay = 500/portTICK_PERIOD_MS;

void serial_task1(void *data)
{
    printf("serial task1 : started\n");
    vTaskDelay(xDelay);
    printf("suspended task3\n");
    printf("serial task1 : again\n");
    printf("serial task1 : again\n");
    printf("serial task1 : again\n");
    
    vTaskResume(serial_task2_handle);

    printf("serial task1 : again\n");
    printf("serial task1 : again\n");

     vTaskSuspend(serial_task1_handle);
     printf("Resumed task1 from task3\n");
    printf("serial task1 : again\n");
    
    vTaskDelete(serial_task1_handle);
}

void serial_task2(void *data)
{
    printf("serial task2 : started\n");
    
    printf("serial task2 : again\n");
    printf("serial task2 : again\n");
    vTaskSuspend(serial_task2_handle);
    printf("Resumed task2 from task1\n");
    printf("serial task2 : again\n");
    printf("serial task2 : again\n");
    printf("serial task2 : again\n");
    
    vTaskDelay(xDelay);
    printf("task1 suspended\n");
    printf("serial task2 : again\n");
    vTaskResume(serial_task3_handle);
    vTaskDelete(serial_task2_handle);
}


void serial_task3(void *data)
{
    printf("suspended task2\n");
    printf("serial task3 : started\n");

    printf("serial task3 : again\n");
    printf("serial task3 : again\n");
    vTaskSuspend(serial_task3_handle);
    printf("Resumed task3 from task2\n");
    printf("serial task3 : again\n");
    printf("serial task3 : again\n");
    printf("serial task3 : again\n");
    printf("serial task3 : again\n");
    vTaskResume(serial_task1_handle);
    vTaskDelete(serial_task3_handle);
}


void app_main()
{
    printf("DESD RTOS\n");
    xTaskCreate(serial_task1,"serialtask1",2048,NULL,5,&serial_task1_handle);
    xTaskCreate(serial_task2,"serialtask2",2048,NULL,6,&serial_task2_handle);
    xTaskCreate(serial_task3,"serialtask2",2048,NULL,7,&serial_task3_handle);
}