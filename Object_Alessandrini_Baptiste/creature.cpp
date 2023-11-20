#include "creature.h"

creature::creature()
{
    nbLife =25;
    attackPower =5;
    mName = " default ";
}

creature::creature(string mn, int l, int ap)
{
    setmName (mn);
    setnbLife (l);
    setattackPower (ap);
}

string creature::getmName() const
{
    return mName;
}

void creature::setmName (string mn)
{
    if (mn == "") 
    {
        cout << "pas de name !" << endl;
        mName = "default";
    }
    else mName = mn;
}

int creature::getnbLife() const
{
    return nbLife;
}

void creature::setnbLife(int l)
{
    if (l < 0) 
    {
        cout << "niveau de vie negatif !" << endl;
        nbLife = 0;
    }
    else  nbLife = l;
}

int creature::getattackPower() const
{
    return attackPower;
}

void creature::setattackPower(int ap)
{
    if (ap <= 0) 
    {
        cout << "attackPower impossible" << endl;
        attackPower = 1;

    }
    else attackPower = ap;  

    nbLife = max(0, nbLife, -attackPower); 
}

ostream& operator<<(ostream& out, const creature& c)
{
    out <<  "-*-     " << c.mName << "     -*- " << endl; 
    out << c.nbLife << " points de vies " << " | " << c.attackPower << " points de degats " << endl; 
    return out; 
}
