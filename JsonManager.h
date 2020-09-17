#ifndef JSON_BASICS_JSONMANAGER_H
#define JSON_BASICS_JSONMANAGER_H

#include <iostream>
#include <string>
#include <vector>

#include "rapidjson.h"
#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"
#include "rapidjson/filewritestream.h"
#include "rapidjson/filereadstream.h"

struct user {
    std::string name;
    std::string city;
    int age;
};

class JsonManager {
private:
    rapidjson::Document document;
    FILE *fp;
    char buffer[65536];
    //used to describe all fields in json object
    const std::vector<const char *> testJsonFields;

public:

    JsonManager()
            : testJsonFields({"name", "version", "number", "array"}) {

    }

    void get_object_from_file();

    void show_data();
};


#endif //JSON_BASICS_JSONMANAGER_H
