
// String.h

#include <iostream>
#include <cassert>

using namespace std;

class String {
        int sizE;
        char *buffer;
public:
	//constructors    
   	String();
    String(const String&);
    String(const char*);
    ~String();
       
    //methods   
	int length();
	int strlen(const char * cs);
	String& operator+=(const char*);
	char operator[](int);
	String& operator=(const String&);

	// friend functions
    friend bool operator==(const String &, const String &);
    friend bool operator<=(const String &, const String &);
    friend bool operator>(const String &, const String &);
    friend ostream & operator<<(ostream &, const String &);  
};

int main(){

String s1; // s1 == ""
   assert(s1.length() == 0);

   String s2("hi");  // s2 == "hi"
   assert(s2.length() == 2);

   String s3(s2);  // s3 == "hi"
   assert(s3.length() == 2);
   assert(s3[0] == 'h');
   assert(s3[1] == 'i');

   s1 = s2;  // s1 == "hi"
   assert(s1 == s2);

   s3 = "bye";  // s3 == "bye"
   assert(s3.length() == 3);
   assert(s3[0] == 'b');
   assert(s3[1] == 'y');
   assert(s3[2] == 'e');
   
   s1 += "re";  // s1 == "hire"
   assert(s1 == "hire");

   s1 += "d"; // s1 == "hired"
   assert(not (s1 == "hire"));

   cout << "SUCCESS" << endl;
 
}


//CONSTRUCTORS


//default constructor
String::String(){
    cout << "INSIDE DEFAULT" << endl;
    sizE = 0;
    buffer = new char[sizE]; 
    buffer = nullptr;
}


//constructor for String s(s2);
String::String(const String &temp){   //core dump when adding delete[]
	cout << "INSIDE s(s2) constructor" << endl;
    sizE = temp.sizE;
    buffer = new char[sizE];
    for(int i = 0;i < sizE ;i++){
        buffer[i] = temp.buffer[i];
    }
}



//for String s("abc");
String::String(const char* temp){
	cout << "INSIDE c-string constructor" << endl;
    sizE = strlen(temp);
    buffer = new char[sizE];
    for(int i = 0; i < sizE; i++)
		buffer[i]=temp[i];

}

//destructor
String::~String(){
    cout << "INSIDE DESTRUCTOR" << endl;
    sizE = 0;
    delete []buffer;
    buffer = nullptr;
}



//NON FRIEND METHODS



String& String::operator+=(const char* rhs){
	int new_size;
	new_size = this->sizE + strlen(rhs);

	String s1;

	s1.buffer = new char[this->sizE];

	for(int i = 0; i < this->sizE; i++) //copy this->buffer into s1 buffer
		s1.buffer[i] = this->buffer[i];   //works

	
		s1.sizE = this->sizE;

	

	delete []this->buffer;    //delete this buffer
        this->buffer = new char[new_size];  //recreate it with new size

    int j = 0;
	for(int i = 0; i < s1.sizE; i++){     //make first "half" of array equal to old this buffer
		this->buffer[i] = s1.buffer[i];
		j++;
	}
        
  
   
        int k = s1.sizE;
	for(int i = 0; i < strlen(rhs); i++){
		this->buffer[k] = rhs[i];
			k++;
	}
	   

	this->sizE = new_size;
	return *this;


}



int String::strlen(const char * cs){
	int i = 0;
	while(*cs != '\0'){
	    i++;
	    cs++;
}
	return i;
}



int String::length(){
    return sizE;
}





//FRIEND FUNCTIONS








//assignment
String& String::operator=(const String& rhs){
	delete []this->buffer;
        this->buffer = new char[rhs.sizE];

        this->sizE = rhs.sizE;
	for(int i = 0; i < this->sizE; i++)
		this->buffer[i] = rhs.buffer[i];

	return *this;

}


char String::operator[](int i){

	return this->buffer[i];
}


bool operator==(const String & lhs, const String & rhs){

	int i = 0;
	do{
	    if(lhs.buffer[i] != rhs.buffer[i])
			return false;
 	
	    if(lhs.buffer[i] == rhs.buffer[i])
			i++;
	    }while(lhs.buffer[i] != '\0' || rhs.buffer[i] != '\0');
	return true; 
}


bool operator<=(const String & lhs, const String & rhs){
   int i = 0;
   do{
   		if(lhs.buffer[i] < rhs.buffer[i]){
   			i++;
			return true;
   		}

		else if(lhs.buffer[i] > rhs.buffer[i])
			return false;
 				
	    else if(lhs.buffer[i] == rhs.buffer[i])
			i++;
	    
	    else
	    	cout << "ERROR INPUT ERROR" << endl;



   }while(lhs.buffer[i] != '\0' || rhs.buffer[i] != '\0');

   return true;
}



bool operator>(const String & lhs, const String & rhs){
    int i = 0;
   do{
   		if(lhs.buffer[i] < rhs.buffer[i])
   			return false;
   		

		else if(lhs.buffer[i] > rhs.buffer[i])
			return true;
 				
	    else if(lhs.buffer[i] == rhs.buffer[i])
			i++;
	    
	    else
	    	cout << "ERROR INPUT ERROR" << endl;



   }while(lhs.buffer[i] != '\0' || rhs.buffer[i] != '\0');

   return true;
}


ostream & operator<<(ostream & os, const String & str){

         os << str.buffer;
	return os;

}












