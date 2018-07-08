/********************************************************************************* 
 * Copyright(C), erfeng
 * FileName     : FSM.c
 * Author       : erfeng
 * Version      : V0.0.1 
 * Date         : 2018-07-07
 * Description  : 状态机框架源文件
**********************************************************************************/

#include "FSM.h"
#include <stdlib.h>
#include <stdio.h>

void FSM_register(FSM *pFSM, FSM_table *Ptable, int count, FSM_State curState)
{
    pFSM->fsmTable = Ptable;
    pFSM->cnt = count;
    pFSM->curState = curState;
}

void FSM_EventHandle(FSM *pFSM, FSM_Event event)
{
    int i = 0;
    FSM_State ps = pFSM->curState;
    FSM_Handle handle = NULL;
    for (; i < pFSM->cnt; i++)
    {
        if (0 != ps && event == pFSM->fsmTable[i].event)
        {
            handle = pFSM->fsmTable[i].handle;
            pFSM->curState = pFSM->fsmTable[i].nextState;
            break;
        }
        else
        {
            //printf("invalid event END!\n");
        }
    }

    if(handle)
    {
        handle(pFSM);
    }
}
