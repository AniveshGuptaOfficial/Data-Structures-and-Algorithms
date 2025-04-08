#include <stdio.h>
#include <stdlib.h>
typedef struct Point {
    int x, y;
} Point;
Point points[100];
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // colinear
    return (val > 0) ? 1 : 2; // clockwise or counterclockwise
}
int distSq(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}
int bottomMost(Point points[], int n) {
    int minIdx = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < points[minIdx].y ||
           (points[i].y == points[minIdx].y && points[i].x < points[minIdx].x)) {
            minIdx = i;
        }
    }
    return minIdx;
}
int compare(const void *p1, const void *p2) {
    Point *a = (Point *)p1;
    Point *b = (Point *)p2;
    int o = orientation(points[0], *a, *b);
    if (o == 0)
        return (distSq(points[0], *a) < distSq(points[0], *b)) ? -1 : 1;
    return (o == 2) ? -1 : 1;
}
void convexHull(Point points[], int n) {
    if (n < 3) {
        printf("Convex hull not possible\n");
        return;
    }
    int minIdx = bottomMost(points, n);
    Point temp = points[0];
    points[0] = points[minIdx];
    points[minIdx] = temp;
    qsort(&points[1], n - 1, sizeof(Point), compare);
    Point hull[n];
    int top = 0;
    hull[top++] = points[0];
    hull[top++] = points[1];
    for (int i = 2; i < n; i++) {
        while (top > 1 && orientation(hull[top - 2], hull[top - 1], points[i]) != 2)
            top--;
        hull[top++] = points[i];
    }
    printf("Convex Hull: ");
    for (int i = 0; i < top; i++)
        printf("(%d, %d) ", hull[i].x, hull[i].y);
    printf("\n");
}
int main() {
    int n;
    printf("Enter number of points: ");
    scanf("%d", &n);
    if (n <= 0 || n > 100) {
        printf("Invalid number of points\n");
        return 1;
    }
    printf("Enter the points (x y):\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d", &points[i].x, &points[i].y);
    convexHull(points, n);
    return 0;
}