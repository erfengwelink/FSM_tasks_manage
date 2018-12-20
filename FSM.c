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

void FSM_register(FSM *pFSM, FSM_table *ptable, int count, FSM_State curState)
{
    pFSM->fsmTable = ptable;
    pFSM->cnt = count;
    pFSM->curState = curState;
}

void FSM_EventHandle(FSM *pFSM, FSM_Event event)
{
    int i = 0;
    FSM_State ps = pFSM->curState;
    FSM_Handle transHandle = NULL;
    FSM_Handle TOHandle = NULL;
    for (; i < pFSM->cnt; i++)
    {
        if (0 != ps && event == pFSM->fsmTable[i].event)
        {
            transHandle = pFSM->fsmTable[i].handle;
            pFSM->curState = pFSM->fsmTable[i].nextState;
            break;
        }
        else if(NO_TO_STATE != pFSM->fsmTable[i].TOState && pFSM->fsmTable[i].tval > 0)
        {
            static cnt = 0;
            if(cnt < pFSM->fsmTable[i].tval)
            {
                cnt++;
            }
            else
            {
                TOHandle = pFSM->fsmTable[i].TOHandle;
                cnt = 0;
            }
        }else{
            //printf("invalid event END!\n");
        }
    }

    if(transHandle)     /* normal transformation */
    {
        transHandle(pFSM);
    }
    else if(TOHandle)   /* timeout transformation */
    { 
        TOHandle(pFSM);
    }
}
