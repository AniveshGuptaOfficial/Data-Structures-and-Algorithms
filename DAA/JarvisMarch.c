#include <stdio.h>
typedef struct {
    int x, y;
} Point;
#define MAX_POINTS 100
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}
void convexHull(Point points[], int n) {
    if (n < 3) {
        printf("Convex hull is not possible\n");
        return;
    }
    int hull[MAX_POINTS];
    int hullCount = 0;
    int leftmost = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[leftmost].x) {
            leftmost = i;
        }
    }
    int p = leftmost, q;
    do {
        hull[hullCount++] = p;
        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2) {
                q = i;
            }
        }
        p = q;
    } while (p != leftmost);
    printf("Convex Hull: ");
    for (int i = 0; i < hullCount; i++) {
        printf("(%d, %d) ", points[hull[i]].x, points[hull[i]].y);
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter number of points: ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX_POINTS) {
        printf("Invaid number of points.\n");
        return 1;
    }
    Point points[MAX_POINTS];
    printf("Enter the points (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }
    convexHull(points, n);
    return 0;
}