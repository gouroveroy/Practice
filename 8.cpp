#include <iostream>
using namespace std;

class SafeString
{
    char *str;

public:
    SafeString(char *s)
    {
        int l = length(s);
        str = new char[l + 1];
        for (int i = 0; i < l; i++)
        {
            str[i] = s[i];
        }
        str[l] = '\0';
    }
    ~SafeString()
    {
        delete[] str;
    }
    int length(char *s)
    {
        int l = 0;
        while (s[l])
        {
            l++;
        }
        return l;
    }
    bool equals(char *s)
    {
        int l1 = length(str);
        int l2 = length(s);
        if (l1 != l2)
        {
            return false;
        }
        else
        {
            for (int i = 0; i < l1; i++)
            {
                if (str[i] != s[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
    void concatenates(char *s)
    {
        int l1 = length(str);
        int l2 = length(s);
        int j = 0;
        for (int i = l1; i < l1 + l2; i++)
        {
            str[i] = s[j];
            j++;
        }
        str[l1 + l2] = '\0';
    }
    void display()
    {
        cout << str << endl;
    }
};

int main()
{
    char str1[] = "gourove";
    char str2[] = " roy";
    SafeString obj(str1);
    cout << obj.length(str2) << endl;
    if (obj.equals(str2))
    {
        cout << "equal" << endl;
    }
    else
    {
        cout << "not equal" << endl;
    }
    obj.concatenates(str2);
    obj.display();
    return 0;
}