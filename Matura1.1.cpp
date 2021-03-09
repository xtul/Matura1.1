#include <iostream>
#include <fstream>
#include <vector>
#include "Matura.h"
using namespace std;

int main() {
	ifstream pairs{ "pary.txt" };

	int integer; string text;
	while (pairs >> integer >> text) {
		// filter odd integers
		if (integer % 2 != 0) {
			continue;
		}

		// primes up until integer
		auto primes = generate_primes(integer);

		// two prime numbers that can be used to construct this integer (Goldbach's conjecture)
		auto components_of_sum{ find_prime_pair_to_sum(primes, integer) };

		println(to_string(integer) + " " + to_string(components_of_sum[0]) + " " + to_string(components_of_sum[1]));
	}

	pairs.close();

	auto _{ getchar() };
}

void println(string str) {
	std::cout << str << std::endl;
}

// Generate primes up until n.
vector<int> generate_primes(int n) {
	vector<int> result;
	for (int i{ 2 }; i < n; i++) {
		if (is_prime(i)) {
			result.push_back(i);
		}
	}
	return result;
}

// Returns a vector of two prime numbers that can be used to construct expectedInt.
vector<int> find_prime_pair_to_sum(vector<int> primes, int expectedInt) {
	vector<int> result;
	int a{};
	int b{};

	for (int x : primes) {
		// if (expectedInt - x) can be found in prime list it's a component of sum for expectedInt
		bool primeExists{ find(primes.begin(), primes.end(), expectedInt - x) != primes.end() };

		if (primeExists) {
			a = expectedInt - x;
			b = x;
			break;
		}
	}

	result.push_back(a);
	result.push_back(b);

	return result;
}

// Tests whether n is a prime integer.
bool is_prime(int n) {
	// 0 and 1 are not prime numbers, we can skip them outright
	if (n == 0 || n == 1) return false;

	// Try all numbers in range from 2 to n / 2
	// We could try all numbers in range from 2 to n - 1, but we can
	// skip numbers over n / 2 because they will always produce a remainder
	for (int i{ 2 }; i <= n / 2; i++) {
		// If there's a number in range that results in 0 (no remainder)...
		if (n % i == 0) {
			// it isn't a prime number, no need to search further
			return false;
		}
	}

	// since no divisible number was found, it's a prime number
	return true;
}
