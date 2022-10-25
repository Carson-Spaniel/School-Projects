//lab2-a
//Carson Spaniel

#include <stdio.h>

void exam_analizer(int *largest,int *smallest, float *total, int exam[])
{
  for (int i = 0; i < 10; ++i) {
    *total += exam[i];
        if (exam[i] > *largest)
    {
        *largest = exam[i];
    }
            if (exam[i] < *smallest)
    {
        *smallest = exam[i];
    }
  }
}

int main()
{

	int exam[] = { 70, 80, 90, 85, 30, 40, 95, 60, 85, 78 };
	int largest = exam[0];
	int smallest = exam[0];
	float total = 0;

  exam_analizer(&largest,&smallest,&total,exam);

	printf("\n\nHighest exam score is: %d", largest);
	printf("\nLowest exam score is: %d", smallest);
	printf("\nClass average is: %.2f\n", total / 10.0);

	return 0;
}
