
#include <stdio.h>
#include <string.h>
#include "esp_log.h"
#include "uFSM.h"
#include "esp_console.h"
#include "argtable3/argtable3.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// static FSM_t *pFSM;

void Handle0(void *param)
{
    ESP_LOGI(__func__, " ********* %s start *************\r\n", __func__);
}

void Handle1(void *param)
{
    ESP_LOGI(__func__, " ********* %s start *************\r\n", __func__);
}

void Handle2(void *param)
{
    ESP_LOGI(__func__, " ********* %s start *************\r\n", __func__);
}

void Handle3(void *param)
{
    ESP_LOGI(__func__, " ********* %s start *************\r\n", __func__);
}

void Handle4(void *param)
{
    ESP_LOGI(__func__, " ********* %s start *************\r\n", __func__);
}

void timeOutHandle1(void *param)
{
    ESP_LOGI(__func__, " ********* %s start *************\r\n", __func__);
}

void timeOutHandle2(void *param)
{
    ESP_LOGI(__func__, " ********* %s start *************\r\n", __func__);
}

#define TAB_MAX 6
static FSM_table_t sTab[TAB_MAX] = {
    {EVENT_NONE, ST_0, ST_0, "0", NULL, 10, ST_4, timeOutHandle1},
    {EVENT_1, ST_4, ST_1, "0", Handle1, 0, ST_NONE, NULL},
    {EVENT_2, ST_1, ST_3, "0", Handle2, 0, ST_NONE, NULL},
    {EVENT_3, ST_3, ST_5, "0", Handle3, 0, ST_NONE, NULL},
    {EVENT_4, ST_5, ST_2, "0", Handle4, 0, ST_NONE, NULL},
    {EVENT_NONE, ST_2, ST_2, "0", NULL, 30, ST_0, timeOutHandle2},
};

#if 0
static int FSM_init(FSM_t *fsm)
{
    pFSM = fsm;
    return 0;
}
#endif

void FSM_register(FSM_t *pfsm, FSM_table_t *ptable, int count, FSM_State_t curState, FSM_time_compare_t cmpFunc)
{

    // if (!pFSM && pfsm)
    // {
    //     FSM_init(pfsm); BURGLAR
    // }

    if (pfsm)
    {
        pfsm->trigger = EVENT_NONE;
        pfsm->fsmTable = ptable;
        pfsm->cnt = count;
        pfsm->curState = curState;
        pfsm->cmpFunc = cmpFunc;
    }
    else
    {
        ESP_LOGI(__func__, "FSM uninitiated!\n");
    }

}

void xFSM_init_default(FSM_t *pfms, FSM_time_compare_t cmpFunc)
{
    int size = sizeof(sTab) / sizeof(FSM_table_t);
    ESP_LOGI(__func__, " ********* %s start *************\r\n", __func__);
    FSM_register(pfms, &sTab[0], size, ST_0, cmpFunc); //TAB_MAX
    ESP_LOGI(__func__, " ********* %s end *************\r\n", __func__);
}

static FSM_table_t *find_target_transmission(FSM_t *pfms)
{
    FSM_table_t *pTab = NULL;
    // FSM_table_t fsmt;
    for (int i = 0; i < pfms->cnt; i++) /* search for target transmission */ ////
    {
        pTab = (FSM_table_t *)&pfms->fsmTable[i];//&sTab[i];
        if (pTab && pTab->curState == pfms->curState)////
        {
            return pTab;
        }
    }
    return NULL;
}

static int target_timeout_expire(FSM_t *pfms, FSM_table_t *p)
{
    int t = p->tval;
    static int origin_t = 0;
    // ESP_LOGI(__func__, " ********* [ %s | timeout: %d] *************\r\n", __func__, t);
    if (t > 0)
    {
        ESP_LOGI(__func__, " ********* [ %s | t: %d] *************\r\n", __func__, t);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        t--;
        origin_t++;
        p->tval = t;
    }
    else if (t == 0 && p->timeOutState > ST_NONE)
    {
        /* code */
        ESP_LOGI(__func__, "\n\n @@@@@@@@@@@@@@@@@@@@@@@@\n timeout exe transimission\n @@@@@@@@@@@@@@@@@@@@\n");
        if(p->timeOutHandle)// 
        {
            p->timeOutHandle(NULL);
        }
        pfms->curState = p->timeOutState;
        p->tval = origin_t;
        origin_t = 0;
        ESP_LOGI(__func__, " ####################  %s >> ST: %d  ################ \r\n", __func__, pfms->curState);
    }

    // ESP_LOGI(__func__, " ********* [ %s | end ] *************\r\n", __func__);
    return 0;
}

static FSM_Event_t event_update(FSM_t *pfms, FSM_Event_t ev)
{
    if(EVENT_NONE != ev)
    {
        pfms->trigger = ev;
        return pfms->trigger;
    }
    return EVENT_NONE;
} 

void FMS_run(FSM_t *pfms, FSM_Event_t event)//
{
    // static FSM_State_t lastState = ST_NONE;
    // int timeout = 0;
    if (pfms) /* assert fsm has initialized */ ////
    {
        // ESP_LOGI(__func__, " if (pFSM) \r\n");
        FSM_table_t *pTab = NULL;
        // ESP_LOGI(__func__, " pFSM->cnt = %d  | pFSM->curState %d | event %d\r\n", pFSM->cnt, pFSM->curState, event);
#if 0
        for (int i = 0; i < pFSM->cnt; i++)/* search for target transmission */
        {
            pTab = (FSM_table_t *)&sTab[i]; //(pFSM->fsmTable + sizeof(FSM_table_t)*i);
            ESP_LOGI(__func__, " i = %d |pTab->curState %d | pFSM->curState %d | event %d|pTab->event %d\r\n", i, pTab->curState, pFSM->curState, event, pTab->event);

            if (pTab && pTab->curState == pFSM->curState)/*  */
            {
                if (event == pTab->event)
                {
                    ESP_LOGI(__func__, " event triggered...  GO to Next ST.\r\n");

                    if (pTab->eventHandle)
                    {
                        pTab->eventHandle(NULL);
                        lastState = pFSM->curState;
                        pFSM->curState = pTab->nextState;
                    }
                }
                else
                {
                    if (lastState != pTab->curState)
                    {
                        timeout = pTab->tval;
                    }
                    else
                    {
                        if (timeout > 0)
                        {
                            timeout -= 1;
                        } //5770015337
                    }
                }
            }

#endif
        pTab = find_target_transmission(pfms);
        if (pTab)
        {
            if (event == pTab->event)
            {
                // ESP_LOGI(__func__, " event triggered...  GO to Next ST.\r\n");
                ESP_LOGI(__func__, " event == pTab->event.\r\n");
                if (pTab->eventHandle)
                {
                    pTab->eventHandle(NULL);
                    // lastState = pFSM->curState;
                    pfms->curState = pTab->nextState; ////
                }
                vTaskDelay(100 / portTICK_PERIOD_MS);
            }
            else /* timeout case */
            {
                // ESP_LOGI(__func__, " event != pTab->event.\r\n");
                target_timeout_expire(pfms, pTab);
            }
        }
        else
        {
            // ESP_LOGI(__func__, " No find target transmission!\r\n");
        }
    }
    else
    {
        ESP_LOGI(__func__, "FSM uninitiated!\n");
    }
}

