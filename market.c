#include "manager.h"

int selectMenu(){
        int menu;
        printf("\n1. 조회\n");
        printf("2. 추가\n");
        printf("3. 수정\n");
        printf("4. 삭제\n");
        printf("5. 저장\n");
        printf("6. 검색\n");
        printf("0. 종료\n\n");
        printf("=> 원하는 메뉴는? ");
        scanf("%d", &menu);

        return menu;
}

int main(void){
    Snack *sp[100];
    int curcount=0, count = 0, menu;

    count = loadFile(sp);
    curcount = count;
    while (1){
        menu = selectMenu();
        #ifdef DEBUG
                printf("Debug: %s %s %s %d  INPUT : menu <= %d\n", __DATE__, __TIME__, __FILE__, __LINE__,menu);
        #endif
        if (menu == 0) {
            break;
        }
        if (menu == 1) {
            if(count>0) listSnack(sp, curcount);
            else printf("조회할 제품이 없습니다!\n");
        }
        if (menu == 2) {
            sp[curcount] = (Snack *)malloc(sizeof(Snack));
            count+=createSnack(sp[curcount++]);
        }
        if (menu == 3) {
            int no = listNumber(sp, curcount);
            if(no == 0){
            printf("=> 취소됨!\n");
            continue;
            }
            updateSnack(sp[no-1]);
        }
        if (menu == 4) {
            int no = listNumber(sp, curcount);
            if(no == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            int deleteok;
            printf("정말로 삭제하시겠습니까?(삭제 :1)");
            scanf("%d", &deleteok);
            if(deleteok == 1){
                #ifdef DEBUG
                        printf("Debug: %s %s %s %d\n INPUT : deleteok <= %d", __DATE__, __TIME__, __FILE__, __LINE__,deleteok);
                #endif
                printf("=> 삭제됨!\n");
                if(sp[no-1]) free(sp[no-1]);
                sp[no-1] = NULL;
                count--;
            }
        }
        if (menu == 5){
            if(count < 0)
                printf("불러올 제품이 없습니다!\n");
            else
                saveFile(sp, curcount);
        }
        if (menu == 6){
            searchSnack(sp,curcount);
        }
    }
    printf("종료됨!\n");

    return 0;
}
