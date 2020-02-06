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
    int fHours;
    int fMinutes;
    int lHours;
    int lMinutes;
};
bool timeLessHour(string);
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
        if(timeLessHour(str)){
            all.push_back(str);
        }
    };

    sort(all.begin(), all.end(), lessTime);
    normalize(all);
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

bool timeLessHour(string str){
    timePair time = getTimePair(str);
    int fHour = time.fHours;
    int fMinut = time.fMinutes;
    int lHour = time.lHours;
    int lMinut = time.lMinutes;

    if(fHour == lHour){
        return true;
    } else if(lHour - fHour == 1){
        return fMinut >= lMinut;
    }else{
        return false;
    }
}
bool lessTime(string str1, string str2){
    timePair time1 = getTimePair(str1);
    timePair time2 = getTimePair(str2);

    if(time1.fHours < time2.fHours){
        return true;
    }else if(time1.fHours == time2.fHours){
        if(time1.fMinutes < time2.fMinutes){
            return true;
        }
    }
    return false;
}
timePair getTimePair(string str){
    const size_t fColon = str.find_first_of(':'); // first : (Colon)
    const size_t lColon = str.find_last_of(':');  // last : (Colon)
    timePair ret;
    ret.fHours = str[fColon-1] - '0' + (str[fColon-2] - '0') * 10;
    ret.fMinutes = str[fColon+2] - '0' + (str[fColon+1] - '0') * 10;
    ret.lHours = str[lColon-1] - '0' + (str[lColon-2] - '0') * 10;
    ret.lMinutes = str[lColon+2] - '0' + (str[lColon+1] - '0') * 10;

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
