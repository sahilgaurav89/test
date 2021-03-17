#include "iostream"

// Find the largest from an array
int FindThelargestElemnt(int arr[], int n) // internally a pointer is passed of arr, so if if we do a size of arr it will be size of the pointer
{
int pos = 0;
for(int i = 1 ; i < n ; ++i)
{
if(!(arr[pos]>arr[i]))
pos=i;
///or
//(arr[pos]>arr[i])?:pos=i; // ternary operator
}
return pos;
}



// Find the second largest number   // l 0 s 1

int FindTheSecondLargest(int arr[], int size)
{
int largest = 0;
int secondlargest = -1;

for(int i = 1; i< size ; i++)
{
if(arr[i] > arr[largest])
{
secondlargest = largest;
largest = i;
}
else if(secondlargest == -1 || arr[i] > arr[secondlargest])
{
secondlargest = i;
}

}

return secondlargest;

}



// Find if the array is sorted
bool ifSorted(int arr[], int n)
{
bool retval = true;
for(int i=1; i < n ;++i)
{
if(arr[i]<arr[i-1])
{
retval = false;
}
}
return retval;

}


// 3 7 5 6 2 1 2



// Reverse a give array
int revAnArray(int arr[],int n)
{
int low = 0;
int high = n-1;

while(high>low)
{
int temp = arr[low];
arr[low]=arr[high];
arr[high]=temp;
++low;
--high;
}
}


// Push all zero to the end {2,4,0,0,8,9}
void pushZeroToend(int arr[], int n)
{
int firstzeroPos = 0;
for(int i = 0; i < n ;++i)
{

if(arr[i] != 0)
{

if(i!=firstzeroPos)
{
arr[firstzeroPos] = arr[i];
arr[i]=0;
}

++firstzeroPos;

}

}


}


// Binary search 
//
//Sorted Array
int srch(int arr[], int n, int ele)
{

int low = 0;
int high = n-1;


while(low <= high)
{
int mid = (low+high)/2;
if(arr[mid] == ele) return mid;
else if(ele>mid)low = mid+1;
else high = mid-1;

}

return -1;

}
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;

int minimumSwaps(vector<int> arr) {
    
    std::map<int,int> indexmap;
    std::unordered_map<int,int> valuemap;
    for(int i: arr)
    {

      indexmap[i] = arr[i-1];  
    }
    for(auto &val : indexmap)
    {
       valuemap[val.second] = val.first; 
    }
    int count = 0;
    for(auto &val : indexmap)
    {

        if(val.first != val.second)
        {

            swap(arr[val.first-1],arr[valuemap[val.first]-1]);
            swap(indexmap[val.first],indexmap[valuemap[val.first]]);
              
            ++count;
        }
    }


return count;
}

/*
#include <functional>


std::function<void(int,int)> fu;


void setProcessFunction( std::function<void(int,int)> args)

{
fu = args;
}

void send(const int a,const int b)
{
std::cout  << "Send called  " << "a" <<a <<std::endl;
}






class base
{
public:
virtual void fu() = 0;
virtual int* fu1()= 0;
};

class derivd: public base
{
void fu(){}
int* fu1(){}
}; 




#include <bits/stdc++.h>
*/

int main()
{

int arr[] = {1222222,5,7,33,4,33333,11,222,7,11111,22222,2222222};
int arr1[] = {1,2,3,3,3,3,3,4,5,6,100,333};
int arr2[]={0,4,0,0,8,9};
std::cout << "Find the largest elemnt in the array " << arr[FindTheSecondLargest(arr, sizeof(arr)/4)]<< std::endl;
std::cout << " Is the array sorted " << ifSorted(arr1,sizeof(arr1)/4) << std::endl;
revAnArray(arr1,sizeof(arr1)/4);.h
std::cout<<"Reverse Array ";
for(int i:arr1)
std::cout<< " " << i;
pushZeroToend(arr2,sizeof(arr2)/4);
std::cout<<std::endl;
std::cout<<" Array without zero "<<std::endl;
for(int i:arr2)
std::cout<< " " << i;
int arr3[]={1,2,3,4,5,6,7,8};
std::cout << "Binary Seach " << srch(arr3,sizeof(arr3)/4,2) << std::endl;

minimumSwaps({1,4,2,3,6,5,7,8});

/*
std::vector<int> v {7,8,9,1,2};
for(int i:v)
std::cout << " " << i ;

std::string str = "000000011111111100000111";


for(int i =0; i < str.length() ; i+=8)
{

std::cout <<"str - " << std::stoi(str.substr(i,8),0,2) << std::endl;

}


base *ptr = new derivd();
int * p = nullptr;
p =  ptr->fu1();

if(p != nullptr)
std::cout <<*p<<std::endl;





setProcessFunction([&](auto&&... args) 
{ send(args...);
 });

fu(1111,1);*/
}
