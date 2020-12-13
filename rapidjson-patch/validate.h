#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include "errors.h"

namespace rapidjson_patch {
    Error validateOperationAdd(rapidjson::GenericObject<false, rapidjson::Value>& obj) {
        rapidjson::Value::ConstMemberIterator itr = obj.FindMember("path");
        auto end = obj.MemberEnd();
        if (itr == end) return Error::OperationMissingPath;
        if (!itr->value.IsString()) return Error::OperationInvalidPath;
        if (obj.FindMember("value") == end) return Error::MissingValue;
        return Error::NoError;
    }

    Error validateOperation(rapidjson::Value& doc) {
        if (!doc.IsObject()) return Error::NotAnObject;
        auto obj = doc.GetObject();
        rapidjson::Value::ConstMemberIterator itr = obj.FindMember("op");
        if (itr == obj.MemberEnd()) return Error::NotAnOperation;
        if (obj["op"] == "add") return validateOperationAdd(obj);
        return Error::UnknownOperation;
    }
}
