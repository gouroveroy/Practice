#include <iostream>
#include <string>
using namespace std;

template <class E>
class Node
{
public:
    E data;
    Node<E> *left_child;
    Node<E> *right_child;
};

template <class E>
class BST
{
    Node<E> *root;
    int nodecount;
    Node<E> *allocate(Node<E> *left_child, E item, Node<E> *right_child)
    {
        Node<E> *new_Node = new Node<E>;
        new_Node->data = item;
        new_Node->left_child = left_child;
        new_Node->right_child = right_child;
        return new_Node;
    }

    void printBSThelp(Node<E> *root)
    {
        if (root == NULL)
        {
            return;
        }

        if (root->left_child == NULL && root->right_child == NULL)
        {
            cout << root->data;
        }

        else if (root->left_child != NULL && root->right_child == NULL)
        {
            cout << root->data << "(";
            printBSThelp(root->left_child);
            cout << ")";
        }

        else if (root->right_child != NULL && root->left_child == NULL)
        {
            cout << root->data << "()(";
            printBSThelp(root->right_child);
            cout << ")";
        }

        else if (root->left_child != NULL && root->right_child != NULL)
        {
            cout << root->data << "(";
            printBSThelp(root->left_child);
            cout << ")(";
            printBSThelp(root->right_child);
            cout << ")";
        }
    }

    Node<E> *Inserthelp(Node<E> *root, E item)
    {
        if (root == NULL)
        {
            root = allocate(NULL, item, NULL);
        }

        else if (item < root->data)
        {
            if (root->left_child != NULL)
            {
                root->left_child = Inserthelp(root->left_child, item);
            }

            else
            {
                Node<E> *new_Node = allocate(NULL, item, NULL);
                root->left_child = new_Node;
            }
        }

        else if (item > root->data)
        {
            if (root->right_child != NULL)
            {
                root->right_child = Inserthelp(root->right_child, item);
            }

            else
            {
                Node<E> *new_Node = allocate(NULL, item, NULL);
                root->right_child = new_Node;
            }
        }
        return root;
    }

    Node<E> *Deletehelp(Node<E> *root, E item)
    {
        if (root == NULL)
        {
            return root;
        }

        if (item != root->data)
        {
            if (item < root->data)
            {
                root->left_child = Deletehelp(root->left_child, item);
            }

            else if (item > root->data)
            {
                root->right_child = Deletehelp(root->right_child, item);
            }
        }

        else if (item == root->data)
        {
            if (root->left_child == NULL && root->right_child == NULL)
            {
                delete root;
                nodecount--;
                return NULL;
            }
        }
        return root;
    }

    bool Findhelp(Node<E> *root, E item)
    {
        if (root == NULL)
        {
            return false;
        }

        if (item != root->data)
        {
            if (item < root->data)
            {
                return Findhelp(root->left_child, item);
            }

            else if (item > root->data)
            {
                return Findhelp(root->right_child, item);
            }
        }

        else if (item == root->data)
        {
            return true;
        }
        return false;
    }

    void preorder(Node<E> *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << " ";
        preorder(root->left_child);
        preorder(root->right_child);
    }

    void inorder(Node<E> *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left_child);
        cout << root->data << " ";
        inorder(root->right_child);
    }

    void postorder(Node<E> *root)
    {
        if (root == NULL)
        {
            return;
        }
        postorder(root->left_child);
        postorder(root->right_child);
        cout << root->data << " ";
    }

public:
    BST()
    {
        root = NULL;
        nodecount = 0;
    }

    ~BST()
    {
        root = NULL;
        nodecount = 0;
    }

    void printBST()
    {
        printBSThelp(root);
        cout << endl;
    }

    void Insert(E item)
    {
        root = Inserthelp(root, item);
        nodecount++;
    }

    void Delete(E item)
    {
        int prenode = nodecount;
        root = Deletehelp(root, item);
        int postnode = nodecount;
        if (postnode < prenode)
        {
            printBST();
        }

        else
        {
            cout << "It's not a leaf node." << endl;
        }
    }

    bool Find(E item)
    {
        return Findhelp(root, item);
    }

    void Traversal(string order)
    {
        if (order == "In")
        {
            inorder(root);
            cout << endl;
        }

        else if (order == "Pre")
        {
            preorder(root);
            cout << endl;
        }

        else if (order == "Post")
        {
            postorder(root);
            cout << endl;
        }
    }
};

int main()
{
    BST<int> bst;
    int node_number;
    cin >> node_number;
    for (int i = 0; i < node_number; i++)
    {
        int element;
        cin >> element;
        bst.Insert(element);
    }
    bst.printBST();
    bst.Delete(5);
    bst.printBST();
    if (bst.Find(5))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    bst.Traversal("In");
    bst.Traversal("Pre");
    bst.Traversal("Post");
    return 0;
}