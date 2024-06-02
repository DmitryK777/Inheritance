// Inheritance
#include <iostream>
#include<string>
using namespace std;

#define delimiter "----------------------------------------"

class Human
{
	std::string last_name;
	std::string first_name;
	int age;

public:
	const std::string& get_last_name()const { return last_name; }
	const std::string& get_first_name()const { return first_name; }
	int get_age()const { return age; }

	void set_last_name(const std::string& last_name) { this->last_name = last_name; }
	void set_first_name(const std::string& first_name) { this->first_name = first_name; }
	void set_age(int age) { this->age = age; }

	// Constructors
	Human(const std::string& last_name, const std::string& first_name, int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);

		cout << "HumanConstructor:\t" << endl;
	}

	virtual ~Human()
	{
		cout << "HumanDestructor:\t" << endl;
	}

	// Methods
	virtual void print()
	{
		cout << last_name << " " << first_name << " " << age << " years" << " ";
	}
};


class Student :public Human
{
	std::string speciality;
	std::string group;
	double rating; // успеваемость
	double attendance; // посещаемость

public:
	const std::string& get_speciality()const {return speciality;}
	const std::string& get_groop()const {return group;}
	double get_rating()const {return rating;}
	double get_attendance()const {return attendance;}

	void set_speciality(const std::string& speciality) {this->speciality = speciality;}
	void set_group(const std::string& group) {this->group = group;}
	void set_rating(double rating) {this->rating = rating;}
	void set_attendance(double attendance) {this->attendance = attendance;}

	// Constructors
	Student(
		const std::string& last_name, const std::string& first_name, int age, 
		const std::string& speciality, const std::string& group, double rating, double attendance
	):Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);

		cout << "StudentConstructor:\t" << endl;
	}

	~Student()
	{
		cout << "StudentDestructor:\t" << endl;
	}

	// Methods
	void print()
	{
		Human::print();
		cout << speciality << " " << group << " " << rating << " " << attendance << " ";
	}
};

class Teacher :public Human
{
	std::string speciality;
	int experience;

public:
	const std::string& get_speciality()const { return speciality; }
	double get_experience()const { return experience; }

	void set_speciality(const std::string speciality) {this->speciality = speciality;}
	void set_experience(int experience) {this->experience = experience;}

	// Constructors

	Teacher
	(const std::string& last_name, const std::string& first_name, int age,
		const std::string& speciality, int experience
	) :Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_experience(experience);

		cout << "TeacherConstructor:\t" << endl;
	}

	~Teacher()
	{
		cout << "TeacherDestructor:\t" << endl;
	}

	//Methods
	void print()
	{
		Human::print();
		cout << speciality << " " << experience << " ";
	}
};

class Graduate :public Student
{
	std::string subject;

public:
	const std::string& grt_subject()const { return subject; }

	void set_subject(const std::string& subject) {this->subject= subject;}

	//Constructors
	Graduate
		(const std::string& last_name, const std::string& first_name, int age,
			const std::string& speciality, const std::string& group, double rating, double attendance,
			std::string subject
		) :Student(last_name, first_name, age, speciality, group,rating, attendance)
	{
		set_subject(subject);
		cout << "GraduateConstructor:\t" << endl;
	}

	~Graduate()
	{
		cout << "GraduateDestructor:\t" << endl;
	}

	//Methods
	void print()
	{
		Student::print();
		cout << subject << " ";
	}
};

//#define INHERITANCE_CHECK

void main()
{
	setlocale(LC_ALL, "");

#if defined INHERITANCE_CHECK
	Human human("Pain", "Max", 30);
	human.print();
	cout << endl << endl;

	Student student("Pinkman", "Jessie", 20, "Chemistry", "WW_220", 95, 97);
	student.print();
	cout << endl << endl;

	Teacher teacher("Green", "Walter", 50, "Chemistry", 25);
	teacher.print();
	cout << endl << endl;

	Graduate graduate("Cristoff", "Brain", 20, "Alchohol", "WD_320", 95, 97, "How to catch Alchohol");
	graduate.print();
	cout << endl << endl;
#endif

	// Generalization 

	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 20, "Chemistry", "WW_220", 95, 97),
		new Teacher("White", "Walter", 50, "Chemistry", 25),
		new Graduate("Cristoff", "Brain", 20, "Alchohol", "WD_320", 95, 97, "How to catch Alchohol"),
		new Student("Vercetty", "Tommy", 30, "Theft", "Vice", 98, 95),
		new Teacher("Diza", "Ricardo", 50, "Weapons", 20)
	};


	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		group[i]->print();
		cout << endl;
		cout << delimiter << endl;
	}

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}

}