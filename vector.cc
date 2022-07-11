#include <iostream>
#include <gmpxx.h>
#include <algorithm>
#include <array>
#include <math.h>

struct Map {
	mpz_class key;
	mpz_class val;
};

mpz_class none(mpz_class i, mpz_class j, mpz_class pair, mpz_class n) {
	return ((i * j) - pair) % n;
}

mpz_class binary(Map v[], mpz_class To_Find, int size) {
	int lo = 0, hi = size - 1;
	int mid;
	// This below check covers all cases , so need to check
	// for mid=lo-(hi-lo)/2
	while (hi - lo > 1) {
		mid = (hi + lo) / 2;
		if (v[mid].key < To_Find) {
			lo = mid + 1;
		}
		else {
			hi = mid;
		}
	}
	if (v[lo].key == To_Find) {
		//cout << "Found"
		//	 << " At Index " << lo << endl;
		return v[lo].val;
	}
	else if (v[hi].key == To_Find) {
		//cout << "Found"
		//	 << " At Index " << hi << endl;
		return v[hi].val;
	}
	else {
		//cout << "Not Found" << endl;
		return -1;
	}
}

mpz_class main_loop(mpz_class n, int map_size, int cong_max) {
	/*mpz_class n = 991642963123;
	//mpz_class n = 1140592783;
	mpz_class p = 491423;
	mpz_class f = 2017901;
	int map_size = 100000;*/
	mpz_class lowest = n;
	Map arr[map_size];
	mpz_class run_i = 1;
	mpz_class run_val = 1;
	for(int i = 0; i < map_size; i++) {
		arr[i].key = run_i;
		arr[i].val = run_val;
		run_i++;
		run_val = (run_i * run_i) % n;
	}

	//for(int i = 0; i < map_size; i++) {
	//	std::cout << "key: " << arr[i].key << " val: " << arr[i].val << "\n";
	//}	

	Map sort_arr[map_size];
	int move = 0;
	mpz_class move_min = NULL;
	for(int i = 0; i < map_size; i++) {
		for(int j = 0; j < map_size; j++) {
			if(arr[j].key != -1) {
				if(move_min == NULL) {
					move = j;
					move_min = arr[move].val;
				} else if(arr[j].val < move_min) {
					move = j;
					move_min = arr[move].val;
				}
			}
		}
		sort_arr[i].key = arr[move].val;
		sort_arr[i].val = arr[move].key;
		arr[move].key = -1;
		move_min = NULL;
	}

	//std::cout << "break\n";

	//for(int i = 0; i < map_size; i++) {
	//	std::cout << "key: " << sort_arr[i].key << " val: " << sort_arr[i].val << "\n";
	//}	

	std::cout << "\n######################### Start Search n: " << n << " ############################\n\n";

	int congruent = 0;
	for(mpz_class i = 1; i < n / 4; i++) {
		mpz_class cur = (i * i) % n;
		mpz_class match = binary(sort_arr, cur, map_size);
		mpz_class n1 = none(i, match, cur, n);
		if(match != -1 && n1 != 0) {
			//std::cout << "val: " << cur << " naive index: " << i << " matching_index: " << match << " n: " << n << " n1: " << n1 << "\n";
			congruent++;

/*} else*/  if(n1 < lowest) {
				lowest = n1;
				std::cout << "New Lowest: " << lowest << " congruent: " << congruent << "\n";
			}	
			if(congruent >= cong_max) {
				std::cout << "\nmax congruent break\n\n";
				break;
			}

		}
	}

	std::cout << "low: " << lowest << "\n";
	return lowest;

}

int main() {
	char ns[] = "696605725810661";
	mpz_t find_init;
	mpz_inits(find_init, NULL);
	mpz_set_str(find_init, ns, 10);
	mpz_class find = mpz_class(find_init);
	mpz_class n = find;
	int map_size = 80000;
	int found_size = 64;
	mpz_class found[found_size];
	int i = 0;
	int cong_max = 1;

	std::cout << "\nfind = " << find << "\n";

	while(n > 100000) {
		found[i] = n;
		n = main_loop(n, map_size, cong_max);
		i++;
		cong_max *= 8;
		//map_size /= 10;
	}
	found[i] = n;
	std::cout << "&&&&&&&&&&&&&&&&&&   final   &&&&&&&&&&&&&&&&&&&&&\n";
	for(int j = 0; j <= i; j++) {
		std::cout << "start: " << find << " found[" << j << "]: " << found[j] << "\n";
	}

}

	


