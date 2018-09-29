// acdt.cpp
// Erroll Abrahamian, CISP 360
// 09-30-2018

#include <iostream>
using namespace std;

int main()
{
	
	// declare my things
	char menu,
		airborne,
		elecSystem,
		engStop,
		airTemp,
		overMount,
		overWater,
		nightFly,
		lovelySight;

	float ice;

	// Program greeting
	cout << "Welcome to the Aircraft Decision Tree!\n\n";

	// menu
	cout << "Pick from the following:\n";
	cout << "(C)ommunications Failure.\n";
	cout << "(E)ngine Failure.\n";
	cout << "(I)n-Flight Icing.\n";
	cout << "(Q)uit.\n";
	cin >> menu;

	switch (menu)
	{
		// Communications Failure
		case 'c':
		case 'C': cout << "\nYou picked Communications Failure.\n";
			cout << "Switch to alternate radio.\n\n";
		break;

		// Engine Failure
		case 'e':
		case 'E': cout << "\nYou picked Engine Failure.\n\n";
		
			cout << "Are you airborne? (y/n)\n";
			cin >> airborne;
		
			// airborne no
			if (airborne == 'n')
				cout << "\nHave a drink and call a mechanic.\n\n";

			// invalid
			else if (airborne != 'n' && airborne != 'y')
				cout << "\nNot a valid entry.\n\n";

			// airborne yes
			else
			{
				cout << "\nIs the electrical system working? (y/n)\n";
				cin >> elecSystem;

				// electricals no
				if (elecSystem == 'n')
					cout << "\nTurn on the master switch.\n\n";
			
				// invalid
				else if (elecSystem != 'n' && elecSystem != 'y')
					cout << "\nNot a valid entry.\n\n";
			
				// electricals yes
				else
				{
					cout << "\nHas the engine stopped running? (y/n)\n";
					cin >> engStop;

					// engine running
					if (engStop == 'n')
					{
						cout << "\nIs the outside air temperature less than 32 degrees? (y/n)\n";
						cin >> airTemp;
					
						// less than 32
						if (airTemp == 'y')
							cout << "\nTurn on carburator heat.\n\n";
					
						// invalid
						else if (airTemp != 'n' && airTemp != 'y')
							cout << "\nNot a valid entry.\n\n";
						
						// more than 32
						else
							cout << "\nSwitch to other fuel tank.\n\n";
					
					// close engine running
					}

					// invalid
					else if (engStop != 'n' && engStop != 'y')
						cout << "\nNot a valid entry.\n\n";
				
					// engine stopped
					else
					{
						cout << "\nAre you over the mountains? (y/n)\n\n";
						cin >> overMount;

						// not over mountains
						if (overMount == 'n')
						{
							cout << "\nAre you over water? (y/n)\n\n";
							cin >> overWater;

							// not over water
							if (overWater == 'n')
								cout << "\nMake an emergency landing on a road.\n\n";
						
							// invalid
							else if (overWater != 'n' && overWater != 'y')
								cout << "\nNot a valid entry.\n\n";
						
							// over water
							else
								cout << "\nInflate your life vest and make an emergency landing.\n\n";
						
						// close not over mountains
						}
					
						// invalid
						else if (overMount != 'n' && overMount != 'y')
							cout << "\nNot a valid entry.\n\n";
					
						// over mountains
						else
						{
							cout << "\nAre you flying at night? (y/n)\n\n";
							cin >> nightFly;

							// not night flying
							if (nightFly == 'n')
								cout << "\n Make an emergency landing.\n\n";
						
							// invalid
							else if (nightFly != 'n' && nightFly != 'y')
								cout << "\nNot a valid entry.\n\n";
						
							// night flying
							else
							{
								cout << "\nTurn on the landing light and look out the window. Do you like what you see?\n\n";
								cin >> lovelySight;

								// terrible sight
								if (lovelySight =='n')
									cout << "\nTurn off the landing light.\n\n";
							
								// invalid
								else if (lovelySight != 'n' && lovelySight != 'y')
									cout << "\nNot a valid entry.\n\n";
								
								// lovely sight
								else
									cout << "\nMake an emergency landing.\n\n";
							
							// close night flying
							}
						
						// close over mountains
						}
					
					// close engine stopped
					}

				// close electricals yes
				}
			
			// close airborne yes
			}
		break;

		// In-Flight Icing
		case 'i':
		case 'I': cout << "\nYou picked In-Flight Icing.\n";
			cout << "How much ice is on the wings? (in mm, between 0 and 10)\n";
			cin >> ice;

			// check to see if input is between 0 and 10
			if (ice >= 0 && ice <= 10)
			{
				// less than 1mm
				if (ice < 1)
					cout << "\nUse 5% power to energize the deicing boots for " << ice << "mm of ice.\n\n";
				
				// 1-5mm
				else if (ice <5)
					cout << "\nUse 20% power to energize the deicing boots for " << ice << "mm of ice.\n\n";
				
				// 5.1-9mm
				else if (ice <9)
					cout << "\nUse 65% power to energize the deicing boots for " << ice << "mm of ice.\n\n";
				
				// 9.1-10mm
				else
					cout << "\nUse 100% power to energize the deicing boots for " << ice << "mm of ice.\n\n";
			}

			// out of range
			else
			{
				cout << "\nThat is an invalid entry. Remember to enter between 0 and 10.\n";
				cout << "Run the program again!\n\n";
			}
		break;

		case 'q':
		case 'Q': cout << "\nYou picked Quit!!!\n\n";

		// invalid entry
		default: cout << "\nThat is an invalid entry. Remember to select C, E, I, or Q.\n\n";
	}

	return 0;

}

/*

g++ -std=c++14 -g -Wall test.cpp

*/