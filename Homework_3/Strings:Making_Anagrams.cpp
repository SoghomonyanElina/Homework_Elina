#include <bits/stdc++.h>
using namespace std;

int makeAnagram(string a, string b) {
    int matches = 0;
    int del = 0;
    for(int i = 0; i < a.size(); ++i) {
        if(a[i] == 0) {
            continue;
        }
        for(int j = 0; j < b.size(); ++j) {
            if(a[i] == b[j]) {
                matches += 1;
                a[i] = b[j] = 0;
            }
            if(a[i] == 0) {
                break;
            }
            if(b[i] == 0) {
                continue;
            }
        }
    }
    del = a.size() + b.size() - 2 * matches;
    return del;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}