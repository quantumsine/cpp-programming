#include <iostream>
using namespace std;

// ERWEITERUNG AUS ÜBUNG 2


template <typename T>
class ArrayElement{
    T data;
    ArrayElement *next;

    public:

    ArrayElement(){
        cout << "IntArrayElement erzeugt.\n";
    }

    ~ArrayElement(){
        cout << "IntArrayElement zersört.\n";
        delete next;
    }


    int getData(){
        return data;
    }

    ArrayElement* getNext(){
        return next;
    }

    void setData(T data){
        this->data = data;
    }


    void setNext(ArrayElement* next){
        this->next = next;
    }

};

template <typename T>
class DynIntArray{

    ArrayElement<T>* _root;

    public:
    DynIntArray(){
        _root = nullptr;
    }

    ~DynIntArray(){
        delete _root;
    }

    void push_back(T data){
        ArrayElement<T>* new_elem = new ArrayElement<T>();
        new_elem->setData(data);
        new_elem->setNext(nullptr);

        ArrayElement<T>* tmp = _root;

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
        ArrayElement<T> *tmp = _root;

        while(tmp != nullptr){
            tmp = tmp->getNext();
            i++;
        }
        return i;
    };

    T at(int index){
        ArrayElement<T> *tmp = _root;
        int i = 0;
        while(index != i){
            tmp = tmp->getNext();
            i++;
        }
        return tmp->getData();
    };

    T operator[](int index){
        return at(index);
    }
};

int main(){
    cout << "Gleich geht es rein... "<< endl;
    {
        DynIntArray<int> int_array;
        int_array.push_back('a'); // Output: 97
        int_array.push_back('b'); // Output: 98
        int_array.push_back(30);
        cout << "size: " << int_array.size() << endl;
        for (int i = 0; i < int_array.size(); i++)
        {
            cout << i << ": " << int_array[i] << endl;
        }
        
    }
    cout << "Jetzt wieder draussen..." << endl;
    return 0;

}


