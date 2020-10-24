#include <stdio.h>
#include <conio.h>
#include <string.h>

int is_exist(int a[], int n, int num)
{
	for (int i = 0; i <= n; i++)
	{
		if (a[i] == num)
			return 1;
	}
	return 0;
}

int location(int a[], int num, int start, int end)
{
	for (int i = start; i <= end; i++)
		if (num == a[i])
			return i;
	return 99999;
}

int main()
{
	int queue[10], input[50], frame_size, i, c, c1, j;
	int count = 0, index = 0;
	char str[50];

	printf("Enter the frame size :");
	scanf("%d", &frame_size);
	frame_size -= 1;

	printf("Enter the String :");
	scanf("%s", str);

	for (i = 0; i < strlen(str); i++)
		input[i] = int(str[i]) - 48;
	input[i] = 99999;
	for (i = 0; input[i] != 99999; i++)
	{
		if (i <= frame_size)
			queue[i] = input[i], count++;
		else if (!is_exist(queue, frame_size, input[i]))
		{
			c = location(input, queue[0], i, strlen(str)), index = 0;
			for (j = 1; j <= frame_size; j++)
			{
				c1 = location(input, queue[j], i, strlen(str));
				if (c < c1)
					c = c1, index = j;
			}
			queue[index] = input[i], count++;
		}
		else
		{
			printf("For %d No replacement is needed\n", input[i]);
			continue;
		}
		printf("For %d\t\t ", input[i]);
		for (j = 0; j <= frame_size; j++)
			printf("----- ");
		printf("\n\t\t");
		for (j = 0; j <= frame_size; j++)
			printf("|  %d  ", queue[j]);
		printf("|\n\t\t ");
		for (j = 0; j <= frame_size; j++)
			printf("----- ");
		printf("\n");
	}
	printf("Page fault is %d ", count);
	getch();
}
//70120304230321201701
