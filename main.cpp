#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct timePair{
    int fTime; // firstHours*60 + firstMinutes
    int lTime; // lastHours*60 + lastMinutes
    int diff;  // lTime - fTime
};
bool lessTime(string, string);
timePair getTimePair(string);
void normalize(vector<string>&);

int main() {
    vector<string> posh;   // list routes company Posh
    vector<string> grotty; // list routes company Grotty
    vector<string> all;    // list all routes
    string str;
    fstream fin("input.txt");
    fstream fout("output.txt", fstream::out);

    // read file
    while(getline(fin, str)){
        if(getTimePair(str).diff < 60){
            all.push_back(str);
        }
    };

    sort(all.begin(), all.end(), lessTime);
    normalize(all);
    for(string i: all){
        (i[0] == 'P' ? posh : grotty).push_back(i);
    }
    for(string i: posh){
        fout << i << endl;
    }
    fout << endl;
    for(string i: grotty){
        fout << i << endl;
    }
    return 0;
}

bool inline lessTime(string str1, string str2){
    return getTimePair(str1).fTime < getTimePair(str2).fTime;
}
timePair getTimePair(string str){
    /*
     * Get struct timePair from str
     * */
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
    timePair tP1, tP2;

    for(int i = 0; i < all.size() - 1; ++i){
        tP1 = getTimePair(all[i]);
        for(int j = i + 1; j < all.size(); ++j){
            tP2 = getTimePair(all[j]);
            if(tP2.fTime - tP1.fTime < 60){
                if(tP1.fTime == tP2.fTime && tP1.lTime == tP2.lTime){
                    all.erase(all.begin()+(all[i][0] == 'P' ? j : i));
                    break;
                }
                if(
                        ((tP1.fTime == tP2.fTime && tP1.lTime < tP2.lTime) ||
                        (tP1.fTime > tP2.fTime && tP1.lTime == tP2.lTime) ||
                        (tP1.fTime > tP2.fTime && tP1.lTime < tP2.lTime))
                ){
                    all.erase(all.begin()+j);
                }else{
                    if(tP1.fTime < tP2.fTime && tP1.lTime < tP2.lTime){
                        break;
                    }
                    all.erase(all.begin()+i);
                    break;
                }
            }else{
                break;
            }
        }
    }
}
