#include <stdio.h>

float mean(float sum, float N);

int main(void) {

    // Assignment statements for the read and write streams.
    char path[] = "./File1.txt";
    FILE *read;
    read = fopen(path, "r");
    FILE *write;
    write = fopen(path, "w");
    // Other variables
    char ch;
    int c;
    float sum = 0;
    float N = 0;
    float numC;
    // Write a line to the standard output prompting the user for an input.
    printf("please input chars on a line, no spaces:\n");
    // Write to File1.txt the standard input (e.g. sf98375hf^%839*&% ).
    while ((ch = getchar()) != '\n') {
        fprintf(write, "%c", ch);
    }
    // Close write stream so File1.txt contains chars to read for the next steps.
    fclose(write);
    // Write the third line to standard output
    printf("Numbers found in the line:\n");
    // Write to standard output all numbers in File1.txt
    if (read == NULL) {
        // Defensive programming - checking to see if File1.txt exists for reading.
        printf("Error opening file\n");
    } else {
        while ((c = fgetc(read)) !=
               EOF) { // Check to see if most recent found char is the EOF (end of file), tried '\n' and just hangs - does not work.
            if (c >= '0' && c <= '9') { // Check to see if the char is in the range of '0'-'9'.
                printf("%c\n", c);
                numC = (float) c - '0'; // Converts a char to the equivalent number value (e.g. '9' -> 9)
                sum += numC; // (sum = sum + numC;)
                N += 1; // (N = N + 1;)
            }
        }
        // Close read stream
        fclose(read);
        // Write the sum to standard output.
        printf("sum is %.1f\n", sum); // %.1f is a float to 1 decimal place
        // Write the count to standard output.
        printf("no of numbers is %.1f\n", N); // %.1f is a float to 1 decimal place
        // Write the mean to standard output.
        printf("The mean is %.2f", mean(sum, N)); // %.2f is a float to 2 decimal places
    }

    return 0;
}

float mean(float sum, float N) {
    return sum / N;
}
