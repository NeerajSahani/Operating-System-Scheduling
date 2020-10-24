#include <stdio.h>
#include <conio.h>
#include <math.h>
struct IO
{
	int id, flag;
} x[50];

int main()
{
	int i, chp, cur_pos = 9999, n, loc, sum = 0;
	printf("Enter number of tracks :");
	scanf("%d", &n);
	printf("Enter Current head position :");
	scanf("%d", &chp);
	printf("Enter the tracks ...\n");
	for (i = 0; i < n; i++)
	{
		printf("[%d]:", i);
		scanf("%d", &x[i].id);
		if (abs(chp - x[i].id) < cur_pos)
			cur_pos = abs(chp - x[i].id), sum += cur_pos;
	}
	printf("first is ,%d", sum);
}
