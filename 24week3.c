#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 6

struct queue_student
{
    char mssv[10];
    char name[30];
    double mark;
};

struct queue_student student[MAX];
int top = 0;
int rear = -1;
int count = 0;


int empty_queue()
{
    if (count==0) return 1;
    else return 0; 
}

int full_queue()
{
    if (count==MAX) return 1;
    else return 0;
}

void add_student(char *mssv, char *name, double mark)
{
    if (full_queue()==0)
    {
        if (rear+1==MAX) rear=-1;
        ++rear;
        strcpy(student[rear].mssv, mssv);
        strcpy(student[rear].name, name);
        student[rear].mark = mark;

       printf("%s, %s, %lf\n", student[rear].id, student[rear].name, student[rear].cbasic);
        count++;
    }
}

struct queue_student remove_student()
{
    struct queue_student current_top;
    if (empty_queue()!=1)
    {
        current_top = student[top++];
        if (top == MAX) top = 0;
        count--;
    }
    return current_top;
}

int main()
{
    FILE *f;
    f = fopen("sinhvien.dat", "r+");
    if (f == NULL) perror("Khong the mo FILE");
    else 
    {
        do 
        {
            char mssv[10], name[30], mark[10];
            if (fscanf(f, "%[^,],%[^,],%s", mssv, name, mark) == EOF) break;
            add_student(mssv, name, (double)atof(mark));
        } while(getc(f)!=EOF);
    }
    fclose(f);
    
    while(count!=0)
    {
        struct queue_student print = remove_student();
        printf("%s, %s, %lf\n", print.mssv, print.name, print.mark);
    }
    return 0;
}
