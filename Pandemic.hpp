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

	// variable representing the total of people and days
	int tot_;
	int tot_day_;

	// probability of contagion and healing
	double beta_;
	double gamma_;

public:
	// class constructor declaration
	Pandemic(int sus, int inf, int rem, int day, double beta, double gamma);

	// evolve function declaration
	void evolve();

	// getter of the number of susceptible at the i-th day
	int get_sus(int i) const;

	// getter of the number of susceptible at the i-th day
	int get_inf(int i) const;

	// getter of the number of susceptible at the i-th day
	int get_rem(int i) const;
};

#endif