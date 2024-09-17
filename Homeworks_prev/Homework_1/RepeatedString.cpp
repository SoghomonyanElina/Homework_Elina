#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
long repeatedString(string s, long n) {
    long count = 0;
    long add = 0;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == 'a') { ++count; }
    }
    if( n % s.size() == 0) { count = count * (n / s.size()); }
    else {
        for(int i = 0; i < n % s.size(); ++i) {
            if(s[i] == 'a') { ++add; }
        }
        count = count * (n / s.size()) + add;
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}