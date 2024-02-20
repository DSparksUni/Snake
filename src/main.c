#include <stdio.h>

int main(int argc, char** argv) {
    puts("Args: \n");
    for(size_t i = 1; i < argc; i++)
        printf("%zu.) %s\n", i, argv[i]);

    return 0;
}
