// name: Di-En Sung
// email: sung.di@northeastern.edu.tw
//To perform insertion sort of integers stored in a file and display the output and store it in another file.
#include <stdio.h>
#include<stdlib.h>

#define MAX_NUMBERS 10  // Adjust as needed
int main()
{
    FILE *fp;
    int arr[10],temp;
    int count=0;
    /*count will have the total number of elements in the array*/

    /*read the file*/
    fp=fopen("Input1.txt","r");
    if(fp==NULL){
        //if file returns NULL then can't open the file
        printf("\n Cannot open the file \n");
        exit(0);
    }
    
    //insert your code here

    while (fscanf(fp, "%d", &arr[count]) != EOF && count < 10) {
        count++;
    }

  
    fclose(fp); 
    
    // Print the numbers to verify
    printf("Numbers stored in the array:\n");
    for (int j = 0; j < count; j++) {
        printf("%d ", arr[j]);
    }

    // Insertion sort
    for (int i=1; i<count; i++){
        int key = arr[i];
        int step = i-1;
        while (step >= 0 && key < arr[step]){
            arr[step+1] = arr[step];
            step --;
        }
        arr[step+1] = key;
    }

    printf("\n");
    printf("Sort:\n");
    for (int j = 0; j < count; j++) {
        printf("%d ", arr[j]);
    }

    FILE *output;
    output = fopen("sorted.txt", "w");

    for (int i = 0; i < count; i++) {
        fprintf(output, "%d\n", arr[i]);
    }

    fclose(output);
    return 0;
}
