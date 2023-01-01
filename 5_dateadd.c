#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int month;
    int year;
    int day;
} date_t;
int compdate(date_t *time1, date_t *time2)
{
    if (time1->day == time2->day && time1->month == time2->month && time1->year == time2->year)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    date_t t1, t2;
    int arr[3];
    printf("Enter 1st day:\n");
    scanf("%d", &t1.day);
    printf("Enter 1st month:\n");
    scanf("%d", &t1.month);
    printf("Enter 1st year:\n");
    scanf("%d", &t1.year);
    printf("Enter 2nd day:\n");
    scanf("%d", &t2.day);
    printf("Enter 2nd month:\n");
    scanf("%d", &t2.month);
    printf("Enter 2nd year\n");
    scanf("%d", &t2.year);
    if (compdate(&t1, &t2))
    {
        printf("The dates %d/%d/%d is EQUAL to %d/%d/%d", t1.day, t1.month, t1.year, t2.day, t2.month, t2.year);
    }
    else
    {
        printf("The dates %d/%d/%d is UNEQUAL to %d/%d/%d", t1.day, t1.month, t1.year, t2.day, t2.month, t2.year);
    }
    return 0;
}
