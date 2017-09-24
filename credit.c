//
//  credit.c
// 
//  Created by Rashomi Silva on 8/2/17.
//
//

#include <stdio.h>


// prototype

int numElements (long long int a);
int product (int numbers[], int n);
int check_sum (int values[] ,int n);


int main (void)

{
    long long int number;
    int sum = 0;
    int digit_sum = 0;
    int product = 0;
    int n;
    
    //Geting the user input
    printf ("Number: ");
    scanf ("%lli", &number);
    
    //Get the digit-count of the card number if digint count is not 13, 15 or 16 the card is considered as invalid, print message and exit the code.
    n = numElements(number);
    
    if (n == 13 || n == 15 || n == 16)
        
    {
        // Initilizing the array with cerdit card numbers.
        int creditCard [n];
        
        for (int i = n-1; i >= 0; i--)
        {
            
            if (number > 0)
            {
                creditCard[i] = number % 10;
                
                number = number/10;
            }
            
        }
        
        sum = check_sum (creditCard , n);
        if (sum % 10  == 0)
        {
            
            if  (creditCard[0] == 4 && n == 16)
                printf ("VISA\n");
            else if
                (creditCard[0] == 4 && n == 13)
                printf ("VISA\n");
            else if
                (n == 16 && creditCard[0] == 5)
            {
                if  (creditCard[1] == 1 || creditCard[1] == 2 || creditCard[1] == 3 || creditCard[1] == 4 || creditCard[1] == 5)
                    printf ("MASTER\n ");
                
            }
            else if
                (n == 15 && creditCard[0] == 3)
            {
                if (creditCard[1] == 4 || creditCard[1] == 7)
                    printf ("AMEX\n ");
            }
            
            
            
        }
        
        else
            printf ("INVALID\n");
        
    }
    
}

//prototypes

int numElements (long long int a)

{
    int b = 0;
    
    do
    {
        a = a/10;
        b++;
    }
    
    while
        (a > 0 );
    
    return b;
}


int product (int numbers[], int n)
{
    int digit_sum = 0;
    int product1;
    
    for (int i  = n-2; i >= 0; i-=2)
    {
        
        product1 = numbers[i] *2;
        if (product1 < 10)
            digit_sum = digit_sum + product1;
        else
        {
            digit_sum = digit_sum+ product1 % 10;
            digit_sum = digit_sum + product1/ 10;
        }
        
    }
    
    return digit_sum;
}


int check_sum (int values[] ,int n)

{
    int sum = 0;
    int digit_sum;
    for (int i = n-1; i > 0 ; i-=2)
    {
        sum = sum +values[i];
        
    }
    digit_sum = product(values, n);
    
    return (sum + digit_sum);
    
}





