#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<int> a = {3,2,1,0};

    vector<int> x; //Creates an empty vector

    vector<int> y(5); //Creates a vector with 5 elements

    vector<int> z(3,7); //Creates a vector with 3 elements, initialized to 7.

    vector<string> g; //You CAN HAVE A VECTOR HOLDING ANY TYPE FROM PRIMITIVE TO OBJECT


    vector<int> t[5]; //Creates an array of 5 elements where each element is a vector of ints. All int vectors are empty.
    a[0].push_back(3); //Add 3 to the end of the first vector in the array.


    //Each vector has a pointer to a dynamic array,


    cout << a[1] << endl;

    z.pop_back(); //Removes an element form the end and decreases the size by one.

    z.push_back(3); //Add 3 to the end of the vector, increasing the size by one.

    z.erase(z.begin()); // Erases first element of the array.

    x.erase(x.begin(),x.end()); //Deletes all elements in the array.

    z.back(); //Will return the last element of the vector

    cout << z.size() << endl;

    x.push_back(3); //Adding element 3 to vector x.

    cout << x[0] << endl;

    return 0;
}

/*

.size(); -- Gets size of the vector.
.pop_back(); -- Removes but does not return the last element.
.push_back(); --Adds an element to the end of the vector, increasing size by one.
.back() -- Returns last element of the vector.


.erase(); -- can either take one or two parameters. One is just telling to delete one element at that index, and two is a range of elements to delete.
.begin();
.end();
reserve -- changes the capacity of array based on int provided of size.

*/
