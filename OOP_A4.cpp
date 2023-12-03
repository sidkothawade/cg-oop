#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    char Give_Info[500];
    ofstream out_file;
    out_file.open("Information.txt",ios::out);
    cout<<"Enter information to store in file (Not more than 150 characters): ";
    fgets(Give_Info,500,stdin);
    out_file<<Give_Info;
    out_file.close();
    char Get_Info[500];
    ifstream in_file;
    in_file.open("Information.txt",ios::in);
    in_file.getline(Get_Info,500);
    cout<<"\n\nGiven Information is : \n";
    cout<<Get_Info;
    in_file.close();
    return 0;
}