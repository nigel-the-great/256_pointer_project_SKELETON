//============================================================================
// Name        : 256_pointer_project.cpp
// Author      : Nigel
// Version     :
// Copyright   : Your copyright notice
// Description : C++
//============================================================================

#include <iostream>
#include <fstream>      // std::ifstream
#include "../includes/constants.h"
#include "../includes/memorymanager.h"
#include "../includes/utilities.h"
#include "../includes/test.h"
#include "../includes/transform1.h"

using namespace std;

int writeFile() {
	ofstream myOutputfile;
	//myOutputfile.open(MYFILE.c_str());

	if (!myOutputfile.is_open())
			return COULD_NOT_OPEN_FILE;

	myOutputfile << "Data for a file.\n";

	//delicate, what if exception is thrown after file is opened
	//but before next line?
	//never close the file, resource leak, and some systems
	//limit number file handles open,
	myOutputfile.close();
	return SUCCESS;
}

int readFile(){
	ifstream myInputfile;
	//myInputfile.open(MYFILE.c_str());	//could open with  flags myfile.open(MYFILE, ios::in)
												//note the .c_str() call on MYFILE
	if (!myInputfile.is_open())
			return COULD_NOT_OPEN_FILE;

	//read and count the data
	std::string line;
	while (!myInputfile.eof()) {				//exits when reach end of file
		getline(myInputfile, line);				//gets a line up to '/n' char
		cout<<line;
	}

	//delicate, what if exception is thrown after file is opened
	//but before next line?
	//never close the file, resource leak, and some systems
	//limit number file handles open,
	myInputfile.close();
	return SUCCESS;
}

int main( int argc, char *argv[] )  {

	//TODO read commandline params
	//expect progname, infile, total_memory, results_file   //program and 3 arguments, argc=4
	if( argc != EXPECTED_NUMBER_ARGUMENTS ) {
	   cout<< WRONG_NUMB_ARGS <<endl;
	   return FAIL_WRONG_NUMBER_ARGS;
	}
	else{
		cout << "Writing to a file"<<endl;
			int res = writeFile();
			if(res == COULD_NOT_OPEN_FILE)
				cout << "Writing to a file"<<endl;


			cout << "Reading following string from a file"<<endl;
			res = readFile();
			if(res == COULD_NOT_OPEN_FILE)
				cout << "Writing to a file"<<endl;
	}
	}

	//TODO get the total memory passed in for use, stoi may come in handy
	//but its delicate because it expects the string to hold only numbers
	int total_memory;

	//test the memorymanager
	run_all_tests(argv,total_memory);
	return SUCCESS;
}
