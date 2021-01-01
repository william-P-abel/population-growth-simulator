#include <iostream>
#include <stdlib.h>
#include <vector>
#include <prototypes.h>

class human {
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

	void setAge(double inputAge) {
		age = inputAge;
	}

	int getAliveState() {
		return aliveState;
	}

	void setAliveState(int inputAliveState) {
		aliveState = inputAliveState;
	}
};

class male :public human {

public:

	male(long long int inputId, double inputAge) {
		setAliveState(1);
		setAge(inputAge);
		setId(inputId);
	}

	~male();
};

class female :public human {
	double fertilityFactor;

public:
	double getFertilityFactor() {
		return fertilityFactor;
	}

	double setFertilityFactor(double inputFertilityFactor) {
		fertilityFactor = inputFertilityFactor;
	}

	female(long long int inputId, double inputAge, double inputFertilityFactor) {
		setAliveState(1);
		setAge(inputAge);
		setId(inputId);
		setFertilityFactor(inputFertilityFactor);
	}

	~female();
};

void makePerson(std::vector<male>& malePop, std::vector<female>& femalePop, long long int newId, double newAge, double newFertilityRate) {
	int sexDecider = rand() % 10;
	if (sexDecider < 5) {
		femalePop.push_back(female(newId, newAge, newFertilityRate));
	}
	else {
		malePop.push_back(male(newId, newAge));
	}
}

void passYear(std::vector<male>& malePop, std::vector<female>& femalePop, double maleMortalityAge, double femaleMortalityAge) {

	for (int i = 0; i < femalePop.size(); i++) { //new births
		if (femalePop[i].getAge < 45) {
			double likelyhoodOfKid = ((femalePop[i].getFertilityFactor / 32) * 100); //yearly average percent chance of having a kid
			double randomSeed = rand() % 100 + 1;
			if (randomSeed < likelyHoodOfKid) {
				int newId = femalePop.size() + malePop.size() + 1;
				makeperson(newId, 0, femalePop[i].fertilityFactor);
			}
		}
	}

	for (int i = 0; i < femalePop.size(); i++) { //female deaths will implement more realistic death disribution logic later
		if (femalePop[i].age >= femaleMortalityAge) {
			femalePop.erase(femalePop.begin() + i);
		}
	}

	for (int i = 0; i < malePop.size(); i++) { //male deaths will implement more realistic death disribution logic later	
		if (malePop[i].age >= maleMortalityAge) {
			malePop.erase(malePop.begin() + i);
		}
	}

}

void displayOutput (vector<male>& malePop, vector<female>& femalePop) {
	std::cout << "total number of people" << femalePop.size() + malePop.size() << endl;
	std::cout << "total number of males" << malePop.size() << endl;
	std::cout << "total number of females" << femalePop.size() << endl;
}