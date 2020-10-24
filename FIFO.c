//12345341678789978954542
//1234215621237632
//70120304230321201701
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
int main()
{

	int queue[10], input[50], frame_size, i = 0, j, count = 0, index = 0;
	char str[50];
	printf("Enter the frame size :");
	scanf("%d", &frame_size);
	frame_size -= 1;
	for (j = 0; j <= frame_size; j++)
		queue[j] = 0;
	printf("Enter the String :");
	scanf("%s", str);

	for (i = 0; i < strlen(str); i++)
		input[i] = int(str[i]) - 48;
	input[i] = 99999;
	for (i = 0; input[i] != 99999; i++)
	{
		if (!is_exist(queue, frame_size, input[i]))
		{
			queue[index] = input[i], count++;
			index = (index + 1) % (frame_size + 1);
		}
		else
			continue;
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
