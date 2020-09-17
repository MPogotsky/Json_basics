#include "JsonManager.h"

using namespace std;

void JsonManager::get_object_from_file() {
    //using filestream to read data from JSON file
    //opening filestream
    fp = fopen("/home/pogotsky/Work/C++Projects/Json_basics/package.json", "r");
    if (!fp) {
        cerr << "Trouble while creating filestream." << endl;
        return;
    }

    //using opened stream to convert it into rapidjson FileReadStream
    rapidjson::FileReadStream streamFromFile(fp, buffer, sizeof(buffer));

    //parsing rapidjson stream into document
    document.ParseStream(streamFromFile);

    //closing filestream
    fclose(fp);
}

void JsonManager::show_data() {
    //asserting that document is an object and we have access to the fields
    assert(document.IsObject());

    for (auto fieldname : testJsonFields) {
        if (!document.HasMember(fieldname)) {
            cerr << "Can`t find field: " << fieldname << endl;
        }
    }

    assert(document["name"].IsString());
    cout << document["name"].GetString() << endl;

    assert(document["version"].IsFloat());
    cout << document["version"].GetFloat() << endl;

    assert(document["number"].IsInt());
    cout << document["number"].GetInt()<<endl;

//    const rapidjson::Value &array = document["array"];
//    assert(document[array].IsArray());

}