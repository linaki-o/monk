#include <stdio.h>
int countPrimes(int n){
    if (n == 0) {
        return 0;
    }
    bool flag[n];     
    for (int i = 0; i < n;i++) {
        flag[i] = 0;  // FASLE means prime
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