#include <stdio.h>

struct matrix {
    char name; // To hold the 1 character name of the matrix.
    float mValues[10][10]; // To hold the values in the matrix, up to 10 rows x 10 columns.
    int nrows; // To hold the number of rows used in mValues.
    int ncols; // To hold the number of columns used in mValues.
};

void matrixInput(struct matrix *mat, FILE *in);

void matrixDisplay(struct matrix mat);

float matrixDeterminant(struct matrix m1, struct matrix *m2, int *check);

void matrixInverse(struct matrix m2, float determinant, struct matrix *m3);

int main() {

    // File to read values from to populate 'original matrix'.
    char path[] = "/Users/David/Desktop/C_Test_Bench/matrix2.txt"; // Will work best with absolute path
    FILE *openFile;
    openFile = fopen(path, "r"); // Open read stream
    // Defensive programming - checking to see if input file exists for reading.
    if (openFile == NULL) {
        printf("No input file found\n");
    } else {
        int repeat = 1;
        while (repeat == 1) {
            struct matrix matA; // Initialise 'original' matrix.
            struct matrix matB; // Initialise '2x2' subset matrix.
            struct matrix matC; // Initialise 'inverse' matrix of '2x2' subset matrix.
            float determinant;
            int check; // Check value according to the determinant result.
            matrixInput(&matA, openFile);
            matrixDisplay(matA);
            determinant = matrixDeterminant(matA, &matB, &check);
            printf("The determinant is %.0f for\n", determinant);
            printf("Matrix %c:\n", matB.name);
            // Print '2x2' subset matrix.
            for (int r = 0; r < 2; r++) {
                printf("Row %d:\t", r);
                for (int c = 0; c < 2; c++) {
                    printf("%.2f\t", matB.mValues[r][c]);
                }
                printf("\n");
            }
            printf("\n");
            if (check != 2) {
                matrixInverse(matB, determinant, &matC);
            }
            printf("Would you like to input another matrix? (type 1 for yes or 0 for no)\n");
            char response = '0';
            while (response == '0') {
                fflush(stdin);
                scanf("%c", &response);
                // Defensive programming logic: (1 <= x <= 10)
                if (response == '0') {
                    repeat = 0;
                    response = '1';
                } else if (response == '1') {
                    printf("\n");
                    response = '1';
                } else if (response != '\n') {
                    printf("*** Illegal response ***\n");
                    printf("Would you like to input another matrix? (type 1 for yes or 0 for no)\n");
                    response = '0';
                }
            }
        }
        fclose(openFile);
    }

    return 0;
}

void getCharacter(struct matrix *mat) {
    printf("please enter one character name for the matrix, e.g. A, B, etc: ");
    int got_name = 0;
    char m_name;
    while (got_name == 0) {
        scanf("%c", &m_name);
        // Defensive programming logic: (a...z || A...Z)
        if ((m_name >= 'a' && m_name <= 'z') || (m_name >= 'A' && m_name <= 'Z')) {
            mat->name = m_name;
            got_name = 1;
        } else if (m_name != '\n') { // Check for '\n' which proceeds a char from stdin.
            printf("*** Illegal character name, please try again ***\n");
            printf("please enter one character name for the matrix, e.g. A, B, etc: ");
        }
    }
}

/**
 * To input the size (number of rows and columns) of the matrix, and the name of the matrix,
 * and read in the values from the file (using fscanf)
 * into the 2D array that makes up the matrix.
 *
 * @param mat The matrix
 * @param in The input file
 */
void matrixInput(struct matrix *mat, FILE *in) {
    getCharacter(mat);
    printf("Enter the # rows of the matrix (<10):\n");
    int rows = 0;
    int got_rows = 0;
    while (got_rows == 0) {
        scanf("%d", &rows);
        // Defensive programming logic: (1 <= x <= 10)
        if (rows >= 1 && rows <= 10) {
            mat->nrows = rows;
            got_rows = 1;
        } else {
            printf("*** Illegal # of rows ***\n");
            printf("Enter the # rows of the matrix (<10):\n");
        }
    }
    printf("Enter the # columns of the matrix (<10):\n");
    int columns = 0;
    int got_columns = 0;
    while (got_columns == 0) {
        scanf("%d", &columns);
        // Defensive programming logic: (1 <= x <= 10)
        if (columns >= 1 && columns <= 10) {
            mat->ncols = columns;
            got_columns = 1;
        } else {
            printf("*** Illegal # of columns ***\n");
            printf("Enter the # columns of the matrix (<10):\n");
        }
    }
    // Read in the values from the input file into the 2D array that makes up the matrix.
    for (int r = 0; r < mat->nrows; r++) {
        for (int c = 0; c < mat->ncols; c++) {
            fscanf(in, "%f", &mat->mValues[r][c]);
        }
    }
    printf("Number of rows is %d\n", mat->nrows);
}

/**
 * To display the name of the matrix and the values in the 2D array that makes up the matrix.
 *
 * @param mat The matrix
 */
void matrixDisplay(struct matrix mat) {
    printf("Matrix %c:\n", mat.name);
    // Print matrix.
    for (int r = 0; r < mat.nrows; r++) {
        printf("Row %d:\t", r);
        for (int c = 0; c < mat.ncols; c++) {
            printf("%.2f\t", mat.mValues[r][c]);
        }
        printf("\n");
    }
    printf("\n\n");
}

/**
 * To find the determinant of m2, where m2 is a 2x2 subset matrix of m1;
 * returns determinant to main;
 * this function does not display either m1 or m2, name of matrix entered here.
 * If determinant > 0, check = 1, check = 2 if determinant = 0,
 * otherwise check is 0 (size of matrix < 2x2, this variable is needed for the inverse too).
 *
 * @param m1 Original matrix
 * @param m2 Subset of original matrix
 * @param check Either: 0,1,2 (see function description)
 * @return Returns determinant to main
 */
float matrixDeterminant(struct matrix m1, struct matrix *m2, int *check) {
    printf("Finding the determinant now!\n");
    float determinant = 0;
    // Defensive Programming, original matrix has to be at least 2x2
    if (m1.nrows >= 2 && m1.ncols >= 2) {
        getCharacter(m2);
        printf("Enter row number where to start 2x2 matrix, number needs to be between 0 and %d:\n",
               (m1.nrows - 2)); // 5 - 2 max row for starting 2x2 matrix
        int rows = 0;
        int got_rows = 0;
        while (got_rows == 0) {
            scanf("%d", &rows);
            // Defensive programming logic
            if (rows >= 0 && rows <= (m1.nrows - 2)) {
                m2->nrows = rows;
                got_rows = 1;
            } else {
                printf("*** Illegal # of rows ***\n");
                printf("Enter row number where to start 2x2 matrix, number needs to be between 0 and %d:\n",
                       (m1.nrows - 2));
            }
        }
        printf("Enter column number where to start 2x2 matrix, number needs to be between 0 and %d:\n",
               (m1.ncols - 2)); // 5 - 2 max column for starting 2x2 matrix
        int columns = 0;
        int got_columns = 0;
        while (got_columns == 0) {
            scanf("%d", &columns);
            // Defensive programming logic
            if (columns >= 0 && columns <= (m1.ncols - 2)) {
                m2->ncols = columns;
                got_columns = 1;
            } else {
                printf("*** Illegal # of columns ***\n");
                printf("Enter column number where to start 2x2 matrix, number needs to be between 0 and %d:\n",
                       (m1.ncols - 2));
            }
        }
        // Populate '2x2' subset matrix starting from provided row and column indexes in 'original' matrix.
        for (int r = 0; r < 2; r++) {
            for (int c = 0; c < 2; c++) {
                m2->mValues[r][c] = m1.mValues[r + m2->nrows][c + m2->ncols];
            }
        }
        /**
         * Find the determinant.
         * e.g. A = '2x2' subset matrix
         * |A| = (a * d) - (c * d) = determinant
         */
        determinant = (m2->mValues[0][0] * m2->mValues[1][1]) - (m2->mValues[1][0] * m2->mValues[0][1]);
    } else {
        printf("*** Matrix %c is only %dx%d, needs to be at least 2x2 ***\n", m1.name, m1.nrows, m1.ncols);
    }
    /**
     * If determinant > 0, check = 1, check = 2 if determinant = 0,
     * otherwise check is 0 (size of matrix < 2x2, this variable is needed for the inverse too).
     */
    if (determinant > 0) {
        *check = 1;
    } else if (determinant == 0) {
        *check = 2;
    } else {
        *check = 0;
    }
    return determinant;
}

/**
 * To find the inverse (if possible) of the 2x2 matrix;
 * this function does not display either m2 or m3, name of matrix entered here.
 *
 * @param m2
 * @param determinant
 * @param m3
 */
void matrixInverse(struct matrix m2, float determinant, struct matrix *m3) {
    printf("Finding the inverse now!\n");
    getCharacter(m3);
    printf("The inverse of the matrix is:\n");
    printf("Matrix %c:\n", m3->name);
    /**
     *     [ a       b ]
     * B = [           ]
     *     [ c       d ]
     *
     * |B| = (a * d) - (c * d) = determinant
     *
     *                 [ d      -b ]
     * B^(-1) = (1/|B|)[           ]
     *                 [ -c      a ]
     */
    // Populate 'inverse' matrix using '2x2' subset matrix.
    float frac = 1 / determinant;
    for (int c = 1; c >= 0; c--) {
        for (int r = 1; r >= 0; r--) {
            if (c != r) {
                // b & c, multiply by -1
                m3->mValues[r][c] = frac * (m2.mValues[r][c] * -1);
            } else {
                // a & d, swap places
                m3->mValues[r][c] = frac * m2.mValues[1 - r][1 - c];
            }
        }
    }
    // Print 'inverse' matrix.
    for (int r = 0; r < 2; r++) {
        printf("Row %d:\t", r);
        for (int c = 0; c < 2; c++) {
            printf("%.2f\t", m3->mValues[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}
