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

void addst(int i)
{
    char name[30],mssv[10];
    double  mark;
    printf("%d.\n",i+1);
    printf("MSSV: ");
    scanf("%s", id);
    printf("NAME: ");
    scanf("%*c%[^\n]", name);
    printf("Diem Cbasic: ");
    scanf("%lf", &cbasic);

    struct student *link = (struct student*) malloc(sizeof(struct student));
    link->mark = mark;
    strcpy(link->name,name);
    strcpy(link->mssv,mssv);

    link->next = head;
    head = link;

}

void printst(int n)
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

int main()
{
    int n,i;
    printf("Nhap so sinh vien: ");
    scanf("%d", &n);

    for(i=0;i<n;i++)
    {
        addst(i);
    }

    printst(n);
}
