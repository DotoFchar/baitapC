#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct noop 
{
    char name[100];
    int HP;
    int AT;
    int DF;
    int PP;
    struct noop* next;
};

typedef struct noop noop;

int menu()
{
    printf("1. Doc Du Lieu\n2. CHIEN NAO!\n3. Xep Hang\n4. Thoat\n");
    
    char s[10];
    int c;
    scanf("%[^\n]%*c", s);
    c = atoi(s);
    return c;
}

void printList(noop * head)
{
    struct noop *ptr= (head);
    while(ptr != NULL)
    {        
        printf("%s HP%d AT%d PP%d DF%d\n",ptr->name,ptr->HP,ptr->AT,ptr->PP,ptr->DF);
        ptr = ptr->next;
    }
}

void enqueue(noop ** Team, noop **rear, noop ** temp)
{
    (*temp)->next = NULL;

    if (*Team == NULL) 
    {
        *Team = *temp; 
        *rear = *temp;
    }
    else 
    {
        (*rear)->next = *temp;
        *rear = *temp;
    }    
}

struct noop* dequeue(noop ** front, noop ** rear)
{
    struct noop *del;
    if ((*front) == NULL) return NULL;
    else if ((*rear)!=(*front))
    {
        del = (*front);
        (*front) = (*front)->next;
    }
    else 
    {
        del = (*rear);
        rear=NULL;
        (*front)=NULL;
    }
    return del;
}


int getData(noop ** Team, noop ** rear,int i)
{
    FILE *f;
    if (i==1) f = fopen("dataT1.txt", "r+");
    else if (i==2) f = fopen("dataT2.txt", "r+");
    if (f == NULL) 
    {
        perror("Can't open File\n");
        return -1;
    }
    do
    {
        noop *temp= (noop*)malloc(sizeof(noop));
        if (fscanf(f,"%s %d %d %d %d",temp->name, &temp->HP, &temp->AT, &temp->PP, &temp->DF)==EOF) break;
        enqueue(Team, rear, &temp);
    } while (1);
    fclose(f);
    printf("Team %d:\n", i);
    printList((*Team));
    return 0;
}

int endGame(noop * P1, noop * P2)
{
    if (P1 == NULL) return 2;
    if (P2 == NULL) return 1;
    else return 0;
}

noop * oneRound(noop ** P1, noop ** P2)
{
    if ((*P1)->HP<=0)
    {
        printf("%s bi loai\n\n", (*P1)->name);
        return *P2;
    }
    if ((*P2)->HP<=0)
    {
        printf("%s bi loai\n\n", (*P2)->name);
        return *P1;
    } 
    (*P2)->HP = (*P2)->HP- (*P1)->AT+ (*P2)->DF;
    printf("%s(%d) tan cong - %s(%d) mat %dHP\n", (*P1)->name, (*P1)->HP, (*P2)->name, (*P2)->HP, (*P1)->AT- (*P2)->DF);
    oneRound(P2,P1);
}

void setBattle(noop ** T1,noop ** T1rear, noop ** T2, noop ** T2rear)
{
    noop * playerT1= dequeue(T1, T1rear);
    noop * playerT2= dequeue(T2, T2rear);
    do 
    {
        noop * winner;
        if (playerT1->PP>playerT2->PP) winner = oneRound(&playerT1,&playerT2);
        else winner=oneRound(&playerT2,&playerT1);

        if (winner== playerT2) playerT1= dequeue(T1, T1rear);
        else if (winner == playerT1) playerT2= dequeue(T2, T2rear);
    } while(endGame(playerT1, playerT2)==0);
}

int main()
{
    int c;
    noop *T1=NULL; noop *T1rear=NULL;
    noop *T2=NULL; noop *T2rear=NULL;
    
    while (c!=4)
    {
        c = menu();
        switch (c)
        {
            case 1: getData(&T1,&T1rear,1); getData(&T2,&T2rear,2); 
            break;
            case 2: setBattle(&T1,&T1rear,&T2,&T2rear);
            break;
            case 3: //rankNoop();
            break;
        }
    }
    
    return 0;
}