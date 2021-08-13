#include "FileCopier.h"

#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	if (argc > 1) {
		FileCopier main{argv[1]};
		try {
			main.copierGoBrrrr();
		} catch (...) {
			cerr << "Something goes wrong" << endl;
		}
	} else {
		cerr << "Write path to xml file" << endl;
		return 1;
	}
	return 0;
}