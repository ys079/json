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

    // functions 배열 가져오기
    json_value functions = json_get(json_data_value, "ext");
    

    // 함수 개수
    int num_functions = json_len(functions);
    printf("Number of functions: %d\n", num_functions);

    // 함수 정보 출력
    for (int i = 0; i < num_functions; ++i) {
        json_value function = json_get(functions, i);
        json_value name = json_get(function, "name");
        json_value return_type = json_get(function, "return_type");
        json_value parameters = json_get(function, "parameters");
        json_value if_conditions = json_get(function, "if_conditions");

        printf("Function %d:\n", i + 1);
        printf("Name: %s\n", json_to_string(name));
        printf("Return Type: %s\n", json_to_string(return_type));

        int num_parameters = json_len(parameters);
        printf("Parameters:\n");
        for (int j = 0; j < num_parameters; ++j) {
            json_value parameter = json_get(parameters, j);
            json_value param_type = json_get(parameter, "type");
            json_value param_name = json_get(parameter, "name");
            printf("\tType: %s, Name: %s\n", json_to_string(param_type), json_to_string(param_name));
        }

        printf("Number of if conditions: %d\n", json_to_int(if_conditions));
        printf("\n");
    }

    // json_value 객체 메모리 해제
    json_free(json_data_value);
    free(json_data);

    return 0;
}
