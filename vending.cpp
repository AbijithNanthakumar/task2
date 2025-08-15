#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

void process(){

    unordered_map<string,int> choicenum = {
        {"Mocha",1},{"Latte",2},{"Espresso",3}
    } ;

    string  choice;
    cout << "Select what you want \n";
    cin >> choice ;
    

    switch (choicenum[choice])
    {
    case 1:
        cout << "Add Chocolate Powder";
    
    case 2:
        cout << "Add Forthed Milk";

    case 3: 
       cout << "Add Hot Coffee";
        break;
    default:
        cout << "No such product available.";
        break;
    }
    
}

int main(){
    while(true){
        process();
      

        string isoff;
        cout << "Is power off?";
        cin >> isoff;
        if(isoff == "Yes" || isoff == "yes"){
            break; 
        }

        
    }
}