//===================
// Amna Shafiq
// 19i-1978
// CS-F
// Question-2
//===================

#include <iostream>
#include <vector>
using namespace std;

int findMax(int , int);
int Simple_Recursive(int , int*);
int Memoized_Recursive(int , int* , int*);
int Iterative_Method(int , int*);

int main() {
	
    int price[] = { 10,20,30,40,50,60,70 };
    int land = (20 * 25) / 100;
    int *values = new int [land + 1];

    for (int i = 0; i < land + 1; i++)
    {
        values[i] = -1;
    }
    cout << "================================================" << endl;
    cout << "Profit from simple recursive method = " << Simple_Recursive(land , price) << endl;
    cout << "Profit from memoized recursive method = " << Memoized_Recursive(land, price, values) << endl;
    cout << "Profit from memoized iterative method = " << Iterative_Method(land, price) << endl;
    cout << "================================================" << endl;	
	return 0;
}

int findMax(int num1, int num2)
{
    if(num1 > num2)
    {
        return num1;
    }
    else
    {
        return num2;
    }
}

// Simple Recursion (Part-1)
int Simple_Recursive(int land, int* price) {
    if(land == 0)
    {
        return 0;
    }
    int max = price[0] + Simple_Recursive(land - 1, price);
    for (int i = 1; i < land; i++)
    {
        int temp = price[i] + Simple_Recursive(land - i - 1, price);
        max = findMax(max, temp);
    }
    return max;
}


int Memoized_Recursive(int land, int* price, int* values)
 {
     if(land == 0)
    {
        return 0;
    }
    else if (values[land] >= 0)
    {
        return values[land];
    }
    int max = price[0] + Memoized_Recursive(land - 1, price, values);
    for (int i = 1; i < land; i++)
    {
        int temp = price[i] + Memoized_Recursive(land - i - 1, price, values);
        max = findMax(max, temp);
    }
     values[land] = max;
    return values[land];
}


// Memoized Iteration (Part-3)
int Iterative_Method(int land, int* price) {
    int* values=new int[land+ 1]{};
    for (int i = 0; i < land; i++) {
        int max = values[i] + price[0];
        for (int j = 0; j < i; j++)
        {
            int temp = values[i - j - 1] + price[j + 1];
            max = findMax(max, temp);
        }
        values[i + 1] = max;
    }
    return values[land];

}