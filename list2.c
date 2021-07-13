#include <stdlib.h>
#include <stdio.h>

struct Node{
    int val;
    struct Node * next;
};

struct Node *p, *p_new;

void reverse(struct Node *l)
{
    struct Node *prev = NULL, *curr = l, *next;
    
    while (curr != NULL)
    {
        next = curr->next;  // a->b
        curr->next = prev;  // b->c
        prev = curr;        // c->d
        curr = next;        // next stage
   }
}

int main(void)
{
    p = (struct Node *)malloc(sizeof(struct Node));
    p->next = (struct Node *)malloc(sizeof(struct Node));
    p->next->next = (struct Node *)malloc(sizeof(struct Node));
    p->next->next->next = (struct Node *)malloc(sizeof(struct Node));
    p->next->next->next->next = NULL;

    printf("%u %u \n", p, p->next);
    printf("%u %u \n", p->next, p->next->next);
    printf("%u %u \n", p->next->next, p->next->next->next);
    printf("%u %u \n", p->next->next->next, p->next->next->next->next);
    
    p_new = p->next->next->next;
    reverse(p);
    printf("p_new = %u \n", p_new);
    
    printf("%u %u \n", p_new, p_new->next);
    printf("%u %u \n", p_new->next, p_new->next->next);
    printf("%u %u \n", p_new->next->next, p_new->next->next->next);
    printf("%u %u \n", p_new->next->next->next, p_new->next->next->next->next);
    
    return 0;
}
