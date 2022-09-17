//
// Created by Egor Pavlov on 17.09.2022.
//


#include <iostream>

using namespace std;

int main()
{   int a;
    double number;
    cout<<"newton --> dyn: press 0"<<endl;
    cout<<"joule --> erg: press 1"<<endl;
    cout<<"pascal-second  --> poise: press 2"<<endl;
    cin>>a;
    cout<<"Give the number:"<<"\n ";
    cin>>number;
    int newton_to_dyn=1e5;
    int joule_to_erg=1e7;
    int pascal_second_to_poise=10;
    switch (a) {
        case 0:
            cout<<number*newton_to_dyn;
            break;
        case 1:
            cout<<number*joule_to_erg;
            break;
        case 2:
            cout<<number*pascal_second_to_poise;
            break;
        default:
            cout<<"error";
    }
    return 0;
}
