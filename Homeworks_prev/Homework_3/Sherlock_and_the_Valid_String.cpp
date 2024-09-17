#include <bits/stdc++.h>
using namespace std;

string isValid(string s) {
    vector<int> freq;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == -1) {
            continue;
        }
        int matches = 0;
        for(int j = i + 1; j < s.size(); ++j) {
            if(s[i] == s[j]) {
                ++matches;
                s[j] = -1;
            }
            if(s[i] == -1) {
                break;
            }
            if(s[j] == -1) {
                continue;
            }
        }
        s[i] = -1;
        freq.push_back(matches + 1);
    }
    //for(int i = 0; i < freq.size(); ++i) {
        //cout << freq[i] << ' ';
    //}
    int count = 0;
    int k = 0;
    int count_of_1 = 0;
    int count_of_dif = 0;
    if(freq.size() == 1) {
        return "YES";
    }
    for(int i = 0; i < freq.size() - 1; ++i) {
        if(freq[i] == freq[i + 1]) {
            ++count;
        }
    }
    if(count + 1 == freq.size() - 2) {
        for(int i = 1; i < freq.size(); ++i) {
            if(abs(freq[0] - freq[i]) == 1) {
                ++k;
            }
        }
        if(k == 1 && freq[0] == freq[freq.size() -1]) {
            return "YES";
        }
        else if(k == 1 && freq[0] != freq[freq.size() -1]) {
            return "NO";
        }
    }
    if(count + 1 == freq.size()) {
        return "YES";
    }
    if(count + 1 == freq.size() - 1) {
        for(int i = 0; i < freq.size(); ++i) {
            if(freq[i] == 1) {
                ++count_of_1;
            }
        }
        if(count_of_1 == 1) {
            return "YES";
        }
        for(int i = 1; i < freq.size(); ++i) {
            if(abs(freq[0] - freq[i]) == 1) {
                ++count_of_dif;
            }
            else if(abs(freq[0] - freq[i]) > 1) {
                return "NO";
            }
        }
        if(count_of_dif > 1) {
            return "NO";
        }
        else if(count_of_dif == 1) {
            return "YES";
        }
    }
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}