#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
    FILE *f1 = fopen("File1.txt", "r");
    FILE *f2 = fopen("File2.txt", "a");
    char c;
    while ((c = fgetc(f1)) !=   EOF) 
    {
        fputc(c, f2);
    }
    fclose(f1);
    fclose(f2);
    return 0;
}