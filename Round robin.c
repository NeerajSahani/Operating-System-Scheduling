#include <stdio.h>
#include <conio.h>
int main()
{
	int at[10], n, bt[10], ft[10], tat[10], wt[10], i, j, time = 0, tq, count = 0, tmp[10], status[10];
	char temp;

	float ATAT = 0, AWT = 0;

	printf("Enter the number of Processes :");
	scanf("%d", &n);
	printf("Enter arrival time,Burst Time (AT,BT)....\n");
	for (i = 1; i <= n; i++)
	{
		printf("\tProcess P[%d]:", i);
		scanf("%d%c%d", &at[i], &temp, &bt[i]);
		tmp[i] = bt[i];
		status[i] = 0;
		wt[i] = 0;
		ft[i] = 0;
	}
	printf("Enter Time Quantum :");
	scanf("%d", &tq);
	i = 1;
	while (count < n)
	{
		if (bt[i] < tq && bt[i] > 0 && status[i] != 1)
		{
			wt[i] += (time - ft[i]);
			time += bt[i];
			bt[i] = 0;
			ft[i] = time;
		}

		if (bt[i] >= tq)
		{
			wt[i] += (time - ft[i]);
			time += tq;
			bt[i] -= tq;
			ft[i] = time;
		}

		if (bt[i] == 0 && status[i] != 1)
		{
			wt[i] += (time - ft[i]);
			ft[i] = time;
			count++;
			status[i] = 1;
			tat[i] = tmp[i] + wt[i];
		}
		if (i == n)
			i = 0;

		i++;
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
		printf(" %d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n", i, at[i], tmp[i], ft[i], tat[i], wt[i]);
	}
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
	printf("\n\n\nAverage Turn Arround Time is %f\nAverage Waiting Time is %f", (float)(ATAT / n), (float)(AWT / n));
	getch();
}
