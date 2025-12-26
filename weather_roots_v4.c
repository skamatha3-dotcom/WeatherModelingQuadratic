#include <stdio.h>
#include <math.h>

int main() {
    FILE *infile = fopen("input.txt", "r");
    FILE *outfile = fopen("output.txt", "w"); // file to save results

    if (infile == NULL) {
        printf("Cannot open input file.\n");
        return 1;
    }

    if (outfile == NULL) {
        printf("Cannot create output file.\n");
        return 1;
    }

    double a, b, c, T_target;

    while (fscanf(infile, "%lf %lf %lf %lf", &a, &b, &c, &T_target) == 4) {
        if (a == 0) {
            fprintf(outfile, "Coefficient a cannot be zero for T=%.2f. Skipping line.\n", T_target);
            continue;
        }

        double discriminant = b*b - 4*a*(c - T_target);

        if (discriminant < 0) {
            fprintf(outfile, "For T = %.2f: No real roots exist\n", T_target);
        } else {
            double root1 = (-b + sqrt(discriminant)) / (2*a);
            double root2 = (-b - sqrt(discriminant)) / (2*a);
            fprintf(outfile, "For T = %.2f: t1 = %.2f, t2 = %.2f\n", T_target, root1, root2);
        }
    }

    fclose(infile);
    fclose(outfile);

    printf("Results saved to output.txt\n");
    return 0;
}
