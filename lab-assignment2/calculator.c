// name: Di-En Sung
// email: sung.di@northeastern.edu.tw
#include<stdio.h>
int main()
{
    int a,b,c, choice;
    
    printf("Enter your choice\n");
    printf(" 1.addition\n 2.Subtraction\n 3.Multiplication\n 4.Division\n");
    scanf("%d",&choice);
    

    printf("Enter a and b values ");
    scanf("%d %d", &a, &b);
    // Add your code here using switch
    switch (choice){

        case (1):
            printf("Addition\n");
            printf("Sum = %d\n", a+b);
            break;
        case(2):
            printf("Subtraction\n");
            printf("Difference = %d\n", a-b);
            break;
        case (3):
            printf("Multiplication\n");
            printf("Product = %d\n", a*b);
            break;
        case (4):
            printf("Division\n");
            if (b == 0){
                printf("Cannot divide by 0");
                break;
            }
            else {
            printf("Quotient = %d\n", a/b);
            break;
            }
        
        default:
        printf("Invalid Option");
        break;
    }
    return 0;
}
