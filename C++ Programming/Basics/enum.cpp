#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    //Wie enums normalerweise aussehen:
    enum ECOLOR{
        RED, GREEN, BLUE //In Reihe 0, 1, 2
    };

    //Um die Aufzählungswerte wiederholt verwenden zu können, wird ein class gebraucht:

    enum class Color{
        HEART,
        SPADES,
        DIAMOND,
        CLUBS
    };

    enum class Ores{
        COAL,
        IRON,
        GOLD,
        DIAMOND
    };

    //Dabei muss der Bereichsoperator verwendet werden.
    Color one = Color::DIAMOND;
    Ores two = Ores::DIAMOND;

    //Aber: Durch die Verwendung von enum class sind implizite Typumwandlungen nicht möglich:
    //int i = Color::DIAMOND + Ores::DIAMOND;

    //Lösung
    int i = static_cast<int>(Color::DIAMOND) + static_cast<int>(Ores::DIAMOND);

    return 0;
}

