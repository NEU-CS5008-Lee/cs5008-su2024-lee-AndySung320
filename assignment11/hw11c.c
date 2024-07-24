// name: Di-En Sung
// email: sung.di@northeastern.edu.tw

#include <stdio.h>

int d[20];

long long int dp(int n) {

    // Add your code here
    if(n % 2 != 0){
        return 0;
    }
    if(n == 0){
        return 1;
    }
    if (n == 2){
        return 3;
    }
    for(int i=0; i<=n; i++){
        d[i] = 0;
    }
    d[0] = 1;
    d[2] = 3;
    for(int i=4; i<=n; i+=2){
        d[i] = 3*d[i-2];
        for(int j = 4; j<=i; j+=2){
            d[i] += 2*d[i-j];
        }
    }
    return d[n];
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", dp(n));
}
