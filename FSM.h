#ifndef __FSM_H__
#define __FSM_H__

/********************************************************************************* 
 * Copyright(C), erfeng
 * FileName     : FSM.h
 * Author       : erfeng
 * Version      : V0.0.1 
 * Date         : 2018-07-07
 * Description  : 状态机框架头文件
**********************************************************************************/
#include "FSM.h"
#include <stdlib.h>
#include <stdio.h>

typedef int FSM_Event;
typedef int FSM_State;
typedef char* FSM_Output;
typedef void (*FSM_Handle)(void *param, int i);

typedef struct __fsm_table__{
    FSM_Event event;
    FSM_State curState;
    FSM_State nextState;
    FSM_Output output;
    FSM_Handle handle;
}FSM_table;

typedef struct __FSM
{
    FSM_table *fsmTable;
    int cnt;
    FSM_State curState; 
}FSM;

void FSM_register(FSM *pFSM, FSM_table *Ptable, int count, FSM_State curState);

void FSM_EventHandle(FSM *pFSM, FSM_Event event);


#endif /* __FSM_H__ */