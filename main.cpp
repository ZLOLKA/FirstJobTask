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
    int fHour = str[fColon-1] - '0' + (str[fColon-2] - '0') * 10;
    int fMinut = str[fColon+2] - '0' + (str[fColon+1] - '0') * 10;
    int lHour = str[lColon-1] - '0' + (str[lColon-2] - '0') * 10;
    int lMinut = str[lColon+2] - '0' + (str[lColon+1] - '0') * 10;

    if(fHour == lHour){
        return true;
    } else if(lHour - fHour == 1){
        return fMinut >= lMinut;
    }else{
        return false;
    }
}
