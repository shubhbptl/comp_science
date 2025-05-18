#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node{
    int value;
    Node* next;
};

Node* recursive_insert_at_tail(Node* head, int value){
    Node* temp;
    temp = (Node*)malloc(sizeof(Node));
    temp->value = value;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
    }else{
        head->next = recursive_insert_at_tail(head->next,value);
    }
    return head;
}


Node* insert_at_tail(Node* head, int value){
    Node* temp;
    Node* current;
    temp = (Node*)malloc(sizeof(Node));
    temp->value = value;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
    }else{
        current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = temp;
    }
    return head;
}
void list_show(Node* head){
    if(head != NULL){
        printf("%d->", head->value);
        list_show(head->next);
    }else{
        printf("NULL");
    }
}

void recursive_list_show(Node* head){
    if(head == NULL){
        printf("NULL");
    }else{
        printf("%d->", head->value);
        recursive_list_show(head->next);
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
int sum_link_node(Node* head){
    int sum = 0;
    while(head != NULL){
    sum += head->value;
    head = head->next;
    }
    return sum;
}

int recursive_sum_link_node(Node* head){
    if(head == NULL){
        return 0;
    }else{
        return head->value + recursive_sum_link_node(head->next);
    }
}

void print_reverse_linked_list(Node* head){
    if(head != NULL){
        print_reverse_linked_list(head->next);
        printf("%d->", head->value);
    }
}

Node* head_insert(Node* head, int value){
    Node* temp = (Node*)malloc(sizeof(Node));
    if(temp == NULL){
        exit(1);
    }
    temp->value = value;
    temp->next = head;
    return temp;
}
void reference_head_insert(Node** pHead, int value){
    Node* temp = (Node*)malloc(sizeof(Node));
    if(temp == NULL){
        exit(1);
    }
    temp->value = value;
    temp->next = (*pHead);
    (*pHead) = temp;
}

// bugs and need to fix index
Node* insert_at_certian_point(Node* head, int index, int value){
    Node* ptr1 = head;
    Node* temp = (Node*)malloc(sizeof(Node));
    if(temp == NULL){
        exit(1);
    }
    temp->value = value;
    temp->next = NULL;
    index--;
    while(index != 1){
        ptr1 = ptr1->next;
        index--;
    }
    temp->next = ptr1->next;
    ptr1->next = temp;
    return head; 
}
void delete_list(Node* head){
    Node* temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}
int main(int argc, char* argv[]){
    Node* head;
    /////////////////
    // non-node-pointer:
    Node data;
    data.value = 20;
    data.next = (Node*)malloc(sizeof(Node));
    data.next->next = NULL;
    printf("%d",data.next->next->value);
    ///////////////////////////
    head = (Node*)malloc(sizeof(Node));
    if(head == NULL){
        exit(1);
    }
    head->value = 10;
    head->next = (Node*)malloc(sizeof(Node));
    head->next->value = 20;
    head->next->next = NULL;
    recursive_insert_at_tail(head, 15);
    reference_recursive_insert_at_tail(&head,20);
    printf("Sum of link_node: %d\n", sum_link_node(head));
    printf("Sum of link_node: %d\n", recursive_sum_link_node(head));
    reference_head_insert(&head, 1);
    head = insert_at_certian_point(head,0,10);
    // reverse_linked_list(head);
    recursive_list_show(head);
    delete_list(head); head = NULL;
    return 0;
}