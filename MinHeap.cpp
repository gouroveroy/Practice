#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 1

template <class E>
class MinHeap
{
    E *Arr;
    int chunk_size;
    int heapsize;

    void increase_chunk_size()
    {
        int new_chunk_size = 2 * chunk_size;
        int *new_Arr = new E[new_chunk_size];
        int i = 0;
        while (i < heapsize)
        {
            new_Arr[i] = Arr[i];
            i++;
        }
        if (heapsize > 0)
        {
            delete[] Arr;
        }
        Arr = new_Arr;
        chunk_size = new_chunk_size;
    }

    int left_child(int index)
    {
        return 2 * index + 1;
    }

    int right_child(int index)
    {
        return 2 * index + 2;
    }

    int parent(int index)
    {
        return (index - 1) / 2;
    }

    void MinHeapify(int index)
    {
        int tempindex;
        int leftchild = left_child(index);
        int rightchild = right_child(index);
        if (Arr[leftchild] < Arr[index])
        {
            tempindex = leftchild;
        }

        else
        {
            tempindex = index;
        }

        if (Arr[rightchild] < Arr[tempindex])
        {
            tempindex = rightchild;
        }

        if (tempindex != index)
        {
            swap(Arr[index], Arr[tempindex]);
            MinHeapify(tempindex);
        }

        else
        {
            return;
        }
    }

    int height(int index)
    {
        if (heapsize == 0)
        {
            return -1;
        }

        else if (index >= heapsize)
        {
            return 0;
        }

        else
        {
            int lheight = height(left_child(index));
            int rheight = height(right_child(index));

            if (lheight > rheight)
            {
                return ++lheight;
            }

            else
            {
                return ++rheight;
            }
        }
    }

    void printCurrentLevel(int index, int level)
    {
        if (heapsize == 0)
        {
            return;
        }

        else if (index >= heapsize)
        {
            return;
        }

        else if (level == 0)
        {
            cout << Arr[index] << " ";
        }

        else
        {
            printCurrentLevel(left_child(index), level - 1);
            printCurrentLevel(right_child(index), level - 1);
        }
    }

public:
    MinHeap(int maxsize = MAXSIZE)
    {
        chunk_size = maxsize;
        Arr = new E[chunk_size];
        heapsize = 0;
    }

    ~MinHeap()
    {
        chunk_size = 0;
        delete Arr;
        heapsize = 0;
    }

    E FindMin()
    {
        return Arr[0];
    }

    E ExtractMin()
    {
        if (heapsize == 0)
        {
            return 0;
        }

        else if (heapsize == 1)
        {
            return Arr[--heapsize];
        }
        int min = Arr[0];
        Arr[0] = Arr[--heapsize];
        MinHeapify(0);
        return min;
    }

    void Insert(E key)
    {
        if (heapsize == chunk_size)
        {
            increase_chunk_size();
        }
        Arr[heapsize++] = key;
        int curr = heapsize - 1;
        while (curr != 0 && Arr[curr] < Arr[parent(curr)])
        {
            swap(Arr[curr], Arr[parent(curr)]);
            curr = parent(curr);
        }
    }

    void DecreaseKey(E prevkey, E newkey)
    {
        int i = 0;
        while (Arr[i] != prevkey)
        {
            i++;
        }
        Arr[i] = newkey;
        int curr = i;
        while (curr != 0 && Arr[curr] < Arr[parent(curr)])
        {
            swap(Arr[curr], Arr[parent(curr)]);
            curr = parent(curr);
        }
    }

    void print()
    {
        int h = height(0);
        for (int i = 0; i < h; i++)
        {
            cout << "Level " << i << ": ";
            printCurrentLevel(0, i);
            cout << endl;
        }
    }
};

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    MinHeap<int> heap;
    string s;
    while (cin >> s)
    {
        if (s == "FIN")
        {
            cout << "FindMin returned " << heap.FindMin() << endl;
        }

        else if (s == "EXT")
        {
            cout << "ExtractMin returned " << heap.ExtractMin() << endl;
        }

        else if (s == "INS")
        {
            int key;
            cin >> key;
            heap.Insert(key);
            cout << "INSERTED " << key << endl;
        }

        else if (s == "DEC")
        {
            int prevkey, newkey;
            cin >> prevkey >> newkey;
            heap.DecreaseKey(prevkey, newkey);
            cout << prevkey << " decreased to " << newkey << endl;
        }

        else if (s == "PRI")
        {
            cout << "Printing the binary heap ..." << endl;
            for (int i = 0; i < 20; i++)
            {
                cout << "- ";
            }
            cout << endl;
            heap.print();
            for (int i = 0; i < 20; i++)
            {
                cout << "- ";
            }
            cout << endl;
        }
    }

    return 0;
}