#include <iostream>

int main() {
    int start, end;

    std::cout << "Input starting integer: ";
    std::cin >> start;
    std::cout << "Input ending integer: ";
    std::cin >> end;

    std::cout << "Even numbers are: ";
    
    for (int i = start; i <= end; i++) {
        if (i % 2 == 0) {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;
    
    return 0;
}
