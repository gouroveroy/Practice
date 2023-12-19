#include <iostream>
#include <new>
using namespace std;

typedef struct node Node;

struct node
{
    int data;
    Node *prev;
    Node *next;
};

Node *create_Node(Node *prev, int item, Node *next)
{
    Node *new_Node = new Node;
    new_Node->data = item;
    new_Node->prev = prev;
    new_Node->next = next;
    return new_Node;
}

Node *prepend(int item, Node *head)
{
    Node *new_Node = create_Node(NULL, item, head);
    new_Node->next->prev = new_Node;
    return new_Node;
}

Node *append(int item, Node *head)
{
    Node *new_Node = create_Node(NULL, item, NULL);
    if (head == NULL)
    {
        return new_Node;
    }
    Node *current_Node = head;
    while (current_Node->next != NULL)
    {
        current_Node = current_Node->next;
    }
    current_Node->next = new_Node;
    new_Node->prev = current_Node;
    return head;
}

void print_link_list(Node *head)
{
    Node *current_Node = head;
    while (current_Node != NULL)
    {
        cout << current_Node->data << ' ';
        current_Node = current_Node->next;
    }
    cout << endl;
}

void revese_print_link_list(Node *head)
{
    Node *current_Node = head;
    while (current_Node->next != NULL)
    {
        current_Node = current_Node->next;
    }
    while (current_Node != NULL)
    {
        cout << current_Node->data << ' ';
        current_Node = current_Node->prev;
    }
    cout << endl;
}

int count(Node *head)
{
    int num_of_node = 1;
    Node *current_Node = head;
    while (current_Node->next != NULL)
    {
        num_of_node++;
        current_Node = current_Node->next;
    }
    return num_of_node;
}

Node *search(Node *head, int item)
{
    Node *current_Node = head;
    while (current_Node->data != item)
    {
        current_Node = current_Node->next;
    }
    return current_Node;
}

Node *remove_Node(Node *head, Node *node)
{
    if (node == head)
    {
        head = node->next;
        head->prev = NULL;
        delete node;
        return head;
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
    return head;
}

Node *insert_Node(Node *head, Node *node, int item)
{
    Node *new_Node = create_Node(node, item, node->next);
    node->next->prev = new_Node;
    node->next = new_Node;
    return head;
}

int main()
{
    Node *head;
    int num_of_node;
    cin >> num_of_node;
    int value;
    cin >> value;
    head = create_Node(NULL, value, NULL);
    for (int i = 0; i < num_of_node - 1; i++)
    {
        cin >> value;
        head = append(value, head);
    }
    print_link_list(head);
    revese_print_link_list(head);
    cout << count(head) << endl;
    // cout << search(head, 10)->val << endl;
    // print_link_list(remove_Node(head, head));
    print_link_list(insert_Node(head, head, 1));
    return 0;
}