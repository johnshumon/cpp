/**
 *
 * Recruitment test: binomial-coefficient.cpp
 * Created on: Apr 10, 2015
 * Author: Abu SHumon
 *
 * This test is implemented in JavaScript, but if you wish, you can implement the same functionality with another language.
 * If your code requires compiling, please, add compiling instructions in the comments.
 */

/**
 * TASK 1: IMPLEMENT: C - binomial coefficient
 *
 * C(n,k) = n! / [ k! (n - k)! ]
 * Where x! is the factorial of x
 *
 * Use a recursive solution. If needed, you can implement helper functions.
 */

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <cstddef>
#include <ctype.h>
#include <stdlib.h>
#include <typeinfo>

template <typename TYPE>
int C(TYPE &n, TYPE &k);

template <>
int C<std::string>(std::string &n, std::string &k);

template <typename TYPE>
bool parametersChecking(TYPE &n, TYPE &k);

bool validInteger(int n, int k);

int claculateBC(int n, int k);

int eachValuesFactorial(int eachVal);

void test1(int);
void test2(int);
void test3_string(int);
void test4_float(int);
void test5_negativeVal(int);
void test6_normalVal(int);
void test7_porperVal(int);
void printStatus(int, int);


int main(){

	test1(1);
	test2(2);
	test3_string(3);
	test4_float(4);
	test5_negativeVal(5);
	test6_normalVal(6);
	test7_porperVal(7);

	return 0;
}

// Function to calculate bionomial coefficient.
template <typename TYPE>
int C(TYPE &n, TYPE &k) {

	if (!parametersChecking(n, k)) {
        return false;
    }
	else{
		return claculateBC(n,k);
	}

}

// specialized Function for string parameters.
template <>
int C<std::string>(std::string &n, std::string &k) {

	int i_n = atoi(n.c_str());
    int i_k = atoi(k.c_str());

    // validate as needed...
    return C(i_n, i_k);
}

// Function checks if the given parameters are valid for calculating bionomial coefficient.
template <typename TYPE>
bool parametersChecking(TYPE &n, TYPE &k) {

	TYPE *nPtr = &n;
	TYPE *kPtr = &k;
    int typeCheckInt = 0;

    if(typeid(*nPtr).name() == typeid(typeCheckInt).name() &&
    		typeid(*kPtr).name() == typeid(typeCheckInt).name()){

    	// If given parameters integer, then these integers are checked for validity
    	// if they qualify to calculate binomial coefficient
    	if (validInteger(n,k)){
    		return true;
    	}
    	else{
    		return false;
    	}

    }
    else {
    		return false;
    }

    return false;
}

// Checking if the integers are valid, i.e. positive and k<n. Because negative integers are not allowed.
//template <typename TYPE>
bool validInteger(int n, int k){

	if (n < 0 || k < 0) {
		return false;
	}
	else if (k > n) {
		return false;
	}

	return true;
}

int claculateBC(int n, int k){

	int bionomial_coefficient = 1;

	if (n == k || k == 0) {
		return 1;
	}

	int nMinusK = n - k;

	// Calling the eachValuesFactorial returns the factorail value of each parameter n, k, and nMinusK.
	// Parameters are separated to make the equation simpler.
	n = eachValuesFactorial(n);
	k = eachValuesFactorial(k);
	nMinusK = eachValuesFactorial(nMinusK);

	bionomial_coefficient = n / (k * nMinusK);

	// Returning the result of the right side of the equation i.e. bionomial coefficient of the given n,k.
	return bionomial_coefficient;
}

// Function returns the factorial value for each parameter on the right side
// of the given equation of bionomial coefficient. Function is being called
// recursively to get the final value.
int eachValuesFactorial(int eachVal) {

    if (eachVal == 1) {
        return eachVal;
    }
    else{
        eachVal *= eachValuesFactorial(eachVal-1);
    }
    return eachVal;
}

void test1(int testNo) {
	int n = 7, k = 6;
	int pass = C(n,k);
	printStatus(pass, testNo-1);
}

void test2(int testNo) {
	int n = 9, k = 1;
	int pass = C(n,k);
	printStatus(pass, testNo-1);
}

void test3_string(int testNo) {

	std::string n = "john", k = "doe";
	int pass = C(n, k);
	printStatus(pass, testNo-1);
}

void test4_float(int testNo) {
	float n = 7.3, k = 3;
	int pass = C(n,k);
	printStatus(pass, testNo-1);
}

void test5_negativeVal(int testNo) {
	float n = 7, k = -5;
	int pass = C(n,k);
	printStatus(pass, testNo-1);
}

void test6_normalVal(int testNo) {
	float n = 2, k = 8;
	int pass = C(n,k);
	printStatus(pass, testNo-1);
}

void test7_porperVal(int testNo) {
	int n = 8, k = 2;
	int pass = C(n,k);
	printStatus(pass, testNo-1);
}

void printStatus(int pass, int testId){
	std::string testCases[] = {"test1", "test2", "test3_string", "test4_float",
			"test5_negativeVal", "test6_normalVal", "test7_porperVal"};

	if (pass >= 0){
		std::cout << "Passed: " << testCases[testId] << " " << pass << std::endl;
	}
	else{
		std::cout << "Failed: " << testCases[testId] << " Message: Expected to return n for k = 1";
	}
}
