#include<stdio.h>
#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
TaskHandle_t serial_task_handle;

void serial_task(void *data)
{
    printf("serial task : started\n");
    vTaskDelete(serial_task_handle);
}

void app_main()
{
    BaseType_t res;
    printf("DESD RTOS\n");
    res = xTaskCreate(serial_task,"serialtask",2048,NULL,5,&serial_task_handle);
    if(res == pdPASS)
    {
        printf("task successfully created.");
    }
}