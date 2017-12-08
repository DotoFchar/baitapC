#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct queue_student
{
    char mssv[10];
    char name[30];
    double mark;

    struct queue_student *next;
};

struct queue_student *front;
struct queue_student *rear;
//int rear = 0;

void enqueue(char *mssv, char *name, char *mark)
{
    struct queue_student *link = (struct queue_student*) malloc(sizeof(struct queue_student));

    strcpy(link->mssv, mssv);
    strcpy(link->name, name);
    link->mark = (double)atof(mark);
    link->next = NULL;

    if (front == NULL) 
    {
        front = link; 
        rear = link;
    }
    else 
    {
        rear->next = link;
        rear = link;
    }    
}

struct queue_student* dequeue()
{
    struct queue_student *del;
    if (front == NULL) return NULL;
    del = front;
    front = front->next;
    return del;
}

//Hàm In khác để check việc in ra bằng dequeue
/*void print()
{
    struct queue_student *print = front;

    while(print!= NULL)
    {
        printf("%s,%s,%lf\n", print->id, print->name, print->cbasic);
        print= print->next;
    }
}*/

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
            if (fscanf(f, "%[^,],%[^,],%s",mssv, name,mark) == EOF) break;
            enqueue(mssv,name,mark);
        } while(getc(f)!=EOF);
    }
    fclose(f);

    //In ra de check 
    do
    {
        struct queue_student *print = (struct queue_student*) malloc(sizeof(struct queue_student));
        print = dequeue();
        if (print == NULL) break;
        printf("\n%s %s %lf", print->mssv, print->name, print->mark);
    } while(1);
    printf("\n");

    return 0;
}
