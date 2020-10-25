#include "JsonManager.h"

int main() {
    JsonManager json;

    json.get_object_from_file();
    json.show_data();
    json.file_input();

    return 0;
}
