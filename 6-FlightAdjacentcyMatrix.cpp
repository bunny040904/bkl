#include<iostream>
using namespace std;
class flight{
    public:
    int totalCity;
    string cityn[100];
    int citydis[100];
    void city()
    {
        cout<<"Enter total no.of cities : ";
        cin>>totalCity;
        for(int i =0;i<totalCity;i++)
        {
            cout<<"Enter name of city "<<i+1<<" : ";
            cin>>cityn[i];
        }
        cityn[totalCity] = "/n";
    }
    void distances()
    {
        int m = 0;
        for(int i =0;cityn[i]!="/n";i++)
        {
            for(int j = 0;cityn[j]!="/n";j++)
            {
                cout<<"Enter distance between city "<<cityn[i]<<" and "<<cityn[j];
                cin>>citydis[m];
                m++;
            }
        }
        citydis[m] = -1;
    }
    void display()
    {
    cout << "\t";
    for(int i = 0;cityn[i]!="/n";i++){
        cout << cityn[i] << "\t";
    }
    cout << endl;
    int m = 0;
    for(int i = 0;i<totalCity;i++)
    {
        cout << cityn[i] << "\t";
        int k = i;
        for(int j = 0;j<totalCity;j++,k++)
        {
            cout << citydis[m] << "\t";
            m++;
        }
        cout << endl;
    }

    }
};
int main()
{
    flight fl;
    fl.city();
    fl.distances();
    fl.display();
}