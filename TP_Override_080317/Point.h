#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

class Point
{
	int x, y; //les données membres, à savoir l'Abscisse et l'Ordonnée de mon Point.

public:
	Point(int abs = 0, int ord = 0) {
		x = abs;
		y = ord;
	}
	Point(const Point &Source) { //constructeur par recopie
		x = Source.x;
		y = Source.y;
	}
	~Point();

	Point operator+(Point)const;				//surcharge de l'operateur +
	friend Point operator-(Point, Point);		//surcharge de l'operateur -
	Point operator+=(Point);					//surcharge de l'operateur +=
	Point operator-=(Point);					//surcharge de l'operateur -=
	Point operator*=(Point);					//surcharge de l'operateur *=
	Point operator/=(Point);					//surcharge de l'operateur /=
	Point operator=(Point); 					//surcharge de l'operateur =
	friend bool operator==(Point, Point);		//surcharge de l'operateur ==
	friend bool operator!=(Point, Point);		//surcharge de l'operateur !=

	friend ostream& operator<<(ostream& os, const Point& mp);	//surcharge de l'operateur <<
	friend istream& operator>>(istream& is, Point& mp);			//surcharge de l'operateur >>

	void* operator new(size_t s);				//surcharge de l'operateur new
	void operator delete(void* ptr);			//surcharge de l'operateur delete
	int operator[](int nv);						//surcharge de l'operateur []

	//BUT : afficher les coordonnées
	//ENTREE : rien 
	//SORTIE : l'affichage des coordonnées
	void affiche()const {
		cout << "coordonnees : " << x << " " << y << "\n";
	}

	int GetCount()const;

};

