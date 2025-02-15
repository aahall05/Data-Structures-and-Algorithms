// Austin Hall
// 90207943

#include <sstream>
#include <iostream>
#include <sstream>
#include <fstream>
#include "AVL.h"
using namespace std;


int main() {
	AVLTree tree;

	//ifstream file("test-io/input-files/custom.txt");
	//if (file.is_open()) {
		string line;
		// todo changed from 'file' to 'cin'
		getline(cin, line);
		// get first line
		istringstream inStream(line);

		// get number of commands
		string numCommand;
		getline(inStream, numCommand, '\n');
		int comNum = stoi(numCommand);
		
		// loop throuhg each line comNum times
		for (int i = 0; i < comNum; i++) {
			// changed from 'file' to 'cin'
			getline(cin, line);
			istringstream dataStream(line);

			string command;
			getline(dataStream, command, ' ');

			// check which command is being called
			if (command.compare("search") == 0) {
				char next;
				dataStream.get(next);

				// if next is a quote, then search by name
				if (next == '"') {
					// get name
					string name;
					getline(dataStream, name, '"');

					// check if name is valid
					if (tree.nameIsValid(name)) {
						// if so, search for name
						tree.search(name);
					}
					else {
						cout << "unsuccessful" << endl;
					}
				}
				// else next is a digit, so search by ufid
				else {
					// assign next to ufid
                    string ufid = string(1, next);
					
					// get the rest of the ufid
					string temp;
					getline(dataStream, temp, '\n');
					
					// append the rest of the string to ufid
					ufid += temp;
					
					// check if ufid is valid
					if (tree.ufidIsValid(ufid)) {
						//if so, search for ufid
						tree.search(ufid);
					}
					else {
						cout << "unsuccessful" << endl;
					}
				}
			}
			else if (command.compare("insert") == 0) {
				string name;
				string ufid;
				string next;

				// advance cursor and get name
				getline(dataStream, next, '"');
				getline(dataStream, name, '"');

				// advance cursor and get ufid
				getline(dataStream, next, ' ');
				getline(dataStream, ufid, '\n');

				// check if name and ufid are valid
				if (tree.nameIsValid(name) && tree.ufidIsValid(ufid)) {
					tree.insert(name, ufid);
				}
				else {
					cout << "unsuccessful" << endl;
				}
			}
			else if (command.compare("remove") == 0) {
				
				// get ufid
				string ufid;
				getline(dataStream, ufid, '\n');

				// check if ufid is valid first, then check if it's in the tree
				if (tree.ufidIsValid(ufid) && tree.inTree(ufid))
					//if so, search for ufid
					tree.remove(ufid);
				else
					cout << "unsuccessful" << endl;
			}
			else if (command.compare("printInorder") == 0) {
				tree.printInorder();
			}
			else if (command.compare("printPreorder") == 0) {
				tree.printPreorder();
			}
			else if (command.compare("printPostorder") == 0) {
				tree.printPostorder();
			}
			else if (command.compare("printLevelCount") == 0) {
				tree.printLevelCount();
			}
			else if (command.compare("removeInorder") == 0) {

				// get number and removeInorder
				string num;
				getline(dataStream, num, '\n');
				tree.removeInorder(stoi(num));

			}
			else
				cout << "unsuccessful" << endl;
		}
		//file.close();
	/*}
	else {
		cout << "Unable to open file" << endl;
	}*/

	return 0;
}

/* RESOURCES USED */
/*
	1. 10.1 AVL Tree - Insertion and Rotations https://www.youtube.com/watch?v=jDM6_TnYIqE
		^this video was very helpful
	2. AVL Tree visualization https://www.cs.usfca.edu/~galles/visualization/AVLtree.html 
	3. https://stackoverflow.com/questions/4191089/how-to-unit-test-function-writing-to-stdout-stdcout

*/

	