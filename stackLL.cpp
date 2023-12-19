#include <iostream>
using namespace std;

template <class E>
class LinkList
{
public:
    E data;
    LinkList *next;
    LinkList *prev;

    LinkList(LinkList *prev = NULL, int data = 0, LinkList *next = NULL)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
    ~LinkList()
    {
        next = NULL;
        prev = NULL;
    }
};

template <class E>
class Stack
{
    LinkList<E> *top;
    int size;
    LinkList<E> *allocate(LinkList<E> *prev, int item, LinkList<E> *next)
    {
        LinkList<E> *new_Node = new LinkList<E>;
        new_Node->data = item;
        new_Node->prev = prev;
        new_Node->next = next;
        return new_Node;
    }

public:
    Stack()
    {
        top = NULL;
        size = 0;
    }
    ~Stack()
    {
        clear();
    }
    void clear()
    {
        while (top != NULL)
        {
            pop();
        }
    }
    void push(E item)
    {
        if (top == NULL)
        {
            top = allocate(NULL, item, NULL);
            size++;
        }
        else
        {
            LinkList<E> *new_Node = allocate(NULL, item, NULL);
            new_Node->prev = top;
            top->next = new_Node;
            top = new_Node;
            size++;
        }
    }
    void pop()
    {
        if (top == NULL)
        {
            return;
        }
        LinkList<E> *new_Node = top;
        if(top->prev != NULL)
        {
            top->prev->next = NULL;
        }
        top = top->prev;
        delete new_Node;
        size--;
    }
    int length()
    {
        return size;
    }
    E topValue()
    {
        return top->data;
    }
    void print()
    {
        if(size == 0)
        {
            cout << " " << endl;
            return;
        }
        LinkList<E> *curr = top;
        while (curr->prev != NULL)
        {
            curr = curr->prev;
        }
        while (curr->next != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << curr->data << endl;
    }
    bool isEmpty()
    {
        if(top == NULL)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

// int main()
// {
//     Stack<int> stack;
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         int a;
//         cin >> a;
//         stack.push(a);
//     }
//     stack.print();
//     stack.pop();
//     stack.print();
//     stack.clear();
//     stack.print();
//     int a;
//     cin >> a;
//     stack.push(a);
//     stack.print();
//     cout << stack.length() << endl;
// }