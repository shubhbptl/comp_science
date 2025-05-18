#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************
Program: <Ferry Loading>
Author: <Shubh Patel>
Date: <01 Mar 2025>
Time spent: <5hr>
Purpose: transport cars from one size to another size using queue data structure implemented using linked list.
***********************************************************************/

int main(int argc, char *argv[]) {
    int t;
    scanf("%d",&t);
    while(t > 0){
        int w, num_of_cars;
        scanf("%d %d",&w,&num_of_cars);
        w *= 100;
        QUEUE* lQ = queue_init_default();
        QUEUE* rQ = queue_init_default();
        if(lQ == NULL || rQ == NULL){
            exit(1);
        }
        // addes lengths to left and right queues
        for(int i = 0; i < num_of_cars; i++){
            int l;
            char LR[6];
            scanf("%d %s",&l,LR);
            if(LR[0] == 'l'){
                queue_insert(lQ, l);
            }else{
                queue_insert(rQ, l);
            }
        }
        int trips = 0;
        int location = 0; // 0 = left, 1 = right
        while(queue_is_empty(lQ) == FALSE || queue_is_empty(rQ) == FALSE){
            int weight = 0;
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
        location = !(location); //flips boolean
    }
        printf("%d\n",trips);
        queue_remove(&lQ);
        queue_remove(&rQ);
        t--;
}
}