#include <stdio.h>
#include <math.h>  // Needed for sqrt()

int main() {
    double a = -0.5, b = 4, c = 25;
    double T_target = 30;

    double discriminant = b*b - 4*a*(c - T_target);

    if (discriminant < 0) {
        printf("No real roots exist\n");
    } else {
        double root1 = (-b + sqrt(discriminant)) / (2*a);
        double root2 = (-b - sqrt(discriminant)) / (2*a);
        printf("Temperature %.2f reached at t = %.2f and t = %.2f\n", T_target, root1, root2);
    }

    return 0;
}
