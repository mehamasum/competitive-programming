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

int number_needed(string a, string b) {
    int mapA[26], mapB[26];
    for(int i=0; i<26; i++) mapA[i]=mapB[i]=0;
    int lA= a.length(), lB = b.length(), cnt = 0;
    for(int i=0; i<lA; i++) {
        mapA[a[i]-97]++;
    }
    for(int i=0; i<lB; i++) {
        mapB[b[i]-97]++;
    }
    for(int i=0; i<26; i++) {
        cnt+= abs(mapA[i]-mapB[i]);
    }
    return cnt;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
