#include <bits/stdc++.h>
using namespace std;
void count_sort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> out(n);
    int cnt[10] = {0};

    for (int i = 0; i < n; ++i) {
        int d = (abs(arr[i]) / exp) % 10;
        cnt[d]++;
    }
    for (int i = 1; i < 10; ++i) cnt[i] += cnt[i-1];
    for (int i = n - 1; i >= 0; --i) {
        int d = (abs(arr[i]) / exp) % 10;
        out[cnt[d] - 1] = arr[i];
        cnt[d]--;
    }

    for (int i = 0; i < n; ++i) arr[i] = out[i];
}

void radix_sort(vector<int>& arr) {
    if (arr.empty()) return;
    vector<int> neg, pos;
    for (int x : arr) {
        if (x < 0) neg.push_back(-x);
        else pos.push_back(x);
    }
    if (!pos.empty()) {
        int mx = *max_element(pos.begin(), pos.end());
        for (int exp = 1; mx / exp > 0; exp *= 10) {
            count_sort(pos, exp);
        }
    }

    if (!neg.empty()) {
        int mx = *max_element(neg.begin(), neg.end());
        for (int exp = 1; mx / exp > 0; exp *= 10) {
            count_sort(neg, exp);
        }
        reverse(neg.begin(), neg.end());
        for (int &x : neg) x = -x;
    }

    arr.clear();
    for (int x : neg) arr.push_back(x);
    for (int x : pos) arr.push_back(x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << "enter n: ";
    int n; cin >> n;
    vector<int> a(n);
    cout << "Enter nums; ";
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << "Before: ";
    for (int x : a) cout << x << ' ';
    radix_sort(a);
    cout << "After:  ";
    for (int x : a) cout << x << ' ';
    return 0;
}
