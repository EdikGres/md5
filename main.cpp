#include <iostream>

extern "C" {
#include "md5.h"
}

using namespace std;



void get_md5(const uint8_t *text, uint32_t size, uint8_t *res);
void print_md5(const uint8_t *text);

int main() {

    uint8_t res[300];

    get_md5((uint8_t*)"kek", sizeof("kek")-1, res);
    print_md5(res);







    return 0;
}

void get_md5(const uint8_t *text, uint32_t size, uint8_t *res){
    if(text == nullptr || res == nullptr)
        return;
    MD5_CTX md5;
    MD5_Init(&md5);
    MD5_Update(&md5, text, size);
    MD5_Final(res, &md5);
}

void print_md5(const uint8_t *text){
    for (int i = 0; i < 16; ++i) {
        cout << hex << (uint16_t)text[i] << " ";
    }
    cout << endl;
}
