//Statement: Competitive Programming 3, Steven Halim - 3.3.1 - Bisection Method

#include <iostream>

#define EPS 1e-9

using namespace std;

float f(float d, float v, int m, float i) {
    float installment_value;
    if (m == 0) 
        return v;
    installment_value = v*(1+i) - d;
    return f(d, installment_value, m-1, i);
}

float findRootInstallmentValue(float r, float l, float v, int m, float i) {
    float mid, shoot;

    if (r < l) {
        mid = (r+l)/2;
        shoot = f(mid, v, m, i);
        if (shoot >= 0 && shoot <= EPS)
            return mid;
        else if (shoot > 0) // Undershoot
            return findRootInstallmentValue(mid, l, v, m, i);
        else if (shoot < 0) // Overshoot
            return findRootInstallmentValue(r, mid, v, m ,i);
    }
}

int main() {
    int m;
    float v, i, d, min, max;

    cout << "Enter months: ";
    cin >> m;
    cout << "Enter car's total value: ";
    cin >> v;
    cout << "Enter bank interest (decimal format): ";
    cin >> i;
    min = 0.01;
    max = v*(1 + i);
    d = findRootInstallmentValue(min, max, v, m, i);
    cout << "Pay " << d << " US$ per month for " << m << " months" << endl;
}
