
#include <string>
#include <iostream>
using namespace std;

struct ListElement
{
    int id;
    ListElement* p_next;
};

ListElement* p_root = nullptr;

void add_new_head_element(int id)
{
    ListElement* p_new_element = new ListElement();
    p_new_element->id = id;
    p_new_element->p_next = p_root;
    p_root = p_new_element;
}

void add_new_tail_element(int id)
{
    // HIER programmieren:
    // Neues listenElement erzeugen.
    // Ans Ende der Liste navigieren und neues listenElement anhängen.

    //Temporären Punkt auf das Ende der Liste setzen
    ListElement* temp = new ListElement();
    temp->id = id;
    temp->p_next = nullptr;

    ListElement* current = p_root;
    if (current == nullptr) {
        p_root = temp;
        return;
    }

    //Bis zum Ende der Liste traversieren & den neuen Punkt anhängen
    while (current->p_next != nullptr) {
        current = current->p_next;
    }

    current->p_next = temp;
    
}

void delete_element(int id)
{
    ListElement *p_tmp = p_root;
    ListElement *p_predecessor = nullptr;

    while (p_tmp != nullptr && p_tmp->id != id)
    {
        p_predecessor = p_tmp;
        p_tmp = p_tmp->p_next;
    }
    if (p_tmp != nullptr)
    {
        if (p_tmp == p_root)
        {
            p_root = p_tmp->p_next;
        }
        else
        {
            p_predecessor->p_next = p_tmp->p_next;
        }
    }
    delete p_tmp;
}

void print_list()
{
    // Hier programmieren:
    // Die Liste durchlaufen und jeweils die id des listenElements ausgeben.
    ListElement* p_current = p_root;
    while ( p_current != nullptr)
    {
        std::cout << p_current->id << std::endl;
        p_current = p_current->p_next;
    }
    
}

int main(int argc, char* argv[])
{
    add_new_tail_element(9);
    add_new_head_element(2);
    add_new_head_element(1);
    add_new_tail_element(10);
    print_list();
    delete_element(2);
    print_list();

    return 0;
};
