#include <iostream>
#include <stdlib.h>
#include <definitions.h>

int main() {
	int totalPop = 0;
	int yearsToPass = 0;
	double averageFertility = 0;
	char ageDistribution = 'Z';
	double averageMortalityRate = 0;
	double maleMortalityConstant = 0;
	double femaleMortalityConstant = 0;

	//get user input
	std::cout << "thank you for using population change simulator please input your settings" << std::endl;
	std::cout << "input total popultion" << std::endl;
	std::cin >> totalPop;
	std::cout << "input average feritility rate" << std::endl;
	std::cin >> averageFertility;
	std::cout << "input number of years to run simulation" << std::endl;
	std::cin >> yearsToPass;
	std::cout << "input initial age distribution bracket: E: equal distribution P: pyramid distribution U: upside down pyramid distribution" << std::endl;
	std::cin >> ageDistribution;
	std::cout << "input average age of mortality, must be over 45" << std::endl;
	std::cin >> averageMortalityRate;
	std::cout << "input gender mortality discrepency for males (negative values indicate earlier death):" << std::endl;
	std::cin >> maleMortalityConstant;
	std::cout << "input gender mortality discrepency for females (negative values indicate earlier death):" << std::endl;
	std::cin >> femaleMortalityConstant;

	double maleMortalityRate = averageMortalityRate + maleMortalityConstant;
	double femaleMortalityRate = averageMortalityRate + femaleMortalityConstant;

	//two vectors are used to contain the population becuse male and female objects are diffrent sizes
	vector<male> malePop(0, male());    
	vector<female> femalePop(0, female());
	
	//input error handling
	if (totalPop < 1) {
		std::cout << "error 101, invalid population size. exiting program" << std::endl;
		return 101;
	}
	else if (averageMortalityRate <= 45) {
		std::cout << "error 102, invalid average mortality. exiting program" << std::endl;
		return 102;
	}
	else if ((ageDistribution == 'p') || (ageDistribution == 'P') || (ageDistribution == 'e') || (ageDistribution == 'E') || (ageDistribution == 'u') || (ageDistribution == 'U')) {
		std::cout << "error 103, invalid age distribution. exiting program" << std::endl;
		return 103;
	}

	for (int i = 0; i < totalPop; i++) {  // creates population using above parameters
		double newAge = 0;   //age of new person variable 
		double newFertility = 0;  //fertility rate of new person variable
		double fertilityBracket = 0; // population distribution variable
		long long int newId = totalPop;

		//generate person attributes based on age distribution
		if ((ageDistribution == 'e') || (ageDistribution == 'E')) { //for equal distribution: 45% of population within fertility range
			fertilityBracket = rand() % 100 + 1;
			if (fertilityBracket <= 45) {  //age 13-45
				newAge = rand() % 32 + 13;
			}
			else if (fertilityBracket <= 60) { //age 0-12
				newAge = rand() % 12 + 1;
			}
			else {  // ages 45-average mortality rate
				while (newAge <= 45) {
					newAge = rand() % averageMortalityRate + 1;
				}
			}
		}
		else if ((ageDistribution == 'p') || (ageDistribution == 'P')) { //for pyramid distribution: 55% of population within fertility range
			fertilityBracket = rand() % 100 + 1;
			if (fertilityBracket <= 55) {  //age 13-45
				newAge = rand() % 32 + 13;
			}
			else if (fertilityBracket <= 75) { //age 0-12
				newAge = rand() % 12 + 1;
			}
			else {  // ages 45-average mortality rate
				while (newAge <= 45) {
					newAge = rand() % averageMortalityRate + 1;
				}
			}
		}
		else if ((ageDistribution == 'u') || (ageDistribution == 'U')) { //for upside down distribution: 30% of population within fertility range
			fertilityBracket = rand() % 100 + 1;
			if (fertilityBracket <= 30) {  //age 13-45
				newAge = rand() % 32 + 13;
			}
			else if (fertilityBracket <= 45) { //age 0-12
				newAge = rand() % 12 + 1;
			}
			else {  // ages 45-average mortality rate
				while (newAge <= 45)
					newAge = rand() % averageMortalityRate + 1;
			}
		}

		// resolve sex and make person object
		makePerson(i, newAge, averageFertility);

	}

	for (int i = 0; i < yearsToPass; i++) { //run simulated years
		passYear(malePop, femalePop, maleMortalityRate, femaleMortalityRate);  // future builds will take inputs that reflect trend curves
		displayOutput(malePop, femalePop); // future builds will have a graphical output 
	}

	for () { //deallocate memory for simulated males

	}

	for () { //deallocate memory for simulated females

	}
	return 0;
}