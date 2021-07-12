#include <stdlib.h>
#include <stdio.h>

unsigned int i;

struct Node{
    int val;
    struct Node * next;
};

struct Node *p, *pt;

void reverse(struct Node *l)
{
    struct Node *curr = l, *l2 = l;
    
    while (curr->next != NULL)
    {
        printf("- %u\n", curr);
        
        l2 = curr->next;
        
        curr->next->next = curr;
        
        curr = l2;
    }
    //curr->next = curr;
}

int main(void)
{
    p = (struct Node *)malloc(sizeof(struct Node));
    p->next = (struct Node *)malloc(sizeof(struct Node));
    p->next->next = (struct Node *)malloc(sizeof(struct Node));
    p->next->next->next = (struct Node *)malloc(sizeof(struct Node));
    p->next->next->next->next = NULL;
    //printf("%u\n", p);
    //printf("%u %u\n", p, p+1);


    pt = p;
    printf("%u %u \n", pt, pt->next);
    printf("%u %u \n", pt->next, pt->next->next);
    printf("%u %u \n", pt->next->next, pt->next->next->next);
    printf("%u %u \n", pt->next->next->next, pt->next->next->next->next);
    
    reverse(p);
    //pt = p->next->next->next;
    //printf("%u ---\n", pt);
    
    //printf("%u %u \n", pt, pt->next);
    //printf("%u %u \n", pt->next, pt->next->next);
    //printf("%u %u \n", pt->next->next, pt->next->next->next);
    //printf("%u %u \n", pt->next->next->next, pt->next->next->next->next);
    
    return 0;
}
