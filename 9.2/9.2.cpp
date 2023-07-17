#include <iostream>
#include <string>
using namespace std;

class big_integer {
private:
    string str;
    bool isOverFlow;
    bool isNegative;
    int integerNumber;

    int isOvfOperation(const big_integer&, const char) const noexcept;

public:
    big_integer(const big_integer& s) = default;
    big_integer& operator=(const big_integer& s) = default;
    ~big_integer() = default;

    big_integer()
        : str("0")
        , isOverFlow(false)
        , isNegative(false)
        , integerNumber(0) {}

    big_integer(string s) : big_integer() {
        if (s.length())
            str = s;

        size_t mx = str.find_first_not_of('-');
        if (mx % 2)
            isNegative = true;

        int check = atoi(str.substr(mx).c_str());

        if (check < 0)
            isOverFlow = true;
        else
            integerNumber = check;
    }


    big_integer(big_integer&& s) {
        str = move(s.str);

        isOverFlow = s.isOverFlow;
        s.isOverFlow = false;

        isNegative = s.isNegative;
        s.isNegative = false;

        integerNumber = s.integerNumber;
        s.integerNumber = 0;
    }

    big_integer& operator=(big_integer&& s) {

        if (&s == this)
            return *this;

        str = move(s.str);

        isOverFlow = s.isOverFlow;
        s.isOverFlow = false;

        isNegative = s.isNegative;
        s.isNegative = false;

        integerNumber = s.integerNumber;
        s.integerNumber = 0;

        return *this;
    }

    big_integer& operator=(const string&& s) {
        return (*this = move(big_integer(s)));
    }


    big_integer operator+(big_integer& s2)
    {
        if (int checkOvf; checkOvf = isOvfOperation(s2, '+') >= 0)
        {
            if (isNegative && s2.isNegative)
                integerNumber = -checkOvf;
            else if (isNegative)
                integerNumber = s2.integerNumber - integerNumber;
            else if (s2.isNegative)
                integerNumber -= s2.integerNumber;
            else
                integerNumber += s2.integerNumber;

            return move(big_integer(to_string(integerNumber)));
        }

        string::reverse_iterator f_begin(str.rbegin()), f_end(str.rend()),
            s_begin(s2.str.rbegin()), s_end(s2.str.rend());

        if (str.length() < s2.str.length()) {
            swap(f_begin, s_begin);
            swap(f_end, s_end);
        }

        int n1, n2, next, sum;
        sum = next = n1 = n2 = 0;
        string result;
        for (; f_begin != f_end; ++f_begin)
        {
            n1 = static_cast<int>(*f_begin - '0');
            n2 = 0;

            if (s_begin != s_end) {
                n2 = *s_begin - '0';
                s_begin++;
            }

            sum = n1 + n2 + next;
            if (sum >= 10) {
                next = static_cast<int>(sum / 10);
                sum %= 10;
            }
            else
                next = 0;

            result.insert(0, to_string(sum));
        }

        if (next > 0)
            result.insert(0, to_string(next));

        return move(big_integer(result));
    }

    big_integer operator*(int num) noexcept
    {
        big_integer s2(to_string(num));
        string result;

        if (int checkOvf(isOvfOperation(s2, '*')); checkOvf > 0)
        {
            s2.integerNumber = isNegative || s2.isNegative ? -checkOvf : checkOvf;
            s2.str = to_string(s2.integerNumber);
            return move(s2);
        }

        string::reverse_iterator f_begin(str.rbegin()), f_end(str.rend()),
            s_begin(s2.str.rbegin()), s_end(s2.str.rend());

        if (str.length() > s2.str.length()) {
            swap(f_begin, s_begin);
            swap(f_end, s_end);
        }

        int n1, n2, next, mul;
        mul = next = n1 = n2 = 0;

        for (; f_begin != f_end; ++f_begin)
        {
            n1 = static_cast<int>(*f_begin - '0');
            if (n1 == 0) {
                result.insert(0, "0");
                continue;
            }

            for (; s_begin != s_end; ++s_begin)
            {
                n2 = static_cast<int>(*s_begin - '0');
                mul = n1 * n2 + next;

                if (mul >= 10) {
                    next = static_cast<int>(mul / 10);
                    mul %= 10;
                }
                else
                    next = 0;

                result.insert(0, to_string(mul));
            }
        }

        if (next > 0)
            result.insert(0, to_string(next));

        return move(big_integer(result));
    }

    friend ostream& operator<<(ostream& os, const big_integer& s);
};

int main()
{
    auto number1 = big_integer("4");
    auto number2 = big_integer("1");
    cout << "number1: " << number1 << endl;
    cout << "number2: " << number2 << endl;

    auto result = number1 + number2;
    cout << number1 << " + " << number2 << " = " << result << endl;

    int multiplier = -10;
    auto result2 = result * multiplier;
    cout << result << " * " << multiplier << " = " << result2 << endl;
    cout << "--------------------------------------\n" << endl;

    number1 = "2147483647";
    number2 = "1000000000";

    cout << "number1: " << number1 << endl;
    cout << "number2: " << number2 << endl;

    result = number1 + number2;
    cout << number1 << " + " << number2 << " = " << result << endl;

    multiplier = 500;
    result2 = result * multiplier;
    cout << result << " * " << multiplier << " = " << result2 << endl;
    cout << "--------------------------------------" << endl;

    return 0;
}

int big_integer::isOvfOperation(const big_integer& s2, const char op) const noexcept
{
    int checkOvf = 0;
    if (!isOverFlow && !s2.isOverFlow)
    {
        switch (op)
        {
        case '+':
            checkOvf = integerNumber + s2.integerNumber;
            break;

        case '*':
            checkOvf = integerNumber * s2.integerNumber;
            break;

        default:
            break;
        }
    }

    return checkOvf;
}

ostream& operator<<(ostream& os, const big_integer& s) {
    os << s.str;
    return os;
}