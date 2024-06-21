#include <iostream>
#include <math.h>
#include <ctime>
#include <algorithm>

//using namespace std;
//using std::cout;
//using std::endl;

#define delimiter "\n------------------------------------------------------------------------\n"

const double PI = 3.14159265;

class Figure
{


public:

	// Constructors

	Figure()
	{
		std::cout << "Figure_Constructor:\t" << this << std::endl;
	}

	virtual ~Figure()
	{
		std::cout << "Figure_Destructor:\t" << this << std::endl;
	}

	// Methods
	virtual double calc_perimeter() = 0;
	virtual double calc_square() = 0;

	virtual void print()
	{
		std::cout << "Perimiter = " << this->calc_perimeter() << std::endl;
		std::cout << "Square = " << this->calc_square() << std::endl;
	}
};

class Circle : public Figure
{
	double radius;

public:
	double get_radius()const { return this->radius; }
	void set_radius(double radius)
	{
		if (radius > 0) this->radius = radius;
		else this->radius = 0;
	}

	// Constructors
	Circle(double radius = 0)
	{
		this->set_radius(radius);
		std::cout << "Circle_Constructor:\t" << this << std::endl;
	}

	Circle(const Circle& other)
	{
		this->radius = other.radius;
		std::cout << "Circle_Copy_Constructor:\t" << this << std::endl;
	}

	~Circle()
	{
		std::cout << "Circle_Destructor:\t" << this << std::endl;
	}

	// Methods
	double calc_perimeter()
	{
		return (2 * PI * this->get_radius());
	}

	double calc_square()
	{
		return (PI * this->get_radius() * this->get_radius());
	}

	void print()
	{
		std::cout << std::endl;
		std::cout << "CIRCLE with RADIUS = " << this->get_radius() << std::endl;
		Figure::print();
		
		

		std::cout << std::endl;
	}

	// Operators
	Circle& operator=(const Circle& other)
	{
		this->radius = other.radius;
		std::cout << "Circle_Copy_Assignment:\t" << this << std::endl;
	}
};

class Quadrate : public Figure
{
	double a;

public:
	double get_a()const { return this->a; }

	void set_a(double a)
	{
		if (a > 0) this->a = a;
		else this->a = 0;
	}

	// Constructors
	Quadrate(double a = 0)
	{
		this->set_a(a);
		std::cout << "Quadrate_Constructor:\t" << this << std::endl;
	}

	Quadrate(const Quadrate& other)
	{
		this->a = other.get_a();
		std::cout << "Quadrat_Copy_Constructor:\t" << this << std::endl;
	}

	~Quadrate()
	{
		std::cout << "Quadrate_Destructor:\t" << this << std::endl;
	}

	// Methods
	double calc_perimeter()
	{
		return (this->get_a() * 4);
	}

	double calc_square()
	{
		return (this->get_a() * this->get_a());
	}

	void print()
	{
		std::cout << std::endl;
		std::cout << "QUADRATE with SIDE: a = " << this->get_a() << std::endl;
		Figure::print();

		std::cout << std::endl;
	}

	// Operators
	Quadrate& operator=(const Quadrate& other)
	{
		this->a = other.get_a();
		std::cout << "Quadrat_Copy_Assignment:\t" << this << std::endl;
	}
};

class Rectangle : public Quadrate
{
	double b;

public:
	double get_b()const { return this->b; }

	void set_b(double b)
	{
		if (b > 0) this->b = b;
		else this->b = 0;
	}

	// Constructors
	Rectangle(double a = 0, double b = 0):Quadrate(a)
	{
		this->set_b(b);
		std::cout << "Rectangle_Constructor:\t" << this << std::endl;
	}

	Rectangle(const Rectangle& other)
	{
		Quadrate::Quadrate(other.get_a());
		this->b = other.get_b();
		std::cout << "Rectangle_Copy_Constructor:\t" << this << std::endl;
	}

	~Rectangle()
	{
		std::cout << "Rectangle_Destructor:\t" << this << std::endl;
	}

	// Methods
	double calc_perimeter()
	{
		return ((this->get_a() + this->get_b()) * 2);
	}

	double calc_square()
	{
		return (this->get_a() * this->get_b());
	}

	void print()
	{
		std::cout << std::endl;
		std::cout << "RECTANGLE with SIDES: a = " << this->get_a() << ", b = " << this->get_b() << std::endl;
		Figure::print();

		std::cout << std::endl;
	}

	// Operators
	Rectangle& operator=(const Rectangle& other)
	{
		Quadrate::operator=(other.get_a());
		this->b = other.get_b();
		std::cout << "Rectangle_Copy_Assignment:\t" << this << std::endl;
	}
};

class Triangle : public Rectangle
{
	double c;

public:
	double get_c()const { return this->c; }

	void set_c(double c)
	{
		if (c > 0) this->c = c;
		else this->c = 0;
	}

	// Constructors
	Triangle(double a = 0, double b = 0, double c = 0): Rectangle(a, b)
	{
		this->set_c(c);
		std::cout << "Triangle_Constructor:\t" << this << std::endl;
	}

	Triangle(const Triangle& other)
	{
		Rectangle::Rectangle(other.get_a(), other.get_b());
		this->c = other.get_c();
		std::cout << "Triangle_Copy_Constructor:\t" << this << std::endl;
	}

	~Triangle()
	{
		std::cout << "Triangle_Destructor:\t" << this << std::endl;
	}

	// Methods
	double calc_perimeter()
	{
		return (this->get_a() + this->get_b() + this->get_c());
	}

	double calc_square()
	{
		double result;
		double p = this->calc_perimeter() / 2; // Половина периметра
		double expression = p * (p - this->get_a()) * (p - this->get_b()) * (p - this->get_c());
		result = sqrt(expression);
		return result;
	}

	void print()
	{
		std::cout << std::endl;
		std::cout << "TRIANGLE with SIDES: a = " << this->get_a() << ", " << "b = " << this->get_b() << ", " << "c = " << this->get_c() << std::endl;
		Figure::print();

		std::cout << std::endl;
	}

	// Operators
	Triangle& operator=(const Triangle& other)
	{
		Rectangle::operator=(other.get_a());
		this->c = other.get_c();
		std::cout << "Triangle_Copy_Assignment:\t" << this << std::endl;
	}
};


//#define FIGURES_CHECK;

void main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));

#if defined FIGURES_CHECK
	Circle circle(5);
	circle.print();

	Quadrate quadrate(4);
	quadrate.print();

	Rectangle rectangle(3, 5);
	rectangle.print();

	Triangle triangle(3, 4, 5);
	triangle.print();
#endif
		
	Figure* group[] = 
	{
		new Circle (rand() % 10 + 1),
		new Quadrate (rand() % 10 + 1),
		new Rectangle ((rand() % 10 + 1), (rand() % 10 + 1)),
		new Triangle ((rand() % 10 + 1), (rand() % 10 + 1), (rand() % 10 + 1))
	};
	
	std::random_shuffle(std::begin(group), std::end(group));

	for (auto element:group)
	{
		element->print();
		std::cout << delimiter << std::endl;
	}

	for (auto element:group) delete element;
	
}