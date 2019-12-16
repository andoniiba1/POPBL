#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char* argv[])
{
    int x, y, z, a;
    char str[128];

    printf("Emaidazu lau zenbaki espazioekin: ");
    fgets(str, 128, stdin);
    sscanf(str, "%d %d %d", &x, &y, &z);
    if (x > y) {
        a = x;
        x = y;
        y = a;
    }
    if (y > z) {
        a = y;
        y = z;
        z = a;
    }
    if (x > y) {
        a = x;
        x = y;
        y = a;
    }
    printf("%d<%d<%d\n",x,y,z);
}