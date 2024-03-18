#include <bits/stdc++.h>
using namespace std;
//another function
long palindrome(int sub, string s) {
    int matches;
    long count = 0;
    int k = 1;
    for(int i = 0; i < s.size() - (sub - 1); ++i) {
        matches = 0;
        for(int j = i, z = 0; z < sub / 2; ++j, ++z) {
            if(s[j] == s[sub - k - j]) {
                ++matches;
            }
            k -= 2;
        }
        if(matches == sub / 2) {
            ++count;
        }
    }
    return count;
}
long substrCount(int n, string s) {
    int subs = 0;
    long count = 0;
    int matches = 0;
    for(int  sub = 1; sub <= s.size() - 1; ++sub) {
        count += palindrome(sub,s);
    }
    for(int i = 0; i < s.size() / 2; ++i) {
        if(s[i] == s[s.size() - 1 - i]) {
            ++matches;
        }
    }
    if(matches == s.size() / 2) {
        count += 1;
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}