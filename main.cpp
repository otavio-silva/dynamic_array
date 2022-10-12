#include "dynamic_array.hpp"
#include <iostream>
#include <string>

std::string random_string(std::size_t length)
{
	std::string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	std::string result = "";
	int p = 0;
	while (result.length() < length)
	{
		p = std::rand() % str.length();
		result += str[p];
	}
	return result;
}

int main([[maybe_unused]]int argc, [[maybe_unused]]char **argv)
{
	auto t = dynamic_array<float>(8);
	t[1] = 9;
	for (auto& item : t)
	{
		std::cout << item << std::endl;
	}
	auto ss = dynamic_array<std::string>(8);
	for (auto& s : ss)
	{
		s = random_string(8);
	}
	for (auto& item : ss)
	{
		std::cout << item << std::endl;
	}
}