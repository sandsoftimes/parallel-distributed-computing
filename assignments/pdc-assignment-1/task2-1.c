#include <stdio.h>
int main() {
int array1[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, ..., 16};
int array2[16] = {16, ..., 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
int result[16];
for (int i = 0; i < 16; i++) {
result[i] = array1[i] + array2[i];
}
for (int i = 0; i < 16; i++) {
printf("%d ", result[i]);
}
printf("\n");

return 0;
}