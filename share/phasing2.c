#include "json_c.c"
#include <stdio.h>

// 파일에서 JSON 데이터를 읽어오는 함수
char* read_json_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buffer = (char*)malloc(length + 1);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        fclose(file);
        return NULL;
    }

    fread(buffer, 1, length, file);
    fclose(file);

    buffer[length] = '\0';
    return buffer;
}

int main() {
    // 파일에서 JSON 데이터 읽어오기
    char* json_data = read_json_file("data.json");
    if (json_data == NULL) {
        return 1;
    }

    // JSON 데이터를 파싱하여 json_value 객체 생성
    json_value json_data_value = json_create(json_data);

    // 함수 배열 가져오기
    json_value ext = json_get(json_data_value, "ext");

    // 함수 개수
    int num_functions = json_len(ext);
    printf("Number of functions: %d\n", num_functions);

    // 함수 정보 출력
    for (int i = 0; i < num_functions; ++i) {
        json_value decl = json_get(ext, i);
        json_value name = json_get(decl, "name");
        json_value type = json_get(json_get(decl, "type"), "names");

        printf("Function %d:\n", i + 1);
        printf("Name: %s\n", json_to_string(name));
        printf("Return Type: %s\n", json_to_string(json_get(type, 0)));

        // 파라미터 정보 출력
        json_value args = json_get(json_get(json_get(decl, "type"), "args"), "params");
        int num_params = json_len(args);
        printf("Parameters:\n");
        for (int j = 0; j < num_params; ++j) {
            json_value param = json_get(args, j);
            json_value param_type = json_get(json_get(param, "type"), "names");
            printf("\tType: %s\n", json_to_string(json_get(param_type, 0)));
        }

        // TODO: 조건 정보 출력

        printf("\n");
    }

    // json_value 객체 메모리 해제
    json_free(json_data_value);
    free(json_data);

    return 0;
}
