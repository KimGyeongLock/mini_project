#include "manager.h"

void listSnack(Snack *s[],int count){
    printf("================================\n");
    int i;
    for( i = 0;i<count;i++){
       
        if(s[i] == NULL) continue;
        printf("[%d] ",i+1);
        readSnack(*s[i]);
    }
}
int listNumber(Snack *s[],int count){
    int no;
    listSnack(s, count);
    printf("\n번호는 (취소 :0)? ");
    scanf("%d", &no);
    return no;
}
