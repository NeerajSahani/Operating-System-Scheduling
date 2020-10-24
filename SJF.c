#include <stdio.h>
#include <conio.h>

struct process
{
	int at, bt, ft, wt, tat, id, flag;
} p[10];

int main()
{
	int n, i = 0, j, time, tt = 0, smallest, count = 0;
	char temp;
	process t;
	float AWT = 0, ATAT = 0;
	printf("Enter number of process :");
	scanf("%d", &n);
	printf("Enter Arrival time and CPU Burst time [AT,BT]...\n");
	while (++i <= n)
	{
		printf("\tProcess P[%d]:", i);
		scanf("%d%c%d", &p[i].at, &temp, &p[i].bt);
		p[i].id = i;
		p[i].flag = 0;
		tt += p[i].bt;
	}
	for (time = 0; count < n;)
	{
		for (i = 1; i <= n; i++)
		{
			if (p[i].flag == 1)
				continue;

			else
			{
				smallest = i;
				for (j = 1; j <= n; j++)
				{
					if (p[j].flag == 1 || p[j].at > time)
						continue;

					else if (p[smallest].bt > p[j].bt)
						smallest = j;
				}
				break;
			}
		}
		p[smallest].ft = time + p[smallest].bt;
		p[smallest].tat = p[smallest].ft - p[smallest].at;
		p[smallest].wt = p[smallest].tat - p[smallest].bt;
		time += p[smallest].bt;
		p[smallest].flag = 1;
		count++;
	}

	for (i = 1; i <= n; i++)
	{
		ATAT += (float)p[i].tat;
		AWT += (float)p[i].wt;
	}

	printf("\n\n PN\t|\tAT\t|\tBT\t|\tFT\t|\tTAT\t|\tWT\t|\n");
	printf("-----------------------------------------------------------------------------------------------------\n");
	for (i = 1; i <= n; i++)
	{
		printf(" %d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n", i, p[i].at, p[i].bt, p[i].ft, p[i].tat, p[i].wt);
	}
	printf("\n\n\nAverage Turn Arround Time is %f\nAverage Waiting Time is %f", (float)(ATAT / n), (float)(AWT / n));

	getch();
}
