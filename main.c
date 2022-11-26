#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
// Definition de la structure
typedef struct node
{
    int val;
    struct node *link;
} node;

node *L2, *temp, *L1, *L;
int i = 1, alt;
// Def de fonction de creation

node *creation(int n)
{
    // La fonction de creation de "Nodes"
    node *HEAD = NULL;
    node *TEMP = NULL;
    node *P = NULL;

    for (int i = 0; i < n; i++)
    {

        TEMP = (node *)malloc(sizeof(node));
        printf("Entrer la valeur %d \n", i + 1);
        scanf("%d", &(TEMP->val));
        TEMP->link = NULL;

        if (HEAD == NULL)
        {
            HEAD = TEMP;
        }
        else
        {

            P = HEAD;
            while (P->link != NULL)
            {
                P = P->link;
            } // Loop
            P->link = TEMP;

        } // else
    }
    return HEAD;
}

void display(node *HEAD)
{

    node *P = HEAD;

    while (P != NULL)
    {
        printf("%d->", P->val);
        P = P->link;
    }
    printf("\n");
}
// la fonction de la deffirance
int diff(int ptr, node *tet2)
{

    node *ptr2 = tet2, *nouv = NULL, *TEMP, *P;
    int flag = 0;

    flag = 0;

    while (ptr2 != NULL)
    {
        if ((ptr) == (ptr2->val))
        {
            flag = 1;
            return 1;
        }
        ptr2 = ptr2->link;
    }

    return flag;
}
node *fon(node *L1, node *L2)
{
    node *ptr1 = L1, *ptr2 = L2, *Tet1 = NULL, *TEMP = NULL, *P = NULL;
    int flag = 0;

    while (ptr1 != NULL)
    {

        flag = diff(ptr1->val, L2);
        if (flag == 0)
        {
            // printf("%d\t%d\n",flag,ptr1->val);
            TEMP = (node *)malloc(sizeof(node));
            // printf("RoZA %d\n",x);
            // printf("amores %d\n",pos);
            if (TEMP == NULL)
                printf("NULLLLL\n");
            TEMP->val = ptr1->val;
            TEMP->link = NULL;
            if (Tet1 == NULL)
            {
                Tet1 = TEMP;
            }
            else
            {

                P = Tet1;
                while (P->link != NULL)
                {
                    P = P->link;
                    // printf("////%d////\n",1);
                } // Loop
                P->link = TEMP;
            }
        }

        ptr1 = ptr1->link;
    }
    return Tet1;
}
int main()
{
    int n = 0;
    // LA premier liste
    printf("Voulez vous entrer la taille de list 1: ");
    scanf("%d", &n);
    L1 = creation(n);
    // LA deuxieme list
    printf("Voulez vous entrer la taille de list 2: ");
    scanf("%d", &n);
    L2 = creation(n);
    // L'affichage
    display(L1);
    display(L2);
    // troiseme list
    L = fon(L1, L2);
    printf("\n--------------------------------\n");
    display(L);
    return 0;
}
