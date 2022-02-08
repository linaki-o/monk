#include <stdio.h>
bool flag[5000001];
int countPrimes(int n){
    if (n == 0) {
        return 0;
    }
    int count = 0;
    for (long i = 2; i < n; i++) {
        if (!flag[i]){
            count++;
            for (long j = i * i; j < n; j+=i) {
                flag[j] = 1;                                
            }
        }
    }
    return count;
}