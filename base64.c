#include <stdio.h>
#include <string.h>


const char base64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void base64_encode(const char *input, char *output){
  int i, j = 0;
  int input_len = strlen(input);
  for (i = 0; i < input_len; i +=3){
    int val = (input[i] << 16) + (i + 1 < input_len ? input[i + 1] << 8 : 0) + (i + 2 < input_len ? input[i + 2] : 0);
    int val_b = 18;
    while (val_b >= 0) {
      output[j++] = base64_table[(val >> val_b) & 0x3F];
      val_b -= 6;
    }
  }
  while(j & 3) output[j++] = '=';
  output[j] = '\0';
}

void base64_decode(char *input, char *output) {
  int table[128] = {0};
  for (int i = 0; i < 64; i++) table[(int)base64_table[i]] = i;
  int i, j = 0;
  int input_len = strlen(input);
  for (i = 0; i < input_len; i += 4){
    int val = table[(int)input[i]] << 18;
    val += i + 1 < input_len ? table[(int)input[i + 1]] << 12 : 0;
        val += i + 2 < input_len ? table[(int)input[i + 2]] << 6 : 0;
        val += i + 3 < input_len ? table[(int)input[i + 3]] : 0;
        output[j++] = (val >> 16) & 0xFF;
        if (input[i + 2] != '=') output[j++] = (val >> 8) & 0xFF;
        if (input[i + 3] != '=') output[j++] = val & 0xFF;
    }
    output[j] = '\0';
}

int main() {
  char input[1024];
  char output[1024];
  int num = 0;
  printf("1.base64_encodeing\n");
  printf("2.base64_decodeing\n");
  scanf("%d", &num);
  if(num == 1){
    printf("인코딩 문자 입력:\n");
    getchar();
    scanf("%s", &input);
    base64_encode(input, output);
    printf("%s", output);
  }
  else if (num == 2){
    printf("디코딩 문자 입력:\n");
    getchar();
    scanf("%s", &input);
    base64_decode(input, output);
    printf("%s", output);
  }
  else{
    printf("올바른 값을 입력해주세요.\n");
  }
  
  return 0;
}
