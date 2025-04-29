#include <stdio.h>

void inputMatrix(int mat[10][10], int r, int c) {
    printf("Enter elements:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &mat[i][j]);
}

void displayMatrix(int mat[10][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
}

void addMatrices(int A[10][10], int B[10][10], int r, int c) {
    int C[10][10];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            C[i][j] = A[i][j] + B[i][j];
    printf("Result:\n");
    displayMatrix(C, r, c);
}

void subtractMatrices(int A[10][10], int B[10][10], int r, int c) {
    int C[10][10];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            C[i][j] = A[i][j] - B[i][j];
    printf("Result:\n");
    displayMatrix(C, r, c);
}

void multiplyMatrices(int A[10][10], int B[10][10], int r1, int c1, int c2) {
    int C[10][10] = {0};
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                C[i][j] += A[i][k] * B[k][j];
    printf("Result:\n");
    displayMatrix(C, r1, c2);
}

void transposeMatrix(int A[10][10], int r, int c) {
    int T[10][10];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            T[j][i] = A[i][j];
    printf("Transpose:\n");
    displayMatrix(T, c, r);
}

int determinant2x2(int mat[2][2]) {
    return (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);
}

int determinant3x3(int mat[3][3]) {
    int det = mat[0][0]*(mat[1][1]*mat[2][2] - mat[1][2]*mat[2][1])
            - mat[0][1]*(mat[1][0]*mat[2][2] - mat[1][2]*mat[2][0])
            + mat[0][2]*(mat[1][0]*mat[2][1] - mat[1][1]*mat[2][0]);
    return det;
}

void inverse2x2(int mat[2][2]) {
    int det = determinant2x2(mat);
    if (det == 0) {
        printf("Inverse doesn't exist (det=0).\n");
        return;
    }
    float inv[2][2];
    inv[0][0] =  mat[1][1] / (float)det;
    inv[0][1] = -mat[0][1] / (float)det;
    inv[1][0] = -mat[1][0] / (float)det;
    inv[1][1] =  mat[0][0] / (float)det;

    printf("Inverse Matrix:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            printf("%.2f\t", inv[i][j]);
        printf("\n");
    }
}

int main() {
    int A[10][10], B[10][10], r1, c1, r2, c2, choice;

    while (1) {
        printf("\n--- Matrix Operations ---\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Transpose\n");
        printf("5. Determinant (2x2)\n6. Determinant (3x3)\n7. Inverse (2x2)\n0. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        if (choice == 0) break;

        switch (choice) {
            case 1:
            case 2:
                printf("Enter rows and cols: ");
                scanf("%d%d", &r1, &c1);
                printf("Matrix A:\n");
                inputMatrix(A, r1, c1);
                printf("Matrix B:\n");
                inputMatrix(B, r1, c1);
                if (choice == 1) addMatrices(A, B, r1, c1);
                else subtractMatrices(A, B, r1, c1);
                break;

            case 3:
                printf("Enter rows and cols for A: ");
                scanf("%d%d", &r1, &c1);
                printf("Enter cols for B (rows same as A cols): ");
                scanf("%d", &c2);
                printf("Matrix A:\n");
                inputMatrix(A, r1, c1);
                printf("Matrix B:\n");
                inputMatrix(B, c1, c2);
                multiplyMatrices(A, B, r1, c1, c2);
                break;

            case 4:
                printf("Enter rows and cols: ");
                scanf("%d%d", &r1, &c1);
                inputMatrix(A, r1, c1);
                transposeMatrix(A, r1, c1);
                break;

            case 5:
                printf("Enter 2x2 matrix:\n");
                inputMatrix(A, 2, 2);
                printf("Determinant = %d\n", determinant2x2(A));
                break;

            case 6:
                printf("Enter 3x3 matrix:\n");
                inputMatrix(A, 3, 3);
                printf("Determinant = %d\n", determinant3x3(A));
                break;

            case 7:
                printf("Enter 2x2 matrix:\n");
                inputMatrix(A, 2, 2);
                inverse2x2(A);
                break;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
