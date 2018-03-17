/*
-clasa de baza ABSTRACTA
-minim 2 derivate
-virtual destructors
-public protected private
-constructor(default,copy)
-Baza b = new Derivata ->>10 obiecte
-print ceva specific

*/

#include<iostream>
#include<string>

using namespace std;

class PassengerPlane {
public: 
	PassengerPlane(int p, int id) { power = p; planeID = id;}
	virtual ~PassengerPlane() {}

	//PassengerPlane(const PassengerPlane&) {};

	void setPower(int p) { power = p; }
	void setPlaneID(int id) { planeID = id; }

	int getPower() { return power; }
	int getPlaneID() { return planeID; }
	virtual int getMileage()= 0;

protected:
	int power, planeID;


};

class Concorde : public PassengerPlane {
public:
	Concorde(int p, int id, int m) : PassengerPlane(p,id){
		mileage = m;
	}
	~Concorde() {}

	int getMileage() { return mileage * 2 + 1; }
	
private:
	int mileage;
};

class Boeing : public PassengerPlane {
public:
	Boeing(int p, int id, int m, int mp) : PassengerPlane(p,id){
		mileage = m;
		maxPassengers = mp;
	}
	~Boeing() {}

	//Boeing(const Boeing&) {};

	int getMileage() { return mileage * maxPassengers; }
	int getMaxPassengers() { return maxPassengers; }

private:
	int mileage, maxPassengers;
};

int main() {
	
	PassengerPlane *p1 = new Concorde(100, 1, 15);
	cout << "Consumul primului avion: " << p1->getMileage();
	cout << "\n";
	PassengerPlane *p2 = new Boeing(1000, 2, 32, 420);
	cout << "Consumul celui de-al doilea avion: " << p2->getMileage(); cout << "\n";

	PassengerPlane *copyOfP1(p1);
	cout << "Copia primului avion: " << copyOfP1->getMileage();

	/*

	PassengerPlane *p3 = new Concorde(300, 3, 19);
	cout << "consumul celui de-al treilea avion: " << p3->getMileage(); cout << "\n";
	p3->setPlaneID(10);
	cout << "id ul schimbat al celui de-al treilea avion: " << p3->getPlaneID(); cout << "\n";

	Boeing p4(123, 5, 30, 400);

	cout << p4.getMaxPassengers();
	*/
	cout << "\nfinal";
	return 0;
}
