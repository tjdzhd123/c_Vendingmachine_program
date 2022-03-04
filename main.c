#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define BLACK 700
#define ULGRAY 700
#define MANGO 600
#define GGRAPE 300
#define SUGAR 300
struct drink_info{
     char name[10];
     int sugar;
     int ice;
     char pearl[10];
     int price;
};
typedef struct drink_info DRINK;
void black_input(DRINK *food, int insert_coin, int menu, int flag);
void ulgray_print(DRINK*food, int insert_coin, int menu);
void mango_input(DRINK*food, int insert_coin, int menu);
void ggrape_input(DRINK*food, int insert_coin, int menu);
void sugar_input(DRINK*food, int insert_coin, int menu);
void clear_print();
int money_return();
int minus_input(int mneu);
int insert_coin = 0;
int insert_coin2 = 0;
int total = 0;
int count = 0;

int main()
{
    DRINK food;
    int menu = 0;
    int flag = 0;
    int i = 0;

   while(!flag){
    printf("\t****안녕하세요 돈을 넣어주세요 *****\n");
    printf("\t**                                **\n");
    printf("\t**    --------------------        ** \n");
    printf("\t************************************\n");
    printf("투입된 금액 : %d \n", insert_coin);
    printf("돈 투입구 :");
    insert_coin2 = insert_coin;
    scanf("%d", &insert_coin);
    system("cls");

     printf("들어간 금액 : %d \n", insert_coin2+insert_coin);
     insert_coin = insert_coin2+insert_coin;
      printf(" ------------------------음료수자판기------------------------------\n");
      printf("│\t\t ① 블랙밀크티(700원)                             │\n");
      printf("│\t\t ② 얼그레이밀크티(700원)                         │\n");
      printf("│\t\t ③ 망고밀크티(600원)                             │\n");
      printf("│\t\t ④ 청포도밀크티(300원)                           │\n");
      printf("│\t\t ⑤ 흑당밀크티(300원)                             │\n");
      printf("│\t\t ⑥   반환하기                                    │\n");
      printf("│\t\t ⑦   종료하기                                    │\n");
      printf(" ------------------------------------------------------------------\n");
      printf("번호를 입력하세요. :");
      scanf("%d", &menu);

        switch(menu){
             case 1: black_input(&food, insert_coin, menu, flag);
                     getchar();
                     getchar();
                    insert_coin = minus_input(menu);
                     system("cls"); break;
             case 2: ulgray_print(&food, insert_coin, menu);
                     getchar();
                     getchar();
                    insert_coin = minus_input(menu);
                    system("cls"); break;
             case 3: mango_input(&food, insert_coin, menu);
                     getchar();
                     getchar();
                    insert_coin = minus_input(menu);
                     system("cls"); break;
             case 4: ggrape_input(&food, insert_coin, menu);
                     getchar();
                     getchar();
                    insert_coin = minus_input(menu);
                     system("cls"); break;
             case 5: sugar_input(&food, insert_coin, menu);
                     getchar();
                     getchar();
                    insert_coin = minus_input(menu);
                     system("cls"); break;
            case 6:  money_return();
                     printf("반환완료 하였습니다. \n");
                     getchar();
                     getchar();
                     system("cls"); break;
            case 7: flag = 1; printf("종료합니다. 이용해주셔서 감사합니다.\n"); break;
            default : printf("다시 입력하세요 \n");
        }
    }
    return 0;
}

int money_return(){
   int refund = 0;
   if(insert_coin > refund){
     insert_coin = 0;
   }

   return refund;
}

//투입된금액 - 선택한 음료의 총금액을 위한 함수선언
int minus_input(int menu){
    int returnfee = 0;

    if(insert_coin < total){
        return insert_coin;
    }
    switch(menu){
    case 1: menu = 700; break;
    case 2: menu = 700; break;
    case 3: menu = 600; break;
    case 4: menu = 300; break;
    case 5: menu = 300; break;
    default: menu = 0;
    }
        returnfee = insert_coin - menu*count;

    return returnfee;
   }


void black_input(DRINK *food, int insert_coin, int menu, int flag){
        char a = ""; //선택한 음료가 맞는지 확인하는 변수 생성
        char b = ""; //결제 확인 변수
        int i = 0;
        char answer = "";

        printf("블랙밀크티가 맞나요? 확인 Y/N :");
        scanf("%s", &a);

    if(insert_coin >= 700){
        if(a =='Y' || a =='y'){
            printf("몇개를 주문 하시나요? : ");
            scanf("%d", &count);
            total = BLACK*count;
            printf("당도를 선택하세요(*10* *30* *50* *70* *100*) :");
            scanf("%d", &food[i].sugar);
            printf("얼음 양을 선택하세요(*50* *70* *100*) : ");
            scanf("%d", &food[i].ice);
            printf("Pearl을 선택하세요 (밀크폼, 타피오카, 코코넛, 알로에):");
            scanf("%s", &food[i].pearl);
            printf("총 %d원입니다. 결제도와드릴까요? Y/N :", total);
            scanf("%s", &b);
        if(insert_coin < total){
            printf("잔액이 부족합니다. \n");
            return;
        }
        if(b =='Y' || b =='y'){
            printf("\n");
            clear_print();
            printf("★블랙밀크티 %d개 / 당도: %d / 얼음 양: %d / pearl : %s 나왔습니다. 맛있게드세요★ \n", count, food->sugar, food->ice, food->pearl);
            getchar();
            getchar();
            printf("계속 이용하시겠습니까? Y/N :");
            scanf("%s", &answer);
            if(answer == 'Y' || answer == 'y'){
                printf("처음으로 이동합니다. 감사합니다 (__)\n");
            }else if(answer =='N' || answer =='n'){
                printf("초기화면으로 이동해 종료해주세요. \n");
                flag = 1;
                return;
            }
        }else if(b =='N' || b =='n'){
            printf("처음으로 이동합니다. 감사합니다 (__)\n");
        }
        }else if(a=='N' || a=='n'){
            printf("다시 선택해주세요. 감사합니다. (__)\n");
        }
    }else{
        printf("잔액이 부족합니다. 처음으로 이동합니다. \n");
    }

    return;
}

void ulgray_print(DRINK*food, int insert_coin, int menu){
        char a = "";
        char b = "";
        int i = 0;
        char answer = "";

        printf("얼그레이밀크티가 맞나요? 확인 Y/N :");
        scanf("%s", &a);
    if(insert_coin >= 700){
        if(a =='Y' || a =='y'){
            printf("몇개를 주문 하시나요? : ");
            scanf("%d", &count);
            total = ULGRAY*count;
            printf("당도를 선택하세요(*10* *30* *50* *70* *100*) :");
            scanf("%d", &food[i].sugar);
            printf("얼음 양을 선택하세요(*50* *70* *100*) : ");
            scanf("%d", &food[i].ice);
            printf("Pearl을 선택하세요(밀크폼, 타피오카, 코코넛, 알로에):");
            scanf("%s", &food[i].pearl);
            printf("총 %d원입니다. 결제도와드릴까요? Y/N :", total);
            scanf("%s", &b);
        if(insert_coin < total){
            printf("잔액이 부족합니다. \n");
            return;
        }
        if(b =='Y' || b =='y'){
            printf("\n");
            clear_print();
            printf("★얼그레이밀크티 %d개 / 당도: %d / 얼음 양: %d / pearl : %s 나왔습니다. 맛있게드세요★ \n", count, food->sugar, food->ice, food->pearl);
            getchar();
            getchar();
            printf("계속 이용하시겠습니까? Y/N :");
            scanf("%s", &answer);
            if(answer == 'Y' || answer == 'y'){
                printf("처음으로 이동합니다. 감사합니다 (__)\n");
            }else if(answer =='N' || answer =='n'){
                printf("초기화면으로 이동해 종료해주세요. \n");
                return;
            }
        }else if(b =='N' || b =='n'){
            printf("처음으로 이동합니다. 감사합니다 (__)\n");
        }
        }else if(a=='N' || a=='n'){
            printf("다시 선택해주세요. 감사합니다. (__)\n");
        }
    }else{
        printf("잔액이 부족합니다. 처음으로 이동합니다. \n");
    }

    return;
}

void mango_input(DRINK*food, int insert_coin, int menu){
        char a = "";
        char b = "";
        int i = 0;
        char answer = "";

        printf("망고밀크티가 맞나요? 확인 Y/N :");
        scanf("%s", &a);
    if(insert_coin >= 600){
        if(a =='Y' || a =='y'){
            printf("몇개를 주문 하시나요? : ");
            scanf("%d", &count);
            total = MANGO*count;
            printf("당도를 선택하세요(*10* *30* *50* *70* *100*) :");
            scanf("%d", &food[i].sugar);
            printf("얼음 양을 선택하세요(*50* *70* *100*) : ");
            scanf("%d", &food[i].ice);
            printf("Pearl을 선택하세요(밀크폼, 타피오카, 코코넛, 알로에):");
            scanf("%s", &food[i].pearl);
            printf("총 %d원입니다. 결제도와드릴까요? Y/N :", total);
            scanf("%s", &b);
        if(insert_coin < total){
            printf("잔액이 부족합니다. \n");
            return;
        }
        if(b =='Y' || b =='y'){
            printf("\n");
            clear_print();
            printf("★망고밀크티 %d개 / 당도: %d / 얼음 양: %d / pearl : %s 나왔습니다. 맛있게드세요★ \n", count, food->sugar, food->ice, food->pearl);
            getchar();
            getchar();
            printf("계속 이용하시겠습니까? Y/N :");
            scanf("%s", &answer);
            if(answer == 'Y' || answer == 'y'){
                printf("처음으로 이동합니다. 감사합니다 (__)\n");
            }else if(answer =='N' || answer =='n'){
                printf("초기화면으로 이동해 종료해주세요. \n");
                return;
            }
        }else if(b =='N' || b =='n'){
            printf("처음으로 이동합니다. 감사합니다 (__)\n");
        }
        }else if(a=='N' || a=='n'){
            printf("다시 선택해주세요. 감사합니다. (__)\n");
        }
    }else{
        printf("잔액이 부족합니다. 처음으로 이동합니다. \n");
    }

    return;
}

void ggrape_input(DRINK*food, int insert_coin, int menu){
        char a = "";
        char b = "";
        int i = 0;
        char answer = "";

        printf("청포도밀크티가 맞나요? 확인 Y/N :");
        scanf("%s", &a);
    if(insert_coin >= 300){
        if(a =='Y' || a =='y'){
            printf("몇개를 주문 하시나요? : ");
            scanf("%d", &count);
            total = GGRAPE*count;
            printf("당도를 선택하세요(*10* *30* *50* *70* *100*) :");
            scanf("%d", &food[i].sugar);
            printf("얼음 양을 선택하세요(*50* *70* *100*) : ");
            scanf("%d", &food[i].ice);
            printf("Pearl을 선택하세요(밀크폼, 타피오카, 코코넛, 알로에):");
            scanf("%s", &food[i].pearl);
            printf("총 %d원입니다. 결제도와드릴까요? Y/N :", total);
            scanf("%s", &b);
        if(insert_coin < total){
            printf("잔액이 부족합니다. \n");
            return;
        }
        if(b =='Y' || b =='y'){
            printf("\n");
            clear_print();
            printf("★청포도밀크티 %d개 / 당도: %d 얼음 / 양: %d / pearl : %s 나왔습니다. 맛있게드세요★ \n", count, food->sugar, food->ice, food->pearl);
            getchar();
            getchar();
            printf("계속 이용하시겠습니까? :");
            scanf("%s", &answer);
            if(answer == 'Y' || answer == 'y'){
                printf("처음으로 이동합니다. 감사합니다 (__)\n");
            }else if(answer =='N' || answer =='n'){
                printf("초기화면으로 이동해 종료해주세요. \n");
                return;
            }
        }else if(b =='N' || b =='n'){
            printf("처음으로 이동합니다. 감사합니다 (__)\n");
        }
        }else if(a=='N' || a=='n'){
            printf("다시 선택해주세요. 감사합니다. (__)\n");
        }
    }else{
        printf("잔액이 부족합니다. 처음으로 이동합니다. \n");
    }

    return;
}

void sugar_input(DRINK*food, int insert_coin, int menu){
        char a = "";
        char b = "";
        int i = 0;
        char answer = "";

        printf("흑당밀크티가 맞나요? 확인 Y/N :");
        scanf("%s", &a);
    if(insert_coin >= 300){
        if(a =='Y' || a =='y'){
            printf("몇개를 주문 하시나요? : ");
            scanf("%d", &count);
            total = SUGAR*count;
            printf("당도를 선택하세요(*10* *30* *50* *70* *100*) :");
            scanf("%d", &food[i].sugar);
            printf("얼음 양을 선택하세요(*50* *70* *100*) : ");
            scanf("%d", &food[i].ice);
            printf("Pearl을 선택하세요(밀크폼, 타피오카, 코코넛, 알로에):");
            scanf("%s", &food[i].pearl);
            printf("총 %d원입니다. 결제도와드릴까요? Y/N :", total);
            scanf("%s", &b);
        if(insert_coin < total){
            printf("잔액이 부족합니다. \n");
            return;
        }
        if(b =='Y' || b =='y'){
            printf("\n");
            clear_print();
             printf("★흑당밀크티 %d개 / 당도: %d / 얼음 양: %d / pearl : %s 나왔습니다. 맛있게드세요★ \n", count, food->sugar, food->ice, food->pearl);
            getchar();
            getchar();
            printf("계속 이용하시겠습니까? Y/N :");
            scanf("%s", &answer);
            if(answer == 'Y' || answer == 'y'){
                printf("처음으로 이동합니다. 감사합니다 (__)\n");
            }else if(answer =='N' || answer =='n'){
                printf("초기화면으로 이동해 종료해주세요. \n");
                return;
            }
        }else if(b =='N' || b =='n'){
            printf("처음으로 이동합니다. 감사합니다 (__)\n");
        }
        }else if(a=='N' || a=='n'){
            printf("다시 선택해주세요. 감사합니다. (__)\n");
        }
    }else{
        printf("잔액이 부족합니다. 처음으로 이동합니다. \n");
    }

    return;
}

void clear_print(){
    int i = 0;

    for(i = 0; i < 1; i++){
        printf("음료 제작중...\n");
        Sleep(1000);
        printf("선택한 pearl 넣는중... \n");
        Sleep(1000);
        printf("조금만 기다려주세요... \n");
        Sleep(1000);
        printf("음료 나왔습니다! \n");
    }
    printf("\n");
    printf("         ＿＿＿           \n");
    printf("        [＿＿  ]          \n");
    printf("             [ ]          \n");
    printf("             [ ]          \n");
    printf("     l￣￣￣￣  ￣￣￣￣l \n");
    printf("     l￣￣￣￣￣￣￣￣￣l \n");
    printf("     l                  l \n");
    printf("     l                  l \n");
    printf("     l                  l \n");
    printf("     l                  l \n");
    printf("     l                  l \n");
    printf("     l                  l \n");
    printf("     l                  l \n");
    printf("     l  ● ● ● ● ●  l \n");
    printf("     l● ● ● ● ● ● l \n");
    printf("      ￣￣￣￣￣￣￣￣￣  \n");


    return;
}

