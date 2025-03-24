#include <iostream>
#include <cstring>
#include <stdexcept>
#include <iomanip>


typedef struct Cars
{
    int id;
    char carBrand[20];
    char model[20];
    int year;
    struct Cars *next;
} Car; 

//Create a new node
Car* createNode(int id, const char* carBrand, const char* model, int year){
   if(model == nullptr) throw std::invalid_argument("Model cannot be null.");

   Car* newNode = new Car();
   if(!newNode) throw std::bad_alloc();

   newNode->id = id;
   strncpy(newNode->carBrand, carBrand, sizeof(newNode->carBrand) - 1);
   newNode->carBrand[sizeof(newNode->carBrand) - 1] = '\0';

   strncpy(newNode->model, model, sizeof(newNode->model)- 1);
   newNode->model[sizeof(newNode->model) - 1] = '\0';

   newNode->year = year;
   newNode->next = nullptr;

   return newNode;
}


Car* newCar(Car* root, int id,const char* carBrand, const char* model, int year){
    if (model == nullptr){
        throw std::invalid_argument("Model cannot be null.");
    }

    Car* newNode = createNode(id, carBrand, model, year);
        if(!root){
            return newNode;
        }

        if(id < root-> id){
            newNode->next = root;
            return newNode;
            }

    //direct sorting of the nodes
    Car* current = root;
    while (current->next && current ->next->id < id){
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    return root;
}


void clearList(Car** root){
    while(*root){
        Car* temp = *root;
        *root = (*root)->next;
        delete temp;
    }
}

void printList(Car* root){
    Car* current = root;
    std::cout << std::left << std::setw(5) << "ID" 
    << " | " << std::setw(15) << "BRAND" 
    << " | " << std::setw(15) << "MODEL" 
    << " | " << std::setw(6) << "YEAR" 
    << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;


    while(current != nullptr){
        std::cout << std::left << std::setw(5) << current->id 
                  << " | " << std::setw(15) << current->carBrand 
                  << " | " << std::setw(15) << current->model 
                  << " | " << std::setw(6) << current->year 
                  << std::endl;
        current = current->next;
    
    }
}

int main(int argc, char const *argv[])
{
    try
    {
        Car* root = nullptr;
        root = newCar(root, 1, "Toyota", "Camry", 2022);
        root = newCar(root, 2, "Honda", "Civic", 2021);
        root = newCar(root, 10, "VW", "Golf", 2019);
        root = newCar(root, 3, "Audi ", "A4", 2024);
        root = newCar(root, 4, "BMW", "3 series", 2021);
        printList(root);

        clearList(&root);
    }
    catch(const std::invalid_argument& e){
        std::cerr << e.what() << std::endl;
    } 
    catch(const std::bad_alloc&e){
        std::cerr << "Memory allocation failed" << std::endl;
    }
    catch (const std::exception& e){
        std::cerr << "Error: An unknown error occured - "<<e.what() << std::endl;
    }
    catch (...){
        std::cerr << "An unknown error occurred" << std::endl;
    }

   
    return 0;
}

