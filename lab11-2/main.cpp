#include <iostream>
#include "Date.h"

int main() {
    Date verifiable = createDate();

    bool result1 = compareDate(verifiable);
    bool result2 = compareDate(verifiable.year, verifiable.month, verifiable.day);
    bool result3 = compareDate(verifiable.month, verifiable.day);

    std::cout << "Result of the first check: " << result1 << std::endl;
    std::cout << "Result of the second check: " << result2 << std::endl;
    std::cout << "Result of the third check: " << result3 << std::endl;

    return 0;
}