class Solution {
public:

string fractionAddition(string expression) {
    istringstream iss(expression);
    int num = 0, den = 1, n, d;
    char slash;

    while (iss >> n >> slash >> d) {
        int lcm_den = lcm(den, d);
        num = num * (lcm_den / den) + n * (lcm_den / d);
        den = lcm_den;

        int g = gcd(abs(num), abs(den));
        num /= g;
        den /= g;

        char op;
        iss >> op;
        if (op == '-') {
            iss.unget(); 
        } else if (op != '+') {
            iss.unget(); 
        }
    }

    if (den < 0) {
        num = -num;
        den = -den;
    }

    return to_string(num) + "/" + to_string(den);
    }
};