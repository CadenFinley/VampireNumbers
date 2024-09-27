//
//  main.cpp
//  vampire numbers
//
//  Created by Caden Finley on 8/29/23.
//
#include <vector> //for vector 2d arrays
#include <algorithm>//for sorting function
#include <iostream>//console reading and writing
#include <sstream>//easier writing to lists and reading and iterating lists
#include <cmath>//complex math (ie. pow)
using namespace std; //namespace malarkey so I dont have to do std::
bool TestInput(int n){ //checks to make sure input is loger than 1 digit and is not text or special charaters
    string n_str = to_string(n); //convert input to string from int
        if (n_str.size() % 2 == 1) { //test length of input
            return false;
        }
    return true;
}
bool VampireNumber( long number, vector<pair<long, long> > & solution ) { //test all possible factors for fangs with process of elimination
   ostringstream numberList ; //create number iteration list
   numberList << number ; //put number input into list
   string numberstring(numberList.str()); //convert int list into string list
    
   sort(numberstring.begin(), numberstring.end()); //use sort function to organize numbers
   long fanglength = numberstring.length()/2; //tests to see if its a positive number of digits
   long firstIteration = static_cast<long>(pow(10,fanglength-1)); //first iteration of process of elimination of finding fangs(factoring)
   long lastIteration = sqrt(number);  //last iteration of process of elimination of finding fangs
    
   for (long index = firstIteration; index <= lastIteration ; index++ ) { //loop through iterations of factors to test if they are fangs
      if (number % index == 0) {
          long quotient = number / index;
          
          if ((index % 10 == 0) && (quotient % 10 == 0)) //tests for trailing zeros in the two factors
              continue ; //continues checks if fangs do not both have trailing zeros, break checks at first fail
          
     numberList.str(""); //clear number list
          
     numberList << index << quotient ; //input new fangs
     string divisionString (numberList.str()); //input fangs into string list
     sort (divisionString.begin(),divisionString.end()); //combines digits into string
          
     if (divisionString == numberstring) { //test to see if fangs digits match input
        pair<long , long> divisors = make_pair(index, quotient);
        solution.push_back(divisors);
        }
      }
   }
   return !solution.empty(); //ends checks
}
void PrintToConsole(const pair<long, long> & solution) { //console output function
    cout << solution.first << " * " << solution.second<< "\n"; //prints fangs stored from vector
}
void PassErrorChecking(){ //error message formula
    cout << "Input an Integer longer than 1 digit only!\n";
}
void FailPrintToConsole(){
    cout <<"No stakes needed\n"; //print "No stakes needed" error message
}
int main( ) { //primary code driver
    cout<<"Enter a number: ";
    int num;
    cin >> num; //take input
    vector<pair<long , long> > solutions ; //create 2d vector to store all factor pairs for console printing purposes
    if(TestInput(num)){ //test for input number of more than 1 digit
        solutions.clear(); //clear solutions vector from previous uses of program
        
        if ( VampireNumber(num, solutions)) { //test number and pass the input and solutions vector
            for_each(solutions.begin(), solutions.end(),PrintToConsole); //prints output
        }
        else {
            FailPrintToConsole();
        }
    }
    else {
        PassErrorChecking(); //run error message
        
    }
}

