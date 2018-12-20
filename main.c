/********************************************************************************* 
 * Copyright(C), erfeng
 * FileName     : FSM.h
 * Author       : erfeng
 * Version      : V0.0.1 
 * Date         : 2018-07-07
 * Description  : 状态机框架Demo文件
**********************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "FSM.h"

void getUPHandle(void *param)
{
    //FSM *pFSM = (FSM *)param;
    printf("now i'm starting %s !\n",__func__);
}

void buyBkfstHandle(void *param)
{
    //FSM *pFSM = (FSM *)param;
    printf("now i'm starting %s !\n",__func__);
}

void eatBkfstHandle(void *param)
{
    //FSM *pFSM = (FSM *)param;
    printf("now i'm starting %s !\n",__func__);
}

void workHandle(void *param)
{
    //FSM *pFSM = (FSM *)param;
    printf("now i'm starting %s !\n",__func__);
}

void buyLunchHandle(void *param)
{
    //FSM *pFSM = (FSM *)param;
    printf("now i'm starting %s !\n",__func__);
}

void eatLunchHandle(void *param)
{
    //FSM *pFSM = (FSM *)param;
    printf("now i'm starting %s !\n",__func__);
}

void napHandle(void *param)
{
    //FSM *pFSM = (FSM *)param;
    printf("now i'm starting %s !\n",__func__);
}

void workAgainHandle(void *param)
{
    //FSM *pFSM = (FSM *)param;
    printf("now i'm starting %s !\n",__func__);
}

void goHomeHandle(void *param)
{
    //FSM *pFSM = (FSM *)param;
    printf("now i'm starting %s !\n",__func__);
}

enum{
    GET_UP,
    BUY_BKFST,
    EAT_BKFST,
    WORK,
    BUY_LUNCH,
    EAT_LUNCH,
    NAP,
    WORK_AGAIN,
    GO_HOME
}APP_EVENT;

#if 0

typedef struct __fsm_table__{
    FSM_Event event;
    FSM_State curState;
    FSM_State nextState;
    FSM_Output output;
    FSM_Handle handle;
    FSM_TOVal_t tval;       /* timeout value */
    FSM_State TOState;      /* timeout >> next state       */
    FSM_Handle TOHandle;    /* 0 timeout handle function   */
}FSM_table;

#endif

static FSM_table table[] = {
    {GET_UP,        1, 2, "GET_UP",     getUPHandle,        1000, 7, NULL},
    {BUY_BKFST,     2, 8, "BUY_BKFST",  buyBkfstHandle,     1000, 7, NULL},
    {EAT_BKFST,     8, 3, "EAT_BKFST",  eatBkfstHandle,     1000, 7, NULL},
    {WORK,          3, 5, "WORK",       workHandle,         1000, 7, NULL},
    {BUY_LUNCH,     5, 6, "BUY_LUNCH",  buyLunchHandle,     1000, 7, NULL},
    {EAT_LUNCH,     6, 4, "EAT_LUNCH",  eatLunchHandle,     1000, 7, NULL},
    {NAP,           4, 7, "NAP",        napHandle,          1000, 7, NULL},
    {WORK_AGAIN,    7, 9, "WORK_AGAIN", workAgainHandle,    1000, 7, NULL},
    {GO_HOME,       9, 0, "GO_HOME",    goHomeHandle,       1000, 7, NULL},
};

static FSM fsm;

/*
int main(int argc, char *argv[])
{
    FSM_register(&fsm, table, sizeof(table)/sizeof(FSM_table), 1);
    FSM_EventHandle(&fsm,GET_UP);
    FSM_EventHandle(&fsm,BUY_BKFST);
    FSM_EventHandle(&fsm,EAT_BKFST);
    FSM_EventHandle(&fsm,WORK);
    FSM_EventHandle(&fsm,BUY_LUNCH);
    FSM_EventHandle(&fsm,EAT_LUNCH);
    FSM_EventHandle(&fsm,NAP);
    FSM_EventHandle(&fsm,WORK_AGAIN);
    FSM_EventHandle(&fsm,GO_HOME);
    return 0;
}
*/

int main(int argc, char *argv[])
{
    FSM_register(&fsm, table, sizeof(table)/sizeof(FSM_table), 1);

    return 0;
} 






