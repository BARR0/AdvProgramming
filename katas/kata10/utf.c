#include <stdbool.h>
#include <stdio.h>

bool getBit(int num, int bit)
{
    return num & (1u << (7 - bit));
}

bool checkByte(int byte)
{
    // byte = byte & ~(~0u << 8)
    return getBit(byte, 0) && !getBit(byte, 1);
}

int checkChar(int *data, int dataSize)
{
    int size = 0;
    for (int i = 0; getBit(data[0], i); ++i)
        ++size;
    if (size == 0)
        return 1;
    if (size < 2 || size > 4)
        return -1;
    if (size > dataSize)
        return -1;
    for (int i = 1; i < size; ++i)
        if (!checkByte(data[i]))
            return -1;
    return size;
}

bool validUtf8(int* data, int dataSize) {
    int size;
    for (int i = 0; i < dataSize; i += size)
    {
        size = checkChar(data + i, dataSize - i);
        printf("%d\n", size);
        if (size == -1)
            return false;
    }
    return true;
}
