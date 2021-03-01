#include <iostream>
#include <fstream>
#include <string>
#include <jsoncpp/json/json.h>
#include <curl/curl.h>

using namespace std;

int main(){
    ifstream ifs("../profile.json");
    Json::Reader reader;
    Json::Value obj;
    reader.parse(ifs, obj);
    cout << "\nLast name: " << obj["lastname"].asString() << endl;
    cout << "First name: " << obj["firstname"].asString() << endl;

    Json::Value ch;
    ch[0]["name"] = "Jabberwock";
    ch[0]["chapter"] = 1;
    ch[1]["name"] = "Cheshire Cat";
    ch[1]["chapter"] = 6;
    ch[2]["name"] = "Mad Hatter";
    ch[2]["chapter"] = 7;

    // create the main object
    Json::Value val;
    val["book"] = "Alice in Wonderland";
    val["year"] = 1865;
    val["characters"] = ch;

    cout << val << '\n';

    return 0;
}