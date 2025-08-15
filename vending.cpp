#include <iostream>
using namespace std;

void process(){
    string choice;
    cout << "Select what you want";
    cin >> choice ;

    switch (choice)
    {
    case "Mocha":
        /* code */
        break;
    
    default:
        break;
    }
    
    
}


int main(){
    while(true){
        process();




        bool isoff;
        cout << "Is power off?";
        cin >> isoff;
        if(isoff){
            return ;
        }
    }
}