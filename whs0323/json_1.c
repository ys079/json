#include <stdio.h>
#include "json_c.c"

int main(void)
{   
    const char *str = "{\"data\":[{\"color\": \"red\", \"value\": \"#f00\"}, {\"color\": \"green\", \"value\": \"#0f0\"}, {\"color\": \"blue\", \"value\": \"#00f\"}, {\"color\": \"cyan\", \"value\": \"#0ff\"}, {\"color\": \"magenta\", \"value\": \"#f0f\"}, {\"color\": \"yellow\", \"value\": \"#ff0\"}, {\"color\": \"black\", \"value\": \"#000\"}]}";
	//Creation and assignment of a json_value
	//Dynamic allocation used
	json_value json = json_create(str);
	json_print(json); putchar('\n');
	json_value json2 = json_get(json, "data");


	for(int i=0;i<json_len(json2);i++){
		printf("json[%d] : ", i);
		json_value obj = json_get(json2, i);
		char *s = json_get_string(obj, "color");
		printf("%s \n", s);

	}

	json_value one = json_get(json2, 0);
	json_print(one);

	return 0;
}

