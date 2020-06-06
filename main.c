#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct fitness {
    int dayNumber;
    char activityName[11];
    int duration;
    int caloriesBurnt;
};

void flowchart();

int functionOne(struct fitness *f);

void printListItem(struct fitness *f);

int main() {

//    flowchart();

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
        int line = 1;
        int exit = 0;
        while (1) {
            char str[255];
            fgets(str, 255, fin); // Read in line.
            if (strcmp(str, "") == 0) {
                break;
            }
            char tmp[255];
            strcpy(tmp, str);
            if (strcmp(str, strtok(tmp, "\n")) == 0) { // Last line will have no '\n' at the end of line.
                exit = 1;
            }
            char *pch;
            pch = strtok(str, " ");
            int index = 1;
            while (pch != NULL) {
                switch (index) {
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
                pch = strtok(NULL, " ");
                index++;
            }
            printListItem(&f[(line - 1)]);
            if (exit) {
                totalActivities = line;
                break;
            }
            strcpy(str, "");
            strcpy(tmp, "");
            line++;
        }
        fclose(fin);
    } else {
        printf("Error opening file");
    }
    return totalActivities;
}

void printListItem(struct fitness *f) {
    printf("%d %s %d %d\n", f->dayNumber, f->activityName, f->duration, f->caloriesBurnt);
}

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

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("The difference is %d ", diffArray[i][j]);
        }
        printf("\n");
    }
}
