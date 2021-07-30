#include <stdio.h>
#include <math.h>
#define PI 3.14159

int cos_value(float angle)
{
    float value;
    value = cos(angle / 180.* PI);
    printf("\nThe Cos is: %5.2f/n", value);
}
