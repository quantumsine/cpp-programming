#include <string>
#include <ctime>
#include <iostream>

// Optional
#include <chrono>
#include <thread>

using namespace std;

// Aufzählungstyp für wählbare Objekte
// STEIN - 0, SCHERE - 1, PAPIER - 2
enum class Object
{
    ROCK,
    SCISSORS,
    PAPER
};

// Aufzählungstyp für mögliche Spielausgänge
enum class Result
{
    PLAYER_WINS,
    COMPUTER_WINS,
    DRAW
};

// Struktur für einen Spieler bestehend aus Name und Wahl des Spielers
struct Player
{
    string name;
    Object choice;
};

// Name des Spielers eingeben
string insert_name()
{
    // HIER programmieren:
    // Den Namen des Spielers von der Konsole einlesen und zurückgeben
    // Tip: für das Einlesen eines Strings gibt es eine bestimmte Funktion, siehe auch Vorlesung Folie "Eine Zeile als String einlesen"
    string name;
    cout << "Name des Spielers: ";
    cin.clear();
    getline(cin, name);
    return name;

}

Object determine_choice(string choice)
{
    if (choice.compare("CoderunnerTestValueROCK") == 0)
    {
        return Object::ROCK;
    }
    else if (choice.compare("CoderunnerTestValueSCISSORS") == 0)
    {
        return Object::SCISSORS;
    }
    else if (choice.compare("CoderunnerTestValuePAPER") == 0)
    {
        return Object::PAPER;
    }
    else
    {
        // Den Computer zufällig waehlen lassen.

        // HIER beantworten Sie folgende Fragen:
        // Was bewirkt die funktion srand?
        // Warum wird hier die Zeit (time) als Eingabe für die Funktion srand verwendet?
        // Wie funktioniert die funktion rand?
        // Warum wird hier modulo 3 verwendet?

        srand(static_cast<int>(time(nullptr))); //srand = generiert eine Reihe von pseudo-Werten

        /* im srand wird ein seed benötigt, der die Zufallsgeneration initialisiert
        time = gibt die aktuelle Zeit in Sekunden seit 1.1.1970 zurück*/

        // rand ist generiert eine Zahl in einem Bereich (0 bis 32767 normalerweise) und gibt sie zurück
        //Durch die Modulo-Operation mit 3 wird die Auswahl rand auf 3 Optionen (Schere, Stein, Papier) reduziert.
        int choice = rand() % 3;

        return static_cast<Object>(choice);
    }
}

// Die Wahl von Stein etc. als String zurückgeben lassen
string get_name(Object object)
{
    switch (object){
        case Object::ROCK:
        return "Stein";
        case Object::SCISSORS:
        return "Schere";
        case Object::PAPER:
        return "Papier";

        default:
        return "Unbekanntes Objekt";
        break;
    }

}

// Einen Text mit dem Namen des Spielers und seiner Wahl ausgeben
void print_choice(Player player)
{
    cout << player.name << " hat das Objekt " << get_name(player.choice) << " gewählt" << endl;
    
}

// Die Wahl des Spielers abfragen
Object choose()
{
    int choice; 


    do
    {
        cout << "Bitte Objektwahl eingeben (1 = Stein, 2 = Schere, 3 = Papier): ";
        cin >> choice;

        //Fehlerüberprüfung bei der Eingabe:
        if (cin.fail()){
            cin.clear(); // Status wird zurückgesetzt
            cin.ignore(1000, '\n'); // Alle verbleibenden Eingaben werden ignoriert

            cout << "Ungültige Eingabe, bitte eine Zahl zwischen 1 und 3 eingeben." << endl;
        }




    } while (choice != 1 && choice != 2 && choice != 3);

    if (choice == 1) return Object::ROCK;
    if (choice == 2) return Object::SCISSORS;
    
    return Object::PAPER;
    //return static_cast<Object>(choice -1);
}

Result determine_result(Player player, Player computer)
{

    //1. Bedingung für Unentschieden
    if (player.choice == computer.choice){
        return Result::DRAW;
    }
    
    switch(player.choice){ 

        case Object::ROCK:
        if (computer.choice == Object::SCISSORS){
            return Result::PLAYER_WINS;
        } else if (computer.choice == Object::PAPER){
            return Result::COMPUTER_WINS;
        }
        break;

        case Object::PAPER:
        if (computer.choice == Object::ROCK){
            return Result::PLAYER_WINS;
            } else if (computer.choice == Object::SCISSORS){
                return Result::COMPUTER_WINS;
        }
        break;

        case Object::SCISSORS:
        if (computer.choice == Object::PAPER){
            return Result::PLAYER_WINS;
            } else if (computer.choice == Object::ROCK){
                return Result::COMPUTER_WINS;
        
        }
        break;
    }
        return Result::DRAW; //Fallback-Fall, sollte nicht erreicht werden

   }



void print_result(Player player, Player computer)
{

    Result result = determine_result(player, computer);
    switch(result){
        case Result::PLAYER_WINS:
        std::cout << "Spieler " << player.name <<  " hat gewonnen." << std::endl;
        break;

        case Result::COMPUTER_WINS:
        std::cout << "Spieler Computer hat gewonnen." << std::endl;
        break;

        case Result::DRAW:
        std::cout << "Unentschieden" << std::endl;
        break;

    }


}

int main(int argc, char *argv[])
{
    
    Player player, computer;
    player.name = insert_name();
    computer.name = "Computer";
    computer.choice = determine_choice(player.name);
    cout << "Der Computer hat seine Wahl getroffen." << endl;
    player.choice = choose();

    this_thread::sleep_for(chrono::milliseconds(1000));
    print_choice(computer);
    this_thread::sleep_for(chrono::milliseconds(1000));
    print_choice(player);
    this_thread::sleep_for(chrono::milliseconds(1000));
    print_result(player, computer);

    return 0;
}

    