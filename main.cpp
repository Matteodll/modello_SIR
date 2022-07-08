#include "Pandemic.hpp"

#include <exception>
#include <iostream>

int main() {
  int n_sus;
  int n_inf;
  int n_rem;

  double beta;
  double gamma;

  int tot_day;

  try {
    std::cout << "Number of susceptible: ";
    std::cin >> n_sus;
    if (!std::cin || n_sus <= 0) throw std::runtime_error{"Invalid number"};

    std::cout << "Number of infected: ";
    std::cin >> n_inf;
    if (!std::cin || n_inf < 0) throw std::runtime_error{"Invalid number"};

    std::cout << "Number of removed: ";
    std::cin >> n_rem;
    if (!std::cin || n_rem < 0) throw std::runtime_error{"Invalid number"};

    std::cout << "Probability of infection [0,1]: ";
    std::cin >> beta;
    if (!std::cin || beta < 0 || beta > 1)
      throw std::runtime_error{"Invalid probability"};

    std::cout << "Probability of healing [0,1]: ";
    std::cin >> gamma;
    if (!std::cin || gamma < 0 || gamma > 1)
      throw std::runtime_error{"Invalid probability"};

    std::cout << "Period of simulation [days]: ";
    std::cin >> tot_day;
    if (!std::cin || tot_day <= 0) throw std::runtime_error{"Invalid period"};

  Pandemic p(n_sus, n_inf, n_rem, beta, gamma, tot_day);

  p.evolve();

  p.print_history();

  p.draw();

  } catch (std::runtime_error const& error) {
    std::cerr << error.what() << '\n';
    return 1;
  }
  
  return 0;
}