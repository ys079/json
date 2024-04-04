#include <stdio.h>

int main(void)
{
  FILE *fp;
  int c=0;

  fp = fopen("test.txt", "r");

  if(fp == NULL){
    printf("파일열기 실패\n");
  } else {
    printf("파일열기 성공\n");
  }
  // while(1){
    
  //   int d = fgetc(fp);
  //   if(d == EOF){
  //     break;
  //   }
  //   printf("%c", d);
  // }
  

  //한문자씩 읽는 fgetc
  //int count = 0;
  // while((c = fgetc(fp)) != EOF){
  //   putchar(c);
  //   count++;
  // }
  // printf("%d \n", count);

  while(1)
  {
    char temp[20];
    char *tStr = fgets(temp, 20, fp);
    if(tStr == NULL)
    {
      break;
    }
    printf("%s", temp);
  }

  fclose(fp);
  return 0;
}



