#include <stdint.h>
#include <stdio.h>
#include <arpa/inet.h>

uint32_t read(const char* filename) {
    FILE* fp = fopen(filename, "rb");

    if (fp == NULL) {
        perror(filename);
        return 0;
    }

    uint32_t n_number;

    if (fread(&n_number, sizeof(n_number), 1, fp) != 1) {
        fprintf(stderr, "%s : can't read file\n", filename);
        fclose(fp);
        return 0;
    }

    fclose(fp);
    return ntohl(n_number);
}

int main(int argc, char* argv[]) {
    uint32_t number;
    uint32_t sum = 0;

    for (int i = 1; i < argc; i++) {
        number = read(argv[i]);
        printf("%u(0x%08x)", number, number);
        sum += number;

        if (i == argc - 1)
            printf(" = %u(0x%08x)", sum, sum);
        else
            printf(" + ");
    }

    printf("\n");
    return 0;
}
