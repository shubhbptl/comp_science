#include <stdlib.h>
#include <stdio.h>

/**********************************************************************
Program: Sum_Linked_List
Author: Shubh Patel
Date: 02/13/2025
Time spent: 4hr
Purpose: The purpose of this program is to sum two linked lists and output the result.
***********************************************************************/

struct node;
typedef struct node Node;
struct node{
    int data;
    Node* next;
};

void head_insert(Node** head, int value);
void print_list(Node* head);
Node* list_sum(Node** head1, Node** head2);
void destroy_list(Node* head);
Node* reverse_list(Node* head);

int main(int argc, char* argv[]){
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* head_sum = NULL;
    
    // Create a list for the number 189 (stored as 1 -> 8 -> 9)
    head_insert(&head1, 9);
    head_insert(&head1, 8);
    head_insert(&head1, 1);
    
    // Create a list for the number 11 (stored as 1 -> 1)
    head_insert(&head2, 1);
    head_insert(&head2, 1);
    
    // Pass the addresses of head1 and head2 so that list_sum can reverse and restore them.
    head_sum = list_sum(&head1, &head2);
    
    printf("The sum of ");
    print_list(head1);
    printf(" + ");
    print_list(head2);
    printf("\n = ");
    print_list(head_sum);
    printf("\n");
    
    // Clean up all lists
    destroy_list(head1);
    destroy_list(head2);
    destroy_list(head_sum);
    
    return 0;
}

void head_insert(Node** head, int value){
    Node* temp = (Node*)malloc(sizeof(Node));
    if(temp == NULL){
        printf("Failed to allocate memory\n");
        exit(1);
    }
    temp->data = value;
    temp->next = (*head);
    (*head) = temp;
}

// reverse_list reverses a linked list and returns the new head.
Node* reverse_list(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// reverses the result list, and then restores the original lists.
Node* list_sum(Node** head1, Node** head2){
    Node* dummy = (Node*)malloc(sizeof(Node));
    if(dummy == NULL){
        printf("Failed to allocate memory\n");
        exit(1);
    }
    dummy->data = 0;
    dummy->next = NULL;
    Node* ptr = dummy;
    
    // Reverse both input lists and update the originals.
    *head1 = reverse_list(*head1);
    *head2 = reverse_list(*head2);
    
    Node* nHead1 = *head1;
    Node* nHead2 = *head2;
    int carry = 0;
    
    // Add corresponding digits until both lists are exhausted and there is no carry.
    while(nHead1 != NULL || nHead2 != NULL || carry != 0){
        int sum = carry;
        if(nHead1 != NULL){
            sum += nHead1->data;
            nHead1 = nHead1->next;
        }
        if(nHead2 != NULL){
            sum += nHead2->data;
            nHead2 = nHead2->next;
        }
        carry = sum / 10;
        Node* newNode = (Node*)malloc(sizeof(Node));
        if(newNode == NULL){
            printf("Failed to allocate memory\n");
            exit(1);
        }
        newNode->data = sum % 10;
        newNode->next = NULL;
        ptr->next = newNode;
        ptr = ptr->next;
    }
    
    // The sum is currently in reverse order. Reverse it to get the proper order.
    Node* result = reverse_list(dummy->next);
    free(dummy);
    
    // Restore the original lists to forward order.
    *head1 = reverse_list(*head1);
    *head2 = reverse_list(*head2);
    
    return result;
}

// print_list prints the entire number by accumulating digits.
void print_list(Node* head){
    Node* current = head;
    if(head == NULL){
        printf("0");
        return;
    }
    while(current != NULL){
        printf("%d",current->data);
        current = current->next;
    }
}

void destroy_list(Node* head){
    Node* temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}
