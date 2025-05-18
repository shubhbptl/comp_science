#include <stdio.h>
#include <stdlib.h>

typedef void* QUEUE;
enum status{FAILURE, SUCCESS};
typedef enum status Status;

enum boolean{FALSE,TRUE};
typedef enum boolean Boolean;

struct node;
typedef struct node Node;
struct node{
    int data;
    Node* next;
};

struct queue{
    Node* head;
    Node* tail;
};
typedef struct queue Queue;

QUEUE queue_init_default(void){
    Queue* pQ = (Queue*)malloc(sizeof(Queue));
    if(pQ != NULL){
        pQ->head = NULL;
        pQ->tail = NULL;
    }
    return pQ;
}

void print_list(QUEUE hQ){
    Queue* pQ = (Queue*) hQ;
    Node* curr = pQ->head;
    while(curr != NULL){
        printf("%d->",curr->data);
        curr = curr->next;
    }
    printf("NULL");
}

Boolean queue_is_empty(QUEUE hQ){
    Queue* pQ = (Queue*) hQ;
    return (pQ->head == NULL) ? TRUE : FALSE;
}
Status queue_insert(QUEUE hQ, int value){
    Queue* pQ = (Queue*) hQ;
    Node* temp = (Node*)malloc(sizeof(Node));
    if(temp == NULL){
        return FAILURE;
    }
    temp->data = value;
    temp->next = NULL;
    if(pQ->head == NULL){
        pQ->head = temp;
        pQ->tail = temp;
    }else{
        pQ->tail->next = temp;
        pQ->tail = temp;
    }
    return SUCCESS;
}

int queue_view(QUEUE hQ, Status* pStatus){
    Queue* pQ = (Queue*) hQ;
    if(queue_is_empty( pQ) == TRUE){
        if(pStatus != NULL){
            return FAILURE;
        }
        return -1337;
    }
    if(pStatus != NULL){
        return SUCCESS;
    }
    return pQ->head->data;
    
}
Status queue_remove(QUEUE hQ){
    Queue* pQ = (Queue*) hQ;
    Node* temp;
    if(pQ->head == NULL){
        return FAILURE;
    }
    temp = pQ->head;
    pQ->head = pQ->head->next;
    free(temp);
    return SUCCESS;
}
void queue_destory(QUEUE** hQ){
    Queue* pQ = (Queue*) *hQ;
    Node* temp;
    while(pQ->head != NULL){
        temp = pQ->head;
        pQ->head = pQ->head->next;
        free(temp);
    }
    free(pQ); pQ = NULL;
}

int main(int argc, char *argv[]) {
    int t;
    int w, num_of_cars;
    int l;
    int i;
    int trips = 0;
    int location = 0;
    int weight = 0;
    char LR[6];
    scanf("%d",&t);
    while(t > 0){
        scanf("%d %d",&w,&num_of_cars);
        w *= 100;
        QUEUE* lQ = queue_init_default();
        QUEUE* rQ = queue_init_default();
        if(lQ == NULL || rQ == NULL){
            exit(1);
        }
        for(i = 0; i < num_of_cars; i++){
            scanf("%d %s",&l,LR);
            if(LR[0] == 'l'){
                queue_insert(lQ, l);
            }else{
                queue_insert(rQ, l);
            }
        }
        trips = 0;
        location = 0;
        while(queue_is_empty(lQ) == FALSE || queue_is_empty(rQ) == FALSE){
            weight = 0;
            if(location == 0){
                while(queue_is_empty(lQ) == FALSE && weight + queue_view(lQ, NULL) <= w){
                    weight += queue_view(lQ,NULL);
                    queue_remove(lQ);
                }
            }else{
                while(queue_is_empty(rQ) == FALSE && weight + queue_view(rQ, NULL) <= w){
                    weight += queue_view(rQ,NULL);
                    queue_remove(rQ);
            }
        }
        trips++;
        location = !(location); 
    }
        printf("%d\n",trips);
        queue_remove(&lQ);
        queue_remove(&rQ);
        t--;
}
}