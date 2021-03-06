# Sort
## Bubble Sort
* 버블 정렬은 이웃하는 숫자를 비교하여 작은 수를 앞쪽으로 이동시키는 과정을 반복하여 정렬하는 알고리즘이다.
* 동작원리:1번째 인덱스부터 마지막 인덱스까지 이웃하는 숫자를 비교해 작은 수를 앞쪽으로 당긴다. 이렇게 마지막 인덱스까지 자리를 이동시키는 것을 패스라고 한다. 1번의 패스후에도 1번재 인덱스부터 마지막 인덱스까지 이웃한 숫자를 비교해 작은수를 앞쪽으로 당긴다. 이렇게 여려번의 패스 후에 배열에 데이터가 차례대로 정렬되어있으면 패스를 멈춘다.

![image](https://t1.daumcdn.net/cfile/tistory/275F9A4A545095BD01)

## Selection Sort
* 입력 배열 전체에서 최솟값을 '선택'하여 배열의 0번 원소와 자리를 바꾸고, 다음에는 0번 원소를 제외한 나머지 원소에서 최솟값을 선택하여, 배열의 1번 원소와 자리를 바꾼다. 이러한 방식으로 마지막에 2개의원소중에서 작은 값을 선택하여 자리를 바꿈으로써 오름차순의 정렬을 마친다.

![image](https://t1.daumcdn.net/cfile/tistory/256B9C34545081D835)

## Insertion Sort
* 배열을 정렬된 부분과 정렬이 안 된 부분으로 나누고, 정렬이 안 된 부분의 가장 왼쪽 원소를 정렬된 부분의 적절한 위치에 삽입하여 정렬되도록 하는 과정을 반복한다.

![image](https://t1.daumcdn.net/cfile/tistory/2569FD3854508BE811)

## Shell Sort
* 쉘 정렬은 버블 정렬이나 삽입 정렬의 단점(이웃하는 원소의 숫자들끼리의 자리를 이동함으로써 정렬이 이루어짐->원소가 매우 느리게 이동)을 보완하기 위해서 삽입 정렬을 이용하여 배열 뒷부분의 작은 숫자를 앞부분으로 '빠르게'이동시키고, 동시에 앞부분의 큰 숫 자는뒷부분으로 이동시키며, 가장 마지막에는 삽입 정렬을 수행한다.

![image](https://t1.daumcdn.net/cfile/tistory/223DFC4B5451F3590A)

## Merge Sort
* 합병 정렬은 하나의 리스트를 두 개의 균등한 크기로 분할하고 분할된 부분 리스트를 정렬한 다음,두 개의 정렬된 부분 리스트를 합하여 전체가 정렬된 리스트가 되게 하는 방법이다.

![image](https://t1.daumcdn.net/cfile/tistory/214EFE385452034624)

## Quick Sort
* 퀵 정렬은 하나의 리스트를 피벗을 기준으로 두 개의 비균등한 크기로 분할하고 분할된 부분 리스트를 정렬한 다음, 두 개의 정렬된 부분 리스트를 합하여 전체가 정렬된 리스트가 되게하는 방법이다

![image](https://t1.daumcdn.net/cfile/tistory/271D2B3354545F7A13)

## 성능 분석 및 비교
각 정렬알고리즘의 시간 복잡도를 수식으로 파악해보면 다음과 같다.
> 버블정렬: O(n^2)  \
> 선택정렬: O(n^2)\
> 삽입정렬: O(n^2)\
> 쉘 정렬:O(n^1.25)\
> 합병정렬:O(nlogn)\
> 퀵정렬:O(nlogn)

수식으로만 봤을떄 버블정렬, 선택정렬, 삽입정렬이 쉘정렬, 합병정렬, 퀵정렬보다 시간복잡도가 더 커 보인다. 시간복잡도가 더 크다는 것은 실행시간이 더 오래걸린다고도 볼 수 있다.
실제로도 시행했을 떄 그런지 확인해보고자 정렬된 데이터, 랜덤 데이터, 역 정렬 데이터 세가지경우로 나누어서 시행해보았고 2^5부터 2^18까지 실행해보았다.(2^19부터는 결과가 안나왔?어요ㅜ)
그래프의 결과로 세가지 경우 모두 버블정렬이 압도적으로 복잡도가 컸고 무엇보다도 퀵정렬이 가장 시간복잡도가 낮은 것을 확인할 수 있다.


