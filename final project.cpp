#include <iostream>
#include <string>
using namespace std;

string inventory[10];
int playerHealth = 500;
void BattleSystem();
void Shop(); 

int main() {
	srand(time(NULL));
	int room = 1;
	string input;
	bool rm3Battle = false;
	while (playerHealth > 0) {


		    cout << "your inventory: ";
		    for (int i = 0; i < 10; i++)
			   cout << inventory[i] << " ";
		    cout << endl << endl;


			switch (room) {
			case 1:
				cout << "Welcome to Memory of the world!" << endl;



				cout << "you got potion!" << endl;
				inventory[1] = "potion";

				cout << "you woke up in the memory of the world but you suddenly don't remember anything, but you had to retrace your steps. walk foward to east." << endl;
				cout << "there's a golden key on the floor " << endl;
				getline(cin, input);
				if (input == "east")
					room = 2;
				else if (input == "floor" || "picks up the key") {
					cout << "you got golden key!" << endl;
					inventory[2] = "golden key";

				}
				break;

			case 2:
				cout << "you got to go outside of the world you checked if something is missing but it was clear, you can go east, north, or west" << endl;
				cout << "there's a wooden sword on the grass" << endl;
				getline(cin, input);

				if (input.compare("get sword") == 0) {
					cout << "you got wooden sword!" << endl;
					inventory[3] = "wooden sword";
				}

				if (input == "east")
					if (inventory[2] == "golden key") {
						cout << "you unlocked the door with a golden key." << endl;
						room = 3;
						inventory[2] = " ";
					}

					else {
						cout << "the door is locked womp womp." << endl;

					}
				else if (input == "north")
					room = 4;
				else if (input == "west")
					room = 1;

				break;

			
			case 3:
				cout << "your in the dungeon, There's a goblin behind the golden chest!" << endl;
				if (rm3Battle == false) {
					BattleSystem();
					rm3Battle = true;
				}
				cout << "You can go west or open golden chest" << endl;
				getline(cin, input);
				if (input == "west")
					room = 2;
				else if (input == "open") {
					cout << "you got golden sword!" << endl;
					inventory[4] = "golden sword";
				}

				break;

			case 4:
				cout << "you are walking to a memory city where there a people wondering remembering who they are, you can go north or south" << endl;
				cout << "there is a gem on a table" << endl;
				getline(cin, input);
				if (input == "north")
					room = 5;
				else if (input == "south")
					room = 2;

			    else if (input == "table" || "picks up the gem") {
					cout << "you got a diamond gem!" << endl;
					inventory[5] = " diamond gem";
				}

				break;

			case 5:
				cout << "you walked in the center and there are three choices of which path gives you a key, you can go east, north, west, or south" << endl;
				getline(cin, input);
				if (input == "east")
					room = 7;
				else if (input == "north")
					room = 8;
				else if (input == "west")
					room = 6;
				else if (input == "south")
					room = 4;
				break;
			case 6:
				cout << "you walked into the shop and a guy is welcoming you tells you 1 gem is required in three items, you can go east" << endl;
				getline(cin, input);
				if (input == "east")
					room = 5;
				
				break;
			case 7:
				cout << "you are in the afternoon forest there is a monster that has a key inside! you can go west" << endl;
				getline(cin, input);
				if (input == "west")
					room = 5;
				break;
			case 8:
				cout << "you are in between Heaven and Hell the angel tells you can continue your path and Devil is telling you that if you choose hell you'll have a really bad time, you can go north (good path) or west (bad path) choose wisely. " << endl;
				getline(cin, input);
				if (input == "north")
					room = 9;
				else if (input == "south")
					room = 5;
				else if (input == "west")
					room = 0;
				break;

			case 0: // bad ending :(
				cout << " you are in hell (0) for the rest of your life because there is no option to leave even when you fight the devil there is no freedom" << endl;


				break;

			case 9:
				cout << "your in room 9, you can go east or south" << endl;
				getline(cin, input);
				if (input == "east")
					room = 10;
				else if (input == "south")
					room = 8;
				break;
			case 10:
				cout << "your in room 10, you can go west" << endl;
				getline(cin, input);
				if (input == "west")
					room = 9;
				break;




			}

	}

}

void BattleSystem() {
	int MonsterHealth = 20; //LOCAL variable: can only be seen and used by this fuction!
	int damage;
	char dummy;
	cout << endl << endl << "-----------MONSTER BATTLE------------------------" << endl;
	cout << "an goblin attacks!" << endl;
	while (playerHealth > 0 && MonsterHealth > 0) {
		//player's attack
		damage = rand() % 16; // number between 0 and 20
		cout << "you hit the goblin for " << damage << " damage." << endl;
		MonsterHealth -= damage;
		cin >> dummy;


		//monster's attack
		damage = rand() % 21; //number between 5 and 25
		cout << " the goblin hits you for " << damage << " damage." << endl;
		playerHealth -= damage;
		cout << "press any key to continue..." << endl;
		cin >> dummy;

		if (playerHealth > 0)
			cout << "your health: " << playerHealth << endl;
		else
			cout << "you died." << endl;

		if (MonsterHealth > 0)
			cout << "Monster health: " << MonsterHealth << endl;
		else
			cout << "you are victorious! the goblin is dead." << endl;

	}//end of the mini loop
	cout << "-------------------------end of battle-------------------------" << endl << endl;
}
void Shop() {


}
