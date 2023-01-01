#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char name[20];
    int roll;
    float marks[5];
} student;
int findavg(student *s, int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            sum = sum + s[i].marks[j];
        }
    }
    sum = sum / (n * 5);
    printf("Average marks is : %f\n", sum);
}
int findtotal(student *s, int n)
{

    for (int i = 0; i < n; i++)
    {
        float sum = 0;
        for (int j = 0; j < 5; j++)
        {
            sum = sum + s[i].marks[j];
        }
        printf("\nThe Total Marks of student %d named %s is %0.2f\n", i + 1, s[i].name, sum);
    }
}
int sorttotal(student *s, int n)
{
    student temp;
    float sum[5] = {0, 0, 0, 0, 0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            sum[i] = sum[i] + s[i].marks[j];
        }
    }
    for (int i = 1; i < n; i++)
    {
        {
            for (int j = 0; j < n - i; j++)
                if (sum[j] < sum[j + 1])
                {
                    temp = s[j];
                    s[j] = s[j + 1];
                    s[j + 1] = temp;
                }
        }
    }
    printf("Sorted names according to marks are:\n");
    for (int j = 0; j < n; j++)
    {
        printf("Student with Rank %d is Name is %s\n", j + 1, s[j].name);
    }
}
int main()
{
    student *s;
    int n;
    float sum[5];

    s = malloc(n * sizeof(student));
    printf("Enter The Number of Students:\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the Name of the Student %d\n", i + 1);
        getchar();
        fgets(s[i].name, 20, stdin);
        printf("Enter the roll no of student %d\n", i + 1);
        scanf("%d", &s[i].roll);
        for (int j = 0; j < 5; j++)
        {
            printf("Enter the Marks of Student %d\n", i + 1);
            scanf("%f", &s[i].marks[j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("Student %d Name: %s\n", i + 1, s[i].name);
        printf("Roll no of student %d\n:%d", i + 1, s[i].roll);
        printf("\nThe Marks of Student %d\n", i + 1);
        for (int j = 0; j < 5; j++)
        {
            printf("Marks %d: %0.2f\n", j + 1, s[i].marks[j]);
        }
    }
    findavg(s, n);
    findtotal(s, n);
    sorttotal(s, n);

    return 0;
}