#ifndef PANDEMIC_HPP
#define PANDEMIC_HPP

#include <vector>

struct Data {
	int sus_;
	int inf_;
	int rem_;
};

class Pandemic{
	// vector keeping the history of the pandemic
	std::vector<Data> history;

	// variable representig the total number of person
	int tot_;

	// probability of contagion and healing
	double beta_;
	double gamma_;

	// variable representing the period of simulation in days
	int tot_day_;

public:
	// class constructor declaration
	Pandemic(int sus, int inf, int rem, double beta, double gamma, int day);

	// evolve function declaration
	void evolve();

	// getter of the number of susceptible at the i-th day
	int get_sus(int i) const;

	// getter of the number of susceptible at the i-th day
	int get_inf(int i) const;

	// getter of the number of susceptible at the i-th day
	int get_rem(int i) const;

	// getter for beta and gamma
	double get_beta() const {return beta_;}
	double get_gamma() const {return gamma_;}
};

#endif