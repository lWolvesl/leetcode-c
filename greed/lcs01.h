int leastMinutes(int n){
    int i = 1;
    int j = 1;
    while(j < n){
        j <<= 1;
        i++;
    }
    return i;
}

#include <cmath>

int leastMinutes(int n) {
    if (n <= 0) return 0;
    return static_cast<int>(std::ceil(std::log2(n))) + 1;
}
