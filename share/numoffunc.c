#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 주어진 데이터에서 함수의 개수를 세는 함수
int countFunctions(char *json_data) {
    int count = 0;
    char *ptr = json_data;
    
    // 주어진 데이터를 파싱하여 "_nodetype"이 "FuncDecl"인 것의 개수를 센다
    while ((ptr = strstr(ptr, "\"_nodetype\": \"FuncDecl\"")) != NULL) {
        count++;
        ptr++;  // 중복 검색을 피하기 위해 다음 위치로 이동
    }
    
    return count;
}

int main() {
    // JSON 데이터를 읽어올 파일명
    char *filename = "data.json";

    // 파일 열기
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return 1;
    }

    // 파일 내용 읽기
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *json_data = (char *)malloc(file_size + 1);
    if (json_data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        return 1;
    }

    fread(json_data, 1, file_size, file);
    json_data[file_size] = '\0'; // 파일 데이터의 끝에 NULL 문자 추가

    // 파일 닫기
    fclose(file);

    // 함수의 개수를 세고 출력
    int function_count = countFunctions(json_data);
    printf("Number of functions: %d\n", function_count);

    // 동적으로 할당된 메모리 해제
    free(json_data);

    return 0;
}
