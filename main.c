#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Exam 2017-18 2a)
 */
struct fitness {
    int dayNumber;
    char activityName[11];
    int duration;
    int caloriesBurnt;
};

/**
 * Exam 2017-18 1b)
 * The exam question asks to write the solution in main(), though it gets its own function for now.
 */
void flowchart();

/**
 * Exam 2017-18 2b)
 * @param f A pointer to the first index in an array of fitness structs.
 * @return The total number of activities, in the file myActivity.txt.
 */
int functionOne(struct fitness *f);

void printListItem(struct fitness *f);

int main() {

    flowchart();

//    struct fitness myFitnessLog[100];
//    int totalActivities = functionOne(myFitnessLog);

    return 0;
}

/**
 * Open the file “myActivity.txt”.
 * Read the list from the file “myActivity.txt” into the array of struct.
 * Output the list to the screen.
 * Close the file “myActivity.txt” and
 * finally return the number of activities taken in the list to the calling function
 * (assume the function is called by main).
 */
int functionOne(struct fitness *f) {
    int totalActivities = 0;
    char path[] = "/Users/David/Documents/CLion/CLion Projects/untitled/myActivity.txt";
    FILE *fin;
    if ((fin = fopen(path, "r")) != NULL) {
        int line = 1; // The line we're at in './myActivity.txt'.
        int exit = 0; // A boolean for exiting while loop when needed.
        while (1) {
            char str[255]; // A line from './myActivity.txt'.
            fgets(str, 255, fin); // Read in line.
            if (strcmp(str, "") == 0) { // Check for an empty line.
                totalActivities = line - 1;
                break;
            }
            char tmp[255];
            strcpy(tmp, str); // Make copy of str
            if (strcmp(str, strtok(tmp, "\n")) == 0) { // Check for no '\n' at the end of a line.
                exit = 1;
            }
            char *pch; // A buffer for getting the next string between whitespaces.
            pch = strtok(str, " "); // Breaks string str into a token using the separator specified.
            int index = 1;
            while (pch != NULL) {
                switch (index) {
                    // atoi(), converts a string to an integer, if it fails, it returns 0 - requires stdlib.h
                    case 1:
                        f[(line - 1)].dayNumber = atoi(pch);
                        break;
                    case 2:
                        strcpy(f[(line - 1)].activityName, pch);
                        break;
                    case 3:
                        f[(line - 1)].duration = atoi(pch);
                        break;
                    case 4:
                        f[(line - 1)].caloriesBurnt = atoi(pch);
                        break;
                }
                pch = strtok(NULL, " "); // Breaks string str into a token using the separator specified.
                index++;
            }
            printListItem(&f[(line - 1)]);
            if (exit) {
                totalActivities = line;
                break;
            }
            strcpy(str, ""); // Set str to be the empty string
            strcpy(tmp, ""); // Set tmp to eb the empty string
            line++;
        }
        fclose(fin);
    } else {
        printf("Error opening file");
    }
    return totalActivities;
}

/**
 * Helper function to functionOne().
 * @param f A pointer to the fitness struct to have its values printed to standard output.
 */
void printListItem(struct fitness *f) {
    printf("%d %s %d %d\n", f->dayNumber, f->activityName, f->duration, f->caloriesBurnt);
}

/**
 * Exam 2017-18 1b)
 * The exam question asks to write the solution in main(), though it gets its own function for now.
 */
void flowchart() {
    printf("Number of rows:\n");
    int m = 1;
    scanf("%d", &m);

    printf("Number of columns:\n");
    int n = 1;
    scanf("%d", &n);

    printf("The values of the matrix array1:\n");
    int array1[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &(array1[i][j]));
//            printf("l[%d][%d] = %d\n", i, j, array1[i][j]);
        }
    }

    printf("The values of the matrix array2:\n");
    int array2[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &(array2[i][j]));
//            printf("l[%d][%d] = %d\n", i, j, array2[i][j]);
        }
    }

    int diffArray[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            diffArray[i][j] = array1[i][j] - array2[i][j];
        }
    }

    printf("The difference is \n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d", diffArray[i][j]);
        }
        printf("\n");
    }
}
