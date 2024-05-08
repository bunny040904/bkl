
//A book consists of chapters, chapters consist of sections and sections consist of subsections. Construct a tree and print the nodes.

#include <iostream> // This library is essential for performing input and output operations 
#include <string>// library is necessary whenever you need to work with strings
using namespace std;// you can access functions, classes, and objects defined in the std namespace without having to prefix them with std::

class Book
{
public: // members declared after this keyword can be accessed from outside class
    int chapno, subch, subn[30];//The size of the array is set to 30, indicating that it can store up to 30 elem
    string bookn; //named data and can store up to 100 strings..
    string data[100];//This array seems to be intended for storing names of chapters and subchapters.

    void add_chapters() // Void used to indicate that function does not return any value
    //indicates that the function's role is to perform a task or action rather than compute 
    {
        cout << "Enter no of chapters in the book : ";
        cin >> chapno;
    }

    void add_subch()// This function prompts user to input number of subchapters for each chapter and stores them in subn array.
    {
        for (int i = 0; i < chapno; i++) //Inside the loop, variable i represents the current chapter being processed.
        {
            cout << "Enter no of subchapters for chapter " << i + 1 << ": ";
            cin >> subn[i];//subn[i] represents array element corresponding to current chapter.The user's input is stored in this array element.
        }
    }

    void insert_data()//This function allows user to input chapter and subchapter names and stores them in data array.
    {
        cout << "\nEnter the book Name  : " << endl;
        cin >> bookn;
        int index = 0;//declare integer variable named index and initializes it to 0.
        //used as an index or a counter to keep track of the current position 
        for (int i = 0; i < chapno; i++)//nitializes loop variable i to 0 before the loop starts, cond, incre
        {
            cout << "Enter name of chapter " << i + 1 << ": ";
            cin >> data[index];//This accesses the data array at the index index. It represents the slot where the name of the current chapter will be stored.

            if (subn[i] != 0)//checks if the current chapter (i) has any subchapters, 
            {
                for (int j = 0; j < subn[i]; j++)// loop iterates over each subchapter of the current chapter (i)
                {
                    cout << "Enter name of subchapter " << j + 1 << " of chapter " << i + 1 << ": ";
//This line prompts the user to enter the name of the current subchapter. It includes the subchapter number (j + 1) and the chapter number (i + 1) for clarity.
                    cin >> data[++index]; // subchapter name will be stored in the next available slot of the data array.
                }
            }
            index++;//It ensures that the next input will be stored in the correct position of the data array.
        }
        data[index] = "/n"; //newline
    }

    void display()//This function displays book's name and the names of chapters and subchapters stored in the data array in a formatted manner.
    {
        cout << "\nName of the Book : " << bookn << "\n"<< endl;//newline and cursor to thr nxt line
        int k;//var k declared and initialized 0, used as an 
        k = 0;//index to access elements in data array
        for (int i = 0; i < chapno; i++)
        {
            cout << i + 1 << "." << data[k] << endl;//accesses the chapter name from the data array using the index k 
            k++;// increments k afterward. i + 1 is used to display the chapter number starting from 1 instead of 0.
            for (int j = 0; j < subn[i]; j++)
            {
                cout << "\t" << i + 1 << "." << j + 1 << "." << data[k] << endl;
 // It accesses the subchapter name from the data array using the index k
// i + 1 is to display parent chapter no., and j + 1 is to display subchapter no.             
//both starting from 1 instead of 0. The \t adds a tab for indentation. 
                k++;
//k is incremented to move to next element in data array
            }
        }
    }
};

int main()
{
    Book my;//indtance of class book named my, It calls default constructor of Book class to create a new object of type Book
    my.add_chapters();//This line calls the add_chapters() member function of the my object. function prompts the user to
//input the number of chapters in the book (chapno) and stores the input in the chapno member variable of the my object.
    my.add_subch();
    my.insert_data();
    my.display();
    return 0;//This line terminates the main() function and returns 0 to the operating system.
//A return value of 0 typically indicates successful execution of the program.
}
