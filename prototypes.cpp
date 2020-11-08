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
	double maleLifeSpan;
	public:
		double getMaleLifeSpan();
		void setMaleLifeSpan(double);
		male(double, long long int, double);
		~male();
}

class female:public human {
	double fertilityFactor:
	double femaleLifeSpan;

	public:
		double getFertilityFactor();
		void setFertilityFactor(double);
		double getFemaleLifeSpan();
		void setFemaleLifeSpan(double);
		void haveChildren(double, double);
		female(double, long long INt, double, double);
		~female();
}

void makePerson();

void passyear(int);