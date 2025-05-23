
#ifndef FAHRZEUG_H
#define FAHRZEUG_H

class Fahrzeug{
    const int _id;
    static int _anzahl;
    bool _ist_gebucht;

public:
    Fahrzeug(int id);
    void buche();
    bool ist_gebucht() const;
    int get_id() const;
    static int get_anzahl();
    bool operator==(const Fahrzeug &fahrzeug) const;
    virtual void print() const;

};

#endif //FAHRZEUG_H
