#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
    char mssv[10];
    char name[30];
    double mark;
    struct student *next;
} ;
struct student *head;
struct student *current;

int menu()
{
    int c;
    printf("1. Them 1 sinh vien\n");
    printf("2. Tim Theo MSSV\n");
    printf("3. Xoa Theo MSSV\n");
    printf("4. Xem tat ca\n");
    printf("5. Thoat\n");
    scanf("%d%*c",&c);
    return c;
}

void insert()
{
    char name[30];
    char mssv[10];
    double mark;
    printf("\n");
    printf("MSSV: ");
    scanf("%s", mssv);
    printf("NAME: ");
    scanf("%*c%[^\n]", name);
    printf("Diem Cbasic: ");
    scanf("%lf", &mark);

    struct student *link = (struct student*) malloc(sizeof(struct student));
    link->mark = mark;
    strcpy(link->name,name);
    strcpy(link->mssv,mssv);
//SAO CHEP CHUOI
    link->next = head;
    head = link;
}

void printall()//show all
{
    struct student *prt = head;
    
        while(prt != NULL)
        {
            printf("\nMSSV: %s", prt->mssv);
            printf("\nNAME: %s", prt->name);
            printf("\nDiem Cbasic: %lf\n", prt->mark);
            prt = prt->next;
        }
}

int find()
{
    char mssv[10];
    printf("\nMSSV can tim: ");
    scanf("%s", mssv);
    struct student *fmssv = head;
    while(fmssv != NULL)
    {
        if (strcmp(fmssv->mssv,mssv)==0) //so sanh
        {
            printf("\nResult: \n");
            printf("\nMSSV: %s", fmssv->mssv);
            printf("\nNAME: %s", fmssv->name);
            printf("\nDiem Cbasic: %lf\n\n", fmssv->mark);
            return 1;
        }
        fmssv = fmssv->next;
    }
    printf("\nKhong tim thay ket qua.\n");
    return 0;
}

int delete()
{
    struct student *del = head;
    struct student *prv = NULL;

    char mssv[10];
    printf("\nMSSV can xoa: ");
    scanf("%s", mssv);
    if (head == NULL) return 0;
    while (del!=NULL)
    {
        if (strcmp(del->mssv, mssv)==0) break;
        prv = del;
        del = del->next;  
    }
    if (del==NULL) printf("\nKhong co ket qua,\n");
    else if (del->next==NULL) prv->next=NULL;
    else if (del == head) head = head->next;
    else prv->next = del->next;
}

int main()
{       
    int c;
    while (c!=5)
    {
        c=menu();
        switch (c)
        {
            case 1: insert(); break;
            case 2: find(); break;
            case 3: delete(); break;
            case 4: printall(); break;
        }
    }
    return 0;
}
