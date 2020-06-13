/////////////////////////
// Read int from file string
// 1. #include<sstream>
// 2. using std::istringstream
// can read string and stop only hit space or error(end)
/////////////////////////


#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::string;
using std::istringstream;


/*
myreader is a pointer, whith point to the contain of string.
if the current pointer READ(>>) the non-number or error or endoffile
the myreader will return error or 0 or false

every time you extract a contain, the myrerader will move right to next contain.
*/


void istringstream_test(){
    cout << __func__<< "\n";

    string a("1 2 3");

    istringstream my_stream(a);

    int n;
    my_stream >> n;
    cout << n << "\n";
}


void use_isstringstream_as_boolen_read_all(){
    cout << __func__<< "\n";

    string a("1 2 3");

    istringstream my_stream(a);

    int n;
    
    // Testing to see if the stream was successful and printing results.
    while (my_stream) {
        my_stream >> n;
        if (my_stream) {
            cout << "That stream was successful: " << n << "\n";
        }
        else {
            cout << "That stream was NOT successful!" << "\n";            
        }
    }
}

void common_way_to_use_istringstream_in_while(){
    cout << __func__<< "\n";

    istringstream myreader("1 2 3");
    int n;
    while(myreader>>n){
        cout << "read: "<< n << "\n";
    }
    cout << "The stream has failed or ended." << "\n";
}



void string_with_MIX_types_not_space(){
/*
In the stream example above, the string contained only whitespaces
and characters which could be converted to ints.

If the string has mixed types, more care is needed to process the string.
In the following example,
the type char is used, which is a type that can hold only a single ASCII character.
*/
    cout << __func__<< "\n";

    string b("1,2,3,4,6q7p8o9");

    istringstream mixstring(b);

    //need two type of tmp value
    char c;
    int n;

    /*
        !! notice that the 9 was not printed

        mixstring >> n >> c

        tried to stream an int followed by a char.
        Since there was no char after the 9, the stream
        failed and the while loop exited.
    */
    while(mixstring >> n >> c){
        cout << "read int: "<< n << ", read char: " << c << "\n";
    }
    cout << "The stream has failed or ended." << "\n";
}


int main(){
    //stream with all INT type
    istringstream_test();
    use_isstringstream_as_boolen_read_all();
    common_way_to_use_istringstream_in_while();

    //stream with MIX type
    //the INT spreated by only one char not space
    string_with_MIX_types_not_space();
}
// istringstream_test
// 1
// use_isstringstream_as_boolen_read_all
// That stream was successful: 1
// That stream was successful: 2
// That stream was successful: 3
// That stream was NOT successful!
// common_way_to_use_istringstream_in_while
// read: 1
// read: 2
// read: 3
// The stream has failed or ended.
// string_with_MIX_types_not_space
// read int: 1, read char: ,
// read int: 2, read char: ,
// read int: 3, read char: ,
// read int: 4, read char: ,
// read int: 6, read char: q
// read int: 7, read char: p
// read int: 8, read char: o
// The stream has failed or ended.