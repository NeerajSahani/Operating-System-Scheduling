#include <stdio.h>
#include <conio.h>
int main()
{
	int at[10], n, bt[10], ft[10], tat[10], wt[10], i, j, k = 0, time = 0;
	char temp;
	float ATAT = 0, AWT = 0;

	printf("Enter the number of Processes :");
	scanf("%d", &n);
	printf("Enter arrival time,Burst Time (AT,BT)....\n");
	for (i = 1; i <= n; i++)
	{
		printf("\tProcess P[%d]:", i);
		scanf("%d%c%d", &at[i], &temp, &bt[i]);
	}

	ft[0] = 0;
	while (++k <= n)
	{

		while (1)
		{
			if (at[k] > time)
				time++;
			else
			{
				ft[k] = time + bt[k];
				tat[k] = ft[k] - at[k];
				wt[k] = tat[k] - bt[k];
				time += bt[k];
				break;
			}
		}
	}

	for (i = 1; i <= n; i++)
	{
		ATAT += (float)tat[i];
		AWT += (float)wt[i];
	}

	printf("\n\n PN\t|\tAT\t|\tBT\t|\tFT\t|\tTAT\t|\tWT\t|\n");
	printf("-----------------------------------------------------------------------------------------\n");
	for (i = 1; i <= n; i++)
	{
		printf(" %d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n", i, at[i], bt[i], ft[i], tat[i], wt[i]);
	}

	printf("\n\n ");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= bt[i]; j++)
			printf("--");
		printf(" ");
	}
	printf("\n|");

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= bt[i] - 1; j++)
			printf(" ");
		printf("P%d", i);

		for (j = 1; j <= bt[i] - 1; j++)
			printf(" ");
		printf("|");
	}
	printf("\n ");

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= bt[i]; j++)
			printf("--");
		printf(" ");
	}
	printf("\n");
	printf("0");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= bt[i]; j++)
			printf("  ");
		{
			if (ft[i] > 9)
				printf("\b");
			printf("%d", ft[i]);
		}
	}

	printf("\n\n\nAverage Turn Arround Time is %f\nAverage Waiting Time is %f\n", (float)(ATAT / n), (float)(AWT / n));

	getch();
}
