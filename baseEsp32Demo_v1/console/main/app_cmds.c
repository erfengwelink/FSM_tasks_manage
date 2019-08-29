#include <stdio.h>
#include <string.h>
#include "esp_log.h"
#include "esp_console.h"
#include "argtable3/argtable3.h"

#include "app_cmds.h"


/*********************************************************/
/* uFSM block | start */
/*********************************************************/
#include "uFSM.h"
static struct {
    struct arg_int *type;
    struct arg_int *param;
    struct arg_end *end;
} fms_args;
//xFSM -t 1 -p 1
//xFSM -t 2 -p 1


static int xFSM(int argc, char** argv)
{
    static FSM_t fsm;
    static FSM_time_compare_t cmp;
    int type = 0;
    int param = 0;
    int nerrors = arg_parse(argc, argv, (void**) &fms_args);
    if (nerrors != 0) {
        arg_print_errors(stderr, fms_args.end, argv[0]);
        return 1;
    }
    ESP_LOGI(__func__, "  arg_parse '%s' OK!", __func__);

    type = fms_args.type->ival[0];
    param = fms_args.param->ival[0];
    ESP_LOGI(__func__, "  arg_parse '%s' OK! type-> %d | param-> %d", __func__,  type, param);
    switch ( type )
    {
    case 1:/* constant-expression */
        xFSM_init_default(&fsm, cmp);
        break;
    case 2:/* constant-expression */
    if(param > EVENT_NONE && param <= EVENT_4)
    {
        for(int i=0; i < 1000; i++)
        {
            FMS_run(&fsm, param);
        } 
    }
    else
    {
        ESP_LOGI(__func__, "  arg_parse '%s' param out of valid range!", __func__);
    }

        break;
    
    default:
        break;
    }
    return 0;
}


static void register_fsm()
{
    fms_args.type = arg_int0("t", "type", "<t>", "type, enum");
    fms_args.type->ival[0] = 1; // set default value
    fms_args.param =  arg_int0("p", "parameter", "<p>", "parameter, enum");
    // fms_args.param->ival[0] = 1;
    fms_args.end = arg_end(2);

    const esp_console_cmd_t fms_cmd = {
        .command = "xFSM",
        .help = "xFSM -t 1 -p 1",
        .hint = NULL,
        .func = &xFSM,
        .argtable = &fms_args
    };

    ESP_ERROR_CHECK( esp_console_cmd_register(&fms_cmd) );
}

/*********************************************************/
/* uFSM block | end */
/*********************************************************/





/*********************************************************/
/* sort block | start */
/*********************************************************/


#include "bubble_sort.h"

static struct {
    struct arg_int *typeCode;
    struct arg_int *parameter;
    struct arg_end *end;
} bubble_args;


static int xSORTS(int argc, char **argv)
{
    int type = 0;
    int param = 0;
    printf(">>>>>>>>>>>>>> \r\n xSORTS start 1 >>>>>>>>>>>>>\r\n");
    int nerrors = arg_parse(argc, argv, (void **)&bubble_args);
    printf(">>>>>>>>>>>>>> \r\n xSORTS start 2 >>>>>>>>>>>>>\r\n");
    if (nerrors != 0)
    {
        arg_print_errors(stderr, bubble_args.end, argv[0]);
        return 1;
    }
    type = bubble_args.typeCode->ival[0];
    param = bubble_args.parameter->ival[0];
    switch(type)
    {
        case 1:
        bubble_sort_test();
        break;
        case 2:
        printf(" bubble_args.parameter-> %d \n", param);
        break;

        default:

        break;
    }

    return 0;
}

static void register_sorts()
{
    bubble_args.typeCode = arg_int0("t", "type code", "<ival>", "type fuc code");
    bubble_args.typeCode->ival = 0;
    bubble_args.parameter = arg_int0("p", "parameter code", "<ival>", "parameter code");
    bubble_args.end = arg_end(2);
    const esp_console_cmd_t cmd = {
        .command = "xSORTS",
        .help = "xSORTS -t 1 -p 0",
        .hint = NULL,
        .func = &xSORTS,
        .argtable = &bubble_args
        };
    ESP_ERROR_CHECK(esp_console_cmd_register(&cmd));
}


/*********************************************************/
/* sort block | end */
/*********************************************************/




#include "cmd_system.h"
#include "cmd_wifi.h"

void app_console_register_default()
{
    /* Register commands */
    esp_console_register_help_command();
    // register_system();
    // register_wifi();
    register_fsm();
    // register_sorts();


}