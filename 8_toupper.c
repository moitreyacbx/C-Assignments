#include <stdio.h>
int main()
{
    FILE *f1, *f2;
    f1 = fopen("07file1.txt", "w");
    char c, buff[500];
    printf("Enter any text : \n");
    scanf("%[^\n]", buff);
    fprintf(f1, buff);
    fclose(f1);

    f1 = fopen("07file1.txt", "r");
    f2 = fopen("07file2.txt", "w");
    while (1)
    {
        c = fgetc(f1);
        if (c == EOF)
            break;
        if (c >= 'a' && c <= 'z')
        {
            c -= ('a' - 'A');
        }
        fputc(c, f2);
    }

    fclose(f2);
    fclose(f1);
}