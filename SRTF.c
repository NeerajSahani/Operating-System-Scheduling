#include <stdio.h>
#include <conio.h>
int main()
{
	int at[10], bt[10], x[10], i, j, smallest, count = 0, time, temp1, temp2, n;
	char temp;
	double avg = 0, tt = 0, ft;
	printf("Enter the number of Processes :");
	scanf("%d", &n);
	printf("Enter arrival time,Burst Time (AT,BT)....\n");
	for (i = 0; i < n; i++)
	{
		printf("\tProcess P[%d]:", i + 1);
		scanf("%d%c%d", &at[i], &temp, &bt[i]);
	}
	for (i = 0; i < n; i++)
		x[i] = bt[i];

	bt[9] = 9999; //Setting it max for comparison
	for (time = 0; count != n; time++)
	{
		smallest = 9;
		for (i = 0; i < n; i++)
		{
			if (at[i] <= time && bt[i] < bt[smallest] && bt[i] > 0)
				smallest = i;
		}

		bt[smallest]--;
		if (bt[smallest] == 0)
		{
			count++;
			ft = time + 1;
			temp1 = avg;
			temp2 = tt;
			avg = avg + ft - at[smallest] - x[smallest];
			tt = tt + ft - at[smallest];
			printf("\n P[%d]\tFT :%d\tWT :%lf\tTAT :%lf\n", smallest + 1, time + 1, avg - temp1, tt - temp2);
		}
	}
	printf("\n\nAverage waiting time = %lf\n", avg / n);
	printf("Average Turnaround time = %lf", tt / n);
	getch();
}
