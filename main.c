#include <stdio.h>
#include <string.h>

#define MAX_NUM 100

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
int totalActivity(struct fitness *f);

void printListItem(struct fitness *f);

int main() {

//    flowchart();

    struct fitness myFitnessLog[MAX_NUM];
    int totalActivities = totalActivity(myFitnessLog);
    printf("%d", totalActivities);

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
int totalActivity(struct fitness *f) {
    int i = 0;
    char path[] = "/Users/David/Documents/CLion/CLion Projects/untitled/myActivity.txt";
    FILE *fin;
    if ((fin = fopen(path, "r")) != NULL) {
        while (fscanf(fin, "%d %s %d %d", &f[i].dayNumber, f[i].activityName, &f[i].duration, &f[i].caloriesBurnt) == 4 && i < MAX_NUM) {
            printf("%d %s %d %d\n", f[i].dayNumber, f[i].activityName, f[i].duration, f[i].caloriesBurnt);
            i++;
        }
    } else {
        printf("Error opening file\n");
    }
    fclose(fin);
    return i;
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
