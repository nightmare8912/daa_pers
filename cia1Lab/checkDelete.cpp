
#include <iostream>
#include <limits.h>

bool isHeap(int arr[], int i, int n)
{
	// If (2 * i) + 1 >= n, then leaf node, so return true
	if (i >= (n - 1) / 2)
		return true;

	// If an internal node and is
	// greater than its children,
	// and same is recursively
	// true for the children
	if (arr[i] >= arr[2 * i + 1] &&
		arr[i] >= arr[2 * i + 2]
		&& isHeap(arr, 2 * i + 1, n)
		&& isHeap(arr, 2 * i + 2, n))
		return true;

	return false;
}

// Driver program
int main()
{
	int arr[] = { 19, 19, 18, 19, 16, 18, 18, 18, 15, 15, 16, 17, 13, 18, 18, 16, 14, 12, 10, 14, 14, 16, 13, 13, 12, 7, 17, 17, 3, 18, 15, 10, 11, 2, 9, 6, 9, 10, 9, 13, 9, 11, 4, 13, 11, 4, 6, 11, 2, 9, 2, 4, 2, 1, 7, 16, 1, 1, 9, 15, 7, 11, 6, 2, 8, 6, 0, 2, 4, 8, 2, 5, 7, 4, 7, 10, 6, 1, 1, 8, 3, 3, 4, 11, 2, 0, 6, 5, 5, 8, 2, 4, 1, 3, 4, 7, 1, 0, 8, 1 };
	int n = sizeof(arr) / sizeof(int) - 1;

	isHeap(arr, 0, n) ? printf("Yes") : printf("No");

	return 0;
}
