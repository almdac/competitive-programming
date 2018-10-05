// Statement: https://uva.onlinejudge.org/external/6/679.pdf

#include <stdio.h>
#include <math.h>

using namespace std;

int d;

int drop(int label, int r, int l, int i) {
    int mid;

    if (label >= pow(2, d-1))
        return label;
    mid = (r+l)/2;
    if (i % 2 == 1) {
        label = 2*label + 1;
        return drop(label, mid, l, i >> 1);
    } else {
        label = 2*label;
        return drop(label, r, mid, i >> 1);
    }
}

int main() {
    int label, size, i, l;

    scanf("%d", &l);
    for (int j = 0; j < l; j++) {
        scanf("%d %d", &d, &i);
        size = pow(2, d)-1;
        label = drop(1, 0, size-1, i-1);
        printf("%d\n", label);
    }
    scanf("%d", &l);
}
