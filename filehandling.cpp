#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class Student
{
    int age;
    char name[20];
    int rollno;
public:
    void input()
    {
        cout<<"Enter the name and age and roll no.: "<<endl;
        cin>>name>>age>>rollno;

    }
    void display()
    {
        cout<<"Name: "<<name;
        cout<<endl<<"Age: "<<age;
        cout<<endl<<"Roll no. :"<<rollno;
    }
    int check (int r)
    {
        if(r==rollno)
            return 1;
        else
            return 0;
    }
    int checkname(char*n)
    {
        if(strcmp(name,n)==0)
            return 1;
        else
            return 0;
    }
};
void add()
{
    fstream fin;
    Student s;
    fin.open("Student.txt",ios::out|ios::app|ios::binary);
    cout<<"\nThe student record: ";
    s.input();
    fin.write((char*)&s,sizeof(s));
    fin.close();
}
void displayAll()
{
    fstream fout;
    Student s;
    fout.open("Student.txt",ios::in|ios::binary);
    while(fout.read((char*)&s,sizeof(s)))
    {
        s.display();
    }
    fout.close();

}
void searchrecord()
{
    fstream f;
    Student s;
    int roll,flag=0;
    cout<<"Enter the roll no. to search: "<<endl;
    cin>>roll;
    f.open("Student.txt",ios::in|ios::out|ios::binary);
    while(f.read((char*)&s,sizeof(s)))
    {
        if(s.check(roll))
        {
            s.display();
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<"RECORD NOT FOUND" <<endl;
    f.close();

}
void searchname()
{
    fstream f;
    Student s;
    int flag=0;
    char name[20];
    cout<<"Enter the name to search: "<<endl;
    cin>>name;
    f.open("Student.txt",ios::in|ios::out|ios::binary);
    while(f.read((char*)&s,sizeof(s)))
    {
        if(s.checkname(name))
        {
            s.display();
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<"RECORD NOT FOUND" <<endl;
    f.close();

}
void modifyrecord()
{
    fstream f;
    Student s;
    int roll,flag=0;
    int size=sizeof(s);
    int count=0;
    int location;
    cout<<"Enter the roll no. to modify: "<<endl;
    cin>>roll;
    f.open("Student.txt",ios::in|ios::out|ios::ate|ios::binary);
    f.seekg(0);
    while(f.read((char*)&s,sizeof(s)))
    {
        count++;
        if(s.check(roll))
        {
            s.input();
            location=size*(count-1);
            f.seekp(location,ios::beg);
            f.write((char*)&s,sizeof(s));
            flag=1;
            cout<<"The record is modified."<<endl;
            break;
            exit(0);

        }
    }
    if(flag==0)
        cout<<"File not found."<<endl;
    f.close();
}

int main()
{
    int n;
    while(1)
    {
        cout<<"\n1.Add Record";
        cout<<"\n2.List";
        cout<<"\n3.Search Record";
        cout<<"\n4.Modify";
        cout<<"\n5.Search by name";
        cout<<"\nEnter the choice: ";
        cin>>n;
        switch(n)
        {
            case(1):add();
            break;
            case(2):displayAll();
            break;
            case(3):searchrecord();
            break;
            case(4):modifyrecord();
            break;
            case(5):searchname();
            break;

            case(6):exit(0);

        }
    }
    return 0;
}

