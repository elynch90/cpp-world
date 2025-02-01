#include<iostream>


class Cake {
   public:
     float *weight;
     std::string name;
     std::string *ingredients;
     int numIngredients;

     Cake() : weight(nullptr), ingredients(nullptr), numIngredients(0) {}

     void setIngredients(std::string ing[], int size){
        delete[] ingredients; // prevent memory leak if reassigning
        numIngredients = size;
        ingredients = new std::string[size]; // Allocate memory for ingredients
        for (int i=0; i < size; ++i) {
           ingredients[i] = ing[i]; // copy values
        }
     }
     ~Cake() {   // destructor
        delete[] ingredients;
        delete weight;
     }
};


int main(void){
   std::cout << "hello world\n";
   // create a piece of cake
   Cake *carrotCake = new Cake();
   carrotCake->name = "Carrot Cake";
   // print the cake name
   std::cout << carrotCake->name + "\n";
   std::string ingredients[] = {"carrot", "cake", "frostin"};
   carrotCake->setIngredients(ingredients, 3); // use setter to avoid pointer issues
   // print the ingredients
   for (int i = 0; i < carrotCake->numIngredients; ++i) {
      std::cout << carrotCake->ingredients[i] << " ";
   }
   std::cout << "\n";
   // clean up
   delete carrotCake;
   return 0;
}
