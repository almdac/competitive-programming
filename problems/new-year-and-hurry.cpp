// Statement: http://codeforces.com/problemset/problem/750/A

#include <iostream>

using namespace std;

int n, k;

int contestDuration(int q) {
    return (5*(1+q)*q)/2;
}

int maxProbs(int min, int max) {
    int mid, contest_duration;

    while (min < max-1) {
        mid = (min+max)>>1;
        contest_duration = contestDuration(mid);
        if (contest_duration == 240-k) return mid;
        else if (contest_duration > 240-k) max = mid;
        else min = mid;
    }
    if (contestDuration(max) <= 240-k) return max;
    else return min;
}

int main() {
    cin >> n >> k;
    cout << maxProbs(0, n);

    return 0;
}