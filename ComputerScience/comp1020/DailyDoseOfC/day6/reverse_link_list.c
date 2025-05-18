#include <stdio.h>
#include <stdlib.h>

/**********************************************************************
Program: <Reverse_Linked_listm>
Author: <Shubh Patel>
Date: <02/12/25>
Time spent: <30min>
Purpose: The purpose of this program is to reverse a linked list using 3 pointer prev,current,next.
***********************************************************************/

struct node;
typedef struct node Node;

struct node
{
	int data;
	Node* next;
};

//declare your function here.
Node* reverse_link_list(Node* head);

int main(int argc, char* argv[])
{
    Node* head = NULL;
	int i;
	Node* temp;
    
	//set up a test list with values 9->8->7->...->0
	for (i = 0; i < 10; i++)
	{
        temp = (Node*)malloc(sizeof(Node));
		if (temp == NULL)
		{
            printf("out of memory?\n");
			exit(1);
		}
		temp->data = i;
		temp->next = head;
		head = temp;
	}
    
	//call your function to reverse the list (should work for any list given the head node pointer).
    
    head = reverse_link_list(head);
	//print the reversed list.
	temp = head;
	while (temp != NULL)
	{
         printf("%d\n", temp->data);
		temp = temp->next;
	}
    
	return 0;
}


Node* reverse_link_list(Node* head){
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
    
    return prev;
}