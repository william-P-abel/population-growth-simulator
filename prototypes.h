#include <iostream>
#include <vector>
#include <stdlib.h>


class human {
	double age;
	double id;

public:
	double getid();
	void setId(double);
	double getAge();
	void setAge(double);
};

class male :protected human {
public:
	male(long long int, double);
	~male();
};

class female :protected human {
	double fertilityFactor;

public:
	double getFertilityFactor();
	void setFertilityFactor(double);
	void haveChildren(double, double);
	female(long long int, double, double);
	~female();
};

void makePerson(std::vector, std::vector, long long int, double, double);

void passYear(std::vector, std::vector, double, double);

void displayOutput(std::vector, std::vector);