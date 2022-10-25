//Carson Spaniel

#include <stdio.h>

void getScore(float *average, float *highest)
{
    int i;
    int num[4];
    int sum = 0;
    *highest = 0;

    for (i = 0; i < 4; i++)
    {
        printf("Enter score for exam %d: ", i + 1);
        scanf("%d", &num[i]);
        sum += num[i];
        if (num[i] > *highest)
        {
            *highest = num[i];
        }
    }
    *average = (sum / 4);
    
}

int main() // Do not change this main function
{
	float average, highest = 0;

	printf("Enter values for your four exam scores:\n");	
	getScore(&average, &highest);
	
	printf("\nHighest score you made is: %.2f\n", highest);
	printf("Your exam average is: %.2f\n", average);

	return 0;
}