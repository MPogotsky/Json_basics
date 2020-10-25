#ifndef JSON_BASICS_JSONMANAGER_H
#define JSON_BASICS_JSONMANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "rapidjson.h"
#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"
#include "rapidjson/filewritestream.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

class JsonManager {
private:

    rapidjson::Document document;

    FILE *fp;
    char buffer[65536];
    //used to describe all fields in json object
    const std::vector<const char *> testJsonFields;
    const std::vector<const char *> objectFields;

public:

    JsonManager()
            : testJsonFields({"name", "version", "number", "array"}),
              objectFields({"name", "age", "position"}){

    }

    void get_object_from_file();

    void show_data();

    void file_input();
};


#endif //JSON_BASICS_JSONMANAGER_H
