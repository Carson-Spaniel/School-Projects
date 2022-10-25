//Carson Spaniel

#include <stdio.h>

int main()
{
    float c, f;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &c);
    while (c <0)
    {
        printf(" Please enter a positive Celsius Value: ");
        scanf("%f", &c);
    }
    
    f = (c * 9 / 5) + 32;
    printf(" %.1f degrees Fahrenheit", f);
    return 0;
}