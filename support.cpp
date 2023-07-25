#include "support.h"

float bin2float(const string& binary)
{
	char signBit = binary[0];

	string exp = binary.substr(1, 8);
	
	string mantissa = binary.substr(9);
	
	float decResult = 0.0f;
	
	float power = pow(2, stoi(exp, nullptr, 2) - 127);

	for (size_t i = 0; i < 23; i++)
	{
		decResult += (mantissa[i] - '0') * pow(2, -static_cast<float>(i + 1));
	}

	float floatValue = (1 + decResult) * power;

	if (signBit == '1')
	{
		floatValue = -floatValue;
	}
	
	return floatValue;
}
