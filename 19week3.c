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
//struct student *current;

int menu()
{
    int c;
    printf("1. Them 1 sinh vien (Tu dong sap xep)\n");
    printf("2. Tim Theo MSSV\n");
    printf("3. Xoa Theo MSSV\n");
    printf("4. Xem tat ca\n");
    printf("5. Thoat\n");
    scanf("%d%*c",&c);
    return c;
}
//cai ham nay mk tao ra lam gi nhi?lol
struct student* insertwhere(double mark)
{
    struct student *insert=head;
    struct student *aft_insert=head->next;
    while(insert!=NULL)
    {
        if (insert->next==NULL)
        {
            return insert;
        }
        else if ((insert->mark<mark) && (aft_insert->mark>mark))
        {
            return insert;
        }
        aft_insert = aft_insert->next;
        insert = insert->next;
    }
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
    if (head==NULL) 
    {
        link->next = head;
        head=link;
    }
    else if (head->mark>link->mark) 
    {
        link->next=head;
        head=link;
    }
    else 
    {
        link->next=insertwhere(mark)->next;     
        insertwhere(mark)->next=link;
    }
    /*link->next = ?;
    head = link;*/
}

void printall()
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
    struct student *fms = head;
    while(fms != NULL)
    {
        if (strcmp(fms->mssv,mssv)==0) 
        {
            printf("\nResult: \n");
            printf("\nMSSV: %s", fms->mssv);
            printf("\nNAME: %s", fms->name);
            printf("\nDiem Cbasic: %lf\n\n", fms->mark);
            return 1;
        }
        fms = fms->next;
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
