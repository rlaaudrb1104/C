#include<stdio.h>

int main(){
    int N = 0;
    int result = 0;
    int x[50] = {0, };
    int y[50] = {0, };

    scanf("%d",&N);

    for(int i=0; i<N; i++){
        scanf("%d %d",&x[i], &y[i]);
    }
    for(int i=0; i<N; i++) {
        result = 1;
        for(int j=0; j<N; j++) {
            if(x[i] < x[j] && y[i] < y[j]){
                result++;
            }
        }
        printf("%d",result);
    }
return 0;
}