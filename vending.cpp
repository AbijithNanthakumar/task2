#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

void process(){

    

    unordered_map<string,int> choicenum = {
        {"Mocha",1},{"Latte",2},{"Espresso",3}
    } ;

    string choice;
    cout << "Select what you want";
    cin >> choice ;
    

    switch (choicenum[choice])
    {
    case 1:
        
        
    
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