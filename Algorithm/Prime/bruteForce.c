#include <stdio.h>
#include <math.h>
#define TRUE 1
#define FASLE 0

bool isPrime(int x) {
    /* The reason judgement condition is "i <= sqrt(x)":
        if x is 11, 
        then we have the calculation: 11 % 2
        and then calculation: 11 % 5 is unnecessary
        and the boundary of unnecessary calc begin with "sqrt(x)"  
        so we just cut off this part
    */
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) 
            return FASLE;
    }
    return TRUE;
}
int countPrimes(int n) {
    if (n == 0)
        return 0;
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime(i)) {
            count++;
        }
    }
    return count;

}