#include <iostream>
using namespace std;


class ClubMember{

    static int _s_count;
    int _member_id;
    static int _id_generator;
    
    public:

    ClubMember(){
        _s_count++;
        _member_id = _id_generator++;
    }

    ~ClubMember(){
        _s_count--;

    }

    void print(){
        cout << "Member-ID: " << _member_id << endl;
    }

    static int get_count(){
        return _s_count;
    }

    void print_amount_of_members(){
        cout << "Anzahl Mitglieder: " << _s_count << endl;
    }
};

int ClubMember::_s_count = 0;
int ClubMember::_id_generator = 0;


int main(int argc, char const *argv[])
{
    cout << "Anzahl Mitglieder: " << ClubMember::get_count() << endl;

    ClubMember peter;
    peter.print();
    peter.~ClubMember();
    ClubMember alice;
    alice.print();
    ClubMember gustav;
    gustav.print();

    cout << "Anzahl Mitglieder: " << ClubMember::get_count() << endl;

    
    return 0;
}
