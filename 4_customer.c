#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct
{
    int accnum;
    char name[MAX];
    float balance;
} customer;
void printlowbal(customer *custom, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (custom[i].balance < 1000)
        {
            printf("Customer no:-%d with low balance is %s with account number:%d and balance %f\n", i + 1, custom[i].name, custom[i].accnum, custom[i].balance);
        }
        else
            printf("No low balance account\n");
        printf("Exited successfully\n");
    }
}
void balminus(customer *custom, int n, float amount, int transaction)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (custom[i].accnum == transaction)
        {
            if (amount > custom[i].balance)
            {
                printf("****************\n");
                printf("The balance is insufficient for the specified withdrawal\n");
            }

            else
            {

                custom[i].balance = custom[i].balance - amount;
            }
        }
    }
}
void baladd(customer *custom, int n, float amount, int transaction)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (custom[i].accnum == transaction)
        {

            custom[i].balance = custom[i].balance + amount;
        }
    }
}

int main()
{
    int n, g, h, p, j, transaction;
    float amount;
    char c;
    customer *cust;
    printf("Enter the number of Customers:\n");
    scanf("%d", &n);
    cust = malloc(n * sizeof(customer));
    for (int i = 0; i < n; i++)
    {
        printf("Enter Customer Name:-");
        getchar();
        fgets(cust[i].name, MAX, stdin);
        printf("\n");
        printf("Enter Customer Account Number:-");
        scanf("%d", &cust[i].accnum);
        printf("\n");
        printf("Enter Customer Balance:-");
        scanf("%f", &cust[i].balance);
        printf("\n");
    }
    for (int i = 0; i < n; i++)
    {
        printf("Customer- %d Name-%sAccount Number-%d Balance-%f\n", i + 1, cust[i].name, cust[i].accnum, cust[i].balance);
    }
    printf("Do you want a transaction to occur from any Customer?\n");
    printf("Press 1 for Yes or press 2 for Cancel:-");
    scanf("%d", &g);
    while (g == 1)
    {
        printf("Do you want to Withdraw or Deposit from any Customer?\n");
        printf("********************************\n");
        printf("Press 0 for Withdraw or press 1 for Deposit:-");
        scanf("%d", &h);
        printf("Enter the amount to be transferred:-");
        scanf("%f", &amount);
        printf("Enter the account number to transfer:-");
        scanf("%d", &transaction);
        if (h == 0)
        {

            balminus(cust, n, amount, transaction);
        }
        else if (h == 1)
        {
            baladd(cust, n, amount, transaction);
        }
        printf("Do you want to continue with the transactions (y/n):");
        scanf("%s", &c);
        if (c == 'n')
        {
            g++;
        }
    }
    printf("Exited successfully\n");

    printf("Do you want to Display the transaction:\n");
    printf("Enter 1 to Display Enter 0 to Cancel\n");
    scanf("%d", &p);
    if (p == 1)
    {
        for (int i = 0; i < n; i++)
        {
            {
                printf("Customer- %d Name-%sAccount Number-%d Balance-%f\n", i + 1, cust[i].name, cust[i].accnum, cust[i].balance);
            }
        }
    }

    printf("************************\n");

    printf("Do you want to Display the account's with low balance?\n");
    printf("Enter 1 to Display Enter 0 to Cancel\n");
    scanf("%d", &j);
    if (j == 1)
    {
        printlowbal(cust, n);
    }
    else
    {
        printf("Exited successfully\n");
    }
    return 0;
}