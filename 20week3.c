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

struct student_clone
{
    char mssv[10];
    char name[30];
    double mark;
} ;

int menu()
{
    int c;
    printf("1. Them 1 sinh vien\n");
    printf("2. Tim Theo MSSV\n");
    printf("3. Xoa Theo MSSV\n");
    printf("4. Xem tat ca\n");
    printf("5. Thoat\n");
    printf("6. Xuat file\n");
    printf("7. Doc file sinhvien.dat va sinh vien co diem Cbasic>4\n");
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

    link->next = head;
    head = link;
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

    char ms[10];
    printf("\nMSSV can xoa: ");
    scanf("%s", ms);
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

void putfile()
{
    FILE * file;
    struct student *fout = head;
    file = fopen("sinhvien.dat","w+");
    while (fout != NULL)
    {
        fprintf(file, "%s,%s,%lf", fout->mssv, fout->name, fout->mark);
        fputc('\n',file);
        fout=fout->next;
    }
    fclose(file);
}

void readfile()
{
    FILE * fin;
    struct student_clone sv[100];
    int count=0;
    fin = fopen("sinhvien.dat", "r+");
    printf("start");
    if (fin == NULL) perror("LOI KHONG THAY DU LIEU");
    else {
        do
        {
            char mark[10];
            if (fscanf(fin,"%[^,],%[^,],%s",sv[count].mssv, sv[count].name, mark) == EOF) break;
            sv[count].mark=(double)atof(mark);
            count++;
        } while (fgetc(fin)!= EOF);
        
    }
    fclose(fin);

    int i;
    for (i=0; i<count; i++)
    {
        printf("\nMSSV: %s", sv[i].mssv);
        printf("\nNAME: %s", sv[i].name);
        printf("\nDiem Cbasic: %lf\n", sv[i].mark);
    }
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
            case 6: putfile(); break;
            case 7: readfile(); break;
        }
    }
    return 0;
}
