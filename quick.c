#include <stdio.h>

void Quick1(int arr[], int left, int right) {
  int L = left;
  int R = right;
  int temp;
  int pivot = arr[left];

  while ( L <= R ) {
    while (arr[L] < pivot) L++;
    while (arr[R] > pivot) R--;
    if (L <= R) {
      if ( L != R) {
        temp = arr[L];
        arr[L] = arr[R];
        arr[R] = temp;
      }
      L++;
      R--;
    }
  }
  if (L < right) Quick1(arr, L, right);
  if (R > left) Quick1(arr, left, R);
}
void Quick2(int arr[], int left, int right) {
  int L = left;
  int R = right;
  int temp;
  int pivot = arr[(L + R) / 2];

  while ( L <= R ) {
    while (arr[L] < pivot) L++;
    while (arr[R] > pivot) R--;
    if (L <= R) {
      if ( L != R) {
        temp = arr[L];
        arr[L] = arr[R];
        arr[R] = temp;
      }
      L++;
      R--;
    }
  }
  if (L < right) Quick2(arr, L, right);
  if (R > left) Quick2(arr, left, R);
}
void Quick3(int arr[], int left, int right) {
  int L = left;
  int R = right;
  int temp;
  int pivot = arr[right];

  while ( L <= R ) {
    while (arr[L] < pivot) L++;
    while (arr[R] > pivot) R--;
    if (L <= R) {
      if ( L != R) {
        temp = arr[L];
        arr[L] = arr[R];
        arr[R] = temp;
      }
      L++;
      R--;
    }
  }
  if (L < right) Quick3(arr, L, right);
  if (R > left) Quick3(arr, left, R);
}

int main()
{
  int num;
  int arr[10] = { 5,3,7,1,9,2,4,6,8,0};
  printf("pivot 위치를 선택해주세요.\n1.처음\n2.중간\n3.마지막\n");
  scanf("%d", &num);
  if(num == 1) {
    Quick1(arr, 0, 9);
  }
  else if(num == 2) {
    Quick2(arr, 0, 9);
  }
  else if(num == 3) {
    Quick3(arr, 0, 9);
  }
  else {
    printf("잘못된 값을 입력했습니다. 다시 실행해주세요.");
    return 1;
  }
  if(num == 1) {
    printf("1.처음 실행결과\n");
  }
  if(num == 2) {
    printf("2.중간 실행결과\n");
  }
  if(num == 3) {
    printf("3.마지막 실행결과\n");
  }
  
  for ( int i = 0; i < 10; i++)
  {
    printf("%d", arr[i]);
  }
  printf("\n");
  return 0;
}