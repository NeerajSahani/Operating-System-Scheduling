#include <stdio.h>
#include <conio.h>
struct process
{
	int allocation[10], max[10], need[10], flag, af;
} p[10];
int main()
{

	/**********************************************Input****************************/
	int pno, rno, available[10], sq[10], count = 1, i, j, x = 0;
	char temp;
	printf("Enter Number of Processes :");
	scanf("%d", &pno);
	printf("Number of Resources :");
	scanf("%d", &rno);
	printf("Enter Data ....\n\t[Allocation,max]\n");
	for (i = 1; i <= pno; i++)
	{
		printf("\n\tFor procss P[%d]...\n", i);
		for (j = 1; j <= rno; j++)
		{
			printf("Enter [%c]", 64 + j);
			scanf("%d%c%d", &p[i].allocation[j], &temp, &p[i].max[j]);
			p[i].need[j] = p[i].max[j] - p[i].allocation[j];
		}
		p[i].flag = 0;
	}
	printf("Enter Available Resources ....\n");
	for (j = 1; j <= rno; j++)
	{
		printf("Resource %c :", 64 + j);
		scanf("%d", &available[j]);
	}

	/****************************************Processing******************************/

	printf("\n***************Need Matrix*********************\n");
	for (i = 1; i <= pno; i++)
	{
		printf("|");
		for (j = 1; j <= rno; j++)
			printf("%4d", p[i].need[j]);
		printf("|\n");
	}

	do
	{
		for (i = 1; i <= pno; i++)
		{
			if (p[i].flag == 1)
				continue;

			p[i].af = 0;
			for (j = 1; j <= rno; j++)
			{
				if (p[i].need[j] <= available[j])
					p[i].af += 1;
				else
					break;
			}
			if (p[i].af == rno)
			{

				sq[count++] = i;
				for (j = 1; j <= rno; j++)
					available[j] += p[i].allocation[j];
				p[i].flag = 1;
				printf("Process %d is in safe Sequence\n", i);
				printf("After Execution of %d Available resources are...\n", i);
				for (j = 1; j <= rno; j++)
					printf("\t%c :%3d\n", j + 64, available[j]);
			}
		}
		if (x++ > pno)
			break;
	} while (count <= pno);
	if (count >= pno)
	{
		printf("Safe Sequence is ...<");
		for (i = 1; i <= pno; i++)
			printf("P[%d] ", sq[i]);
		printf(">");
	}
	else
		printf("Processes are not in safe state....\n");

	getch();
}
