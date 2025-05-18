#include <stdio.h>
#include <stdlib.h>

struct node;

typedef struct node Node;

struct node{
    int value;
    Node* next;
};

void output_list(Node* head){
    while(head != NULL){
        printf("%d->",head->value);
        head = head->next;
    }
    printf("NULL");
}
void recursive_list(Node* head){
    if(head != NULL){
        printf("%d->",head->value);
        recursive_list(head->next);
    }else{
        printf("NULL");
    }
}
Node* insert_at_tail(Node* head, int value){
    Node* temp;
    Node* current;
    temp = (Node*)malloc(sizeof(Node));
    if(temp == NULL){
        printf("NULL");
    }
    temp->value = value;
    temp->next = NULL;

    if(head == NULL){
        head = temp;
    }
    else{
        current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = temp;
    }
    return head;
}
Node* recursive_insert_at_tail(Node* head, int value){
    if(head == NULL){
        head = (Node*)malloc(sizeof(Node));
        if(head == NULL){
            printf("Failed");
            exit(1);
        }
        head->value = value;
        head->next = NULL;
    }
    else{
        head->next = recursive_insert_at_tail(head->next, value);
    }
    return head;
}

void reference_insert_at_tail(Node** pHead, int value){
    Node* temp;
    Node* current;
    temp = (Node*)malloc(sizeof(Node));
    if(temp == NULL){
        exit(1);
    }
    temp->value = value;
    temp->next = NULL;

    if(*pHead == NULL){
        *pHead = temp;
    }else{
        current = *pHead;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp;
    }
}

void reference_recursive_insert_at_tail(Node** pHead, int value){
    if(*pHead == NULL){
        *pHead = (Node*)malloc(sizeof(Node));
        if(*pHead == NULL){
            exit(1);
        }
        (*pHead)->value = value;
        (*pHead)->next = NULL;
    }else{
        reference_recursive_insert_at_tail(&((*pHead)->next),value);
    }
}

int sum_list(Node* head){
    int sum = 0;
    while(head != NULL){
        sum += head->value;
        head = head->next;
    }
    return sum;
}
int recursive_sum_list(Node* head){
    if(head == NULL){
        return 0;
    }else{
        return head->value + recursive_sum_list(head->next);
    }
}

int count_node(Node* head){
    int count = 0;
    while(head != NULL){
        count++;
        head = head->next;
    }
    return count;
}
int recursive_count_node(Node* head){
    if(head == NULL){
        return 0;
    }else{
        return 1 + recursive_count_node(head->next);
    }
}

int main(int argc, char* argv[])
{
    Node* head = NULL;

    head = (Node*)malloc(sizeof(Node));
    if(head == NULL){
        printf("failed to allocate space for node.\n");
    }
    head->value = 42;
    head->next = (Node*)malloc(sizeof(Node));
    if(head == NULL){
        printf("failed to allocate space for node.\n");
    }
    head->next->value = 100;
    head->next->next = (Node*)malloc(sizeof(Node));
    if(head == NULL){
        printf("failed to allocate space for node.\n");
    }
    head->next->next = NULL;
    recursive_list(head);
    printf("%d",sum_list(head));
    recursive_sum_list(head);
    return 0;
}