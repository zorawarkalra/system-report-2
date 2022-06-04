#include <stdio.h>
#include <stdlib.h>

struct node {
    int arr;       
    struct node *next; 
}*head;


void operation(int a);
void displayList();
void deletebeginning();

void main()
{
    int a, arr;

    printf("Insert Your Storage Requirement of Nodes : ");
    scanf("%d", &a);
    operation(a);

    printf("Before Data Operation in the list : \n");
    displayList();
    
    deletebeginning();
    
    printf("After Performing Data Operation in the list : \n");
    displayList();
    
}

void operation(int a){
	
    struct node *newNode,*temp;
    int arr, i;

    head = (struct node *)malloc(sizeof(struct node));
    
    printf("Enter the arr of node 1 : ");
    scanf("%d", &arr);
    head->arr = arr; 
    head->next = NULL; 
    temp = head;
         
    for(i=2; i<=a; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the arr of node %d: ", i);
        scanf("%d", &arr);
        newNode->arr = arr; 
        newNode->next = NULL;
        temp->next = newNode; 
        temp = temp->next; 
    }
    printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
}

void deletebeginning(){
	struct node *toDelete;
	toDelete = head;
    head = head->next;
    printf("\nData deleted = %d\n", toDelete->arr);
    free(toDelete);
    printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST ");
}


void displayList(){
    struct node *temp;
    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("Elements = %d\n", temp->arr); 
            temp = temp->next;            
        }
    }
}

