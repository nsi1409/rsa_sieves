#include <iostream>
#include <gmpxx.h>
#include <tuple>

struct IncPair {
	mpz_class val;
	mpz_class inc;
};

mpz_class psuMod(mpz_class inpt, mpz_class n) {
	if(inpt >= n) {
		return inpt - n;
	}
	return inpt;
}

/*std::tuple<mpz_class, mpz_class> increment(std::tuple<mpz_class, mpz_class> cur, mpz_class n) {
	mpz_class val, inc;
	std::tie(val, inc) = cur;
	inc += 2;
	//cur.inc = psuMod(cur.inc, n);
	if(inc >= n) {
		inc -= n;
	}
	//cur.val = psuMod(cur.val, n);
	if(val >= n) {
		val -= n;
	}
	return std::make_tuple(val, inc);
}*/

int main() {
	mpz_class val, inc;
	val = 1;
	inc = 1;
	int n = 643;
	for(int i = 1; i < 100; i++) {
		std::cout << "fast: " << val << " naive: " << (i * i) % n << "\n";
		inc += 2;
		if(inc >= n) {
			inc -= n;
		}
		val += inc;	
		if(val >= n) {
			val -= n;
		}
	}
}


