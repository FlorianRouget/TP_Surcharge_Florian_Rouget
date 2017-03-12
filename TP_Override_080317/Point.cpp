#include "Point.h"

//une variable qui compte le nombre de Points auxquels ont �t� allou� de la m�moire avec une fonction "new"
int Count = 0;

Point::~Point()
{
}

//BUT : additionner deux points (surcharge de +)
//ENTREE : un second point
//SORTIE : un point dont le X et le Y correspond � la somme des X et Y du point appelant et du second point en param�tre.
Point Point::operator+(Point a) const
{
	Point p;

	p.x = a.x + x;
	p.y = a.y + y;

	return p;
}

//BUT : ajouter un point � un autre (surcharge de +=)
//ENTREE : un second point
//SORTIE : un pointeur vers le point appelant, dont les valeurs ont �t� mises � jour.
Point Point::operator+=(Point a)
{
	this->x += a.x;
	this->y += a.y;
	return *this;
}

//BUT : soustraire un point d'un autre (surcharge de -=)
//ENTREE : un second point
//SORTIE : un pointeur vers le point appelant, dont les valeurs ont �t� mises � jour.
Point Point::operator-=(Point a)
{
	this->x -= a.x;
	this->y -= a.y;
	return *this;
}

//BUT : multiplier un point par un autre (surcharge de *=)
//ENTREE : un second point
//SORTIE : un pointeur vers le point appelant, dont les valeurs ont �t� mises � jour.
Point Point::operator*=(Point a)
{
	this->x *= a.x;
	this->y *= a.y;
	return *this;
}

//BUT : diviser un point par un autre (surcharge de /=)
//ENTREE : un second point
//SORTIE : un pointeur vers le point appelant, dont les valeurs ont �t� mises � jour.
Point Point::operator/=(Point a)
{
	if (a.x != 0 && a.y != 0) {
		this->x /= a.x;
		this->y /= a.y;	
	}
	return *this;
}

//BUT : affecter les valeurs d'un point � un autre (surcharge de =)
//ENTREE : un second point
//SORTIE : un pointeur vers le point appelant, dont les valeurs ont �t� mises � jour. 
Point Point::operator=(Point a)
{
	this->x = a.x;
	this->y = a.y;
	return *this;
}

//BUT : allouer un espace m�moire � un point (surcharge de new)
//ENTREE : une taille
//SORTIE : un pointeur dont la taille a �t� d�finie
void * Point::operator new(size_t s)
{
	void* ptr = malloc(s);
	Count += 1; // pour �tre certain que nous sommes pass�s par cette fonction
	return ptr;
}

//BUT : lib�rer un point de la m�moire (surcharge de delete)
//ENTREE : un Point
//SORTIE : rien
void Point::operator delete(void * ptr)
{
	Count -= 1; // pour �tre certain que nous sommes pass�s par cette fonction
	free(ptr);
}

//BUT :  selectionner une donn�e membre d'un Point en fonction de l'index donn� (surcharge de [])
//ENTREE : un index
//SORTIE : une donn�e membre ou une valeur par d�faut.
int Point::operator[](int nv)
{
	switch(nv) {
	case 0:
		return x;
		break;
	case 1:
		return y;
		break;
	default:
		return 0;
		break;
	}
}

//BUT : r�cup�rer la valeur de Count
//ENTREE : rien
//SORTIE : la valeur de Count
int Point::GetCount() const
{
	return Count;
}

//BUT : soustraire deux points (surcharge de -)
//ENTREE : deux points
//SORTIE : un troisi�me point dont les X et Y correspondent � la diff�rences entre les X et Y des Points en param�tre.
Point operator-(Point a, Point b)
{
	Point c;
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	return c;
}

//BUT : comparer deux points (surcharge de ==)
//ENTREE : deux points � comparer
//SORTIE : un bool�en qui est VRAI si les deux points sont �gaux.
bool operator==(Point a, Point b)
{
	if (a.x == b.x && a.y == b.y)
		return true;

	return false;
}

//BUT : comparer deux points (surcharge de !=)
//ENTREE : deux points � comparer
//SORTIE : un bool�en qui est VRAI si les deux points sont diff�rents.
bool operator!=(Point a, Point b)
{
	return !operator==(a,b); //on r�utilise la surcharge de == existante, et on inverse son r�sultat.
}

//BUT : afficher directement les donn�es membres d'un point (surcharge de <<)
//ENTREE : un flux de sortie et le point � afficher
//SORTIE : un flux de sortie
ostream & operator<<(ostream & os, const Point & mp)
{
	// TODO: insert return statement here
	os << "(" << mp.x << ", " << mp.y << ")";
	return os;
}

//BUT : affecter des valeurs donn�es par un utilisateur � un point
//ENTREE : un flux d'entr�e et le point � updater
//SORTIE : un flux d'entr�e
istream & operator>>(istream & is, Point & mp)
{
	// TODO: insert return statement here
	double x, y;

	// read x
	cout << "Entrez une nouvelle valeur de X : " << endl;
	is >> x;
	mp.x = x;

	// read y
	cout << "Entrez une nouvelle valeur de Y : " << endl;
	is >> y;
	mp.y = y;

	return is;
}
