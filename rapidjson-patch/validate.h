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

    Error validateOperationRemove(rapidjson::GenericObject<false, rapidjson::Value>& obj) {
        rapidjson::Value::ConstMemberIterator itr = obj.FindMember("path");
        auto end = obj.MemberEnd();
        if (itr == end) return Error::OperationMissingPath;
        if (!itr->value.IsString()) return Error::OperationInvalidPath;
        return Error::NoError;
    }

    Error validateOperationMove(rapidjson::GenericObject<false, rapidjson::Value>& obj) {
        rapidjson::Value::ConstMemberIterator itr = obj.FindMember("path");
        auto end = obj.MemberEnd();
        if (itr == end) return Error::OperationMissingPath;
        if (!itr->value.IsString()) return Error::OperationInvalidPath;
        itr = obj.FindMember("from");
        if (itr == end) return Error::OperationMissingFrom;
        if (!itr->value.IsString()) return Error::OperationInvalidFrom;
        return Error::NoError;
    }

    Error validateOperation(rapidjson::Value& doc) {
        if (!doc.IsObject()) return Error::NotAnObject;
        auto obj = doc.GetObject();
        rapidjson::Value::ConstMemberIterator itr = obj.FindMember("op");
        if (itr == obj.MemberEnd()) return Error::NotAnOperation;
        if (obj["op"] == "add") return validateOperationAdd(obj);
        if (obj["op"] == "replace") return validateOperationAdd(obj);
        if (obj["op"] == "remove") return validateOperationRemove(obj);
        if (obj["op"] == "move") return validateOperationMove(obj);
        if (obj["op"] == "copy") return validateOperationMove(obj);
        return Error::UnknownOperation;
    }
}
