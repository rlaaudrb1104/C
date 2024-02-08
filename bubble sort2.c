#include <stdio.h>
#define COUNT 20

int main()
{
    // 1~20의 숫자를 랜덤하게 가지는 배열
    int data[COUNT]
        = { 5 , 15 , 7 , 20 , 1 ,
            4 , 10 , 2 , 8  , 11,
            9 ,  6 , 13, 18 ,  3,
            16, 12 , 14, 17 , 19 };
    //temp 변수는 데이터를 교환할때 쓸 임시 변수이다.
    int temp = 0;
    
    printf("랜덤하게 섞여있는 데이터 값 : ");
    for (int i = 0; i < COUNT; i++)
    {
        printf("%d ", data[i]);
    }
    //내림차순 정렬
    for (int i = 0; i < COUNT - 1; i++)
    {
        for (int j = 0; j < COUNT - 1 - i; j++)
        {
            if (data[j] < data[j + 1])
            {
                temp        = data[j];
                data[j]     = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    //내림차순 정렬된 출력
    printf("\n\n버블 정렬을 사용하여 내림차순한 결과 : ");
    for (int i = 0; i < COUNT; i++)
    {
        printf("%d ", data[i]);
    }
    return 0;
}