#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int hour;
    int minute;
    int second;
} timeval;
int add_time(timeval *time1, timeval *time2, int *arr)
{
    int sum = 0;
    int sum2 = 0;
    int sum3 = 0;
    sum = time1->hour + time2->hour;
    sum2 = time1->minute + time2->minute;
    sum3 = time1->second + time2->second;
    if (sum3 >= 60)
    {
        sum2++;
        sum3 = sum3 - 60;
        arr[2] = sum3;
    }
    else
    {
        arr[2] = sum3;
    }
    if (sum2 >= 60)
    {
        sum++;
        sum2 = sum2 - 60;
        arr[1] = sum2;
    }
    else
    {
        arr[1] = sum2;
    }
    if (sum >= 24)
    {
        sum = sum - 24;
        arr[0] = sum;
        arr[3] = 1;
    }
    else
    {
        arr[0] = sum;
        arr[3] = 0;
    }
}
int main()
{
    timeval t1, t2;
    int arr[3];
    printf("Enter 1st Hour:\n");
    scanf("%d", &t1.hour);
    printf("Enter 1st Minute:\n");
    scanf("%d", &t1.minute);
    printf("Enter 1st Second:\n");
    scanf("%d", &t1.second);
    printf("Enter 2nd Hour:\n");
    scanf("%d", &t2.hour);
    printf("Enter 2nd Minute:\n");
    scanf("%d", &t2.minute);
    printf("Enter 2nd Second:\n");
    scanf("%d", &t2.second);
    add_time(&t1, &t2, &*arr);
    printf("The added time is %d:%d:%d with %d days added", arr[0], arr[1], arr[2], arr[3]);
    return 0;
}
