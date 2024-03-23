#include "./headers/json.hpp" // Make sure this points to the correct path of json.hpp
//#include "./headers/timer.hpp"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

using json = nlohmann::json;

void saveWords(json j) {
    ofstream fout;
    fout.open("./data/words.txt");

    for (auto &element : j.items()) {
        string key = element.key();
        fout << key << "\n";
    }
}

json loadJsonFile(string filePath) {

    Timer T;   // create a timer
    T.Start(); // start it

    // Load your JSON object as shown in previous examples
    ifstream fileStream(filePath);
    //string partialKey = " ";
    json myJson;
    if (fileStream.is_open()) {
        fileStream >> myJson;
        fileStream.close();
    } else {
        cerr << "Failed to open file: " << filePath << endl;
        return 1;
    }

    T.End(); // end the current timer
    printf("Nanoseconds: %.17f\n", (double)T.NanoSeconds() / 1000000000);
    

  /*  // The substring you are looking for in the keys
    if (argc == 1)
        partialKey = "axal";
    else
        partialKey = argv[1];

    // Iterate over all key-value pairs
    for (auto &element : myJson.items()) {
        string key = element.key();

        // Check if the key contains the partialKey substring
        if (key.find(partialKey) != string::npos) {
            // Found a match, do something with it
            cout << "Found partial match: " << key << " -> " << element.value() << endl;
        }
    }*/

    return myJson;
}