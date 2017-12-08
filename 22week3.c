#include <stdio.h>
#include <stdlib.h>
#define MAX 8


struct stack_student
{
    char mssv[10];
    char name[30];
    double mark;
};

struct stack_student stack[MAX];
static int top=-1; 

void print_stack()
{
    int i=0;
    while (i!=top)
    {
        printf("%s,%s,%lf\n", stack[i].mssv, stack[i].name, stack[i].mark);
        i++;
    }
}

int main()
{
    FILE *f;
    f = fopen("sinhvien.dat", "r+");
    do 
    {
        char mark[10];
        top++;
        if (fscanf(f, "%[^,],%[^,],%s", stack[top].mssv, stack[top].name, mark) == EOF) break;
        stack[top].mark = (double)atof(mark);
    } while(getc(f)!=EOF);
    fclose(f);
    print_stack();
    return 0;
}
