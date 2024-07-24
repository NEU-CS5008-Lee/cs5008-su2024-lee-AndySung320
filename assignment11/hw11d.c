// name: Di-En Sung
// email: sung.di@northeastern.edu.tw

#include <stdio.h>

int d[20];

long long int dp(int n) {

    // Add your code here
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return 2;
    }
    if (n == 2){
        return 7;
    }
    for(int i=0; i<=n; i++){
        d[i] = 0;
    }
    d[0] = 1;
    d[1] = 2;
    d[2] = 7;
    for(int i=3; i<=n; i++){
        d[i] = 3*d[i-2] + 2*d[i-1];
        for(int j=3; j<=i; j++){
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
