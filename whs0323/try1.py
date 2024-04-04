import json

# 파일 경로 설정
file_path = "result.json"

# 파일 열기
with open(file_path, "r", encoding="utf-8") as file:
    # JSON 데이터 로드
    data = json.load(file)

    # 파일 AST의 최상위 객체
    ext = data["_nodetype"]["ext"]

    # "ext" 배열의 각 요소를 반복하여 함수 이름을 추출
    for item in ext:
        if item["_nodetype"] == "FuncDef":
            # 함수 이름을 출력
            print("함수 이름:", item["name"])
