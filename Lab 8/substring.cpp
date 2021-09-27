/*
	Bugged code made by Shashwat Garg, 200050130.
	Lab 8, CS154
	May 3, 2021
*/

#include <iostream>
#include <string>
//#define NDEBUG  // uncomment to turn off Assertions

#include <cassert>
using namespace std;

int find(string str, string sub)
{
    int fulllength, partlength;
    bool check;

    fulllength = str.length();
    partlength = sub.length();

    assert(partlength > 0);                 //precondition
    assert(fulllength >= partlength);       //precondition

    for(int i=0; i<=fulllength-partlength; i++){
        check = true;
        for(int j=0; j<partlength; j++){
            if(str[i+j]!=sub[j]){
                check=false;
                break;
            }
        }
        if(check){
            assert(i>=0 && i<fulllength);       //postcondition
            return i;
        }
    }
    return -1;
}

int main()
{

    string full, part;
    int index;

    cout << "Enter full string\n";
    cin >> full;
    cout << "Enter part of string\n";
    cin >> part;

    index = find(full, part);
    //Control reaches here implies no error caught by assert statements.
    cout<<index<<endl;

}
