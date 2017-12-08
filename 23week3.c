#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack_student
{
    char mssv[10];
    char name[30];
    double mark;
    struct stack_student *next;
};

struct stack_student *head;

void add_top(char *mssv, char *name, char *mark)
{
    struct stack_student *link = (struct stack_student *)malloc(sizeof(struct stack_student));

    strcpy(link->mssv, mssv);
    strcpy(link->name, name);
    link->mark = (double)atof(mark);
//ep kieu
    link->next = head;
    head = link;
}

void print_stack()
{
    struct stack_student *print = head;

    while(print!= NULL)
    {
        printf("%s,%s,%lf\n", print->mssv, print->name, print->mark);
        print= print->next;
    }
}

int main()
{
    FILE *f;
    f = fopen("sinhvien.dat", "r+");
    if (f==NULL) perror("Khong doc duoc FILE");
    else 
    {
        char mssv[10], name[30], mark[10];

        do 
        {
            if (fscanf(f, "%[^,],%[^,],%s", mssv, name, mark) == EOF) break;
            add_top(mssv,name,mark);
        } while(getc(f)!=EOF);
    }
    fclose(f);

    print_stack();

    return 0;
}
