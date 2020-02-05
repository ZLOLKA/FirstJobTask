#include <iostream>
#include <fstream>
#include <vector>

/*
 * Grotty 12:45 13:25
 * Posh 17:25 18:01
 * */

using namespace std;

bool timeLessHour(string);

int main() {
    string str;
    vector<string> posh;
    vector<string> grotty;
    fstream file("input.txt");
    while(getline(file, str)){
        if(timeLessHour(str)){
            (str[0] == 'P' ? posh : grotty).push_back(str);
        }
    };
    for(string i: posh){
        cout << i << endl;
    }
    cout << endl;
    for(string i: grotty){
        cout << i << endl;
    }
    return 0;
}

bool timeLessHour(string str){
    const size_t fColon = str.find_first_of(':'); // first : (Colon)
    const size_t lColon = str.find_last_of(':');  // last : (Colon)
    if(str[lColon-2] == str[fColon-2]){
        if(str[lColon-1] == str[fColon-1]){

        }else if(str[lColon-1] - str[fColon-1] == 1){

        }else{
            return false;
        }
    }else if(str[lColon-2] - str[fColon-2] == 1){ // 19:nn 20:nn or 09:nn 10:nn

    }else{
        return false;
    }
    return true;
}
