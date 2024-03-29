# problem-solving

## sort
정렬에 대해 정리 중.

### 버블 정렬
- O(N^2)
- 안정 정렬
- 교환 정렬(비교 정렬)

### 선택 정렬
- O(N^2), 최소값 찾기
- 불안정 정렬
- 제자리 정렬
- 사용할 수 있는 메모리가 제한적인 경우에 사용 시, 성능상의 이점이 있음

### 힙 정렬
- O(N log N), 힙트리를 이용해 정렬
- 불안정 정렬
- 선택 정렬의 응용한 알고리즘
- 주의사항) root index = 1 이다.(그래야 /2, *2할때 자식,부모를 이동할 수 있다)
- 방법
    1. 힙트리를 만든다
        - 순차적으로 element를 돌면서, 자기 자리를 찾아가자
        - 부모보다 크면 올라간다(계속)
    2. 힙 정렬
        - root element는 가장 큰 값(max heap tree일 경우)이다
        - 아래를 반복한다
            - 가장 큰 값을 빼내고, 힙트리의 마지막 element를 root로 옮긴 후에, 자리 자리를 찾아가자
                - 결국, root와 last를 swap하고, last는 last - 1의 index를 가리키게 함
            - 왼쪽 child, 오른쪽 child 중 큰 값과 위치 교환하면서 내려간다(계속)

### 삽입 정렬
- O(N^2), 정렬된 부분에서 자신의 위치를 찾아 삽입
- 안정 정렬
- 제자리 정렬
- 선택정렬이나 버블 정렬보다 빠름
- 거의 정렬되어 있는 데이터는 삽입정렬이 효율이 좋음
- 대신 한 번 돌 때 하나만 정렬됨(단점)

### 쉘 정렬
- 삽입 정렬의 단점을 보완, 삽입정렬의 일반화 버전
- 불안정 정렬
- 부분그룹으로 나누어서, 부분그룹의 인덱스끼리 모아서 정렬
- 나누는 크기는 N / 3 + 1 이 효율이 N / 2보다 좋다 함
- 데이터 교환 시 멀리 이동하지 않음(장점)
extern void shellSort(int *list, int s, int e);

### 퀵 정렬
- 평균 O(N logN), 최악 O(N^2)
- 재귀
- 불안정 정렬(동일값의 기존 순서가 바뀔 수 있음)
- 제자리 정렬(스택을 log N만큼 사용하지만 보통 제자리 정렬로 구분함)
- 일반적인 경우 다른 O(N log N)정렬보다 빠르다(CPU캐시 히트율이 높아서)

### 병합 정렬
- O(N log N)
- 재귀
- 안정 정렬
- 교환 정렬(비교 정렬)
- 온라인정렬(데이터가 처음부터 다 주어지지 않고 차례대로 들어와도 처리할 수 있음)

### 기수 정렬(Radix Sort)
- 낮은 자리수부터 비교하여 정렬해 감
- O(dn), d는 가장 큰 데이터의 자리수
- 비교연산을 하지 않음, 정수와 같은 자료의 정렬속도가 매우 빠름
  - 부동소수점 실수에는 적용할 수 없음
- 데이터 전체 크기만큼의 메모리가 더 필요함
- 안정 정렬

### 계수 정렬(Counting Sort)
- O(n + k), k: maximum number
- 일반적인 상황에서 가장 빠름
- 메모리 낭비가 심하므로, 숫자들이 특정 범위에 있을 때 사용
- 비교 연산이 없음
- 안정 정렬
