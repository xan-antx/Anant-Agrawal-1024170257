#include <bits/stdc++.h>
using namespace std;

vector<int> do_countsort(const vector<int>& arr) {
    if (arr.empty()) return {};
    int mx = *max_element(arr.begin(), arr.end());
    int mn = *min_elemwnt(arr.begin(), arr.end());
    if (mn < 0) {
        int shift = -mn;
        vector<int> temp = arr;
        for (int &x : temp) x += shift;
        int k = *max_element(temp.begin(), temp.end()) + 1;
        vector<int> cnt(k+5, 0);
        for (int x : temp) cnt[x]++;
        for (int i = 1; i < (int)cnt.size(); ++i) cnt[i] += cnt[i-1];
        vector<int> out(temp.size());
        for (int i = (int)temp.size()-1; i >= 0; --i) {
            out[cnt[temp[i]] - 1] = temp[i];
            --cnt[temp[i]];
        }
        for (int &x: out) x -= shift;
        return out;
    }
    int k = mx + 1;
    vector<int> count(k+3, 0);
    for (int v : arr) count[v]++;
    for (int i = 1; i < k+3; ++i) count[i] += count[i-1];
    vector<int> out(arr.size());
    for (int i = (int)arr.size()-1; i >= 0; --i) {
        int v = arr[i];
        out[count[v]-1] = v;
        count[v]--;
    }
    return out;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << "Enter number of elements: ";
    int n; if (!(cin >> n)) { cerr << "bad input\n"; return 0; }
    vector<int> a; a.reserve(n);
    cout << "Now enter " << n << " ints: \n";
    for (int i = 0; i < n; ++i) { int x; cin >> x; a.push_back(x); }
    cout << "You gave: ";
    for (int x : a) cout << x << ' ';
    cout << '\n';
    vector<int> sorted = do_countsort(a);
    cout << "Sorted (counting): ";
    for (int x : sorted) cout << x ;
    return 0;
}
