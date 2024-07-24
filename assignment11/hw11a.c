// name: Di-En Sung
// email: sung.di@northeastern.edu.tw

#include <stdio.h>

int d[20];

long long int dp(int n) {

    // Add your code here
    d[0] = 1;
    d[1] = 1;
    for(int i=2; i<=n; i++){
        d[i] = d[i-1] + d[i-2];
    }
    return d[n];

}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", dp(n));
}
