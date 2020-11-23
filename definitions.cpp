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

void passYear(vector<male> &malePop, vector<female> &femalePop) {

	for (int i = 0; i < femalePop.size(); i++) { //new births
		if (femalePop[i].age < 45) {
			double likelyhoodOfKid = ((femalePop[i].fertilityfactor / 32) * 100); //yearly average percent chance of having a kid
			double randomSeed = rand() % 100 + 1;
			if (randomSeed < likelyHoodOfKid) {
				int newId = femalePop.size() + malePop.size() + 1;
				makeperson(newId, 0, femalePop[i].fertilityFactor);
			}
		}
	}

	for (int i = 0; i < femalePop.size(); i++) { //female deaths

	}

	for (int i = 0; i < femalePop.size(); i++) { //male deaths	
	
	}

}

void displayOutput (vector<male>& malePop, vector<female>& femalePop) {
}