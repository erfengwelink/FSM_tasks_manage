#ifndef _U_FSM_H_
#define _U_FSM_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef int FSM_Event_t;
typedef int FSM_State_t;
typedef char* FSM_Debug_t;
typedef void (*FSM_Handle_t)(void *param);
typedef int FSM_timeOut_val_t;

typedef bool (*FSM_time_compare_t)(int timeout);

typedef struct __fsm_table__{
    FSM_Event_t event;
    FSM_State_t curState;
    FSM_State_t nextState;
    FSM_Debug_t debug;
    FSM_Handle_t eventHandle;
    FSM_timeOut_val_t tval;       /* timeout value */
    FSM_State_t timeOutState;      /* timeout >> next state       */
    FSM_Handle_t timeOutHandle;    /* 0 timeout handle function   */
}FSM_table_t;


typedef struct __FSM
{
    // bool NoEventTrigger;
    int cnt;
    FSM_table_t *fsmTable;
    FSM_Event_t trigger;
    FSM_State_t curState; 
    FSM_time_compare_t cmpFunc;
}FSM_t;


enum{
    EVENT_NONE,
    EVENT_0,
    EVENT_1,
    EVENT_2,
    EVENT_3,
    EVENT_4,
    EVENT_MAX
};

enum{
    ST_NONE,
    ST_0,
    ST_1,
    ST_2,
    ST_3,
    ST_4,
    ST_5
};


#ifdef __cplusplus
extern "C" {
#endif

// int FSM_init(FSM_t *fsm);
void FSM_register(FSM_t *pfsm, FSM_table_t *ptable, int count, FSM_State_t curState, FSM_time_compare_t cmpFunc);
void xFSM_init_default(FSM_t *pfms, FSM_time_compare_t cmpFunc);
void FMS_run(FSM_t *pfms, FSM_Event_t event);

// void register_fsm();

#ifdef __cplusplus
}
#endif

#endif /* _U_FSM_H_  */