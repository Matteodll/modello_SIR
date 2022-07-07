#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "Pandemic.hpp"
#include "doctest.h"

TEST_CASE("Testing class Pandemic") {
	SUBCASE("Testing evolve and all the getters: predominace of susceptible") {
		Pandemic p(100, 5, 3, 0.3, 0.2, 20);

		CHECK(p.get_sus(0) == 100);
		CHECK(p.get_inf(0) == 5);
		CHECK(p.get_rem(0) == 3);

		p.evolve();
		CHECK(p.get_sus(1) == 99);
		CHECK(p.get_inf(1) == 5);
		CHECK(p.get_rem(1) == 4);

		p.evolve();
		CHECK(p.get_sus(2) == 98);
		CHECK(p.get_inf(2) == 5);
		CHECK(p.get_rem(2) == 5);

		p.evolve();
		CHECK(p.get_sus(3) == 97);
		CHECK(p.get_inf(3) == 5);
		CHECK(p.get_rem(3) == 6);

		p.evolve();
		CHECK(p.get_sus(4) == 96);
		CHECK(p.get_inf(4) == 5);
		CHECK(p.get_rem(4) == 7);
	}

	SUBCASE("Testing evolve and all the getters: predominace of Infected") {
		Pandemic p(20, 70, 30, 0.5, 0.3, 20);

		CHECK(p.get_sus(0) == 20);
		CHECK(p.get_inf(0) == 70);
		CHECK(p.get_rem(0) == 30);

		p.evolve();
		CHECK(p.get_sus(1) == 14);
		CHECK(p.get_inf(1) == 55);
		CHECK(p.get_rem(1) == 51);

		p.evolve();
		CHECK(p.get_sus(2) == 11);
		CHECK(p.get_inf(2) == 42);
		CHECK(p.get_rem(2) == 67);

		p.evolve();
		CHECK(p.get_sus(3) == 9);
		CHECK(p.get_inf(3) == 31);
		CHECK(p.get_rem(3) == 80);

		p.evolve();
		CHECK(p.get_sus(4) == 8);
		CHECK(p.get_inf(4) == 23);
		CHECK(p.get_rem(4) == 89);
	}

	SUBCASE("Testing evolve and all the getters: predominace of removed") {
		Pandemic p(20, 10, 50, 0.3, 0.5, 20);

		CHECK(p.get_sus(0) == 20);
		CHECK(p.get_inf(0) == 10);
		CHECK(p.get_rem(0) == 50);

		p.evolve();
		CHECK(p.get_sus(1) == 19);
		CHECK(p.get_inf(1) == 6);
		CHECK(p.get_rem(1) == 55);

		p.evolve();
		CHECK(p.get_sus(2) == 19);
		CHECK(p.get_inf(2) == 3);
		CHECK(p.get_rem(2) == 58);

		p.evolve();
		CHECK(p.get_sus(3) == 19);
		CHECK(p.get_inf(3) == 2);
		CHECK(p.get_rem(3) == 59);

		p.evolve();
		CHECK(p.get_sus(4) == 19);
		CHECK(p.get_inf(4) == 1);
		CHECK(p.get_rem(4) == 60);
	}

	SUBCASE("Testing evolve and all the getters: beta = 0") {
		Pandemic p(20, 10, 20, 0., 0.3, 20);

		CHECK(p.get_sus(0) == 20);
		CHECK(p.get_inf(0) == 10);
		CHECK(p.get_rem(0) == 20);

		p.evolve();
		CHECK(p.get_sus(1) == 20);
		CHECK(p.get_inf(1) == 7);
		CHECK(p.get_rem(1) == 23);

		p.evolve();
		CHECK(p.get_sus(2) == 20);
		CHECK(p.get_inf(2) == 5);
		CHECK(p.get_rem(2) == 25);

		p.evolve();
		CHECK(p.get_sus(3) == 20);
		CHECK(p.get_inf(3) == 4);
		CHECK(p.get_rem(3) == 26);

		p.evolve();
		CHECK(p.get_sus(4) == 20);
		CHECK(p.get_inf(4) == 3);
		CHECK(p.get_rem(4) == 27);

		p.evolve();
		CHECK(p.get_sus(5) == 20);
		CHECK(p.get_inf(5) == 2);
		CHECK(p.get_rem(5) == 28);

		p.evolve();
		CHECK(p.get_sus(6) == 20);
		CHECK(p.get_inf(6) == 1);
		CHECK(p.get_rem(6) == 29);
	}

	SUBCASE("Testing evolve and all the getters: gamma = 0") {
		Pandemic p(20, 50, 10, 0.3, 0., 20);

		CHECK(p.get_sus(0) == 20);
		CHECK(p.get_inf(0) == 50);
		CHECK(p.get_rem(0) == 10);

		p.evolve();
		CHECK(p.get_sus(1) == 16);
		CHECK(p.get_inf(1) == 54);
		CHECK(p.get_rem(1) == 10);

		p.evolve();
		CHECK(p.get_sus(2) == 13);
		CHECK(p.get_inf(2) == 57);
		CHECK(p.get_rem(2) == 10);

		p.evolve();
		CHECK(p.get_sus(3) == 10);
		CHECK(p.get_inf(3) == 60);
		CHECK(p.get_rem(3) == 10);

		p.evolve();
		CHECK(p.get_sus(4) == 8);
		CHECK(p.get_inf(4) == 62);
		CHECK(p.get_rem(4) == 10);
	}

	SUBCASE("Testing evolve and all the getters: beta = 1") {
		Pandemic p(50, 20, 10, 1., .3, 20);

		CHECK(p.get_sus(0) == 50);
		CHECK(p.get_inf(0) == 20);
		CHECK(p.get_rem(0) == 10);

		p.evolve();
		CHECK(p.get_sus(1) == 37);
		CHECK(p.get_inf(1) == 27);
		CHECK(p.get_rem(1) == 16);

		p.evolve();
		CHECK(p.get_sus(2) == 25);
		CHECK(p.get_inf(2) == 31);
		CHECK(p.get_rem(2) == 24);

		p.evolve();
		CHECK(p.get_sus(3) == 15);
		CHECK(p.get_inf(3) == 31);
		CHECK(p.get_rem(3) == 34);

		p.evolve();
		CHECK(p.get_sus(4) == 9);
		CHECK(p.get_inf(4) == 28);
		CHECK(p.get_rem(4) == 43);
	}

	SUBCASE("Testing evolve and all the getters: gamma = 1") {
		Pandemic p(20, 50, 10, .3, 1., 20);

		CHECK(p.get_sus(0) == 20);
		CHECK(p.get_inf(0) == 50);
		CHECK(p.get_rem(0) == 10);

		p.evolve();
		CHECK(p.get_sus(1) == 16);
		CHECK(p.get_inf(1) == 4);
		CHECK(p.get_rem(1) == 60);

		p.evolve();
		CHECK(p.get_sus(2) == 16);
		CHECK(p.get_inf(2) == 0);
		CHECK(p.get_rem(2) == 64);

		p.evolve();
		CHECK(p.get_sus(3) == 16);
		CHECK(p.get_inf(3) == 0);
		CHECK(p.get_rem(3) == 64);

		p.evolve();
		CHECK(p.get_sus(4) == 16);
		CHECK(p.get_inf(4) == 0);
		CHECK(p.get_rem(4) == 64);
	}

	SUBCASE("Testing evolve and all the getters: beta = 1 and gamma = 1") {
		Pandemic p(20, 50, 10, 1., 1., 20);

		CHECK(p.get_sus(0) == 20);
		CHECK(p.get_inf(0) == 50);
		CHECK(p.get_rem(0) == 10);

		p.evolve();
		CHECK(p.get_sus(1) == 8);
		CHECK(p.get_inf(1) == 13);
		CHECK(p.get_rem(1) == 59);

		p.evolve();
		CHECK(p.get_sus(2) == 7);
		CHECK(p.get_inf(2) == 1);
		CHECK(p.get_rem(2) == 72);

		p.evolve();
		CHECK(p.get_sus(3) == 7);
		CHECK(p.get_inf(3) == 0);
		CHECK(p.get_rem(3) == 73);

		p.evolve();
		CHECK(p.get_sus(4) == 7);
		CHECK(p.get_inf(4) == 0);
		CHECK(p.get_rem(4) == 73);
	}
}