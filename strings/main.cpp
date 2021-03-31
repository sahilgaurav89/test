#include "iostream"
#include "string"
#include "vector"
#include <algorithm> 
#include <bits/stdc++.h>
#include <memory>


using namespace std;
// Reverse a string
void rev(std::string &str)
{
    reverse(str.begin(), str.end()); 

}


// 123456789
std::vector<string> splitSTring(std::string str, int length)
{
int size = str.size();
std::vector<string> ret;
for(int i = 0; i<size; i+=length)
{
if(i>size)i=size;
ret.push_back(str.substr(i,length));
}
return ret;
}


// check pallindrome

bool chckIfPalindrome(string str)
{
int size =str.size();
bool chk = true;
for(int i = 0; i < size ; ++i)
{
if (str[i] != str[size-i-1]) 
{
chk = false;
break; 
}
}
return chk;
}


// geeksforgeeks grge =   
// Subsequence of a string  ///  ABC - "", A , B , C , AB, AC , BC , ABC ->  ACtually same order
bool chksub(std::string main, string sub)
{
int subIndex = 0;
bool flag = false;

for(int i = 0 ; i < main.size() ; ++i)
{
if(main[i] == sub[subIndex])
{
++subIndex;
if(subIndex == sub.size())
{
flag = true;
break;
}
}

}

return flag;

}



// Anagram 
// listen = silent ,  aab baa or aba ,   xyz, zxy 

bool checkifangram(string str, string str2)
{
bool check = true;
if(str.size() != str2.size())
{
return false;
}

int arr[256] = {0};
for(int i = 0; i < str.size(); ++i)
{
arr[str[i]]++;
arr[str2[i]]--;
}
for(int i = 0 ; i < 256 ;++i)
{
if(arr[i] != 0)
{

check = false;
break;
}

}
return check;
}


// reverse each word in sentece
// Hi I am Gaurav -? ih I ma varuaG -> Now read from  right to left (So reverse)

void reveTheSentence(string s)
{
auto itrFirst = s.begin();
auto itr = s.begin();
while(itr != s.end())
{
if(*itr == ' ')
{
reverse(itrFirst,itr);
++itr;
itrFirst = itr;
}
else
{
++itr;
}

}
reverse(itrFirst,itr);
reverse(s.begin(),s.end());
cout << s << endl;
}
class A
{
public:
A(){std::cout<<"A () "<<std::endl;}
~A(){std::cout<<"~A () "<<std::endl;}
};

int main()
{

string stri = "Gaurav";
auto itr = stri.begin()+2;
cout<< " hi " << *itr << endl;
rev(stri);
cout << "String = " << stri << endl;
cout << "Check Palindrome = " << chckIfPalindrome("ABA") <<endl;
cout << " Subsequence = " << chksub("geeksforgeeks" , "ro") << endl;
cout << " if Annagram " << checkifangram("aaabbbbbbb","ababbbbabb") << endl;
reveTheSentence("Hi I am Gaurav ");


}
