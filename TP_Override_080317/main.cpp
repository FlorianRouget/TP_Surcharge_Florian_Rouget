#include "Point.h"

int main() {
	Point a(2, 5), b(3, 6), c(1, 1);
	Point d(a);
	cout << "a : ";
	a.affiche();
	cout << "b : ";
	b.affiche();
	cout << "c : ";
	c.affiche();
	cout << "d : ";
	d.affiche();

	a += c;											//utilisation de +=
	cout << "a : ";
	a.affiche();
	a -= c;											//utilisation de -=
	cout << "a : ";
	a.affiche();
	a /= d;											//utilisation de /=
	cout << "a new values : " << a << endl;
	a *= b;											//utilisation de *=
	cout << "a new values : " << a << endl;
	a = d;											//utilisation de =
	cout << "a new values : " << a << endl;

	if (a != b) {									//utilisation de !=
		cout << "a est different de b" << endl;
	}
	if (a == d) {									//utilisation de ==
		cout << "a est egal a d" << endl;
	}
	cout << "b - c = " << b - c << endl; 			//utilisation de << avec -
	cout << "b + c = " << b + c << endl;			//utilisation de << avec +

	cin >> a;										//utilisation de >>
	cout << "a new values : " << a << endl;

	system("pause");
	Point *h = new Point(30);						//utilisation du new surcharg�
	cout << a.GetCount() << endl;
	delete h;										//utilisation du delete surcharg�
	cout << a.GetCount() << endl;

	cout << a[5] << endl;							//utilisation du [] surcharg�
	cout << a[0] << " ; " << a[1] << endl;			//utilisation du [] surcharg�

	system("pause");
	return 0;
}