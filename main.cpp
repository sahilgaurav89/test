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


int main()
{
std::cout << "The number of digits in the Number are: - " << iFindTheNumberOfDigit(7653) <<std::endl;
std::cout << "The reverse of a give number is : " << iReverseNumber(1234) << std::endl;
std::cout << "The factorial of a Number is:" << iFactorial(5) << std::endl;
std::cout << "The trailing number of Zeros are: "<<  iTrailingNumberOfZeros(100) << std::endl;
std::cout << "Check if the number is prime: " << bIfTheNumberIsPrime(11) << std::endl;


return 0;

}
