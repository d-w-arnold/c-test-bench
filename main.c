#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NUM 100
#define MAX 10

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
 * Exam 2018-19 2a)
 */
struct employee {
    char name[100];
    char surname[100];
    int age;
    int salary
};

/**
 * Exam 2019-20 2a)
 */
struct walking {
    int indexNumber;
    char buildingName[100];
    float distance; // Miles
    int timeToDiamond; // Time taken to walk from the named building to the Diamond
    int timeFromDiamond; // Time taken to walk from the Diamond to the named building
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

/**
 * Exam 2018-19 1bi)
 * The exam question asks to write the solution in main(), though it gets its own function for now.
 */
void flowchart2();

/**
 * Exam 2018-19 2b)
 * The exam question asks to write the solution in main(), though it gets its own function for now.
 * @param e A pointer to the first index in an array of structs.
 * @param numEmployees The number of employees already in the array of structs.
 * @return The total number of employees by the end of the functions execution.
 */
int appendFile(struct employee *e, int numEmployees);

/**
 * Exam 2019-20 2bii)
 */
float findVariance(float *diff, float *arrayData, float mean, float var);

int main() {

    /**
     * Exam 2019-20 1a)
     * Prompts a user to enter a security code by typing a sequence of four characters from the keyboard.
     * The program must determine whether or not the sequence is correct,
     * if it is not correct the program must print out a message for each incorrect character.
     * The message should print the incorrect input character and its position in the sequence (i.e. position 1, 2, 3 or 4).
     * If the input sequence is too short, the program must print out a message to say at which position(s) no character has been provided.
     * The correct characters will be stored in a character array, and the four input characters will be stored in another character array.
     */
//    char sequence[4] = {'0', '0', '0', '0'};
//    char correctSequence[4] = {'A', 'C', 'S', 'E'};
//    int i = 0;
//    int j;
//    int k;
//    int stopFlag = 0;
//    printf("Enter 4 character sequence\n");
//    while (i < 4 && stopFlag != 1) {
//        sequence[i] = getchar();
//        if (sequence[i] == '\n') {
//            stopFlag = 1;
//        } else {
//            i++;
//        }
//    }
//
//    int x = 0;
//    int y;
//    int currentPos;
//    while (x < 4) {
//        if (sequence[x] == '\n') {
//            currentPos = (x + 1);
//            if (currentPos <= 4) {
//                for (y = currentPos; y <= 4; y++) {
//                    printf("No character has been provided at position %d\n", y);
//                }
//            }
//            break;
//        } else {
//            if (sequence[x] != correctSequence[x]) {
//                printf("%c is incorrect at position %d\n", sequence[x], (x + 1));
//            }
//            x++;
//        }
//    }

    /**
     * Exam 2019-20 1bi)
     * Exam 2019-20 1bii)
     */
//    float sum = 0;
//    float mean;
//    float var = 0;
//    float diff;
//    int i, j, k;
//    float arrayData[MAX];
//    printf("Enter 10 elements\n");
//    // enter array elements
//    for (i = 0; i < 10; i++) {
//        scanf("%f", &arrayData[i]);
//    }
//    // find the mean
//    for (j = 0; j < 10; j++) {
//        sum = sum + arrayData[j];
//    }
//    mean = sum / 10;
//    // find the variance
//    var = findVariance(&diff, arrayData, mean, var);
//    printf("Mean = %f, Var / 10 = %f", mean, (var / 10));

    /**
     * Exam 2019-20 1biii)
     */
//    int N;
//    printf("Please specify size of array:");
//    scanf("%d", &N);
//    float *arrayPtr;
//    arrayPtr = (float *) calloc(N, sizeof(float));

    /**
     * Exam 2019-20 2b)
     * Please note that you must program defensively at every possible point.
     * If the user enters incorrect information, then the user needs to be asked to enter another value.
     * To keep things simple, if the program asks the user to enter a number (e.g. 0‒7),
     * then you only need to check the entered value against numbers (e.g. 8 is not allowed)
     * and not characters (e.g. not a‒z, A‒Z).
     * Do not show main(), or any other functions.
     * Note: The structure is declared in main() and not in the Function 3.
     *
     * asks the student to select a building she has visited via its index number
     * asks the student to select the time either walking from named building to the Diamond (enter 1) or walking from Diamond to named building (enter 2)
     * prints to the screen the student’s chosen information
     * loops to the start until the student opts to quit
     * prints the total distance walked, and the total time taken in hours.
     */
    char path[] = "/Users/David/Documents/CLion/CLion Projects/untitled/walking.txt";
    FILE *fin;
    if ((fin = fopen(path, "r")) != NULL) {
        while (1) {
            int n;
            printf("Please select a building via its index number (enter -1 to quit):\n");
            scanf("%d", &n);
            if (n == -1) {
                //quit
                break;
            }
            struct walking tw;
            int found = 0;
            while (fscanf(fin, "%d %s %f %d %d", &tw.indexNumber, tw.buildingName, &tw.distance, &tw.timeToDiamond,
                          &tw.timeFromDiamond) == 5) {
                if (tw.indexNumber == n) {
                    found = 1;
                    break;
                }
            }
            if (found == 1) {
                while (1) {
                    int t;
                    printf("Please select the time either: walking from named building to the Diamond (enter 1) or walking from Diamond to named building (enter 2)\n");
                    scanf("%d", &t);
                    if (t == 0) {
                        printf("Time taken walking from named building to the Diamond: %d minutes", tw.timeToDiamond);
                        break;
                    } else if (t == 1) {
                        printf("Time taken walking from Diamond to named building: %d minutes", tw.timeFromDiamond);
                        break;
                    } else {
                        // Not 0 or 1
                        printf("Please enter either 0 or 1\n");
                    }
                }
                break;
            } else {
                printf("Could not find index number\n");
                continue;
            }
        }
    } else {
        printf("Error opening file\n");
    }
    fclose(fin);

    return 0;
}

/**
 * Exam 2019-20 1bii)
 */
float findVariance(float *diff, float *arrayData, float mean, float var) {
    int k;
    float tmpDiff = *diff;
    float tmpVar = var;
    for (k = 0; k < 10; k++) {
        tmpDiff = arrayData[k] - mean;
        tmpVar = tmpVar + (tmpDiff * tmpDiff);
    }
    *diff = tmpDiff;
    return tmpVar;
}

/**
 * Exam 2018-19 2b)
 * Opens the file
 * Asks the student how many new entries are to be added to the file
 * Asks the student to enter the name, surname, age and salary the appropriate number of times.
 * These new entries are added to the file
 * The file is closed
 * The total number of employees is returned to main.
 */
int appendFile(struct employee *e, int numEmployees) {
    int i = 0;
    int a;
    int total = 0;
    char path[] = "/Users/David/Documents/CLion/CLion Projects/untitled/employees.txt";
    FILE *fin;
    if ((fin = fopen(path, "a")) != NULL) {

        do {
            printf("\nNumber of employees to append:");
            scanf("%d", &a);
            total = numEmployees + a;
            if (total > MAX_NUM) {
                printf("You have exceeded %d employees in list. Cannot add more!\n", MAX_NUM);
            }
        } while (total > MAX_NUM);

        for (i = 0; i < a; i++) {
            printf("\nEnter name;\n");
            scanf("%s", e[i].name);
            printf("Enter surname;\n");
            scanf("%s", (e[i].surname));
            printf("Enter age;\n");
            scanf("%d", &(e[i].age));
            printf("Enter salary;\n");
            scanf("%d", &(e[i].salary));
            fprintf(fin, "\n%s %s %d %d", (e[i].name), e[i].surname, (e[i].age), (e[i].salary));
        } // end for loop

    } else {
        printf("Error opening file\n");
    }

    fclose(fin);
    return total;
}

/**
 * Exam 2018-19 1bi)
 * The exam question asks to write the solution in main(), though it gets its own function for now.
 */
void flowchart2() {
    int n;
    int i;
    int j;
    int k;
    int flag = 0;
    int isPrime1 = 1;
    int isPrime2 = 1;

    printf("Enter a positive integer: ");
    scanf("%d", &n);
    for (i = 2; i <= n / 2; i++) {
        isPrime1 = 1;
        for (j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                isPrime1 = 0;
            }
        }
        if (isPrime1 == 1) {
            isPrime2 = 1;
            for (k = 2; k <= (n - i) / 2; k++) {
                if ((n - i) % k == 0) {
                    isPrime2 = 0;
                }
            }
            if (isPrime2 == 1) {
                printf("%d = %d + %d\n", n, i, n - i);
                flag = 1;
            }
        } //close if loop (isPrime1 == 1)
    } //close for loop (i)
    if (flag == 0) {
        printf("%d cannot be expressed as the sum of two prime numbers.", n);
    }
}

/**
 * Exam 2017-18 2b)
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
        while (fscanf(fin, "%d %s %d %d", &f[i].dayNumber, f[i].activityName, &f[i].duration, &f[i].caloriesBurnt) ==
               4 && i < MAX_NUM) {
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
