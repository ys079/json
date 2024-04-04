#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_SIZE 10000  // 적절한 최대 JSON 크기로 조정하세요
#define MAX_JSON_DEPTH 100

int count_functions(const char *json_data);

int main() {
    FILE *file;
    char *json_data;
    long file_size;
    int function_count;

    // JSON 파일 열기
    file = fopen("data.json", "r");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    // 파일 크기 계산
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // JSON 데이터를 읽을 버퍼 할당
    json_data = (char *)malloc((file_size + 1) * sizeof(char));
    if (json_data == NULL) {
        printf("메모리 할당 오류\n");
        fclose(file);
        return 1;
    }

    // 파일에서 JSON 데이터 읽기
    fread(json_data, sizeof(char), file_size, file);
    json_data[file_size] = '\0';  // 문자열 끝에 널 문자 추가

    // 파일 닫기
    fclose(file);

    // 함수의 개수 세기
    function_count = count_functions(json_data);
    printf("함수의 개수: %d\n", function_count);

    // 메모리 해제
    free(json_data);

    return 0;
}

int count_functions(const char *json_data) {
    if (json_data == NULL) {
        return 0;
    }

    int count = 0;
    char *token;
    char *rest = strdup(json_data);

    while ((token = strtok(rest, "{}")) != NULL) {
        char *nodetype = strstr(token, "\"_nodetype\": \"FuncDef\"");
        if (nodetype != NULL) {
            count++;
        }
    }

    free(rest);

    return count;
}
