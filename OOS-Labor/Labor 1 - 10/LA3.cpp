#include <iostream>
#include <iomanip>
using namespace std;

void print_rectangle(int x, int y = -1){
    
    //Wenn x nicht gegeben -> Quadrat mit der Seitenlänge x ausgeben.
    if (y == -1 ) {
        y = x;
        }

    for (int i = 0; i < y; i++){   
        for (int j = 0; j < x; j++){
            cout << "X ";
        }
        cout << endl;
    }   
    cout << endl;
}
int main(int argc, char *argv[])
{
	std::cout << "x = 2, y = 5: " << std::endl;
	print_rectangle(2, 5);

	std::cout << "x = 3, y = 3: " << std::endl;
	print_rectangle(3, 3);

	std::cout << "x = 4: " << std::endl;   
	print_rectangle(4);

	return 0;
};

