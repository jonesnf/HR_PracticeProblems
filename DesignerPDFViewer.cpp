#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
    Determine the area of a highlighted box in a PDF viewer based on the tallest letter.  Will post the whole problem later
*/



int main(){
    
    int max, area;
    
    vector<int> h(26);
    for(int h_i = 0;h_i < 26;h_i++){
       cin >> h[h_i];
    }
    string word;
    cin >> word;
    
    string alph = "abcdefghijklmnopqrstuvwxyz";
    unsigned int found = 0;
    max = 0;
    
    for(int i = 0; i < word.length(); i++){
        found = alph.find(word[i]);
        found = h[found];
        (found > max) ? max = found : max = max;
    }
    
    area = max * word.length();
    cout << area;
    
    return 0;
}