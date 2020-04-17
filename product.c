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
    int curcount=0, count = 0, menu=0;

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
s21900064@peace:~/2020OSS/mini_project$ vim market.c
s21900064@peace:~/2020OSS/mini_project$ vim product.c
s21900064@peace:~/2020OSS/mini_project$ cat product.c
#include "product.h"

int createSnack(Snack *s){
        printf("제품명은? ");
        getchar();
        fgets(s->name,sizeof(s->name),stdin);
        s->name[strlen(s->name)-1]='\0';
        printf("중량은? ");
        scanf("%d", &s->gram);
        printf("가격은? ");
        scanf("%d", &s->price);
        printf("별점수는? ");
        scanf("%d", &s->star);

        return 1;
        }
void readSnack(Snack s){
        s.g_price = s.price * 10/ s.gram;
        printf("%s %dg\n    %d 원\n    (10g 당 %d 원)\n    ★★★★★(%d 개)\n",s.name,s.gram,s.price,s.g_price,s.star);
}
int updateSnack(Snack *s){
        printf("새 제품명은? ");
        getchar();
        fgets(s->name,sizeof(s->name),stdin);
        s->name[strlen(s->name)-1]='\0';
        printf("새 중량은? ");
        scanf("%d", &s->gram);
        printf("새 가격은? ");
        scanf("%d", &s->price);
        printf("새 별점수는? ");
        scanf("%d", &s->star);
        printf("=> 수정성공!\n");

        return 1;
}
int deleteSnack(Snack *s){
        s = NULL;
        printf("=> 삭제됨!\n");

        return 1;
}

int loadFile(Snack *s[]){
    int count = 0;
    FILE *fp;
    fp = fopen("snack.txt", "rt");
    if(fp == NULL){
        printf("=> 파일 없음\n");
        return 0;
    }
    for(;;count++){
       if(feof(fp)) break;
       s[count] =  (Snack*)malloc(sizeof(Snack));
        fgets(s[count]->name,sizeof(s[count]->name),fp);
        s[count]->name[strlen(s[count]->name)-1]='\0';
        fscanf(fp,"%d %d %d\n",&s[count]->gram, &s[count]->price, &s[count]->star);
    }
    fclose(fp);
    printf("=> 로딩성공!\n");
    return count;
}

void saveFile(Snack *s[],int count){
    FILE *fp;
    fp = fopen("snack.txt", "wt");

    for(int i=0;i<count;i++){
        if(s[i] != NULL){
           s[count] =  (Snack*)malloc(sizeof(Snack));
            fprintf(fp,"%s\n%d %d %d\n",s[i]->name,s[i]->gram,s[i]->price,s[i]->star);

        }
    }
    fclose(fp);
    printf("저장됨!\n");
}

void searchSnack(Snack *s[], int count){
    int menu;
    printf("1. 키워드\n");
    printf("2. 가격\n");
    printf("3. 별점수\n");
    printf("무엇을 검색하시겠습니까? ");
    scanf("%d",&menu);
    if(menu==1) searchName(s,count);
    if(menu==2) searchPrice(s,count);
    if(menu==3) searchStar(s,count);
}
void searchName(Snack *s[],int count){
    int scount =0;
    char search[20];
    getchar();
    printf("검색할 키워드? ");
    scanf("%s",search);

    printf("================================\n");

    for(int i =0;i<count;i++){
        if(s[i] != NULL){
            if(strstr(s[i]->name,search)){
                printf("[%d] ", i+1);
                readSnack(*s[i]);
                scount++;
            }
        }
    }
    if(scount == 0) printf("=> 검색된 데이터 없음!\n");
}
void searchPrice(Snack *s[],int count){
    int scount =0;
    int search;
    printf("검색할 가격? ");
    scanf("%d", &search);

    printf("================================\n");
    for(int i =0;i<count;i++){
        if(s[i] != NULL){
            if(s[i]->price==search){
                printf("[%d] ", i+1);
                readSnack(*s[i]);
                scount++;
            }
        }
    }
    if(scount == 0) printf("=> 검색된 데이터 없음!\n");
}
void searchStar(Snack *s[],int count){
    int scount =0;
    int search;
    printf("검색할 별점수? ");
    scanf("%d", &search);
    printf("================================\n");
    for(int i =0;i<count;i++){
        if(s[i] != NULL){
            if(s[i]->star==search){
                printf("[%d] ", i+1);
                readSnack(*s[i]);
                scount++;
            }
        }
    }
    if(scount == 0) printf("=> 검색된 데이터 없음!\n");
}

