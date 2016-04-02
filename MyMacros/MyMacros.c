#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include <stdbool.h>
/* define local constants */
#define PI 3.14159

/* define macros */
#define AREA_CIRCLE(radius) ((PI) * (radius) * (radius))
#define AREA_SQUARE(length) ((length) * (length))
#define AREA_RECTANGLE(width,height_r) ((width) * (height_r))
#define AREA_TRIANGLE(base,height_t) ((((base) * (height_t))/2))

int main(int argc, char **argv)
{
	float a = AREA_CIRCLE(10);
	float b = AREA_SQUARE(10);
	float c = AREA_RECTANGLE(5,10);
	float d = AREA_TRIANGLE(10,10);
	printf("The area of the circle is: %.2f\n", a);
	printf("The area of the square is: %.2f\n", b);
	printf("The area of the rectangle is: %.2f\n", c);
	printf("The area of the triangle is: %.2f\n", d);
    
    return (0);
}