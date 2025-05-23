#include <array>
#include <iostream>
using namespace std;

const unsigned int length = 10;

template <typename T, size_t N> // Hier Typ des arrays und Größe initialisieren
array<T, N> sort(array<T, N> array){
  for(size_t i = 0; i < N - 1; i++){
    for(size_t  j = 0; j < N - i - 1; j++){
      if(array[j] > array[j + 1]){
           swap(array[j], array[j + 1]); // Man kann es auch mit einer temp-Variable sortieren
      }
    }
  }
  return array;
}

int main(int argc, char *argv[])
{
    array<int,length> int_container = {10, 2, 7, 5, 8, 3, 4, 1, 9, 6};
    array<int, length> sorted_int_container = sort(int_container);

    for (size_t i = 0; i < sorted_int_container.size(); i++) {
        cout << i << ": " << sorted_int_container[i] << endl;
    }

    array<char,length> char_container = {'j', 'm', 'e', 't', 'k', 'o', 'p', 's', 'a', 'f'};
    array<char, length> sorted_char_container = sort(char_container);

    for (size_t i = 0; i < sorted_char_container.size(); i++) {
        cout << i << ": " << sorted_char_container[i] << endl;
    }

    array<string,length> string_container = {"Im", "Sommer", "ist", "es", "meistens", "heiß", "und", "es", "regnet", "wenig."};
    array<string, length> sorted_string_container = sort(string_container);

    for (size_t i = 0; i < sorted_string_container.size(); i++) {
        cout << i << ": " << sorted_string_container[i] << endl;
    }
}

