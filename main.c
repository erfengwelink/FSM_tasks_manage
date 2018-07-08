/********************************************************************************* 
 * Copyright(C), erfeng
 * FileName     : FSM.h
 * Author       : erfeng
 * Version      : V0.0.1 
 * Date         : 2018-07-07
 * Description  : 状态机框架Demo文件
**********************************************************************************/

#include "FSM.h"
#include <stdlib.h>
#include <stdio.h>

void handle(void *param)
{

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

static FSM_table table[] = {
    {GET_UP,        1, 2, "GET_UP", handle},
    {BUY_BKFST,     2, 3, "BUY_BKFST", handle},
    {EAT_BKFST,     3, 4, "EAT_BKFST", handle},
    {WORK,          4, 5, "WORK", handle},
    {BUY_LUNCH,     5, 6, "BUY_LUNCH", handle},
    {EAT_LUNCH,     6, 7, "EAT_LUNCH", handle},
    {NAP,           7, 8, "NAP", handle},
    {WORK_AGAIN,    8, 9, "WORK_AGAIN", handle},
    {GO_HOME,       9, 0, "GO_HOME", handle},
};

static FSM fsm;
int main(int argc, char *argv[])
{
    FSM_register(&fsm, &table, 1, 1);
    FSM_EventHandle(&fsm,GET_UP);
    FSM_EventHandle(&fsm,BUY_BKFST);
    FSM_EventHandle(&fsm,EAT_BKFST);
    FSM_EventHandle(&fsm,WORK);
    FSM_EventHandle(&fsm,WORK);
    return 0;
}

//void FSM_EventHandle(FSM *pFSM, FSM_Event event);







