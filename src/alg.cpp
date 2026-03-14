

double pown(double value, uint16_t n) {
    double result = 1.0;
    if (n == 0) {
        return 1.0;
    }
    for (uint16_t i = 0; i < n; i++) {
        result *= value;
    }
    return result;
}

uint64_t fact(uint16_t n) {
    uint64_t result = 1;
    if (n == 0) {
        return 1;
    }
    for (uint16_t i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / (double)fact(n);
}

double expn(double x, uint16_t count) {
    double result = 0.0;
    for (uint16_t n = 0; n < count; n++) {
        result += calcItem(x, n);
    }
    return result;
}

double sinn(double x, uint16_t count) {
    double result = 0.0;
    for (uint16_t i = 0; i < count; i++) {
        uint16_t num = 2 * i + 1;
        double a = pown(x, num) / fact(num);
        if (i % 2 == 0) {
            result += a;
        } else {
            result -= a;
        }
    }
    return result;
}

double cosn(double x, uint16_t count) {
    double result = 0.0;
    for (uint16_t i = 0; i < count; i++) {
        uint16_t num = 2 * i;
        double c = pown(x, num) / fact(num);
        if (i % 2 == 0) {
            result += c;
        } else {
            result -= c;
        }
    }
    return result;
}
