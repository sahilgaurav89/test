#include <iostream>
#include<thread>
#include<mutex>
#include <condition_variable>




class Node
{
public:
int value;
Node* next;
Node(int val = 0):value(val)
{
next = nullptr;
}

Node(const Node& obj)
{
std::cout << "Copy " << std::endl;
next = new Node();
next = obj.next;
value = obj.value;

}

Node& operator =(const Node& obj)
{
std::cout << "assignment " << std::endl;
 if(this != &obj) 
{
     *next = *(obj.next); 
     value = obj.value;
}
  
   return *this;

}


};
using namespace std;

struct LL
{

Node* head = nullptr;
Node* tail = nullptr;
int size = 0;

public:
void pushFront(int val)
{
++size;
if(head == nullptr)
{
head = new Node(val);
tail = head;
}
else
{
Node* temp = new Node(val);
temp->next = head;
head = temp;

}
}

void pushback(int val)
{
++size;
if(head == nullptr)
{
head = new Node(val);
tail = head;
}
else
{
Node* temp = new Node(val);
tail->next = temp;
tail = temp;

}
}

void popfront()
{
--size;
std::cout << "Pop"<<std::endl;
Node* temp = head->next;
head->next = nullptr;
delete head;
head = temp;


/*
    Node *temp=new Node;
    temp=head;
    head=head->next;
    delete temp;
*/
}

void popback()
{
--size;
Node* temp = head;
while(temp->next != tail)
{
temp = temp->next;
}

tail = temp;
delete temp->next;
temp->next = nullptr;
}

void print()
{
Node* temp = head;
while(temp != nullptr)
{
std::cout << temp->value << " " ;
temp = temp->next;
}
std::cout<< size <<std::endl;

}
//5 6 7 8 9 
void insert(int pos, int val)
{
++size;
Node* temp = head;
Node * pre = nullptr;
while(pos-1 > 0)
{
pre = temp;
temp = temp->next;
--pos;
}

Node * n = new Node(val);
pre->next = n;
n->next = temp;
 
}

int getsize()
{
return size;
}


// 5 6 7 8 9 
void reverseALinkList()
{
Node* current = head;
Node* nxt = nullptr;
Node* prev = nullptr;


while(current != nullptr)
{

nxt = current->next;
current->next = prev;

prev = current;
current = nxt;

}

head = prev;


}


friend ostream & operator<< ( ostream & output, LL &obj)
{
Node* temp = obj.head;
while(temp != nullptr)
{
output << temp->value << " " ;
temp = temp->next;
}
return output;
}


};
    

int main()
{

LL obj;

obj.pushFront(2);
obj.pushFront(3);
obj.pushFront(4);
obj.pushFront(6);
obj.pushFront(7);
obj.pushFront(11);
obj.pushback(12);
obj.pushback(13);
obj.pushback(14);
//obj.print();
obj.insert(2,99);
obj.reverseALinkList();

std::cout << obj << std::endl;

/*
int count = 0;

std::mutex mu;
bool flag = false;
std::condition_variable cond;

std::thread t([&](){
 while( count <50 )
    {
    std::unique_lock<std::mutex> locker(mu);
    cond.wait(locker,[&](){  if(count%2 == 1)return true;else false; });
    cout<< "From Odd:    " <<  count << endl;
    count++;
    locker.unlock();
    cond.notify_all();
    }


});



std::thread t2([&](){

 while( count <50 )
    {
    std::unique_lock<std::mutex> locker(mu);
    cond.wait(locker,[&](){ if(count%2 == 0)return true;else false; });
    cout<< "From Even: " << count << endl;
    count++;
    locker.unlock();
    cond.notify_all();
    }
});
t.join();
t2.join();
//obj.print();
*/
return 0;
}
