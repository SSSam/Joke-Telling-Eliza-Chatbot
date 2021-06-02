// chatbot_driver.cpp
//
// This is the file the marker will use to run your chatbot, so make sure
// Charbot class works with this.

#include "chatbot.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	Chatbot bot("Chatty");
	for (;;) {  // loop forever
		cout << "You> ";
		string input;
		getline(cin, input);  // reads entire line of input

		bot.tell(input);
		string reply = bot.get_reply();
		cout << bot.get_name() << "> " << reply << "\n\n";
	} // for
} // main

