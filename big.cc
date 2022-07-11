#include <iostream>
#include <gmpxx.h>

int main() {
	std::cout << "test\n";
	unsigned int max = -1;
	mpz_class i = 1;
	mpz_t j, t;
	mpz_inits(j, t, NULL);
	mpz_set_str(j, "5", 10);
	mpz_set_str(t, "10", 10);
	for(int k = 0; k < 100; k++) {	
		std::cout << "i value: " << i << " j value: " << j << " max value: " << max << "\n";
		i *= 10;
		mpz_mul(j, j, t);
	}
	return 0;
}


