class human() {
	double age;
	double id;
	
	public:
		double getid();
		void setId(double);
		double getAge();
		void setAge(double);
}

class male:public human {
	public:
		male(long long int, double);
		~male();
}

class female:public human {
	double fertilityFactor;

	public:
		double getFertilityFactor();
		void setFertilityFactor(double);
		void haveChildren(double, double);
		female(long long int, double, double);
		~female();
}

void makePerson(long long int, double, double);

void passyear(vector, vector);

void displayOutput(vector, vector);