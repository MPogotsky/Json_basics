#include "JsonManager.h"

using namespace std;

void JsonManager::get_object_from_file() {
    //Using filestream to read data from JSON file
    //Opening filestream
    fp = fopen("/home/pogotsky/Work/C++Projects/Json_basics/package.json", "r");
    if (!fp) {
        cerr << "Trouble while creating filestream." << endl;
        return;
    }

    //Using opened stream to convert it into rapidjson FileReadStream
    rapidjson::FileReadStream streamFromFile(fp, buffer, sizeof(buffer));

    //Parsing rapidjson stream into document
    document.ParseStream(streamFromFile);

    //Closing filestream
    fclose(fp);
}

void JsonManager::show_data() {
    //Asserting that document is an object and we have access to the fields
    assert(document.IsObject());

    //Asserting that document has all fields. If not -> showing error.
    for (auto fieldname : testJsonFields) {
        if (!document.HasMember(fieldname)) {
            cerr << "Can`t find field: " << fieldname << endl;
        }
    }

    //We are "verifying" types of our fields & obtaining values
    assert(document["name"].IsString());
    cout << document["name"].GetString() << endl;

    assert(document["version"].IsFloat());
    cout << document["version"].GetFloat() << endl;

    assert(document["number"].IsInt());
    cout << document["number"].GetInt()<<endl;

    //Using a reference for consecutive access
    const rapidjson::Value &array = document["array"];
    assert(document["array"].IsArray());
    //Using cycle for to access to array field values
    for(int i = 0; i < array.Size(); i++){
        cout<<array[i].GetString()<<endl;
    }

}