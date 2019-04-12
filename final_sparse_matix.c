/**
*   AIM : TO IMPLEMENT SPARSE MATRIX  USING LINKED LIST AND TO CHECK WHETHER THE MATRIX IS A SPARSE MATRIX OR NOT
*   DEVELOPED BY : GROUP 1B OF IEM.
*   SUBJECT :- DATASTRUCTURE WITH C (BCAN-203)
*/

#include <stdio.h>
#include <stdlib.h>

struct node// declaration of the structure node
{
    int data;
    struct node *next;
};
//Declaration of the global variables
struct node *start= NULL;
static int zc=0,nzc=0,r,c,rc=0,cc=0,pc=0;
//Method to check whether the matrix is sparse or not
int check()
{
    struct node *q;
    q=start;
    while(q!=NULL)
    {
        if(q->data==0)
            zc++;
        else
            nzc++;
        q=q->next;
    }
    return (zc>nzc)?1:0;
}
// Method to display non zero elements in the matrix
void dispNZC()
{
    int f=check();
    if(f==0)
    {
        puts("\nThe matrix is not sparse ");
        return;
    }
    puts("\nThe matrix is sparse ");
    rc=0;cc=0;// To re-initialize the variables to 0
    struct node *q=start;
    while(q!=NULL)
    {
        if(q->data!=0)
        {
            printf("\nData is %d ",q->data);
            printf ("\nRow :- %d \t Col :- %d ",rc,cc);
        }
        q=q->next;
        cc++;
        if(cc==c)
        {
            cc=0;
            rc++;
        }
    }
}
// Method to display all the elements of the sparse matrix
void display()
{
    puts("The elements are : \n ");
    struct node *q;
    q=start;
    while(q!=NULL)
    {
        cc++;
        printf("%d\t",q->data);
        if(cc==c)
        {
            printf("\n");
            cc=0;
        }
        q=q->next;
    }
}
// Method used for getting the elements in the matrix
void getElements()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));// To allocate the memory dynamically
    printf("\nEnter data %d : ",pc+1);
    scanf("%d",&temp->data);
    if(start==NULL)
        temp->next=NULL;
    else
        temp->next=start;
    start=temp;
    pc++;
}
// Method used to reverse the elements of the linked list
void reverse()
{
    struct node *before,*present,*after;
    before=start;// To point the first pointer to start
    present=before->next;
    after=present->next;
    before->next=NULL;
    present->next=before;
    while(after!=NULL)// To check whether the node has list been traversed whole or not?
    {
        before=present;
        present=after;
        after=after->next;
        present->next=before;
    }
    start=present;// To point the start pointer to the last node
}
// Method used to get the row and column details from the user
void getRowCol()
{
    int f1,f2;
    // Loop used for checking whether the row and col. no. inputted by the user is valid or not
    do
    {
        puts("Enter row details : ");
        scanf("%d",&r);
        if(r>0)
            f1=1;
        puts("\nEnter col. details : ");
        scanf("%d",&c);
        if(c>0)
            f2=1;
        if(f1==1&&f2==1)
            break;
        else
            puts("Invalid Input !!!");
    }
    while(1);
    int i;
    for(i=0;i<r*c;i++)
        getElements();
}
// Method used to delete the memory allocated dynamically
void del()
{
    struct node *p;
    p=start;
    start=start->next;
    free(p);//To deallocate the dynamically allocated memory
}
// Main Method
int main()
{
    int i,ch;
    do
    {
        getRowCol();
        if(r*c!=1)
            reverse();
        display();
        dispNZC();
        for(i=0;i<r*c;i++)
            del();
        puts("\nSuccessfully deallocated the memory ");
        puts("\nEnter 1 to exit ");
        scanf("%d",&ch);
        if(ch==1)
            exit(0);
        zc=0;nzc=0;rc=0;cc=0;pc=0;// To reinitialize  the global variables to 0
    }
    while(1);
}
