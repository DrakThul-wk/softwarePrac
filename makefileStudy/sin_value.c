#include <stdio.h>
#include <math.h>
#define PI 3.14159

int sin_value(float angle)
{
    float value;
    value = sin(angle / 180. * PI);
    printf("\nThe sin is: %5.2f\n", value);
}