// name: Di-En Sung
// email: sung.di@northeastern.edu.tw

#include<stdio.h>
#include<string.h>

int compression(char arr[], int n, char res[]){
    
    
    
    
    //insert your code here
    int start = 0;
    char encoding[50];
    strcpy(res, "");
    while (start < n){
        char cur = arr[start];
        int repeat = 0;
        int idx = start;
        while(cur == arr[idx]){
            repeat++;
            idx++;
        }
        if (repeat > 1){
            sprintf(encoding, "%c%d", cur, repeat);
            strcat(res, encoding);
            start = start + repeat;
        }
        else{
            sprintf(encoding, "%c", cur);
            strcat(res, encoding);
            start++;
        }
    }
    printf("output: %s\n", res);
    return strlen(res);
}
 
int main()
{
    char a[]="aaaaaaaaaaaaaabbbbcccd";
    char res[50];
    int r,n=strlen(a);//n is the size of input array
    r=compression(a,n,res);
    printf("length of the compressed string:%d\n",r);
    return 0;
}
