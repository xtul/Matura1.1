#pragma once
#include <string>

void println(std::string str);
bool is_prime(int n);
std::vector<int> generate_primes(int n);
std::vector<int> find_prime_pair_to_sum(std::vector<int> primes, int expectedInt);
