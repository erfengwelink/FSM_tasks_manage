#include "bubble_sort.h"
#include <stdio.h>
#include <string.h>

#include "esp_log.h"
#include "esp_console.h"
#include "argtable3/argtable3.h"


//2 5 3 7 6
int *bubble_sort(int *arr, int *size)
{
    int max = *size;
    int temp = 0;
    for (int i = 0; i < max; i++)
    {
        temp = arr[i];
        for (int j = i + 1; j < max; j++)
        {
            if (arr[j] < arr[i])
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    return arr;
}

static void case_print(int type, int *arr, int *size)
{
    int max = *size;
    if(type)
    {
        printf("After:\n");
    }
    else
    {
        printf("Before:\n");
    }
    for(int k=0; k<max; k++)
    {
        printf("%d ->  ", arr[k]);
    }
    printf("\r\n");
}

void bubble_sort_test(void)
{
    int array[] = { 2, 4, 78, 21, 3, 9};
    int size = sizeof(array)/sizeof(int);
    case_print(0, array, &size);
    case_print(1, bubble_sort(array, &size), &size);
}

