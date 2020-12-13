#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include "errors.h"

namespace rapidjson_patch {
    Error validateOperationAdd(rapidjson::GenericObject<false, rapidjson::Value>& obj) {
        rapidjson::Value::ConstMemberIterator itr = obj.FindMember("path");
        if (itr == obj.MemberEnd()) return Error::OperationMissingPath;
        if (!itr->value.IsString()) return Error::OperationInvalidPath;
        if (obj.FindMember("value") == obj.MemberEnd()) return Error::MissingValue;
        return Error::NoError;
    }

    Error validateOperation(rapidjson::Document& doc) {
        if (!doc.IsObject()) return Error::NotAnObject;
        auto obj = doc.GetObject();
        rapidjson::Value::ConstMemberIterator itr = obj.FindMember("op");
        if (itr == obj.MemberEnd()) return Error::NotAnOperation;
        if (obj["op"] == "add") return validateOperationAdd(obj);
        return Error::UnknownOperation;
    }
}
