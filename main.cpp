#include <iostream>

extern "C" {
#include "openssl/md5.h"
}

#include "md5.h"
#include "string.h"


using namespace std;


void get_md5(const uint8_t *text, uint32_t size, uint8_t *res);

void print_md5(const uint8_t *text);

void get_md5_openssl(const uint8_t *text, uint32_t size, uint8_t *res);

int my_strcmp(uint8_t* str1, uint8_t* str2, uint32_t size);

int main() {
    uint8_t res1[100];
    uint8_t res2[100];
    uint8_t text[] = "edik";
    uint8_t text2[] = "kek";
    uint8_t text3[] = "18651354wehyrg";

    cout << "------------------------------\n";
    cout << "First test word: " << text << endl;
    cout << "My MD5:      ";
    get_md5(text, sizeof(text) - 1, res1);
    print_md5(res1);

    cout << "MD5 openssl: ";
    get_md5_openssl(text, sizeof(text) - 1, res2);
    print_md5(res2);

    if (my_strcmp(res1, res2, MD5_DIGEST_LENGTH) == 0) {
        cout << "ALL OK!" << endl;
    } else {
        cout << "ERROR, does not match MD5" << endl;
    }
    cout << "------------------------------\n";

    cout << "------------------------------\n";
    cout << "Second test word: " << text2 << endl;
    cout << "My MD5:      ";
    get_md5(text2, sizeof(text2) - 1, res1);
    print_md5(res1);

    cout << "MD5 openssl: ";
    get_md5_openssl(text2, sizeof(text2) - 1, res2);
    print_md5(res2);

    if (my_strcmp(res1, res2, MD5_DIGEST_LENGTH) == 0) {
        cout << "ALL OK!" << endl;
    } else {
        cout << "ERROR, does not match MD5" << endl;
    }
    cout << "------------------------------\n";



    return 0;
}

void get_md5(const uint8_t *text, uint32_t size, uint8_t *res) {
    if (text == nullptr || res == nullptr)
        return;
    MD5_C md5;
    md5::init(&md5);
    md5::update(&md5, text, size);
    md5::final(res, &md5);
}

void print_md5(const uint8_t *text) {
    for (int i = 0; i < MD5_DIGEST_LENGTH; ++i) {
        cout << hex << (uint16_t) text[i] << " ";
    }
    cout << endl;
}

void get_md5_openssl(const uint8_t *text, uint32_t size, uint8_t *res) {
    if (text == nullptr || res == nullptr)
        return;
    MD5_CTX md5;
    MD5_Init(&md5);
    MD5_Update(&md5, text, size);
    MD5_Final(res, &md5);
}

int my_strcmp(uint8_t* str1, uint8_t* str2, uint32_t size){
    uint32_t i = 0;
    while(*str1 && (*str1 == *str2) && i < size)
    {
        str1++;
        str2++;
        i++;
    }
    return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}

