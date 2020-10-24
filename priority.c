#include <stdio.h>
#include <conio.h>
struct process
{
	int p, at, bt, wt, ft, tat, priority, status;
} pq[20];
int main()
{
	int i, j, n, time = 0, largest, count = 0;
	char temp;
	struct process tmp;
	float ATAT = 0, AWT = 0;

	printf("Enter the number of Processes :");
	scanf("%d", &n);
	printf("Enter arrival time,Burst Time (AT,BT,Priority)....\n");
	for (i = 1; i <= n; i++)
	{
		printf("\tProcess P[%d]:", i);
		scanf("%d%c%d%c%d", &pq[i].at, &temp, &pq[i].bt, &temp, &pq[i].priority);
		pq[i].status = 0;
	}

	for (i = 1; i <= n - 1; i++)
	{
		for (j = i + 1; j <= n; j++)
		{
			if (pq[i].at > pq[j].at)
			{
				tmp = pq[i];
				pq[i] = pq[j];
				pq[j] = tmp;
			}
		}
	}

	pq[19].priority = -9999;
	for (time = pq[1].at; count <= n;)
	{
		largest = 19;
		for (i = 1; i <= n; i++)
		{
			if (pq[i].at <= time && pq[i].status != 1 && (pq[i].priority > pq[largest].priority))
				largest = i;
		}
		time = time + pq[largest].bt;
		pq[largest].ft = time;
		pq[largest].tat = pq[largest].ft - pq[largest].at;
		pq[largest].wt = pq[largest].tat - pq[largest].bt;
		pq[largest].status = 1;
		count++;
	}

	for (i = 1; i <= n; i++)
	{
		ATAT += (float)pq[i].tat;
		AWT += (float)pq[i].wt;
	}

	printf("\n\n PN\t|\tAT\t|\tBT\t|\tPriority|\tFT\t|\tTAT\t|\tWT\t|\n");
	printf("-----------------------------------------------------------------------------------------------------\n");
	for (i = 1; i <= n; i++)
	{
		printf(" %d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n", i, pq[i].at, pq[i].bt, pq[i].priority, pq[i].ft, pq[i].tat, pq[i].wt);
	}
	printf("\n\n\nAverage Turn Arround Time is %f\nAverage Waiting Time is %f", (float)(ATAT / n), (float)(AWT / n));
	getch();
}
