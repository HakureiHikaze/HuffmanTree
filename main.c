#include <stdio.h>
#include "LList.h"

char compare(void* a, void* b){
    if((a > b)) return 1;
    else return 0;
}
char compareInt(void* a, void* b){
    if((*((int*)a))>(*((int*)b))) return 1;
    else return 0;
}
int main() {
    LList list = ListInit();
    int x[100];
    for(int i = 99; i>=0; i--){
        x[i] = i;
        ListAppend(&list,x+(99-i));
    }
    for(int i = 0; i<100; i++){
        int b = *(int*)ListRemove(&list, ListFindMin(list,compareInt));
        printf("i:%d\tb:%d\n",i,b);
    }
    return 0;
}

