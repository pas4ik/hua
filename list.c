#include <stdlib.h>
#include <stdio.h>

unsigned int i;

struct Node{
    int val;
    struct Node * next;
} v[4];

struct Node * p = &v[0];

void reverse(struct Node *l)
{
    struct Node *curr = l;
    curr++->next = NULL;
    while (curr->next)
    {
        curr->next = curr-1;
        curr++;
    }
    curr->next = curr-1;
}

int main(void)
{
    v[0].next = &v[1];// + (struct Node *)malloc(sizeof(struct Node));
    v[1].next = &v[2];// + (struct Node *)malloc(sizeof(struct Node));
    v[2].next = &v[3];// + (struct Node *)malloc(sizeof(struct Node));
    v[3].next = NULL;
    printf("%u\n", p);
    for (i = 0; i < 4; i++)
    printf("%u %u \n", &v[i], (unsigned int)v[i].next);
    reverse(&v[0]);
    printf("---\n");
    for (i = 0; i < 4; i++)
    printf("%u %u \n", &v[i], (unsigned int)v[i].next);
    p = &v[3];
    printf("%u\n", p);
    return 0;
}
