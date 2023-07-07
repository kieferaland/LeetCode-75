void myFunction(int* value1, float* value2, char* value3) {
    *value1 = 10;
    *value2 = 20.5f;
    *value3 = 'a';
}

int main() {
    int a;
    float b;
    char c;
    myFunction(&a, &b, &c);
}
