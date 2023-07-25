#include "support.h"

int main(int argc, char* argv[])
{
    /*
    * binary to float test
    string binaryNum = "0100000000011010001000000000100";

    float result = bin2float(binaryNum);

    cout << "float val: " << result << endl;
    */

    vector<bool> transmitMessage = { true, false, true, true };

    char charData = 'A';

    transmitMessage = packetizeTemp(transmitMessage, charData);

    uint32_t uintData = 123456789;
    transmitMessage = packetizeTemp(transmitMessage, uintData);

    float floatData = 3.14f;
    transmitMessage = packetizeTemp(transmitMessage, floatData);

    for (bool bit : transmitMessage)
    {
        cout << bit;
    }

    cout << endl;
    return 0;
}