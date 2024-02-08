#include <stdio.h>
char item_list() {
  printf("상품목록 |  1.콜라  | 2.사이다 |  3.물  | 4.비타600 |\n");
  printf("  가격   |   1800  |   1300   |  1000  |    600   |\n");
}

int main(void) {
  int money = 0;
  
  printf("금액을 입력해주세요.\n");
  scanf("%d",&money);
  printf("잔액:%d\n",money);
  item_list();
  
  for (int i = 600; i < money;){
    int item = 0;
    printf("상품번호를 입력해주세요.\n");
    scanf("%d", &item);
    
    if(item == 1) {
      money = money - 1800;
      if (money < 1) {
        break;
      }
      printf("콜라\n");
      printf("잔액:%d\n", money);
      item_list();
    }
      
    else if ( item == 2) {
      money = money - 1300;
      if (money < 1) {
        break;
      }
      printf("사이다\n");
      printf("잔액:%d\n", money);
      item_list();
    }
      
    else if ( item == 3) {
      money = money - 1000;
      if (money < 1) {
        
        break;
      }
      printf("물\n");
      printf("잔액:%d\n", money);
      item_list();
    }
    else if ( item == 4) {
      money = money - 600;
      if (money < 1) {
        break;
      }
      printf("비타600\n");
      printf("잔액:%d\n", money);
      item_list();
    }
    else {
      printf("해당 상품이 존재하지 않습니다.\n");
    }
  }
  printf("잔액이 부족합니다.");
}