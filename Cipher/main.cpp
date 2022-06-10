#include <iostream>
#include <string>
#include <cctype>

using namespace std;



string GenerateKey(string given_key, string message) {
	//equal the length of the message and the key
	for (int i = 0;; i++) {
		if (given_key.size() == message.size())
			break;
		given_key.push_back(given_key[i]);
	}
	return given_key;
}

string TransferToUpper(string word) {
	//make capital letters
	char letter;
	for (int i = 0; i <= word.size(); i++) {
		word[i] = toupper(word[i]);
	}
	return word;
}

string Encryption(string key, string message) {
	// return encrypted text. Encryption is done with the help of the key
	string ciphertext;

	for (int i = 0; i < message.size(); i++) {

		char x = (key[i] + message[i]) % 26;
		x += 'A';
		ciphertext.push_back(x);
	}
	return ciphertext;
}

string Decryption(string ciphertext, string key) {
	//returns decrypted text, with the help of the key 
	string decrypted_text;

	for (int i = 0; i < ciphertext.size(); i++) {
		char x = (ciphertext[i] - key[i] + 26) % 26;
		x += 'A';
		decrypted_text.push_back(x);
	}

	return decrypted_text;
}

string RemoveSpaces(string message) {
	//removes blank spaces
	message.erase(remove_if(message.begin(), message.end(), isspace), message.end());
	return message;
}

int main() {
	string message;
	string given_key;
	string ciphertext;
	string orginal_text;

	cout << "Give me the message you want to encrypt (spaces will be removed): ";
	getline(cin, message);
	
	message = RemoveSpaces(message);

	cout << "Give me your key: ";
	getline(cin, given_key);
	
	
	string key = GenerateKey(given_key, message);
	
	message = TransferToUpper(message);
	key = TransferToUpper(key);

	ciphertext = Encryption(key, message);

	orginal_text = Decryption(ciphertext, key);

	cout << "Your message is " << message <<endl<< "The key is " << key <<endl<< "The ciphret message looks like: "<< ciphertext <<endl<<"Decrypted message: " << orginal_text << endl;

	return 0;
}