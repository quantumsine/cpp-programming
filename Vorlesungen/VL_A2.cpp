#include <iostream>
using namespace std;

class IntArrayElement{
    int data;
    IntArrayElement *next;

    public:

    IntArrayElement(){
        cout << "IntArrayElement erzeugt.\n";
    }

    ~IntArrayElement(){
        cout << "IntArrayElement zersört.\n";
        delete next;
    }


    int getData(){
        return data;
    }

    IntArrayElement* getNext(){
        return next;
    }

    void setData(int data){
        this->data = data;
    }


    void setNext(IntArrayElement* next){
        this->next = next;
    }

};


class DynIntArray{

    IntArrayElement* _root;

    public:
    DynIntArray(){
        _root = nullptr;
    }

    ~DynIntArray(){
        delete _root;
    }

    void push_back(int data){
        IntArrayElement* new_elem = new IntArrayElement();
        new_elem->setData(data);
        new_elem->setNext(nullptr);

        IntArrayElement* tmp = _root;

        if (_root == nullptr){
            _root = new_elem;
        } else {
        
            while (tmp->getNext() != nullptr)
            {
                tmp = tmp->getNext();
            }
            tmp->setNext(new_elem);
            }
    };

    int size(){
        int i = 0;
        IntArrayElement *tmp = _root;

        while(tmp != nullptr){
            tmp = tmp->getNext();
            i++;
        }
        return i;
    };

    int at(int index){
        IntArrayElement *tmp = _root;
        int i = 0;
        while(index != i){
            tmp = tmp->getNext();
            i++;
        }
        return tmp->getData();
    };
};

int main(){
    cout << "Gleich geht es rein... "<< endl;
    {
        DynIntArray int_array;
        int_array.push_back(10);
        int_array.push_back(20);
        int_array.push_back(30);
        cout << "size: " << int_array.size() << endl;
        for (int i = 0; i < int_array.size(); i++)
        {
            cout << i << ": " << int_array.at(i) << endl;
        }
        
    }
    cout << "Jetzt wieder draussen..." << endl;
    return 0;

}