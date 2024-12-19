#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		arr[i] = a;
	}
	int min = arr[0];
	for (int i = 1; i < n; i++)
	{
		min = min < arr[i] ? min : arr[i];
	}
	printf("so be nhat la : %d", min);
}
