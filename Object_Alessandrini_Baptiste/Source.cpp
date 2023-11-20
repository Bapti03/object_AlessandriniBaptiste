
#include "creature.h"

using namespace std; 

creature* choicePlayer()
{
	int choice;

	cout << "-*- " << "choisis un personnage" << " -*- " << endl;
	cout << "--- " << "1. golum" << " --- " << endl;
	cout << "--- " << "2. Scarface du ghettos" << " --- " << endl;
	cout << "--- " << "3. Kang le conquerant" << " --- " << endl;
	cout << "--- " << "4. Murloc" << " --- " << endl;
	cout << " votre choix : ";
	cin >> choice;

	switch (choice) 
	{
	case 1:
		return new creature("golum", 17 ,2);
	case 2:
		return new creature ("Scareface du ghettos", 55, 9);
	case 3: 
		return new creature("Kang le conquerant", 95, 17);
	case 4:
		return new creature("murloc", 25, 7);
	default :
		cerr << "Choix invalide. Personnage par défault sélectionné." << endl; 
		return new creature();
	}
} 

void gameFight(creature* player,  creature* ennemies) 
{
	cout << "Combat tour : " << player->getmName() << " vs " << ennemies->getmName() << endl;

	int damage = player->getattackPower();

	cout << player->getmName() << " inflige " << damage << " points de dégâts à " << ennemies->getmName() << endl;
	
	int remainingLife = ennemies->getnbLife() - damage;

	ennemies->setnbLife(max(remainingLife, 0));


	cout << ennemies->getmName() << " a maintenant " << ennemies->getnbLife() << "points de vie" << endl;
	
}


int main() 

{
	creature* player = choicePlayer(); 

	cout << "Vous avez choisi : " << player->getmName() << endl; 

	
	
	creature v1("golum", 17, 2);
	creature v2(" Scarface du ghettos",55,9);
	creature v3(" Kang le conquerant",95,17);
	creature v4(" murloc",25,7); 

	cout << v1.getmName() << " a " << v1.getnbLife() << " points de vie" << endl;
	cout << v2.getmName() << " a " << v2.getnbLife() << " points de vie" << endl;
	cout << v3.getmName() << " a " << v3.getnbLife() << " points de vie" << endl;
	cout << v4.getmName() << " a " << v4.getnbLife() << " points de vie" << endl;



	for (int i = 0; i < 3; ++i) 
	{
		cout << " Round " << i + 1 << endl;
		gameFight(player, &v1);
		gameFight(player, &v2);
		gameFight(player, &v3);
		gameFight(player, &v4);

		if (v1.getnbLife() <= 0 && v2.getnbLife() <= 0 && v3.getnbLife() <= 0 && v4.getnbLife() <= 0)
		{
			cout << "Le joueur est mort. Fin du combat." << endl;
			break;
		}

	}
	
	delete player; 

	return 0;
} 

   