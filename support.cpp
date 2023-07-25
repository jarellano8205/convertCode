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

template<typename T>
vector<bool> packetizeTemp(const vector<bool>& transmitMessage, const T& message)
{
	vector<bool> data;

	if constexpr (is_same_v<T, char> || is_same_v <T, uint8_t>)
	{
		data.reserve(8);
		for (size_t i = 7; i >= 0; i--)
		{
			data.push_back((message & (1 << i)) != 0);
		}
	}
	else if constexpr (is_same_v <T, uint16_t>)
	{
		data.reserve(16);
		for (size_t i = 15; i >= 0; i--)
		{
			data.push_back((message & (1 << i)) != 0);
		}
	}
	else if constexpr (is_same_v <T, uint32_t>)
	{
		data.reserve(32);
		for (size_t i = 31; i >= 0; i--)
		{
			data.push_back((message & (1U << i)) != 0);
		}
	}
	else if constexpr (is_same_v<T, float> || is_same_v<T, double>)
	{
		const bitset<sizeof(T) * 8> bits(*reinterpret_cast<const uint64_t*>(&message));
		for (size_t i = 0; i < sizeof(T) * 8; i++)
		{
			data.push_back(bits[i]);
		}
	}
	else if constexpr (is_same_v<T, bool>)
	{
		data.push_back(message);
	}
	else
	{
		cout << "please input proper variable" << endl;
	}

	vector<bool> transmitMessageAppended;
	transmitMessageAppended.reserve(transmitMessage.size() + data.size());
	transmitMessageAppended.insert(transmitMessageAppended.end(), transmitMessage.begin(), transmitMessage.end());
	transmitMessageAppended.insert(transmitMessageAppended.end(), data.begin(), data.end());

	return transmitMessageAppended;
}