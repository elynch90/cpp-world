#include <iostream>
#include <vector>

class DynamicArray {
   private:
      std::string* data;
      int capacity;
      int size;
   public:
      DynamicArray() : data(new std::string[2]), capacity(2), size(0) {}
      void print(){
         for(int i = 0; i < size; ++i){
            std::cout << data[i] << " ";
         }
         std::cout << "\n";
      }
      void append(const std::string& item) {
         // check if +1 is within capacity
	 if (size + 1 <= capacity) {
	    // add to the next empty index
	     ++size;
             data[size - 1] = item;
         }
         else {
           // allocate a new data array
           int newCapacity = capacity * 2;
           std::string* newArray = new std::string[newCapacity * 2];
           // loop through old and add to new
           for (int i = 0; i < capacity; ++i){
              newArray[i] = data[i];
           }
           // add latest
           newArray[capacity] = item;
           // update capacity
	   capacity = newCapacity;
           // free old data
           delete[] data;
           data = newArray;
         }
         // add item at index
         data[size++] = item;
      }
    
      // destructor
      ~DynamicArray() {
         delete[] data;
      }

    std::string get(int index){
        // check if out of bounds index
        if (size < index) {
            return "OUT OF BOUNDS INDEX";
        }
        return data[index];
    }
};

// ✅ TEST CASES
int main() {
    DynamicArray arr;
    arr.append("apple");
    arr.append("banana");
    arr.append("cherry");  // This should trigger resizing
    arr.append("date");
    arr.print();  // Expected Output: apple banana cherry date

    std::cout << "Element at index 2: " << arr.get(2) << "\n";  // Expected Output: cherry
    std::cout << "Element at index 5: " << arr.get(5) << "\n";  // Expected Output: Index out of bounds

    return 0;
}
