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
    printf("\t****�ȳ��ϼ��� ���� �־��ּ��� *****\n");
    printf("\t**                                **\n");
    printf("\t**    --------------------        ** \n");
    printf("\t************************************\n");
    printf("���Ե� �ݾ� : %d \n", insert_coin);
    printf("�� ���Ա� :");
    insert_coin2 = insert_coin;
    scanf("%d", &insert_coin);
    system("cls");

     printf("�� �ݾ� : %d \n", insert_coin2+insert_coin);
     insert_coin = insert_coin2+insert_coin;
      printf(" ------------------------��������Ǳ�------------------------------\n");
      printf("��\t\t �� ����ũƼ(700��)                             ��\n");
      printf("��\t\t �� ��׷��̹�ũƼ(700��)                         ��\n");
      printf("��\t\t �� �����ũƼ(600��)                             ��\n");
      printf("��\t\t �� û������ũƼ(300��)                           ��\n");
      printf("��\t\t �� ����ũƼ(300��)                             ��\n");
      printf("��\t\t ��   ��ȯ�ϱ�                                    ��\n");
      printf("��\t\t ��   �����ϱ�                                    ��\n");
      printf(" ------------------------------------------------------------------\n");
      printf("��ȣ�� �Է��ϼ���. :");
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
                     printf("��ȯ�Ϸ� �Ͽ����ϴ�. \n");
                     getchar();
                     getchar();
                     system("cls"); break;
            case 7: flag = 1; printf("�����մϴ�. �̿����ּż� �����մϴ�.\n"); break;
            default : printf("�ٽ� �Է��ϼ��� \n");
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

//���Եȱݾ� - ������ ������ �ѱݾ��� ���� �Լ�����
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
        char a = ""; //������ ���ᰡ �´��� Ȯ���ϴ� ���� ����
        char b = ""; //���� Ȯ�� ����
        int i = 0;
        char answer = "";

        printf("����ũƼ�� �³���? Ȯ�� Y/N :");
        scanf("%s", &a);

    if(insert_coin >= 700){
        if(a =='Y' || a =='y'){
            printf("��� �ֹ� �Ͻó���? : ");
            scanf("%d", &count);
            total = BLACK*count;
            printf("�絵�� �����ϼ���(*10* *30* *50* *70* *100*) :");
            scanf("%d", &food[i].sugar);
            printf("���� ���� �����ϼ���(*50* *70* *100*) : ");
            scanf("%d", &food[i].ice);
            printf("Pearl�� �����ϼ��� (��ũ��, Ÿ�ǿ�ī, ���ڳ�, �˷ο�):");
            scanf("%s", &food[i].pearl);
            printf("�� %d���Դϴ�. �������͵帱���? Y/N :", total);
            scanf("%s", &b);
        if(insert_coin < total){
            printf("�ܾ��� �����մϴ�. \n");
            return;
        }
        if(b =='Y' || b =='y'){
            printf("\n");
            clear_print();
            printf("�ں���ũƼ %d�� / �絵: %d / ���� ��: %d / pearl : %s ���Խ��ϴ�. ���ְԵ弼��� \n", count, food->sugar, food->ice, food->pearl);
            getchar();
            getchar();
            printf("��� �̿��Ͻðڽ��ϱ�? Y/N :");
            scanf("%s", &answer);
            if(answer == 'Y' || answer == 'y'){
                printf("ó������ �̵��մϴ�. �����մϴ� (__)\n");
            }else if(answer =='N' || answer =='n'){
                printf("�ʱ�ȭ������ �̵��� �������ּ���. \n");
                flag = 1;
                return;
            }
        }else if(b =='N' || b =='n'){
            printf("ó������ �̵��մϴ�. �����մϴ� (__)\n");
        }
        }else if(a=='N' || a=='n'){
            printf("�ٽ� �������ּ���. �����մϴ�. (__)\n");
        }
    }else{
        printf("�ܾ��� �����մϴ�. ó������ �̵��մϴ�. \n");
    }

    return;
}

void ulgray_print(DRINK*food, int insert_coin, int menu){
        char a = "";
        char b = "";
        int i = 0;
        char answer = "";

        printf("��׷��̹�ũƼ�� �³���? Ȯ�� Y/N :");
        scanf("%s", &a);
    if(insert_coin >= 700){
        if(a =='Y' || a =='y'){
            printf("��� �ֹ� �Ͻó���? : ");
            scanf("%d", &count);
            total = ULGRAY*count;
            printf("�絵�� �����ϼ���(*10* *30* *50* *70* *100*) :");
            scanf("%d", &food[i].sugar);
            printf("���� ���� �����ϼ���(*50* *70* *100*) : ");
            scanf("%d", &food[i].ice);
            printf("Pearl�� �����ϼ���(��ũ��, Ÿ�ǿ�ī, ���ڳ�, �˷ο�):");
            scanf("%s", &food[i].pearl);
            printf("�� %d���Դϴ�. �������͵帱���? Y/N :", total);
            scanf("%s", &b);
        if(insert_coin < total){
            printf("�ܾ��� �����մϴ�. \n");
            return;
        }
        if(b =='Y' || b =='y'){
            printf("\n");
            clear_print();
            printf("�ھ�׷��̹�ũƼ %d�� / �絵: %d / ���� ��: %d / pearl : %s ���Խ��ϴ�. ���ְԵ弼��� \n", count, food->sugar, food->ice, food->pearl);
            getchar();
            getchar();
            printf("��� �̿��Ͻðڽ��ϱ�? Y/N :");
            scanf("%s", &answer);
            if(answer == 'Y' || answer == 'y'){
                printf("ó������ �̵��մϴ�. �����մϴ� (__)\n");
            }else if(answer =='N' || answer =='n'){
                printf("�ʱ�ȭ������ �̵��� �������ּ���. \n");
                return;
            }
        }else if(b =='N' || b =='n'){
            printf("ó������ �̵��մϴ�. �����մϴ� (__)\n");
        }
        }else if(a=='N' || a=='n'){
            printf("�ٽ� �������ּ���. �����մϴ�. (__)\n");
        }
    }else{
        printf("�ܾ��� �����մϴ�. ó������ �̵��մϴ�. \n");
    }

    return;
}

void mango_input(DRINK*food, int insert_coin, int menu){
        char a = "";
        char b = "";
        int i = 0;
        char answer = "";

        printf("�����ũƼ�� �³���? Ȯ�� Y/N :");
        scanf("%s", &a);
    if(insert_coin >= 600){
        if(a =='Y' || a =='y'){
            printf("��� �ֹ� �Ͻó���? : ");
            scanf("%d", &count);
            total = MANGO*count;
            printf("�絵�� �����ϼ���(*10* *30* *50* *70* *100*) :");
            scanf("%d", &food[i].sugar);
            printf("���� ���� �����ϼ���(*50* *70* *100*) : ");
            scanf("%d", &food[i].ice);
            printf("Pearl�� �����ϼ���(��ũ��, Ÿ�ǿ�ī, ���ڳ�, �˷ο�):");
            scanf("%s", &food[i].pearl);
            printf("�� %d���Դϴ�. �������͵帱���? Y/N :", total);
            scanf("%s", &b);
        if(insert_coin < total){
            printf("�ܾ��� �����մϴ�. \n");
            return;
        }
        if(b =='Y' || b =='y'){
            printf("\n");
            clear_print();
            printf("�ڸ����ũƼ %d�� / �絵: %d / ���� ��: %d / pearl : %s ���Խ��ϴ�. ���ְԵ弼��� \n", count, food->sugar, food->ice, food->pearl);
            getchar();
            getchar();
            printf("��� �̿��Ͻðڽ��ϱ�? Y/N :");
            scanf("%s", &answer);
            if(answer == 'Y' || answer == 'y'){
                printf("ó������ �̵��մϴ�. �����մϴ� (__)\n");
            }else if(answer =='N' || answer =='n'){
                printf("�ʱ�ȭ������ �̵��� �������ּ���. \n");
                return;
            }
        }else if(b =='N' || b =='n'){
            printf("ó������ �̵��մϴ�. �����մϴ� (__)\n");
        }
        }else if(a=='N' || a=='n'){
            printf("�ٽ� �������ּ���. �����մϴ�. (__)\n");
        }
    }else{
        printf("�ܾ��� �����մϴ�. ó������ �̵��մϴ�. \n");
    }

    return;
}

void ggrape_input(DRINK*food, int insert_coin, int menu){
        char a = "";
        char b = "";
        int i = 0;
        char answer = "";

        printf("û������ũƼ�� �³���? Ȯ�� Y/N :");
        scanf("%s", &a);
    if(insert_coin >= 300){
        if(a =='Y' || a =='y'){
            printf("��� �ֹ� �Ͻó���? : ");
            scanf("%d", &count);
            total = GGRAPE*count;
            printf("�絵�� �����ϼ���(*10* *30* *50* *70* *100*) :");
            scanf("%d", &food[i].sugar);
            printf("���� ���� �����ϼ���(*50* *70* *100*) : ");
            scanf("%d", &food[i].ice);
            printf("Pearl�� �����ϼ���(��ũ��, Ÿ�ǿ�ī, ���ڳ�, �˷ο�):");
            scanf("%s", &food[i].pearl);
            printf("�� %d���Դϴ�. �������͵帱���? Y/N :", total);
            scanf("%s", &b);
        if(insert_coin < total){
            printf("�ܾ��� �����մϴ�. \n");
            return;
        }
        if(b =='Y' || b =='y'){
            printf("\n");
            clear_print();
            printf("��û������ũƼ %d�� / �絵: %d ���� / ��: %d / pearl : %s ���Խ��ϴ�. ���ְԵ弼��� \n", count, food->sugar, food->ice, food->pearl);
            getchar();
            getchar();
            printf("��� �̿��Ͻðڽ��ϱ�? :");
            scanf("%s", &answer);
            if(answer == 'Y' || answer == 'y'){
                printf("ó������ �̵��մϴ�. �����մϴ� (__)\n");
            }else if(answer =='N' || answer =='n'){
                printf("�ʱ�ȭ������ �̵��� �������ּ���. \n");
                return;
            }
        }else if(b =='N' || b =='n'){
            printf("ó������ �̵��մϴ�. �����մϴ� (__)\n");
        }
        }else if(a=='N' || a=='n'){
            printf("�ٽ� �������ּ���. �����մϴ�. (__)\n");
        }
    }else{
        printf("�ܾ��� �����մϴ�. ó������ �̵��մϴ�. \n");
    }

    return;
}

void sugar_input(DRINK*food, int insert_coin, int menu){
        char a = "";
        char b = "";
        int i = 0;
        char answer = "";

        printf("����ũƼ�� �³���? Ȯ�� Y/N :");
        scanf("%s", &a);
    if(insert_coin >= 300){
        if(a =='Y' || a =='y'){
            printf("��� �ֹ� �Ͻó���? : ");
            scanf("%d", &count);
            total = SUGAR*count;
            printf("�絵�� �����ϼ���(*10* *30* *50* *70* *100*) :");
            scanf("%d", &food[i].sugar);
            printf("���� ���� �����ϼ���(*50* *70* *100*) : ");
            scanf("%d", &food[i].ice);
            printf("Pearl�� �����ϼ���(��ũ��, Ÿ�ǿ�ī, ���ڳ�, �˷ο�):");
            scanf("%s", &food[i].pearl);
            printf("�� %d���Դϴ�. �������͵帱���? Y/N :", total);
            scanf("%s", &b);
        if(insert_coin < total){
            printf("�ܾ��� �����մϴ�. \n");
            return;
        }
        if(b =='Y' || b =='y'){
            printf("\n");
            clear_print();
             printf("������ũƼ %d�� / �絵: %d / ���� ��: %d / pearl : %s ���Խ��ϴ�. ���ְԵ弼��� \n", count, food->sugar, food->ice, food->pearl);
            getchar();
            getchar();
            printf("��� �̿��Ͻðڽ��ϱ�? Y/N :");
            scanf("%s", &answer);
            if(answer == 'Y' || answer == 'y'){
                printf("ó������ �̵��մϴ�. �����մϴ� (__)\n");
            }else if(answer =='N' || answer =='n'){
                printf("�ʱ�ȭ������ �̵��� �������ּ���. \n");
                return;
            }
        }else if(b =='N' || b =='n'){
            printf("ó������ �̵��մϴ�. �����մϴ� (__)\n");
        }
        }else if(a=='N' || a=='n'){
            printf("�ٽ� �������ּ���. �����մϴ�. (__)\n");
        }
    }else{
        printf("�ܾ��� �����մϴ�. ó������ �̵��մϴ�. \n");
    }

    return;
}

void clear_print(){
    int i = 0;

    for(i = 0; i < 1; i++){
        printf("���� ������...\n");
        Sleep(1000);
        printf("������ pearl �ִ���... \n");
        Sleep(1000);
        printf("���ݸ� ��ٷ��ּ���... \n");
        Sleep(1000);
        printf("���� ���Խ��ϴ�! \n");
    }
    printf("\n");
    printf("         �ߣߣ�           \n");
    printf("        [�ߣ�  ]          \n");
    printf("             [ ]          \n");
    printf("             [ ]          \n");
    printf("     l��������  ��������l \n");
    printf("     l������������������l \n");
    printf("     l                  l \n");
    printf("     l                  l \n");
    printf("     l                  l \n");
    printf("     l                  l \n");
    printf("     l                  l \n");
    printf("     l                  l \n");
    printf("     l                  l \n");
    printf("     l  �� �� �� �� ��  l \n");
    printf("     l�� �� �� �� �� �� l \n");
    printf("      ������������������  \n");


    return;
}

