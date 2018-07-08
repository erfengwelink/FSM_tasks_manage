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
    FSM_State ps = pFSM->curState;
    if(0 != ps && event == pFSM->fsmTable[ps-1].event)
    {
        printf("%s | cnt:%d\n",pFSM->fsmTable[ps-1].output, pFSM->cnt);
        pFSM->curState = pFSM->fsmTable[ps-1].nextState;
        pFSM->cnt++;
    }
    else
    {
        printf("invalid event END!\n");
    }
}

