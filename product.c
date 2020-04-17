nclude "product.h"
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
 s.g_price = s.price * 10 / s.gram;
 printf("%s %dg\n%d 원\n(10g 당
%d 원)\n★★★★★(%d 개)\n",s.name,s.gram,s.price,s.g_price,s.star);
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
