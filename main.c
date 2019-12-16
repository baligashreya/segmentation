#include<stdio.h>
#include<conio.h>
struct list
{
    int seg;
    int base;
    int limit;
    struct list *next;
} *p;
void insert(struct list *q,int base,int limit,int seg)
{

    if(p==NULL)
    {
        p=malloc(sizeof(struct list));
        p->limit=limit;
        p->base=base;
        p->seg=seg;
        p->next=NULL;
    }
    else
    {
        while(q->next!=NULL)
        {

            q=q->next;
            printf("yes");
        }
        q->next=malloc(sizeof(struct list));
        q->next->limit=limit;
        q->next->base=base;
        q->next->seg=seg;
        q->next->next=NULL;

    }
}
int find(struct list *q,int seg)
{

    while(q->seg!=seg)
    {
        q=q->next;
    }
    return q->limit;
}
int search(struct list *q,int seg)
{

    while(q->seg!=seg)
    {
        q=q->next;
    }
    return q->base;
}
int main()
{

    p=NULL;
    int seg,offset,limit,base,c,s,physical;
    printf("enter segment table\n");
    printf("enter -1 as segment value for termination\n");
    do
    {
        printf("enter segment number");
        scanf("%d",&seg);
        if(seg!=-1)
        {

            printf("enter base value:");
            scanf("%d",&base);
            printf("enter the value for limit:");
            scanf("%d",&limit);
            insert(p,base,limit,seg);
        }
    }while(seg!=-1);
    {
        printf("enter offset");
        scanf("%d",&offset);
        printf("enter segmentation number");
        scanf("%d",&seg);
        c=find(p,seg);
        s=search(p,seg);
        if(offset<c)
        {

            physical=s+offset;
            printf("address in physical memory %d\n",physical);
        }
        else
        {
            printf("error");
        }
    }
}
