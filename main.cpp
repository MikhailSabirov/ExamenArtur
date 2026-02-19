#include <iostream>
#include <vector>
#include <stdexcept>

int main() {
    std::vector<char> seq;
    unsigned int n;

    while (std::cin >> n) {
        char c;
        if (!(std::cin >> c)) {
            std::cerr << "Error: не смогли прочитать элементы" << std::endl;
            for (int i = (int)seq.size() - 1; i >= 0; --i)
                std::cout << seq[i];
            std::cout << std::endl;
            return 1;
        }
        try {
            for (unsigned int i = 0; i < n; ++i)
                seq.push_back(c);
        } catch (const std::bad_alloc&) {
            std::cerr << "Error: не смогли выделить память" << std::endl;
            std::cout << std::endl;
            return 2;
        }
    }

    if (std::cin.fail() && !std::cin.eof()) {
        std::cerr << "Error: не смогли прочитать число" << std::endl;
        for (int i = (int)seq.size() - 1; i >= 0; --i)
            std::cout << seq[i];
        std::cout << std::endl;
        return 1;
    }
    for (int i = (int)seq.size() - 1; i >= 0; --i)
        std::cout << seq[i];
    std::cout << std::endl;

    return 0;
} // ИСправил первое перепеши 



// Задание 2
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(int argc, char* argv[]) {
    bool reverse_mode = false;

    if (argc > 2) {
        std::cerr << "Получили больше агргументов чем нужно" << std::endl;
        return 1;
    }
    if (argc == 2) {
        if (std::string(argv[1]) == "reverse") {
            reverse_mode = true;
        } else {
            std::cerr << "Неизвестный аргумент" << argv[1] << "'" << std::endl;
            return 1;
        }
    }

    std::vector<char> seq;
    char c;
    while (std::cin >> c){
        seq.push_back(c);
    }
    if (std::cin.fail() && !std::cin.eof()) {
        std::cerr << "Error: failed to read input" << std::endl;
        return 1;
    }

    if (seq.empty()) {
        std::cout << std::endl;
        return 0;
    }

    if (reverse_mode){
        std::reverse(seq.begin(), seq.end());
    }

    int i = 0;
    while (i < (int)seq.size()) {
        char cur = seq[i];
        int count = 0;
        while (i < (int)seq.size() && seq[i] == cur) {
            ++count;
            ++i;
        }
        std::cout << count << " " << cur << std::endl;
    }

    return 0;
}
