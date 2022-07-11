all:
	g++ big.cc -lgmpxx -lgmp -o big
	g++ vector.cc -lgmpxx -lgmp -o vector
	g++ inc.cc -lgmpxx -lgmp -o inc
	g++ tfast.cc -g -lgmpxx -lgmp -o tfast


