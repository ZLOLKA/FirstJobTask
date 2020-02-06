#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

/*
 * Grotty 12:45 13:25
 * Posh 17:25 18:01
 * */

using namespace std;

struct timePair{
    int fTime;
    int lTime;
    int diff;
};
bool lessTime(string, string);
timePair getTimePair(string);
void normalize(vector<string>&);

int main() {
    string str;
    vector<string> posh;
    vector<string> grotty;
    vector<string> all;
    fstream file("input.txt");

    while(getline(file, str)){
        if(getTimePair(str).diff < 60){
            all.push_back(str);
        }
    };

    sort(all.begin(), all.end(), lessTime);
    //normalize(all);
    for(string i: all){
        cout << i << endl;
    }

    sort(posh.begin(), posh.end(), lessTime);
    sort(grotty.begin(), grotty.end(), lessTime);
    for(string i: posh){
        cout << i << endl;
    }
    cout << endl;
    for(string i: grotty){
        cout << i << endl;
    }
    return 0;
}

bool inline lessTime(string str1, string str2){
    return getTimePair(str1).fTime < getTimePair(str2).fTime;
}
timePair getTimePair(string str){
    const size_t fColon = str.find_first_of(':'); // first : (Colon)
    const size_t lColon = str.find_last_of(':');  // last : (Colon)
    int hours;
    int minutes;
    timePair ret;

    hours = str[fColon-1] - '0' + (str[fColon-2] - '0') * 10;
    minutes = str[fColon+2] - '0' + (str[fColon+1] - '0') * 10;
    ret.fTime = hours*60 + minutes;

    hours = str[lColon-1] - '0' + (str[lColon-2] - '0') * 10;
    minutes = str[lColon+2] - '0' + (str[lColon+1] - '0') * 10;
    ret.lTime = hours*60 + minutes;

    ret.diff = ret.lTime - ret.fTime;

    return ret;
}
void normalize(vector<string>& all){
    timePair timePair1, timePair2;

    for(int i = 0; i < all.size() - 1; ++i){
        timePair1 = getTimePair(all[i]);
        for(int j = i + 1; j < all.size(); ++j){
            timePair2 = getTimePair(all[j]);

        }
    }
}
