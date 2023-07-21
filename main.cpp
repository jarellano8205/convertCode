#include "support.h"

int main(int argc, char* argv[])
{
    string binaryNum = "0100001100011010001000000000100";

    float result = bin2float(binaryNum);

    cout << "float val: " << result << endl;

    return 0;
}