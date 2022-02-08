#include <stdio.h>
bool flag[5000002];
int minPrimes[5000002];
int countPrimes(int n) {
    int k = 0;
    if (n == 0)
        return 0;
    for (int i = 2; i < n;i++) {
        if (!flag[i]) {
            minPrimes[++k] = i;
        }
        for (int j = 1; j <= k && (i * minPrimes[j]) < n; j++) { // the condition "(i * minPrimes[j]) < n" 
            flag[i * minPrimes[j]] = 1;                          // inside for or outside have great impact in time consumption
            if (i % minPrimes[j] == 0) 
                break;
        }
    }
    return k;
}