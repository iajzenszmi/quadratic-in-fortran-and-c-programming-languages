#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    float x, y;
    char line[100];

    // Open the file that contains the Fortran output
    fp = fopen("quad.txt", "r"); // Change "output.txt" to the actual file name
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Create a temporary data file for gnuplot
    FILE *gnuplotData = fopen("data.dat", "w");
    if (gnuplotData == NULL) {
        printf("Error creating data file!\n");
        return 1;
    }

    // Read each line of the file and extract x and y values, then write them to the data file
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (sscanf(line, " x= %f , y= %f", &x, &y) == 2) {
            fprintf(gnuplotData, "%f %f\n", x, y); // Write data in two columns for gnuplot
        }
    }

    // Close the files
    fclose(fp);
    fclose(gnuplotData);

    // Call gnuplot to plot the data
    FILE *gnuplot = popen("gnuplot -persistent", "w");
    if (gnuplot == NULL) {
        printf("Error opening gnuplot!\n");
        return 1;
    }

    // Write gnuplot commands to plot the data
    fprintf(gnuplot, "set title 'Plot of y = x^2'\n");
    fprintf(gnuplot, "set xlabel 'x'\n");
    fprintf(gnuplot, "set ylabel 'y = x^2'\n");
    fprintf(gnuplot, "plot 'data.dat' with linespoints lt 1 lw 2 pt 7\n"); // Line with points

    // Close gnuplot
    pclose(gnuplot);

    return 0;
}
