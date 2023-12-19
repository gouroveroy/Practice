#include <iostream>
#include <new>
using namespace std;

typedef struct node Node;

typedef struct node
{
    int val;
    Node *next;
};

Node *create_Node(int item, Node *next)
{
    Node *new_Node = new Node;
    new_Node->val = item;
    new_Node->next = next;
    return new_Node;
}

Node *prepend(int item, Node *head)
{
    Node *new_Node = create_Node(item, head);
    return new_Node;
}

Node *append(int item, Node *head)
{
    Node *new_node = create_Node(item, NULL);
    if (head == NULL)
    {
        return new_node;
    }
    Node *current_Node = head;
    while (current_Node->next != NULL)
    {
        current_Node = current_Node->next;
    }
    current_Node->next = new_node;
    return head;
}

void print_link_list(Node *head)
{
    Node *current_Node = head;
    while (current_Node != NULL)
    {
        cout << current_Node->val << ' ';
        current_Node = current_Node->next;
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
    while (current_Node->val != item)
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
        delete node;
        return head;
    }
    Node *current_Node = head;
    while (current_Node != NULL)
    {
        if (current_Node->next == node)
        {
            break;
        }
        current_Node = current_Node->next;
    }
    if (current_Node == NULL)
    {
        return head;
    }
    current_Node->next = node->next;
    delete node;
    return head;
}

Node *insert_Node(Node *head, Node *node, int item)
{
    Node *new_Node = create_Node(item, node->next);
    node->next = new_Node;
    return head;
}

int main()
{
    Node *head;
    int num_of_node;
    cin >> num_of_node;
    int data;
    cin >> data;
    head = create_Node(data, NULL);
    for (int i = 0; i < num_of_node - 1; i++)
    {
        cin >> data;
        head = append(data, head);
    }
    print_link_list(head);
    cout << count(head) << endl;
    // cout << search(head, 10)->val << endl;
    // print_link_list(remove_Node(head, head));
    print_link_list(insert_Node(head, head, 1));
    return 0;
}