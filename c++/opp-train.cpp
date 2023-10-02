#include <iostream>
#include <string>
#include <list>
#include <math.h>

using namespace std;


class Gobj
{
public:
	virtual void draw() = 0;
	~Gobj() {
		cout << "deleting" << endl;
	}
};

class XY : public Gobj
{
public:
	double x;
	double y;

	XY(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
	};

	void draw() 
	{
		cout << "X: " << x << " Y: " << y << endl << endl;
	};
};

class Point : public XY
{
public:
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
	}
};

class Car : public Point
{
public:
	string brand;

	Car(double x = 0, double y = 0, string brand = "")
	{
		this->x = x;
		this->y = y;
		this->brand = brand;
	}

	void draw()
	{
		cout << "Car " << this->brand << ": " << this->x << ", " << this->y << endl << endl;
	}
};

class Tree : public Point
{
public:
	string treeType;

	Tree(double x = 0, double y = 0, string treeType = "")
	{
		this->x = x;
		this->y = y;
		this->treeType = treeType;
	}

	void draw()
	{
		cout << "Tree " << this->treeType << ": " << this->x << ", " << this->y << endl << endl;
	}
};

class Arc : public XY
{
public:
	list <XY*> arc;

	Arc() {};
};

class Road : public Arc {
public:
	Road(list <XY*> *items)
	{
		this->arc = *items;
	};
	~Road()
	{
		for (XY* item : arc)
		{
			cout << "Deleting point of road" << endl;
			delete item;
		}
	}

	void draw()
	{
		for (XY* item : arc)
		{
			cout << "Point of road" << endl;
			item->draw();
		}
	};

	double calculateLength()
	{
		double length = 0;
		XY temp = { 0, 0 };

		for (XY* point : arc)
		{
			length += sqrt((point->x - temp.x) * (point->x - temp.x) + (point->y - temp.y) * (point->y - temp.y));
			temp = *point;
		}

		return length;
	};
};

class Route : public Arc
{
public:
	double direction;

	Route(list <XY*> items, double direction = 0)
	{
		this->direction = direction;
		this->arc = items;
	};
	~Route()
	{
		for (XY* item : arc)
		{
			cout << "Deleting point of route" << endl;
			delete item;
		}
	}

	void draw()
	{
		for (XY* item : arc)
		{
			cout << "Point of route" << endl;
			item->draw();
		}
	};
};

class Rectangle : public XY
{
public:
	XY top_left;
	XY bottom_right;

	Rectangle(XY top_left = { 0,0 }, XY bottom_right = { 0,0 })
	{
		this->top_left = top_left;
		this->bottom_right = bottom_right;
	}
};

class Map : public Rectangle
{
protected:
	list <Gobj*> items;
public:
	Map(XY top_left = { 0,0 }, XY bottom_right = { 0,0 })
	{
		this->top_left = top_left;
		this->bottom_right = bottom_right;
	};

	void addItem(Gobj* item)
	{
		items.push_back(item);
	}

	void draw()
	{
		cout << "I'm drawing" << endl;
	}

	void drawAll()
	{
		for (Gobj* item : items)
		{
			item->draw();
		}
	}

	void deleteAll()
	{
		for (Gobj* item : items)
		{
			cout << "del" << endl;
			delete item;
		} 
	}
};

int main()
{
	try
	{
		Map map = Map({ 10, 10 }, { 100, 100 });  
		
		/*
		* map.addItem(new Car(1, 1, "BMW"));
		map.addItem(new Car(2, 3, "Tesla"));
		map.addItem(new Car(5, 7, "Porshe"));

		map.addItem(new Tree(1, 9, "Owk"));
		map.addItem(new Tree(8, 7, "Pine"));
		map.addItem(new Tree(5, 6, "Owk"));
		map.addItem(new Tree(5, 7, "Palm"));
		map.addItem(new Tree(5, 8, "Blossom"));
		*/


		list <XY*> l { new XY(0, 0), new XY(1, 1) };

		Road road = Road(&l);

		cout << road.calculateLength();


		/*
		map.addItem(new Road(ptr));
		map.addItem(new Route(list <XY*> { new XY(1, 1), new XY(2, 2), new XY(1, 1), }, 100));

		//map.addItem(new Map({20, 20}, {40, 40}));

		map.drawAll();

		map.deleteAll();
		*/

		throw "Custom error";
	}
	catch (...)
	{
		cout <<  endl << "ERROR!" << endl << "Unexpected result" << endl ;
	}
	return 0;
};