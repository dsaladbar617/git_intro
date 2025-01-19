#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    const double PI = 3.14159265359;

    int segments;
    double radius;
    double ha;
    double hb;

    double a;
    double b;
    double h;
    double top_surface;
    double bottom_surface;
    double lateral_surface;
    double total_surface;
    double volume;

    double session_surface = 0;
    double session_volume = 0;
    
    while (segments < 2 || segments > 10) {
        printf("How many spherical segments you want to evaluate [2-10]? \n");
        scanf("%d", &segments);
    }

    int i = 1;
    int temp_segments = segments;
    while (temp_segments > 0) {
        printf("Obtaining data for spherical segment number %d\n", i);
        printf("What is the radius of the sphere? (R) \n");
        scanf("%lf", &radius);
        printf("What is the height of the top area of the segment? (ha) \n");
        scanf("%lf", &ha);
        printf("What is the height of the bottom area of the segment? (hb) \n");
        scanf("%lf", &hb);
        printf("Entered Data: R = %.2f ha = %.2f hb = %.2f.\n", radius, ha, hb);

        if (ha < hb) {
            printf("Invalid Input: ha = %.2f hb = %.2f. ha must be greater than or equal hb.\n", ha, hb);
            continue;
        } else if (radius < ha) {
            printf("Invalid Input: R = %.2f hb = %.2f. R must be greater than or equal ha.\n", radius, ha);
            continue;
        }

        a = sqrt((radius * radius) - (ha * ha));
        b = sqrt((radius * radius) - (hb * hb));
        h = ha - hb;

        top_surface = PI * (a * a);
        bottom_surface = PI * (b * b);
        lateral_surface = 2 * PI * radius * h;
        total_surface = top_surface + bottom_surface + lateral_surface;
        volume = (1.0 / 6.0 * PI * h) * (3 * (a * a) + 3 * (b * b) + (h * h));

        session_surface += total_surface;
        session_volume += volume;

        printf("Total Surface Area = %.2f Volume = %.2f.\n", total_surface, volume);
        i++;
        temp_segments--;
    }

    printf("segments = %d", segments);

    double average_surface = session_surface / (double)segments;
    double average_volume = session_volume / (double)segments;

    printf("Total Average Results\n");
    printf("Average Surface Area = %.2f Average Volume = %.2f\n", average_surface, average_volume);

    return EXIT_SUCCESS;
}