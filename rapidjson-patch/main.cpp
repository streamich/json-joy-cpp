#include "validate.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>

int main() {
    const char* json = "{\"op\":\"add\",\"path\":\"\",\"value\":null}";
    rapidjson::Document d;
    d.Parse(json);

    // Output {"project":"rapidjson","stars":11}
    std::cout << "Validation result: " << rapidjson_patch::validateOperation(d) << std::endl;
    return 0;
}
