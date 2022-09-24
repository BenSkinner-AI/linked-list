/*
Name: Ben Skinner                       NetID: bts277
Date: 4/25/22                    Due Date: 4/26/22
Description: Managing linked list
*/
#include "linkedlist.h"

// GIVEN TO STUDENTS

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

LinkedList::~LinkedList()
{
    if(head != nullptr)
    {
        Node *temp;

        while(head != nullptr)
        {
            temp = head->next;

            // deletes head
            delete head;

            // goes to next element
            head = temp;
        }
    }
}

void LinkedList::display()
{
    Node *temp = head;

    for(int i = 0; i < size; i++)
    {
        cout << temp->data << "\t";

        temp = temp->next;
    }

    cout << endl;
}

void LinkedList::append(int num)
{
    // list is empty
    if(head == nullptr)
    {
        head = new Node;

        head->data = num;
        head->next = nullptr;

        // sets tail to head
        tail = head;
    }

    else
    {
        // creates new node
        Node *temp = new Node;

        // sets new node data
        temp->data = num;
        temp->next = nullptr;

        // sets previous tail link to new node
        tail->next = temp;

        // sets this node to new tail
        tail = temp;
    }

    // increments size
    size++;
}

void LinkedList::pop()
{
    if(size > 1)
    {
        Node *temp = head;

        // loops to node before tail
        while(temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        // deletes tail
        delete tail;

        // sets new tail
        tail = temp;
        tail->next = nullptr;
    }

    // if there's only one item
    else if(size == 1)
    {
        Node *temp = tail;

        // head and tail are now null
        head = nullptr;
        tail = nullptr;

        // deletes node
        delete temp;
    }

    size--;
}

// END GIVEN TO STUDENTS


void LinkedList::insert(int num,int X)
{

   if(X < 0 or X > size+1)
{
       cout << "Invalid Xition "<<endl;

       return;
}

   Node *temp = new Node;

   temp->data = num;

   temp->next = nullptr;

   if(X==0)
{
       temp->next = head;

       head =temp;
}
   else if(X==size)
{
       tail->next = temp;

       tail = temp;
}
   else
{
       Node *curr = head;

       int i = 0;

       while(i < (X-1))
{
           curr = curr->next;

           i++;
}

       Node *p = curr->next;

       curr->next = temp;

       temp->next = p;

}
   size++;
}
int LinkedList::linearSearch(int key)
{
   Node *curr = head;

   int index = 0;

   while(curr!=nullptr)
{
       if(curr->data == key)
{
           return index;
}
       curr = curr->next;

       index++;
}
   return -1;
}
int LinkedList::min()
{
   Node *curr = head->next;

   int minValue = head->data;

   while(curr!=nullptr)
{
       if(minValue > curr->data)
{
           minValue = curr->data;
}
       curr = curr ->next;
}
   return minValue;
}
int LinkedList::max()
{
   Node *curr = head->next;

   int maxValue = head->data;

   while(curr!=nullptr)
{
       if(maxValue < curr->data)
{
           maxValue = curr->data;
}
       curr = curr ->next;
}
   return maxValue;
}
int LinkedList::mean()
{
   Node *curr = head;

   int sum = 0;

   while(curr!=nullptr)
{
       sum += curr->data;

       curr = curr->next;
}
   return sum/size;
}
void LinkedList::reverse()
{


Node* curr = head;

tail = head;

Node *prev = NULL, *next = NULL;

while (curr != nullptr)
{

next = curr->next;

curr->next = prev;

prev = curr;

curr = next;
}
head = prev;
}
void LinkedList::sort()
{

   for(Node * i = head ; i != nullptr; i = i->next)
{
       for(Node * j = head; j->next !=nullptr; j = j->next)
{
           if(j->data > j->next->data)
{
              int temp = j->data;

              j->data = j->next->data;

              j->next->data = temp;
}
}
}
}
void LinkedList::remove(int X)
{

   if(X < 0 or X > size + 1)
{
       cout<< " Invalid Xition " <<endl;

       return;
}
   if(X==0)
{
       head = head->next;
}
   else
{
       Node *curr = head;
       int i = 0;
       while(i < (X - 1))
{
           curr = curr->next;
           i++;
}
       Node *p = curr->next;

       curr->next = curr->next->next;

       delete p;
}
   size--;
}
