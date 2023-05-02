#include <iostream>
using namespace std;

template <typename T>
struct node
{
    T data;
    node<T> *next;
};

template <typename T>
class LinkedList
{
public:
    node<T> *head;
    int count;

    LinkedList()
    {
        head = NULL;
        count = 0;
    }

    node<T> *createNode(T data)
    {
        node<T> *newnode = new node<T>;
        newnode->data = data;
        newnode->next = NULL;
        return newnode;
    }

    void insertFront(T data)
    {
        node<T> *newnode = createNode(data);
        if (head == NULL)
            head = newnode;
        else
        {
            newnode->next = head;
            head = newnode;
        }
        count++;
    }
};