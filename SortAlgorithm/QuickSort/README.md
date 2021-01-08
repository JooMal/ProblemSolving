# 𝐐𝐮𝐢𝐜𝐤 𝐒𝐨𝐫𝐭

### 목차
1. <a href="#1">퀵 소트란?</a>
2. <a href="#2">c++ 구현 코드</a>
3. <a href="#3">algorithm 헤더의 sort</a>

<a name="1"></a>
### 퀵 소트란?
C++의 algorithm 헤더에 포함되어있는 sort 함수는 시간복잡도 O(NlogN)을 갖는 퀵 소트로 구현되어 있습니다.  

<img src="img/quick-sort.png"><br>

1. 리스트 안에 있는 한 요소(=피벗pivot)을 선택하여
2. 피벗을 기준으로 왼쪽엔 피벗보다 작은 요소를, 오른쪽엔 피벗보다 큰 요소를 넣습니다.
3. 피벗을 제외한 왼쪽 부분 리스트와 오른쪽 부분 리스트에서도 위의 과정을 반복하는데,
4. 언제까지 반복하냐면, 부분 리스트들의 크기가 0이나 1이 되어, 더이상 분할이 불가능할 때까지 반복합니다.

이처럼 큰 문제를 작은 문제로 분할(Divide)하여 해결(Conquer)하는 방법론을 `분할 정복(divide and conquer)`이라 합니다. 퀵 정렬은 분할 정복의 한 예입니다.  

<a name="2"></a>

### c++ 구현 코드

```c++
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <typeinfo>
#define LEN(a) (sizeof(a)/sizeof(typeid(list).name()));

using namespace std;

void Print(int list[], int len);

inline void swap(int &a, int &b) {
	int t = a; a = b; b = t;
}

void quickSort(int A[], int low, int high) {
	if (low >= high) return; // base condition

	// divide process
	int i = low - 1, j = low;
	int& pivot = A[high];
	for (; j < high; ++j) {
		if (A[j] < pivot)
			swap(A[++i], A[j]);
	}
	swap(A[++i], pivot);

	// conquer process
	quickSort(A, low, i - 1);
	quickSort(A, i + 1, high);
}


int main()
{
	int list[] = { 5,1,3,2,7,6,9,4 };
	int len = LEN(list);
	quickSort(list, 0, len-1);
	Print(list, len);
}

void Print(int list[], int len) {
	for (int i = 0; i < len; i++) {
		cout << list[i] << " ";
	}
}
```

#### divide process

<img src="img/part_ex.png"><br>

I. pivot은 우선 배열의 맨 오른쪽으로 보내줍니다.
  - 왼쪽, 오른쪽으로 pivot에 비해 작은 값과 큰 값을 옮겨줄 예정이니, 비교에서 pivot은 제외한 상태로 진행되어야 해서 그렇습니다. pivot과 pivot과 비교할 순 없으니까요. 이렇게 pivot을 한 쪽으로 빼준 후,  

II. 피벗을 기준으로 왼쪽엔 피벗보다 작은 요소를, 오른쪽엔 피벗보다 큰 요소를 넣습니다.
  - for문을 돌며 받은 배열을 순회하며 pivot보다 작은 값은 swap을 통해 왼쪽으로, 큰 값은 오른쪽으로 보내주고 있습니다.  

#### conquer process

III. 피벗을 제외한 왼쪽 부분 리스트와 오른쪽 부분 리스트에서도 위의 과정을 반복해줍니다.  
  - 코드에서 conquer process라 표시되어 있는 곳을 보시면, 이제 1, 2의 과정을 A list의 low ~ (i-1)에서 다시 quicksort를 해주고 있습니다.
  - 즉, 왼쪽에 있는 부분리스트들은 기저조건base condition(`low >= high`)에 도달할 때까지 작은 놈들은 왼쪽으로, 큰 놈들은 오른쪽으로 가는 과정을 반복하다 못해 결국에는 가장 작은 녀석이 왼쪽으로 가고, 그 다음으로 작은 녀석은 그 다음 위치에 있고, ..., 가장 큰 녀석(A의 첫번째 pivot보단 작겠죠?)이 가장 오른쪽(pivot 기준 바로 왼쪽)에 도달하게 될 것입니다. 왼쪽 부분리스트가 정렬이 된 것입니다. 이후 기저조건에서 줄줄 재귀함수를 빠져나와 이제 오른쪽 놈들을 정렬하기 위한 i+1 ~ high의 quicksort가 시작됩니다.

IV. 언제까지 반복하냐면, 부분 리스트들의 크기가 0이나 1이 되어, 더이상 분할이 불가능할 때까지 반복합니다.
  - 결국 모든 녀석들이 정렬이 될 때, 즉 기저조건에 해당하여서 모든 재귀함수를 빠져나와 원래의 quicksort함수로 리턴되어 돌아온다는 것은 부분 리스트들이 잘리다못해 0개로 나뉘거나 1개의 요소만 갖게 되는 순간입니다.
  - 가령 low=2, i=1인 상태로 `quicksort(A, low, i-1);` 에 들어가면 `low>high`라는 base condition에 해당되어 나오게 됩니다. 잘라서 정렬을 하고 싶었는데, 요소가 없는 상태인거니 0개로 잘린거라고 생각할 수 있겠죠?
  - 반면 low=2, i=2인 상태로 `quicksort(A, low, i-1);`에 들어가면 `low==high`라는 base condition에 해당되어 나오게 됩니다. 잘라서 정렬을 하려는데, 부분리스트의 인덱스라며 들어온 놈이 요소를 한 개만 갖고 있는 상황인거죠. 이러한 의미에서 퀵소트는 "부분 리스트들의 크기가 0이나 1이 되어, 분할이 불가능해질 때까지 반복한다"는 표현을 사용합니다.  


### algorithm 헤더의 sort

<a name="3"></a>
이번엔 C++ algorithm 헤더에 들어가있는 sort를 보겠습니다.  

```c++
template<class _RanIt,
	class _Pr> inline
	void _Sort_unchecked(_RanIt _First, _RanIt _Last, _Iter_diff_t<_RanIt> _Ideal, _Pr _Pred)
	{	// order [_First, _Last), using _Pred
	_Iter_diff_t<_RanIt> _Count;
	while (_ISORT_MAX < (_Count = _Last - _First) && 0 < _Ideal)
		{	// divide and conquer by quicksort
		auto _Mid = _Partition_by_median_guess_unchecked(_First, _Last, _Pred);
		// TRANSITION, VSO#433486
		_Ideal = (_Ideal >> 1) + (_Ideal >> 2);	// allow 1.5 log2(N) divisions

		if (_Mid.first - _First < _Last - _Mid.second)
			{	// loop on second half
			_Sort_unchecked(_First, _Mid.first, _Ideal, _Pred);
			_First = _Mid.second;
			}
		else
			{	// loop on first half
			_Sort_unchecked(_Mid.second, _Last, _Ideal, _Pred);
			_Last = _Mid.first;
			}
		}

	if (_ISORT_MAX < _Count)
		{	// heap sort if too many divisions
		_Make_heap_unchecked(_First, _Last, _Pred);
		_Sort_heap_unchecked(_First, _Last, _Pred);
		}
	else if (2 <= _Count)
		{
		_Insertion_sort_unchecked(_First, _Last, _Pred);	// small
		}
	}

template<class _RanIt,
	class _Pr> inline
	void sort(const _RanIt _First, const _RanIt _Last, _Pr _Pred)
	{	// order [_First, _Last), using _Pred
	_Adl_verify_range(_First, _Last);
	const auto _UFirst = _Get_unwrapped(_First);
	const auto _ULast = _Get_unwrapped(_Last);
	_Sort_unchecked(_UFirst, _ULast, _ULast - _UFirst, _Pass_fn(_Pred));
	}

template<class _RanIt> inline
	void sort(const _RanIt _First, const _RanIt _Last)
	{	// order [_First, _Last), using operator<
	_STD sort(_First, _Last, less<>());
	}
```

아주 복잡하고 길어보이지만, 적당히 흐린 눈으로 읽어보자면 배열의 길이로 추정되는 `_Count` 변수가 어떠한 `_ISORT_MAX`보다 크고, `0 < _Ideal`이라는 값을 만족하는 동안 quicksort를 통해 분할정복(divide and conquer)를 하고 있습니다. 눈에 띄는 부분이 있네요. Pivot이라 추정되는 `_Mid`를 특정한 함수를 통해 추정해 가져오고 있습니다. 그리고 `_ISORT_MAX < _Count` 라는 조건 하에는 heap으로 만들어 힙 정렬(heap sort)를 하고, `_Count`가 2보다 크다면 삽입 정렬(Insertion sort)를 해주고 있네요. `_ISORT_MAX`가 뭔진 정확히 알 수 없지만, 주석을 보니 divisions라는 것이 많은지, 적은지를 판별하는 상수값으로 보입니다.  

한 번 구현한 코드와, 헤더의 함수를 비교하여 돌려볼까요?

### 100000개의 요소

<img src="img/res_graph.JPG"><br>




---

# 𝑹𝒆𝒇𝒆𝒓𝒆𝒏𝒄𝒆
[퀵 정렬이란](https://gmlwjd9405.github.io/2018/05/10/algorithm-quick-sort.html)
[퀵 정렬 위키](https://ko.wikipedia.org/wiki/%ED%80%B5_%EC%A0%95%EB%A0%AC)
