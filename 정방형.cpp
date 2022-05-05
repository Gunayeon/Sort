#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 60000
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
int original[MAX_SIZE];
int list[MAX_SIZE];
int n;
int sorted[MAX_SIZE];
clock_t start, finish, used_time = 0;

void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left, j = mid + 1, k = left;

	while (i <= mid && j <= right)
	{
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	if (i > mid)
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else
		for (l = i; l <= right; l++)
			sorted[k++] = list[l];

	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}

int partition(int list[], int left, int right)
{
	int pivot = list[left], tmp, low = left, high = right + 1;

	do {
		do
			low++;
		while (low <= right && list[low] < pivot);

		do
			high--;
		while (high >= left && list[high] > pivot);
		if (low < high) SWAP(list[low], list[high], tmp);
	} while (low < high);

	SWAP(list[left], list[high], tmp);
	return high;
}

void quick_sort(int list[], int left, int right)
{
	if (left < right)
	{
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}
void bubble_sort(int list[], int n)
{
	int i, j, tmp;
	printf("버블 정렬 중..");
	for (i = n - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
			if (list[j] > list[j + 1])
				SWAP(list[j], list[j + 1], tmp);
	}
}

void insertion_sort(int list[], int n)
{
	int i, j, key;
	printf("삽입 정렬 중...");
	for (i = 1; i < n; i++)
	{
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--)
			list[j + 1] = list[j];
		list[j + 1] = key;
	}
}

void shell_sort(int list[], int n)
{
	int i, j, k, h, v;
	for (h = n / 2; h > 0; h /= 2)
	{
		for (i = 0; i < h; i++) {
			for (j = i + h; j < n; j += h) {
				v = list[j];
				k = j;
				while (k > h - 1 && list[k - h] > v) {
					list[k] = list[k - h];
					k -= h;
				}
				list[k] = v;

			}
		}
	}

}
void selection_sort(int list[], int n)
{
	int i, j, key;
	printf("삽입 정렬 중..");
	for (i = 1; i < n; i++)
	{
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--)
			list[j + 1] = list[j];
		list[j + 1] = key;
	}
}

void CopyArr(void)
{
	int i;
	for (i = 0; i < n; i++)
		list[i] = original[i];
}

void CalcTime(void)
{
	used_time = finish - start;
	printf("완료!\n소요시간: %f sec\n\n", (float)used_time / CLOCKS_PER_SEC);
}

int main(void)
{
	int i;
	n = MAX_SIZE;
	for (i = 0; i < n; i++) {
		original[i] = rand();
		if (i + 1 > i)
			list[i + 1] >= list[i];
	}


	printf("데이터의 개수: %d\n\n", n);

	CopyArr();
	start = clock();
	selection_sort(list, n);
	finish = clock();
	CalcTime();

	CopyArr();
	start = clock();
	insertion_sort(list, n);
	finish = clock();
	CalcTime();

	CopyArr();
	start = clock();
	bubble_sort(list, n);
	finish = clock();
	CalcTime();

	CopyArr();
	start = clock();
	printf("합병 정렬 중..");
	merge_sort(list, 0, n);
	finish = clock();
	CalcTime();

	CopyArr();
	start = clock();
	printf("퀵 정렬 중..");
	quick_sort(list, 0, n);
	finish = clock();
	CalcTime();

	CopyArr();
	start = clock();
	printf("쉘 정렬 중..");
	shell_sort(list, n);
	finish = clock();
	CalcTime();


}