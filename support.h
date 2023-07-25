#ifndef SUPPORT_H
#define SUPPORT_H

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <bitset>

using std::cout;
using std::endl;
using std::string;
using std::pow;
using std::stoi;
using std::vector;
using std::is_same_v;
using std::bitset;

float bin2float(const string& binary);

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

#endif