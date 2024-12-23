#define _CRT_SECURE_NO_WARNINGS
#define MEMORY_ALLOCATION_ERROR 1
#include <stdio.h>
#include <math.h>

// Structure Definitions
typedef struct point {
	double x, y, z;
} Point;

typedef struct triangle {
	Point p, q, r;
} Triangle;

double distance(Point p1, Point p2) {
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) + (p1.z - p2.z)*(p1.z - p2.z));
}
// Function to calculate the perimeter of a triangle in 3 D
double perimeter(const Triangle* t) {
	double per = distance(t->p, t->q) + distance(t->p, t->r) + distance(t->q, t->r);
	return per;
}

// Function to calculate the area of a triangle in 3D 
double area(const Triangle* t) {
	double v1_x, v1_y, v1_z, v2_x, v2_y, v2_z, v_x, v_y, v_z;
	v1_x = (t->p.x) - (t->r.x);
	v1_y = (t->p.y) - (t->r.y);
	v1_z = (t->p.z) - (t->r.z);
	v2_x = (t->q.x) - (t->r.x);
	v2_y = (t->q.y) - (t->r.y);
	v2_z = (t->q.z) - (t->r.z);
	v_x = (v1_y*v2_z - v1_z * v2_y);
	v_y = -(v1_z*v2_z - v1_z * v2_x);
	v_z = v1_x * v2_y - v1_y * v2_x;
	return sqrt(v_x*v_x + v_y * v_y + v_z * v_z);
}

int main() {
	double perimeter1, area1;
	Triangle* t;
	t = (Triangle*)malloc(sizeof(Triangle));
	if (t == NULL) {
		printf("Fatal error: memory allocation failed!\n");
		return MEMORY_ALLOCATION_ERROR;
	}
	printf("Enter the coordinates of the 3 points of the triangle(x, y, z) format:\n");
	printf("Point 1 (x, y, z): ");
	scanf("%lf%lf%lf", &(t->p.x), &(t->p.y), &(t->p.z));
	printf("Point 2 (x, y, z): ");
	scanf("%lf%lf%lf", &(t->q.x), &(t->q.y), &(t->q.z));
	printf("Point 3 (x, y, z): ");
	scanf("%lf%lf%lf", &(t->r.x), &(t->r.y), &(t->r.z));
	perimeter1 = perimeter(t);
	area1 = area(t);
	// Print the results
	printf("Perimeter: %lf\n", perimeter1);
	printf("Area: %lf\n", area1);

	return 0;
}
