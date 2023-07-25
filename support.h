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
vector<bool> packetizeTemp(const vector<bool>& transmitMessage, const T& message);

#endif