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
        cout << "Add Chocolate Powder ,\n";
    
    case 2:
        cout << "Add Forthed Milk ,\n";

    case 3: 
       cout << "Add Hot Coffee \n";
        break;
    default:
        cout << "No such product available.\n";
        break;
    }
    
}

int main(){
    while(true){
        process();
      

        string isoff;
        cout << "Is power off? \n";
        cin >> isoff;
        if(isoff == "Yes" || isoff == "yes"){
            break; 
        }

        
    }
}