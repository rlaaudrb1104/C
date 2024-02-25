#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void file_base64(char *file_name, int num) {
    FILE *fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("파일 열기 실패\n");
        return; 
    }

    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp); 
    fseek(fp, 0, SEEK_SET);

    char *input = (char *)malloc(fsize + 1); 
    fread(input, 1, fsize, fp); 
    input[fsize] = '\0';
    fclose(fp); 

    char *output = (char *)malloc(fsize * 2); 

    if (num == 1) {
        base64_encode(input, output);
    } else if (num == 2) {
        base64_decode(input, output);
    } else {
        printf("잘못된 입력입니다.\n");
    }

    fp = fopen(file_name, "wb"); 
    if (fp != NULL) {
        fputs(output, fp);
        fclose(fp);
    } else {
        printf("파일 열기 실패\n");
    }

    printf("%s\n", output); 

    free(input);
    free(output);
}


int main() {
  char file_name[100];
  int num = 0;
  printf("1.base64_encoding\n");
  printf("2.base64_decoding\n");
  scanf("%d", &num);
  printf("파일 이름 입력:\n");
  scanf("%s", file_name);
  file_base64(file_name, num);
  
  return 0;
}
