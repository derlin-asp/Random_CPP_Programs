#include <iostream>
using namespace std;


//FindMatches Function
void findMatches(
    const int* values, //int pointer can take in an array
    size_t valuesLength, //size of array
    int query,            //waat were looking for
    int* firstMatchIndex,   //position of first query
    size_t* numberOfMatches     //total number of queries found
) {

    //since it is a pre-sorted array of integers all we need to do is loop until we hit a non query after we find it

    size_t temp_count = 0; //temp variables to make function easier to read
    int temp_first = -1;
    for(int i = 0; i < valuesLength; i++,values++){ //incrementing values via pointer arithmatic
        cout << *values;
        if( *values == query){ //checking if current value = query
            temp_count++;     //add to count if true
            if(temp_count == 1)  //checking if it was first time
                temp_first = i;  //saving current index
            if(i+1 != valuesLength && *(values+1) != query  ) //if were not at end of array and next value is not query
                // then were done, this is so if the array is long we dont need to go all the way trough it
                break;

        }
    }
    *firstMatchIndex = temp_first;
    *numberOfMatches = temp_count;


 }


int main() {

    int *first_match_ptr = new int;     //ptr in main to be edited by reference
    size_t *match_count_ptr = new size_t; //same

    const int array_size = 6; //const int for size so we know that the size of the array matches whats inputed into function
    int arr [array_size] = {1,2,3,4,5,5};

    findMatches(arr, array_size,3, *&first_match_ptr, *&match_count_ptr); //passing in pointer by referencce
    cout << endl << endl << "Index of First Match: " << *first_match_ptr;
    cout << endl << endl << "Number of Matches: " << *match_count_ptr;
    return 0;
}



