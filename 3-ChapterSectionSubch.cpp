//A book consists of chapters, chapters consist of sections and sections consist of subsections. Construct a tree and print the nodes.
#include <iostream>
#include <string>
using namespace std;

class Book
{
public:
    int chapno, subch, subn[30];
    string bookn;
    string data[100];

    void add_chapters()
    {
        cout << "Enter no of chapters in the book : ";
        cin >> chapno;
    }

    void add_subch()
    {
        for (int i = 0; i < chapno; i++)
        {
            cout << "Enter no of subchapters for chapter " << i + 1 << ": ";
            cin >> subn[i];
        }
    }

    void insert_data()
    {
        cout << "\nEnter the book Name  : " << endl;
        cin >> bookn;
        int flag = 0;
        for (int i = 0; i < chapno; i++)
        {
            cout << "Enter name of chapter " << i + 1 << ": ";
            cin >> data[flag];

            if (subn[i] != 0)
            {
                for (int j = 0; j < subn[i]; j++)
                {
                    cout << "Enter name of subchapter " << j + 1 << " of chapter " << i + 1 << ": ";
                    cin >> data[++flag];
                }
            }
            flag++;
        }
        data[flag] = "/n";
    }

    void display()
    {
        cout << "\nName of the Book : " << bookn << "\n"<< endl;
        int k;
        k = 0;
        for (int i = 0; i < chapno; i++)
        {
            cout << i + 1 << "." << data[k] << endl;
            k++;
            for (int j = 0; j < subn[i]; j++)
            {
                cout << "\t" << i + 1 << "." << j + 1 << "." << data[k] << endl;
                k++;
            }
        }
    }
};

int main()
{
    Book my;
    my.add_chapters();
    my.add_subch();
    my.insert_data();
    my.display();
    return 0;
}
