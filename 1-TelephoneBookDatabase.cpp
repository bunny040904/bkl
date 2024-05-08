#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

class HashFunction
{
    typedef struct hash
    {
        long key;
        char name[10];
    } hash;
    hash h[10];

public:
    HashFunction()
    {
        int i;
        for (i = 0; i < 10; i++)
        {
            h[i].key = -1;
            strcpy(h[i].name, "NULL");
        }
    }
    void display()
    {
        cout<<"\n\n";
        cout << "Key"
             << "      "
             << "Name" << endl;
        int i;
        for (i = 0; i < 10; i++)
        {
            cout << h[i].key << "     " << h[i].name << endl;
        }
        cout<<endl;
    }

    void delete_key()
{
    int k, position;
    cout << "Enter key to delete: ";
    cin >> k;
    position = k % 10;

    // Check if the key exists at the initial position
    if (h[position].key == k)
    {
        h[position].key = -1;
        strcpy(h[position].name, "NULL");
        cout << "Key is deleted";
        return;
    }
    
    // Look for the key in subsequent positions, wrapping around if needed
    for (int i = (position + 1) % 10; i != position; i = (i + 1) % 10)
    {
        if (h[i].key == k)
        {
            h[i].key = -1;
            strcpy(h[i].name, "NULL");
            cout << "Key is deleted";
            return;
        }
    }

    // Key not found
    cout << "Key not found";
}

    void insert()
    {
        int keys, position;
        char names[10];
        cout << "Enter a Telephone No :";
        cin >> keys;
        cout << "Enter a Client Name :";
        cin >> names;
        position = keys % 10;

        if (h[position].key == -1)
        {
            h[position].key = keys;
            strcpy(h[position].name,names);
        }
        else{
            for(int i = position+1;i!=position;i++)
            {
                int s = i%10;
                if(h[s].key == -1)
                {
                    h[s].key = keys;
                    strcpy(h[s].name,names);
                    return;
                }
            }
        }

    }

    int findd()
    {
        int fk;
            cout<<"Enter key which you want to search : ";
            cin>>fk;
        int j;
        for(j=0;j<10;j++)
        {
            if(h[j].key == fk)
            {
                return j;
            }
        }
        return -1;
        
    }
};
void menu()
{
    cout<<endl;
    cout<<"**** Dictionary (ADT) ****"<<endl;
    cout<<"Enter 1 for insertion "<<endl;
    cout<<"Enter 2 for display"<<endl;
    cout<<"Enter 3 for delete"<<endl;
    cout<<"Enter 4 for find "<<endl;
    cout<<endl;
}
int main()
{
    HashFunction obj;
    int ch;
    while(true)
    {
        menu();
        cout<<"Enter your choice : ";
        cin>>ch;
        if(ch == 1)
        {
            obj.insert();
            
        }
        else if(ch == 2)
        {
            obj.display();
            
        }
        else if(ch == 3)
        {
            obj.delete_key();
            
        }
        else{
            
            int a = obj.findd();
            cout<<"Key present at index : "<<a<<endl;
        }
cout<<endl;
        
}}