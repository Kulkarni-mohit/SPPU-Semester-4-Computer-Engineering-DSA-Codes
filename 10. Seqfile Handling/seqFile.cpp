#include <iostream>
#include <fstream>

using namespace std;

class Student
{
public:
    int roll;
    string name, Class;


    void accept();
    void display();
    int search(int);
};

void Student::accept()
{
        cout<<"\nEnter The Name of Student: ";
        cin>>name;
        cout<<"\nEnter the roll number: ";
        cin>>roll;
        cout<<"\nEnter the Class of Student: ";
        cin>>Class;
}

void Student::display()
{
    cout<<roll<<'\t'<<name<<'\t'<< Class<<endl;
}

int Student::search(int s)
{
    if (roll==s)
    {
        return 1;
    }
    return 0;
}

int main()
{
    Student s[10],a[20];

    ifstream fin;
    ofstream fout;

    int ch, n;

    do
    {
        cout<<"Menu \n1) Accept The Records\n2) Display the Records\n3) Search the data\n4) Delete\n5) Exit\n";
        cin>>ch;

        switch(ch)
        {
            case(1):
            {
                cout<<"How Many records you want to Enter? ";
                cin>>n;

                fout.open("Records", ios::binary|ios::out);

                for (int i=0; i<n; i++)
                {
                    s[i].accept();
                    fout.write((char*)&s[i], sizeof(s[i]));
                }
                fout.close();
                break;
            }

            case(2):
            {
                cout<<"Dispalying The Data"<<endl;
                fin.open("Records",ios::binary|ios::in);

                for (int i=0; i<n; i++)
                {
                    fin.read((char*)&a[i],sizeof(a[i]));
                    a[i].display();
                }
                fin.close();
                break;
            }

            case(3):
            {
                int l,x,flag,z;
                cout<<"Enter the Roll no. to be searched: ";
                cin>> l;
                
                fin.open("Records", ios::binary| ios::in);

                for(int i=0; i<n; i++)
                {
                    fin.read((char*)&a[i], sizeof(a[i]));
                    x = a[i].search(l);
                    if (x==1)
                    {
                        flag = 1;
                        z=i;
                        break;
                    }
                }
                if (flag == 1)
                {
                    cout<<"Record is Found!!"<<endl;
                    a[z].display();
                }
                else
					cout<<"Record not present";

                fin.close();

                break;

            }
            
            case(4):
            {
                int cx;

                fin.open("Records",ios::binary|ios::in);
                fout.open("temp", ios::binary|ios::out);

                cout<<"Enter the roll number to be deleted: ";
                cin>>cx;

                for (int i=0; i<n; i++)
                {
                    fin.read((char*)&a[i],sizeof(a[i]));
                    if(a[i].roll !=cx)
                    {
                        fout.write((char*)&a[i], sizeof(a[i]));

                    }
                }
                fout.close();
                fin.close();

                fin.open("temp",ios::binary|ios::in);
                fout.open("Records", ios::binary|ios::out);

                n--;
                while(fin.read((char*)&a,sizeof(a)))
                    fout.write((char*)&a,sizeof(a));
                fout.close();
                fin.close();

                break;
            }

            case(5):
                break;
        }
    } while (ch!=3);

    return 0;
}