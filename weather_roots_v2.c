#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, T_target;

    // Take input from user
    printf("Enter coefficient a: ");
    scanf("%lf", &a);
    printf("Enter coefficient b: ");
    scanf("%lf", &b);
    printf("Enter coefficient c: ");
    scanf("%lf", &c);
    printf("Enter target temperature: ");
    scanf("%lf", &T_target);

    // Check for a=0 (not a quadratic)
    if(a == 0){
        printf("Coefficient a cannot be zero for a quadratic equation.\n");
        return 1;
    }

    double discriminant = b*b - 4*a*(c - T_target);

    if(discriminant < 0){
        printf("No real roots exist for T = %.2f\n", T_target);
    } else {
        double root1 = (-b + sqrt(discriminant)) / (2*a);
        double root2 = (-b - sqrt(discriminant)) / (2*a);
        printf("Temperature %.2f reached at t = %.2f and t = %.2f\n", T_target, root1, root2);
    }

    return 0;
}
