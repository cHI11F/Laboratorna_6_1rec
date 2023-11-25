#include <iostream>
#include <cstdlib>
#include <ctime>

void fillArray(int x[], int index) {
    if (index == 24) {
        return;
    }

    x[index] = rand() % 71 - 17;
    fillArray(x, index + 1);
}

void printArray(const int x[], int index) {
    if (index == 24) {
        std::cout << std::endl;
        return;
    }

    std::cout << x[index] << " ";
    printArray(x, index + 1);
}

void processAndCount(int x[], int& count, int& sum, int index) {
    if (index == 24) {
        return;
    }

    if (x[index] < 0 && x[index] % 3 != 0) {
        count++;
        sum += x[index];
        x[index] = 0;
    }

    processAndCount(x, count, sum, index + 1);
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));

    int myArray[24];
    int count = 0, sum = 0;

    fillArray(myArray, 0);

    std::cout << "Original Array: ";
    printArray(myArray, 0);

    processAndCount(myArray, count, sum, 0);

    std::cout << "Count of elements satisfying the criteria: " << count << std::endl;
    std::cout << "Sum of elements satisfying the criteria: " << sum << std::endl;

    std::cout << "Modified Array : ";
    printArray(myArray, 0);

    return 0;
}
