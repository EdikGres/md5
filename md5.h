//
// Created by atlon on 05.04.2023.
//

#ifndef HASHCMZI_MD5_H
#define HASHCMZI_MD5_H

#define MD5_DIGEST_LENGTH 16

typedef unsigned int MD5_u32plus;

typedef struct {
    MD5_u32plus lo, hi;
    MD5_u32plus a, b, c, d;
    unsigned char buffer[64];
    MD5_u32plus block[16];
} MD5_C;


namespace md5{
        void init(MD5_C *ctx);
        void update(MD5_C *ctx, const void *data, unsigned long size);
        void final(unsigned char *result, MD5_C *ctx);
}

#endif //HASHCMZI_MD5_H
