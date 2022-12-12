#include <iostream>
using namespace std;

class Engine
{
public:
	virtual void releaseEngine() = 0;
};

class RussianEngine : public Engine
{
public:
	void releaseEngine() override
	{
		cout << "russian engine" << endl;
	}
};

class UsaEngine : public Engine
{
public:
	void releaseEngine() override
	{
		cout << "usa engine" << endl;
	}
};

class Car
{
public:
	virtual void releaseCar(Engine* engine) = 0;
};

class RussianCar : public Car
{
public:
	void releaseCar(Engine* engine) override
	{
		cout << "the russian car is assembled: ";
		engine->releaseEngine();
	}
};

class UsaCar : public Car
{
public:
	void releaseCar(Engine* engine) override
	{
		cout << "the usa car is assembled: ";
		engine->releaseEngine();
	}
};

class Factory
{
public:
	virtual Engine* createEngine() = 0;
	virtual Car* createCar() = 0;
};

class RussianFactory : public Factory
{
public:
	Engine* createEngine() override
	{
		return new RussianEngine();
	}
	Car* createCar() override
	{
		return new RussianCar();
	}
};

class UsaFactory : public Factory
{
	Engine* createEngine() override
	{
		return new UsaEngine();
	}
	Car* createCar() override
	{
		return new UsaCar();
	}
};

int main()
{
	Factory* factory1 = new RussianFactory();
	Engine* engine1 = factory1->createEngine();
	Car* car1 = factory1->createCar();
	car1->releaseCar(engine1);

	Factory* factory2 = new UsaFactory();
	Engine* engine2 = factory2->createEngine();
	Car* car2 = factory2->createCar();
	car2->releaseCar(engine2);
}