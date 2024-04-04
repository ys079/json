#include <stdio.h>

int main(void){
  FILE *fp;
  int c=0;

  // w와 a
  fp = fopen("error.c", "r");

  if(fp == NULL){
    printf("파일열기 실패\n");
  } else {
    printf("파일열기 성공\n");
  }





  // while(fgets(file_buff, sizeof(file_buff), fp)!=NULL){
  //   printf("%s",file_buff);

  // }
  while (1) {

    char temp[20];
    char *tStr = fgets(temp, 20, fp);
    if(tStr == NULL)
    {
      break;
    }
    char str2[] = "mian";
    char str3[] = "num+";
    char str4[] = "println";
    char* ptr1 = strstr(temp, str2);
    if(ptr1 != NULL){strncpy(ptr1, "mian", 4);

    char* ptr2 = strstr(temp, str3);
    if(ptr2 != NULL){strncpy(ptr2, "num++", 5);

    char* ptr3 = strstr(temp, str4);
    if(ptr3 != NULL){strncpy(ptr3, "printf", 6);

    printf("strstr example : %s\n", temp);}
  }


  fclose(fp);
  return 0;


    }
  }
    
}

int main(){
  FILE = output_fp = fopen
}