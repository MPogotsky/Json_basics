#include "JsonManager.h"

using namespace std;

void JsonManager::get_object_from_file() {
    //Using filestream to read data from JSON file
    //Opening filestream
    fp = fopen(" File path ", "r");
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
            return;
        }
    }

    //We are "verifying" types of our fields & obtaining values
    assert(document["name"].IsString());
    cout << "name: " <<document["name"].GetString() << endl;

    assert(document["version"].IsFloat());
    cout << "version: " <<document["version"].GetFloat() << endl;

    assert(document["number"].IsInt());
    cout << "number: " << document["number"].GetInt() << endl;

    //Using a reference for consecutive access
    cout<<"array: "<<endl;
    const rapidjson::Value &array = document["array"];
    assert(document["array"].IsArray());
    //Using cycle for access to array field values
    for (int i = 0; i < array.Size(); i++) {
        cout << "\t" <<array[i].GetString() << endl;
    }

    //Work with object is very similar to previous work with array
    //Asserting that "object" is an object and we have access to the fields
    assert(document["object"].IsObject());
    //Asserting that object has all fields. If not -> showing error.
    for (auto objFieldName : objectFields) {
        if (!document["object"].HasMember(objFieldName)) {
            cerr << "Can`t find field in \"object\": " << objFieldName << endl;
            return;
        }
    }

    //Using a reference for consecutive access
    const rapidjson::Value &object = document["object"];
    cout << "object: " << endl;
    //Using cycle for to access to object field values
    for (int i = 0; i < objectFields.size(); i++) {
        cout << "\t" << object[objectFields.at(i)].GetString() << endl;
    }
}

void JsonManager::file_input(){
    fp = fopen(" Path to the file where to write down new json", "w");

    //Putting data ino stream
    rapidjson::FileWriteStream streamToFile(fp, buffer,sizeof(buffer));

    //Using writer to write down data into json file
    rapidjson::Writer<rapidjson::FileWriteStream> writer(streamToFile);

    document.Accept(writer);

    fclose(fp);
}