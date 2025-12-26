#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void displayMenu();
int calculateFactorial(int n);
void fibonacciSeries(int terms);
int isPrime(int num);
void reverseString(char *str);
int findMax(int arr[], int size);

int main() {
    printf("=== C Programming Assignment ===\n");
    printf("Student: LASTNAME FIRSTNAME\n");
    printf("GitHub Repository: c-assignment-LASTNAME-FIRSTNAME\n\n");
    
    int choice, number, size;
    char str[100];
    int *array;
    
    do {
        displayMenu();
        printf("Enter your choice (1-6, 0 to exit): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter a number to calculate factorial: ");
                scanf("%d", &number);
                if(number < 0) {
                    printf("Factorial is not defined for negative numbers.\n");
                } else {
                    printf("Factorial of %d = %d\n", number, calculateFactorial(number));
                }
                break;
                
            case 2:
                printf("Enter number of terms for Fibonacci series: ");
                scanf("%d", &number);
                if(number <= 0) {
                    printf("Please enter a positive integer.\n");
                } else {
                    fibonacciSeries(number);
                }
                break;
                
            case 3:
                printf("Enter a number to check if it's prime: ");
                scanf("%d", &number);
                if(isPrime(number)) {
                    printf("%d is a prime number.\n", number);
                } else {
                    printf("%d is not a prime number.\n", number);
                }
                break;
                
            case 4:
                printf("Enter a string to reverse: ");
                getchar(); // Clear input buffer
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = 0; // Remove newline character
                reverseString(str);
                printf("Reversed string: %s\n", str);
                break;
                
            case 5:
                printf("Enter the size of array: ");
                scanf("%d", &size);
                array = (int*)malloc(size * sizeof(int));
                
                if(array == NULL) {
                    printf("Memory allocation failed!\n");
                    break;
                }
                
                printf("Enter %d integers:\n", size);
                for(int i = 0; i < size; i++) {
                    printf("Element %d: ", i+1);
                    scanf("%d", &array[i]);
                }
                
                printf("Maximum element in array = %d\n", findMax(array, size));
                free(array);
                break;
                
            case 6:
                printf("=== Program Features ===\n");
                printf("1. Calculate factorial using recursion\n");
                printf("2. Generate Fibonacci series\n");
                printf("3. Prime number checker\n");
                printf("4. String reversal\n");
                printf("5. Find maximum element in array\n");
                printf("6. Display this information\n");
                printf("0. Exit program\n");
                break;
                
            case 0:
                printf("Thank you for using the program!\n");
                printf("GitHub Repository: https://github.com/yourusername/c-assignment-LASTNAME-FIRSTNAME\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("\n");
        
    } while(choice != 0);
    
    return 0;
}

// Function to display menu
void displayMenu() {
    printf("=====================\n");
    printf("      MAIN MENU\n");
    printf("=====================\n");
    printf("1. Calculate Factorial\n");
    printf("2. Fibonacci Series\n");
    printf("3. Check Prime Number\n");
    printf("4. Reverse String\n");
    printf("5. Find Maximum in Array\n");
    printf("6. Display Program Features\n");
    printf("0. Exit\n");
    printf("=====================\n");
}

// Function to calculate factorial recursively
int calculateFactorial(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }
    return n * calculateFactorial(n - 1);
}

// Function to generate Fibonacci series
void fibonacciSeries(int terms) {
    int t1 = 0, t2 = 1, nextTerm;
    
    printf("Fibonacci Series: ");
    for(int i = 1; i <= terms; i++) {
        printf("%d ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n");
}

// Function to check if a number is prime
int isPrime(int num) {
    if(num <= 1) return 0;
    if(num == 2) return 1;
    if(num % 2 == 0) return 0;
    
    for(int i = 3; i * i <= num; i += 2) {
        if(num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to reverse a string
void reverseString(char *str) {
    int length = strlen(str);
    char temp;
    
    for(int i = 0; i < length / 2; i++) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

// Function to find maximum element in array
int findMax(int arr[], int size) {
    int max = arr[0];
    
    for(int i = 1; i < size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}    