#include <stdio.h>

int main(void)
{
  FILE *fp;
  int c=0;

  // w와 a
  fp = fopen("test.txt", "w");

  if(fp == NULL){
    printf("파일열기 실패\n");
  } else {
    printf("파일열기 성공\n");
  }
  for (int i =0; i<5;i++){
    // memset(file_buff, 0, sizeof(file_buff));
    // fgets(file_buff, sizeof(file_buff),stdin);
    // file_buff[strlen(file_buff)]='\n';
    // fputs(file_buff, fp);
    char temp[20];
    printf("%d라인 : ",i+1);
    scanf("%s",&temp);
    fputs(temp, fp);
    fputs("\n",fp);
  }
  fclose(fp);
  fp = fopen("test.txt", "r");
  if(fp == NULL){
    printf("파일열기 실패\n");
  } else {
    printf("파일열기 성공\n");
  }

  // while(fgets(file_buff, sizeof(file_buff), fp)!=NULL){
  //   printf("%s",file_buff);

  // }
  while (1)  
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




