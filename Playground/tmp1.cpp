#include <iostream>
#include "Triangle.h"
using std::cin;
using std::cout;

bool isTriangle(double a, double b, double c) {
	if ((b + c > a) && (a + c > b) && (a + b > c) && (a > 0) && (b > 0) && (c > 0))
		return true;
	return false;
}

int main() {
	double a, b, c, d, e, f;
	cout << "Enter the sides of first triangle: ";
	cin >> a >> b >> c;
	cout << "Enter the sides of second triangle: ";
	cin >> d >> e >> f;


	Angle bac, abc, acb;
	Angle edf, def, dfe;

	Triangle A(a, b, c);

	//Triangle B(d, e, f);

	int choice;

	if (isTriangle(a, b, c) && isTriangle(d, e, f)) {
		/*A.setAB(a);
		A.setBC(b);
		A.setAC(c);
		B.setAB(d, edf, def, dfe);
		B.setBC(e, edf, def, dfe);
		B.setAC(f, edf, def, dfe);
		B.set(d, e, f);*/
		do {
			cout << "Choose an action:\n";
			cout << "1. Calculate the Area.\n";
			cout << "2. Calculate the Perimeter.\n";
			cout << "3. Find the A Heights.\n";
			cout << "4. Find the B Heights.\n";
			cout << "5. Find out the Types.\n";
			cout << "6. Increase Degrees and Minutes.\n";
			cout << "7. Decrease Degrees and Minutes.\n";
			cout << "8. Degrees to Radians.\n";
			cout << "9. Find the sine.\n";
			cout << "0. Exit.\n";

			cin >> choice;
			cout << "\n===================================================\n";
			switch (choice) {
			case 1: {
				cout << "The Area of triangles:\n" <<
					"A: " << A.getArea() << "\n";// <<
					//"B: " << B.getArea() << "\n";
				break;
			}
			case 2: {
				cout << "The Perimeter of triangles:\n" <<
					"A: " << A.getPerimeter() << "\n";// <<
					//"B: " << B.getPerimeter() << "\n";
				break;
			}
			case 3: {
				cout << "The Heights of triangle A:\n" <<
					"AB = " << A.getHeightAB() << "\n" <<
					"BC = " << A.getHeightBC() << "\n" <<
					"AC = " << A.getHeightAC() << "\n";
				break;
			}
			case 4: {
				/*cout << "The Heights of triangle B:\n" <<
					"AB = " << B.getHeightAB() << "\n" <<
					"BC = " << B.getHeightBC() << "\n" <<
					"AC = " << B.getHeightAC() << "\n";
				break;*/
			}
			case 5: {
				cout << "The Type of triangles:\n" <<
					"A: " << A.triangleType() << "\n"; //<<
					//"B: " << B.triangleType() << "\n";
				break;
			}
			case 6: {
				double d, m;
				cout << "How many degrees and minutes? ";
				cin >> d >> m;
				
				bac.increaseDegrees(d); bac.increaseMinutes(m);
				abc.increaseDegrees(d); abc.increaseMinutes(m);
				acb.increaseDegrees(d); acb.increaseMinutes(m);
				edf.increaseDegrees(d); edf.increaseMinutes(m);
				def.increaseDegrees(d); def.increaseMinutes(m);
				dfe.increaseDegrees(d); dfe.increaseMinutes(m);
				cout << "\nNew value of Angles:\n" << 
					"A: BAC = " << bac.toDegrees() << "; ABC = " << abc.toDegrees() << "; ACB = " << acb.toDegrees() << "\n" <<
					"B: BAC = " << edf.toDegrees() << "; ABC = " << def.toDegrees() << "; ACB = " << dfe.toDegrees() << "\n";
				break;
			}
			case 7: {
				double d, m;
				cout << "How many degrees and minutes? ";
				cin >> d >> m;
				bac.decreaseDegrees(d); bac.decreaseMinutes(m);
				abc.decreaseDegrees(d); abc.decreaseMinutes(m);
				acb.decreaseDegrees(d); acb.decreaseMinutes(m);
				edf.decreaseDegrees(d); edf.decreaseMinutes(m);
				def.decreaseDegrees(d); def.decreaseMinutes(m);
				dfe.decreaseDegrees(d); dfe.decreaseMinutes(m);
				cout << "\nNew value of Angles:\n" <<
					"A: BAC = " << bac.toDegrees() << "; ABC = " << abc.toDegrees() << "; ACB = " << acb.toDegrees() << "\n" <<
					"B: BAC = " << edf.toDegrees() << "; ABC = " << def.toDegrees() << "; ACB = " << dfe.toDegrees() << "\n";
				break;
			}
			case 8: {
				cout << "Value of Angles in Radians:\n" <<
					"A: BAC = " << bac.toRadians() << "; ABC = " << abc.toRadians() << "; ACB = " << acb.toRadians() << "\n" <<
					"B: BAC = " << edf.toRadians() << "; ABC = " << def.toRadians() << "; ACB = " << dfe.toRadians() << "\n";
				break;
			}
			case 9: {
				cout << "The sine of Angles:\n" <<
					"A: BAC = " << bac.getSin() << "; ABC = " << abc.getSin() << "; ACB = " << acb.getSin() << "\n" <<
					"B: BAC = " << edf.getSin() << "; ABC = " << def.getSin() << "; ACB = " << dfe.getSin() << "\n";
				break;
			}
			case 0: break;
			default: break;
			}
			cout << "===================================================\n\n";
		} while (choice);
	}
	else cout << "This is not a triangle!\n";

	return 0;
}
