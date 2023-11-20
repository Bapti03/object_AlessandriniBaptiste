#pragma once
#include <iostream>
#include <string> 
using namespace std; 

class creature

{
private:

	int nbLife;
	int attackPower;
	string mName;

public:

	creature(); 
	creature(string mn, int l, int ap);

	string getmName() const;
	void setmName(string mn);

	int getnbLife() const ;
	void setnbLife(int l);

	int getattackPower() const ;
	void setattackPower(int ap);

	

friend ostream& operator << (ostream& out, const creature& c); 

};