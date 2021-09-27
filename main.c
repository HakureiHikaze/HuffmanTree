#include <stdio.h>
#include "LList.h"

char compare(void* a, void* b){
    if((a > b)) return 1;
    else return 0;
}
int main() {
    LList list = ListInit();
    for(int i = 4; i>=0; i--){
        ListAppend(&list, (void*)i);
    }
    for(int i = 0; i<5; i++){
        int b = ListRemove(&list, ListFindMin(list,compare));
        printf("\ni:%d\nb:%d\n",i,b);
    }
    return 0;
}

