#include <iostream>
#include "JsonManager.h"

int main() {
    JsonManager json;
    json.get_object_from_file();
    json.show_data();
    return 0;
}
