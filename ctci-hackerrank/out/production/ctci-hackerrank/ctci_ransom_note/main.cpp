#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;

#define MAX 30005

bool ransom_note(vector<string> magazine, vector<string> ransom) {
    map<string,int> freq;
    for(string s : magazine) {
        if(!freq[s]) freq[s]=1;
        else freq[s]++;
    }

    bool flag = true;
    for(string s : ransom) {
        if(!freq[s]) {
            flag = false;
            break;
        }
        else {
            freq[s]--;
        }
    }

    return flag;
}

int main(){
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int i = 0;i < m;i++){
       cin >> magazine[i];
    }
    vector<string> ransom(n);
    for(int i = 0;i < n;i++){
       cin >> ransom[i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
