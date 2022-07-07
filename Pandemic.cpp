#include "Pandemic.hpp"

#include <vector>
#include <cassert>
#include <cmath>
#include <iostream>


Pandemic::Pandemic(int sus, int inf, int rem, int day, double beta, double gamma) : history{Data{sus, inf, rem}}, tot_{sus+inf+rem}, tot_day_{day}, beta_{beta}, gamma_ {gamma} { 
	assert(sus > 0 && inf > 0 && rem > 0 && tot_day_ > 0);
	assert(beta >= 0 && beta <= 1);
	assert(gamma >= 0 && gamma <= 1);
}


void Pandemic::evolve() {
	auto last = history.end();
	--last;

	int prev_s = static_cast<double>((*last).sus_);
	int prev_i = static_cast<double>((*last).inf_);
	int prev_r = static_cast<double>((*last).rem_);

	double BSN = beta_*prev_s*prev_i/tot_;
	double GI = gamma_*prev_i;

	double d_next_s = prev_s - BSN; 
	double d_next_i = prev_i + BSN - GI;
	double d_next_r = prev_r + GI;

	int next_s = static_cast<int>(std::round(d_next_s));
	int next_i = static_cast<int>(std::round(d_next_i));
	int next_r = static_cast<int>(std::round(d_next_r));

	int diff = (next_s + next_i + next_r) - tot_;

	if(next_s >= next_i && next_s >= next_r) {
		next_s -= diff; 
	} else if (next_i > next_s && next_i >= next_r) {
		next_i -= diff;
	} else {
		next_r -= diff;
	}

	history.push_back(Data{next_s, next_i, next_r});
}

int Pandemic::get_sus(int i) const {
	assert(i < static_cast<int>(history.size()));
	return history[i].sus_;
}

int Pandemic::get_inf(int i) const {
	assert(i < static_cast<int>(history.size()));
	return history[i].inf_;
}

int Pandemic::get_rem(int i) const {
	assert(i < static_cast<int>(history.size()));
	return history[i].rem_;
}