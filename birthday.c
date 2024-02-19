#include <stdio.h>

int main() {
  int input_year = 0;
  int input_month = 0;
  int input_day = 0;
  int month[12] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 
  };

  printf("생년월일을 입력하세요. ex)0000-00-00\n");
  scanf("%d-%d-%d",&input_year,&input_month, &input_day);
  int a = input_month - 1;
  
  if (month[a] == 1) {
    printf("January\n");
    if (1 <= input_day && input_day <= 19){
      printf("염소자리");
    }
    else if(20 <= input_day && input_day <= 31) {
      printf("물병자리");
    }
    else {
      printf("잘못된 요일입니다.");
    }
  }
  else if (month[a] == 2) {
    printf("February\n");
    if (1 <= input_day && input_day <= 18){
      printf("물병자리");
    }
    else if(19 <= input_day && input_day <= 29) {
      printf("물고기자리");
    }
    else {
      printf("잘못된 요일입니다.");
    }
  }
  else if (month[a] == 3) {
    printf("March\n");
    if (1 <= input_day && input_day <= 20){
      printf("물고기자리");
    }
    else if(21 <= input_day && input_day <= 31) {
      printf("양자리");
    }
    else {
      printf("잘못된 요일입니다.");
    }
  }
  else if (month[a] == 4) {
    printf("April\n");
    if (1 <= input_day && input_day <= 19){
      printf("양자리");
    }
    else if(20 <= input_day && input_day <= 30) {
      printf("황소자리");
    }
    else {
      printf("잘못된 요일입니다.");
    }
  }
  else if (month[a] == 5) {
    printf("May\n");
    if (1 <= input_day && input_day <= 20){
      printf("황소자리");
    }
    else if(21 <= input_day && input_day <= 31) {
      printf("쌍둥이자리");
    }
    else {
      printf("잘못된 요일입니다.");
    }
  }
  else if (month[a] == 6) {
    printf("June\n");
    if (1 <= input_day && input_day <= 21){
      printf("쌍둥이자리");
    }
    else if(22 <= input_day && input_day <= 30) {
      printf("게자리");
    }
    else {
      printf("잘못된 요일입니다.");
    }
  }
  else if (month[a] == 7) {
    printf("July\n");
    if (1 <= input_day && input_day <= 22){
      printf("게자리");
    }
    else if(23 <= input_day && input_day <= 31) {
      printf("사자자리");
    }
    else {
      printf("잘못된 요일입니다.");
    }
  }
  else if (month[a] == 8) {
    printf("August\n");
    if (1 <= input_day && input_day <= 22){
      printf("사자자리");
    }
    else if(23 <= input_day && input_day <= 31) {
      printf("처녀자리");
    }
    else {
      printf("잘못된 요일입니다.");
    }
  }
  else if (month[a] == 9) {
    printf("September\n");
    if (1 <= input_day && input_day <= 23){
      printf("처녀자리");
    }
    else if(24 <= input_day && input_day <= 30) {
      printf("천칭자리");
    }
    else {
      printf("잘못된 요일입니다.");
    }
  }
  else if (month[a] == 10) {
    printf("October\n");
    if (1 <= input_day && input_day <= 22){
      printf("천칭자리");
    }
    else if(23 <= input_day && input_day <= 31) {
      printf("전갈자리");
    }
    else {
      printf("잘못된 요일입니다.");
    }
  }
  else if (month[a] == 11) {
    printf("November\n");
    if (1 <= input_day && input_day <= 22){
      printf("전갈자리");
    }
    else if(23 <= input_day && input_day <= 30) {
      printf("사수자리");
    }
    else {
      printf("잘못된 요일입니다.");
    }
  }
  else if (month[a] == 12) {
    printf("December\n");
    if (1 <= input_day && input_day <= 24){
      printf("사수자리");
    }
    else if(25 <= input_day && input_day <= 31) {
      printf("염소자리");
    }
    else {
      printf("잘못된 요일입니다.");
    }
  }
  else {
    printf("잘못된 달입니다.");
  }
}