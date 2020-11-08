#include <iostream>
#include <stdlib.h>

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
	double maleLifeSpan;

	public:
		double getMaleLifeSpan(){
			return maleLifeSpan;
		}

		double setMaleLifeSpan(double inputLifeSpan) {
			maleLifeSpan = inputLifeSpan;
		}

		male(double inputAge, long long int inputId, double inputLifeSpan) {
			age = inputAge;
			id = inputId;
			maleLifeSpan = inputLifespan;
		}

		~male();
}

class female:public human() {
	double femaleLifeSpan;
	double fertilityFactor;

	public:
		double getFemaleLifeSpan() {
			return femaleLifeSpan;
		}

		double setFemaleLifeSpan(double inputLifeSpan) {
			femaleLifeSpan = inputLifeSpan;
		}

		double getFertilityFactor() {
			return fertilityFactor;
		}

		double setFertilityFactor(double inputFertilityFactor) {
			fertilityFactor = inputFertilityFactor;
		}

		female(double inputAge, long long int inputId, double inputLifeSpan, double inputFertilityFactor) {
			age = inputAge;
			id = inputId;
			femaleLifeSpan = inputLifespan;
			fertilityFactor = inputFertilityFactor;
		}

		~female();
};

void makePerson(double newAge) {
	int sexDecider = rand() % 10;
	if (sexDecider < 5) {
		return new female(newAge, );
	}
	else {
		return new male(newAge,)
	}
}

void passYear(int popArray) {

}