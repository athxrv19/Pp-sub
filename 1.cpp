    return 0;
}

//using virtual function
#include <iostream>

class Number {
public:
    virtual double getAverage() = 0;
};

class FiveNumberAverage : public Number {
private:
    double numbers[5];

public:
    FiveNumberAverage(double num1, double num2, double num3, double num4, double num5) {
        numbers[0] = num1;
        numbers[1] = num2;
        numbers[2] = num3;
        numbers[3] = num4;
        numbers[4] = num5;
    }

    double getAverage() override {
        double sum = 0.0;
        for (int i = 0; i < 5; i++) {
            sum += numbers[i];
        }
        return sum / 5.0;
    }
};

int main() {
    FiveNumberAverage number(1.0, 2.0, 3.0, 4.0, 5.0);
    double average = number.getAverage();
    std::cout << "The average of the numbers is: " << average << std::endl;

    return 0;
}
//using  friend function 

#include <iostream>

using namespace std;

class AverageCalculator {
private:
    double numbers[5];

public:
    AverageCalculator(double num1, double num2, double num3, double num4, double num5) {
        numbers[0] = num1;
        numbers[1] = num2;
        numbers[2] = num3;
        numbers[3] = num4;
        numbers[4] = num5;
    }

    friend double calculateAverage(AverageCalculator& calculator);
};

double calculateAverage(AverageCalculator& calculator) {
    double sum = 0.0;
    for (int i = 0; i < 5; i++) {
        sum += calculator.numbers[i];
    }
    return sum / 5.0;
}

int main() {
    double num1, num2, num3, num4, num5;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    cout << "Enter the third number: ";
    cin >> num3;

    cout << "Enter the fourth number: ";
    cin >> num4;

    cout << "Enter the fifth number: ";
    cin >> num5;

    AverageCalculator calculator(num1, num2, num3, num4, num5);
    double average = calculateAverage(calculator);

    cout << "The average of the numbers is: " << average << endl;

    return 0;
}
