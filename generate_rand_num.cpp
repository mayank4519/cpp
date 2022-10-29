#include <iostream>
#include <string>
#include <random>
#include <cstring>
using namespace std;

uint8_t x = 5;

int main(int argc, char **argv) {

    uint8_t x  = atoi(argv[1]);
    cout << x << " " <<  (int)::x << "\n";

    for (uint8_t i  = 10; i < 20; i++)
        cout << rand() % i + 100 << "\t";

    uint8_t *p = new uint8_t[1];
    memcpy(p, &x, 1);
    cout << (int)*p << "   ";

    const char *filename = "temp.txt";
    FILE *fp = fopen(filename, "wb");
    fwrite((int*)p, sizeof(uint8_t), 1, fp);
    fclose(fp);

    delete []p;
}