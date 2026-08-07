#include <iostream>
#include <String>
using namespace std;

int main(){
    string input;

    while(true){
        cout <<"book>";
        getline(cin,input);
        
        if (input == "exit" || input == "quite"){
            break;
        }
    }

    return 0
}