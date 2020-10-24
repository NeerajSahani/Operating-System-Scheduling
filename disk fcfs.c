#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
	int n, a[50], i, chp, sum = 0;
	float avg;
	printf("Enter the number of tracks :");
	scanf("%d", &n);
	printf("Enter tracks \n");
	for (i = 1; i <= n; i++)
	{
		printf("[%d] :", i);
		scanf("%d", &a[i]);
	}
	printf("Enter current head position :");
	scanf("%d", &a[0]);

	for (i = 1; i <= n; i++)
		sum += abs(a[i] - a[i - 1]);

	avg = float(sum / n);
	printf("Head movement =%d\nAvg head movement =%f", sum, avg);
	getch();
}
