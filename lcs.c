#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getStringInput(char *prompt, char *str, int size) {
    printf("%s", prompt);
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = 0;
}

int lcsLength(char *X, char *Y, int m, int n) {
    int L[m+1][n+1];
    int i, j;
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = (L[i-1][j] > L[i][j-1]) ? L[i-1][j] : L[i][j-1];
        }
    }
    return L[m][n];
}

int main() {
    char X[100], Y[100];
    int m, n, length;
    getStringInput("Enter first string: ", X, sizeof(X));
    getStringInput("Enter second string: ", Y, sizeof(Y));
    m = strlen(X);
    n = strlen(Y);
    length = lcsLength(X, Y, m, n);
    printf("Length of LCS: %d\n", length);
    return 0;
}
