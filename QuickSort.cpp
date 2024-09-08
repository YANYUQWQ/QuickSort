#include <stdio.h>
#include <stdlib.h>

int partition(int* arr, int begin, int end) {
	int piriot = begin;
	int i = begin, j = end + 1;
	while (1) {
		while (arr[++i] <= arr[piriot]);

		while (arr[--j] > arr[piriot]);
		if (i > j)
			break;
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	int temp = arr[j];
	arr[j] = arr[begin];
	arr[begin] = temp;
	piriot = j;

	return piriot;
}

void QuickSort(int* arr, int begin, int end) {
	
	if(begin<end)
	{
		/*int pirPos = begin + rand() % (end - begin + 1);

		int temp = arr[pirPos];
		arr[pirPos] = arr[begin];
		arr[begin] = temp;*/

		int pirPos = partition(arr, begin, end);
		QuickSort(arr, begin, pirPos - 1);
		QuickSort(arr, pirPos + 1, end);
	}
	return;
}

int main()
{
	int arr[] = { 11,2,4,9,7,4,5,10};
	QuickSort(arr, 0, 7);
	for (int i = 0; i < 7; i++)
		printf("%d  ", arr[i]);

	return 0;
}