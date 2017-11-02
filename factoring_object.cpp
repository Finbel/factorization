#include <vector>
#include <stack>
#include <string>
#include <gmp.h>
#include <iostream>
#include "factoring_object.h"

factoring_object::factoring_object(std::string n) {
	const char * mycharp = n.c_str();

	mpz_init (N);
	mpz_set_str (N, mycharp, 10);
}

//void factoring_object::g(mpz_t & x){
//	mpz_pow_ui(x, x, 2);
//	mpz_add_ui(x,x,1);
// 	mpz_mod (x, x, N);
//}


std::vector<std::string> factoring_object::pollard(){

	std::string tmp;	
	std::string tmp2;
	
	mpz_t x;
	mpz_init (x);

	mpz_t x2;
	mpz_init (x2);

	const char * ccp; 

	std::stack<std::string> to_check;
	std::vector<std::string> prime;
	std::vector<std::string> ret;

	// to string
	char * n = {};
	n = mpz_get_str(NULL,10,N);
	std::string n2(n);

	std::cout << mpz_probab_prime_p (N, 20) << std::endl;

	if(mpz_probab_prime_p (N, 20) == 0){
		to_check.push(n2);
	} else{
		prime.push_back(n2);
	}

	while( to_check.size() != 0 ){

		//pop
		tmp = to_check.top();
		to_check.pop();

		// to mpz
		ccp = tmp.c_str();
		mpz_init_set_str (x,ccp,10);

		// pollard
		tmp2 = pollard_inner(x);

		// to mpz
		ccp = tmp2.c_str();
		mpz_init_set_str (x2,ccp,10);

		// divide
		mpz_divexact (x, x, x2);

		// check prime 1
		if(mpz_probab_prime_p (x, 20) == 0){
			//to string
			n = mpz_get_str(NULL,10,x);
			n2 = n;			
			to_check.push(n2);
		} else{
			//to string
			n = mpz_get_str(NULL,10,x);
			n2 = n;
			prime.push_back(n2);
		}

		// check prime 2
		if(mpz_probab_prime_p (x2, 20) == 0){
			//to string
			n = mpz_get_str(NULL,10,x2);
			n2 = n;
			to_check.push(n2);
		} else{
			//to string
			n = mpz_get_str(NULL,10,x2);
			n2 = n;
			prime.push_back(n2);
		}

	}
	return prime;
}


std::string factoring_object::pollard_inner(mpz_t n){
	// implement pollard!
	int i = 0;
	// x = 2
	mpz_t x;
	mpz_init (x);
	mpz_init_set_str (x,"2",10);
	// y = 2
	mpz_t y;
	mpz_init (y);
	mpz_init_set_str (y,"2",10);
	// d = 1
	mpz_t d;
	mpz_init (d);
	mpz_init_set_str (d,"1",10);

	// tmp
	mpz_t tmp;
	mpz_init (tmp);
	mpz_init_set_str (tmp,"1",10);
	while ( mpz_cmp_ui(d,1) == 0 ){	
		std::cout << mpz_cmp_ui(d,1) << std::endl;
//		g(x);
		mpz_pow_ui(x, x, 2);
		mpz_add_ui(x,x,1);
	 	mpz_mod (x, x, n);

//		g(y);
		mpz_pow_ui(y, y, 2);
		mpz_add_ui(y,y,1);
	 	mpz_mod(y,y, n);
//		g(y);
		mpz_pow_ui(y, y, 2);
		mpz_add_ui(y,y,1);
	 	mpz_mod(y,y, n);	
		

		mpz_sub(tmp, x, y);
		mpz_abs(tmp, tmp);
		mpz_gcd(d, tmp, n);

		gmp_printf ("tmp = %Zd\n", tmp);
		gmp_printf ("x = %Zd\n", x);
		gmp_printf ("y = %Zd\n", y);
		gmp_printf ("d = %Zd\n", d);
		gmp_printf ("n = %Zd\n", n);
		std::cout << std::endl;
		std::cout << "i = "<< i << std::endl;
		i++;
		if(i>10){
			break;			
		}
		std::cout << "*********" << std::endl;
	}
	char * ret = {};

	if (mpz_cmp(d,n)==0){
		ret = mpz_get_str(NULL,10,n);
	}
	else {
		ret = mpz_get_str(NULL,10,d);
	}	
	std::string str(ret);

	return str;
}


