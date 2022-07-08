#include "Pandemic.hpp"

#include <algorithm>
#include <cassert>
#include <cmath>
#include <exception>
#include <iomanip>
#include <iostream>
#include <vector>

// Pandemic constructor
Pandemic::Pandemic(int sus, int inf, int rem, double beta, double gamma,
                   int day)
    : history{Data{sus, inf, rem}},
      tot_{sus + inf + rem},
      beta_{beta},
      gamma_{gamma},
      tot_day_{day} {
  assert(sus > 0 && inf >= 0 && rem >= 0 && tot_day_ > 0);
  assert(beta >= 0 && beta <= 1);
  assert(gamma >= 0 && gamma <= 1);
}

// function that performs the simulation
void Pandemic::evolve() {
  for (int i = 0; i < tot_day_; ++i) {
    auto last = history.end();
    --last;

    int prev_s = static_cast<double>((*last).sus_);
    int prev_i = static_cast<double>((*last).inf_);
    int prev_r = static_cast<double>((*last).rem_);

    double BSN = beta_ * prev_s * prev_i / tot_;
    double GI = gamma_ * prev_i;

    double d_next_s = prev_s - BSN;
    double d_next_i = prev_i + BSN - GI;
    double d_next_r = prev_r + GI;

    int next_s = static_cast<int>(std::round(d_next_s));
    int next_i = static_cast<int>(std::round(d_next_i));
    int next_r = static_cast<int>(std::round(d_next_r));

    int diff = (next_s + next_i + next_r) - tot_;

    if (next_s >= next_i && next_s >= next_r) {
      next_s -= diff;
    } else if (next_i > next_s && next_i >= next_r) {
      next_i -= diff;
    } else {
      next_r -= diff;
    }

    history.push_back(Data{next_s, next_i, next_r});
  }
}

// getter of the number of susceptible at the i-th day
int Pandemic::get_sus(int i) const {
  assert(i < static_cast<int>(history.size()));
  return history[i].sus_;
}

// getter of the number of infected at the i-th day
int Pandemic::get_inf(int i) const {
  assert(i < static_cast<int>(history.size()));
  return history[i].inf_;
}

// getter of the number of removed at the i-th day
int Pandemic::get_rem(int i) const {
  assert(i < static_cast<int>(history.size()));
  return history[i].rem_;
}

// method to print on standard output the results
void Pandemic::print_history() const {
  std::cout << "\033c";
  std::cout << "\nResult of the simulation:\n\n";
  std::cout << std::setw(6) << "day" << '\t' << std::setw(11) << "susceptible"
            << '\t' << std::setw(11) << "infected" << '\t' << std::setw(11)
            << "removed"
            << "\n\n";

  for (int i = 0; i <= tot_day_; ++i) {
    std::cout << std::setw(6) << i << '\t' << std::setw(11) << this->get_sus(i)
              << '\t' << std::setw(11) << this->get_inf(i) << '\t'
              << std::setw(11) << this->get_rem(i) << '\n';
  }

  std::cout << "\n\n";
}

// free function that takes two vectors and print a graph on standard output
void draw_h(std::vector<int> v, std::vector<int> day) {
  assert(v.size() != 0 && day.size() != 0);
  if (v.size() != day.size())
    throw std::runtime_error("different dimension of vectors");
  double max = static_cast<double>(*std::max_element(v.begin(), v.end()));

  double lines = 30.;
  double delta = max / lines;

  for (int i = 0; i < lines; ++i) {
    std::cout << std::setw(8) << std::setprecision(3)
              << (max - static_cast<double>(i) * delta);
    for (int j = 0; j < static_cast<int>(v.size()); ++j) {
      if (static_cast<double>(v[j]) >= (max - static_cast<double>(i) * delta))
        std::cout << std::setw(3) << "*";
      else
        std::cout << std::setw(3) << ' ';
    }
    std::cout << '\n';
  }

  std::cout << "day:    ";
  for (auto it = day.begin(), last = day.end(); it != last; ++it) {
    std::cout << std::setw(3) << *it;
  }

  std::cout << "\n\n\n";
}

// method to draw the result on standard output
void Pandemic::draw() const {
  int dim = history.size();
  if (dim > 101) throw std::runtime_error("period too long to be represented");

  std::vector<int> v_sus;
  std::vector<int> v_inf;
  std::vector<int> v_rem;
  std::vector<int> v_day;

  if (dim <= 50) {
    for (int i = 0; i < dim; ++i) {
      v_sus.push_back(this->get_sus(i));
      v_inf.push_back(this->get_inf(i));
      v_rem.push_back(this->get_rem(i));
      v_day.push_back(i);
    }
  } else {
    for (int i = 0; i < dim; ++i) {
      v_sus.push_back(this->get_sus(i));
      v_inf.push_back(this->get_inf(i));
      v_rem.push_back(this->get_rem(i));
      v_day.push_back(i);
      ++i;
    }
  }

  std::cout << "Number of susceptible in the period of the simulation:\n\n";
  draw_h(v_sus, v_day);

  std::cout << "Number of infected in the period of the simulation:\n\n";
  draw_h(v_inf, v_day);

  std::cout << "Number of removed in the period of the simulation:\n\n";
  draw_h(v_rem, v_day);
}