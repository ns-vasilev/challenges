/*

Power of 2

Find if the given number is a power of 2 or not. More specifically, find if the given number can be expressed as 2^k where k >= 1.
Note: The number length can be more than 64, which means the number can be greater than 2 ^ 64 (out of long long range)

*/

std::pair<string, int> divideBy2(const string &num) {
    std::string result;

    int carry = 0;

    for (char c : num) {
        int current = carry * 10 + (c - '0');
        result.push_back((current / 2) + '0');
        carry = current % 2;
    }

    int pos = 0;
    while (pos < (int)result.size() && result[pos] == '0') {
         pos++;
    }

    if (pos == (int)result.size()) { 
        return { "0", carry };
    }

    return { result.substr(pos), carry };
}

int Solution::power(string num) {
    if (num == "0" || num == "1") {
        return false;
    }

    while (num != "1") {
        auto [quotient, remainder] = divideBy2(num);
        if (remainder != 0) {
            return false;
        }
        num = quotient;
    }

    return true;
}
