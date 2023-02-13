#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

  // Define two vectors of characters, `normal_letters` and `encryption_letters`. 
  vector<char> normal_letters{ 'a','b','c','d','e','f','g','h' ,'i','j','k','l','m','n','o','p','r','s','t','u','v','y','z' };

  vector<char> encryption_letters{};

  // Define a vector of characters `decryption_letters` and a vector of characters `final_answer`.
  vector<char> decryption_letters{};

  vector<char> final_answer{};

  // Populate `encryption_letters` in reverse order with respect to `normal_letters`.
  for (int i = normal_letters.size() - 1; i >= 0; i--) {
    encryption_letters.push_back(normal_letters[i]);
  }

  // Output the encryption letters.
  cout << "Encrypted letters are: ";
  for (auto encrypted : encryption_letters) {
    cout << " " << encrypted;
  }

  // Populate `decryption_letters` in reverse order with respect to `encryption_letters`.
  for (int i = encryption_letters.size() - 1; i >= 0; i--) {
    decryption_letters.push_back(encryption_letters[i]);
  }

  // Define a string `choice` and a string `text`. Also define a boolean variable `again` and set it to true.
  string choice;
  string text;
  bool again = true;

  // Keep running this loop until `again` is false.
  while (again) {
    // Clear the contents of the `final_answer` vector.
    final_answer.clear();

    // Ask the user whether they would like to encrypt or decrypt.
    cout << "\nEnter 'e' for encryption or 'd' for decryption: ";
    cin >> choice;

    // If the user wants to encrypt, do the following:
    if (choice == "e") {
      cout << "\nEnter what you would like to encrypt: ";
      cin.ignore();
      getline(cin, text);

      // Loop over each character in `text`.
      for (int k = 0; k < text.size(); k++) {
        bool found_letter = false;
        // Loop over each character in `normal_letters`.
        for (int letter_index = 0; letter_index < normal_letters.size(); letter_index++) {
          // If the current character in `text` is equal to the current character in `normal_letters`,
          if (text[k] == normal_letters[letter_index]) {
            // add the corresponding character from `encryption_letters` to `final_answer`.
            final_answer.push_back(encryption_letters.at(letter_index));
            found_letter = true;
            break;
          }
        }
        // If the current character in `text` was not found in `normal_letters`, add it to `final_answer` without changing it.
        if (!found_letter) {
          final_answer.push_back(text[k]);
        }
      }
      cout << "\nFinal answer is: ";
      for (int k = 0; k < final_answer.size(); k++) {
        cout << final_answer[k];
      }
    }
    else if (choice == "d") {
      cout << "\nEnter what you would like to decrypt: ";
      cin.ignore();
      getline(cin, text);

      for (int k = 0; k < text.size(); k++) {
        bool found_letter = false;
        for (int letter_index = 0; letter_index < encryption_letters.size(); letter_index++) {
          if (text[k] == encryption_letters[letter_index]) {
            final_answer.push_back(normal_letters.at(letter_index));
            found_letter = true;
            break;
          }
        }
        if (!found_letter) {
          final_answer.push_back(text[k]);

        }
      }
      cout << "\nFinal answer is: ";
      for (int k = 0; k < final_answer.size(); k++) {
        cout << final_answer[k];
      }
      char another;

      cout << "\nDo you want to encrypt another text? (y/n): ";
      cin >> another;

      if (another == 'n' || another == 'N') {
        again = false;
      }

    }
  }
  return 0;
}
