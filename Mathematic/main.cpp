#include "iostream"


// Find the number of digits in a number
int iFindTheNumberOfDigit(int number)
{

int count = 0;
while(number != 0)
{
number = number/10;
++count;
}
return count;

}


// Reverse a number
int iReverseNumber(int number)
{
int rev = 0;
while(number != 0)
{
int last = number%10;
rev = rev * 10 + last;
number = number/10;

}
return rev;

}


// Factorial of a number
int iFactorial(int number)
{
int fact = 1;
for(int i = number ; i > 1; --i)
fact = fact*i;

return fact;
}


// Find Trailing Number of Zeros
int iTrailingNumberOfZeros(int number)
{
int count = 0;
while(number % 10 == 0)
{
number = number / 10;
++count;
}
return count;
}


//check if the number is prime
bool bIfTheNumberIsPrime(int number)
{
bool ret = true;
if (number == 1)  ret = false;
for(int i = 2; i <number ; i++) //the number is only divible by itself, so we dividing all the number before it
{
if(number%i == 0) ret =  false;
}
return ret;
}



// Bit wise operator
/*
And & = mutiplications of bits
Or | = addition of bits
XOR ^ = 0^1=1, 1^0=1 , 1^1=0, 0^0=0
left shift << - shift the byte = 0011 << 1 = 0110 
Right shift >> - shift the byte = 0011 >> 1 = 0001
Not ~ - opposite
*/


// check if the Kth bit is set

bool checkiftheKthBitSet(int number, int k)
{
bool retval = false;
if((number & (1 << (k - 1) ) ) != 0) // so number is 5 and k = 4v then, if( 0101 & (1 << (3))) != 0) , 0101 & (00001 << 3) , 0101 & 1000 = 0,So not set
retval = true;

return retval; 
} 


// MultiPly by 2
int multiplyByTwo(int number)
{
return number << 1;
}


// Divide by 2
int divideByTwo(int number)
{
return number >> 1;
}


// add 2 number without using +
int addWithoutArth(int a, int b)
{
int carry = 0;
while(b!=0)
{
carry = a & b;
a = a^b;
b = carry << 1;
}

return a;

}




int main()
{
std::cout << "The number of digits in the Number are: - " << iFindTheNumberOfDigit(7653) <<std::endl;
std::cout << "The reverse of a give number is : " << iReverseNumber(1234) << std::endl;
std::cout << "The factorial of a Number is:" << iFactorial(5) << std::endl;
std::cout << "The trailing number of Zeros are: "<<  iTrailingNumberOfZeros(100) << std::endl;
std::cout << "Check if the number is prime: " << bIfTheNumberIsPrime(11) << std::endl;
std::cout << "Check if the kth bit is set: " << checkiftheKthBitSet(5,4) << std::endl;
std::cout << "Multiply by 2 " << multiplyByTwo(44) << std::endl;
std::cout << "Divide by 2 " << divideByTwo(44) << std::endl;
std::cout << "Add 2 numbers without arthemetic " << addWithoutArth(900,9) << std::endl;


return 0;

}
