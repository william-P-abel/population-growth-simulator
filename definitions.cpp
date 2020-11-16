#include <iostream>
#include <stdlib.h>
#include <prototypes.h>

class human() {
	int aliveState;
	double age;
	long long int id;

	public:
		long long int getId() {
			return id;
		}

		void setId(long long int inputId) {
			id = inputId;
		}
		
		double getAge() {
			return id;
		}

		void setage(double inputAge) {
			age = inputAge;
		}

		int getAliveState() {
			return aliveState;
		}

		void setAliveState(int inputAliveState) {
			aliveState = inputAliveState;
		}
}

class male:public human() {

	public:

		male(long long int inputId, double inputAge) {
			aliveState = 1;
			age = inputAge;
			id = inputId;
		}

		~male();
}

class female:public human() {
	double fertilityFactor;

	public:
		double getFertilityFactor() {
			return fertilityFactor;
		}

		double setFertilityFactor(double inputFertilityFactor) {
			fertilityFactor = inputFertilityFactor;
		}

		female(long long int inputId, double inputAge, double inputFertilityFactor) {
			aliveState = 1;
			age = inputAge;
			id = inputId;
			fertilityFactor = inputFertilityFactor;
		}

		~female();
};

void makePerson(long long int newId, double newAge, double newFertilityRate) {
	int sexDecider = rand() % 10;
	if (sexDecider < 5) {
		femalePop.pushback(female(newId, newAge, newFertilityRate));
	}
	else {
		malePop.pushback(male(newId, newAge));
	}
}

void passYear(int) {

}