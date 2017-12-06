#include <stdio.h>
#include <string.h>
int main()
{
    char s[255];
    printf("Nhap xau: ");
    scanf("%[^\n]", s);
    int i,check=0;
    for (i=0; i<strlen(s); i++)
    {
        printf("%c", s[i]);
        if ((s[i]==' ')&&(check==0))
        {
            printf("\n");
            check++;
        }
    }
    printf("\n");
    return 0;
}
