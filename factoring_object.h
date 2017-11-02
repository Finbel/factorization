#include <gmp.h>
#include <string>
#include <vector>

class factoring_object{
private:
    mpz_t N;
	void g(mpz_t & x);
public:
    factoring_object(std::string n);
	std::string pollard_inner(mpz_t n);
	std::vector<std::string> pollard();
};
