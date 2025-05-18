#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("How many integer you need to have? ");
    scanf("%d", &n);

    int* pn;
    pn =  (int*) malloc(sizeof(int) * n);

    if(pn == NULL){
        printf("Failed");
        exit(1);
    }
    for(int i =0; i<n; i++){
        pn[i] = rand();
    }

    for(int i =0; i<n; i++){
        printf("%d\n", pn[i]);
    }

    printf("The address of p stores is %p\n", pn);
    free(pn); pn == NULL;
    printf("The address of p stores is %p", pn);

    return 0;

}