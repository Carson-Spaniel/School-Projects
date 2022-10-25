#include <stdio.h>
float exp(float a1, float a2);
int main() {
    float base, a, result;
    printf("Enter base: ");
    scanf("%f", &base);
  
    printf("Enter exponent:");
    scanf("%f", &a);
  
    result = exp(base, a);
    printf("\nResult: %.2f", result);
    return 0;
}

float exp(float base, float a) {
    if (a != 0)
        return (base * exp(base, a - 1));
    else
        return 1;
}