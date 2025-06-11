#include <iostream>
#include <vector>
#include <cmath> 
class Notation {
private:
    int base = 0;
    int base2 = 0;
    int number = 1101;
    int size = 1;
    std::vector <std::string> const seledka = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };
public:

    int In10System() {
        int result = 0;
        int cnt = 0;
        while (number > 0)
        {
            result += number % 10 * pow(base, cnt++);
            number /= 10;
        }
        number = result;
        base = base2;
        return result;
    }

    std::string In2to30System() {
        std::vector <std::string> theNumbers;
        int digit = number;
        int digit1 = number;
        std::string fish = "";
        
        while (digit1>0) {
            digit = digit1 % base2;
            digit1 = digit1 / base2;
            theNumbers.push_back(seledka[digit]);
        }
        
        for (int i = ; i >= 0; i--) { //Доработать
            fish += theNumbers[i];
        }
        return fish;
    }

    void run() {
        bool choize = true;
        while (choize) {
            std::cout << "Введите систему счисления в вашем числе: \n";
            std::cin >> base;
            std::cout << "Введите ваше число: \n";
            std::cin >> number;
            std::cout << "Введите систему счисления желаемого вами числа: \n";
            std::cin >> base2;
            if (base2 > 30 or base2 < 2) {
                std::cout << "Try again";
                std::cin >> base2;
            }
            In10System();
            std::cout << "Ваше число: " << In2to30System() << std::endl;
            std::cout << "Do you want continue working? (yes/no)";
            std::cin >> choize;
        }
    }

};

int main()
{
    setlocale(LC_ALL, "ru");
    Notation b{};
    b.run();
}

