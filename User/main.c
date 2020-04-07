#include "includes.h"

/**********************************Task priority***********************************/
#define AppTaskCreate_TASK_PRIO         1


/*********************************Task stack size**********************************/
/*
 *(in words, under a 32-bit processor, one word is equal to 4 bytes)
 */
#define AppTaskCreate_STK_SIZE          128


/**************************************Task handle**********************************/
static TaskHandle_t AppTaskCreate_Handle = NULL;



/**************************************Task function********************************/
static void AppTaskCreate(void);




/*************************************************************************************
  * @brief  main
  * @param  NULL
  * @retval NULL
  * @note   first:      BSP Init
            second:     Create APP task
            third:      Start FreeRTOS

  ************************************************************************************/
int main(void)
{
	BaseType_t xReturn = pdPASS;
    
    BSP_Init();
    
    xReturn = xTaskCreate((TaskFunction_t)  AppTaskCreate,
                          (const char*)     "App TaskCreate",
                          (uint16_t)        AppTaskCreate_STK_SIZE,
                          (void* )          NULL,
                          (UBaseType_t)     AppTaskCreate_TASK_PRIO,
                          (TaskHandle_t*)   &AppTaskCreate_Handle
                          );
    if(pdPASS == xReturn)
        vTaskStartScheduler();
    else 
        return -1;
    
    while(1);
}

static void AppTaskCreate(void)
{
    BaseType_t xReturn = pdPASS;
    
    taskENTER_CRITICAL();
    
    //创建任务
    
    vTaskDelete(AppTaskCreate_Handle);
    
    taskEXIT_CRITICAL();
}



