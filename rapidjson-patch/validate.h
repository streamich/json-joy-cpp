#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include "errors.h"

namespace rapidjson_patch {
    JsonPatchError validateOperationAdd(rapidjson::GenericObject<false, rapidjson::Value>& obj) {
        rapidjson::Value::ConstMemberIterator itr = obj.FindMember("path");
        if (itr == obj.MemberEnd()) return JsonPatchError::OperationMissingPath;
        if (!itr->value.IsString()) return JsonPatchError::OperationInvalidPath;
        if (obj.FindMember("value") == obj.MemberEnd()) return JsonPatchError::MissingValue;
        return JsonPatchError::NoError;
    }

    JsonPatchError validateOperation(rapidjson::Document& doc) {
        if (!doc.IsObject()) return JsonPatchError::NotAnObject;
        auto obj = doc.GetObject();
        rapidjson::Value::ConstMemberIterator itr = obj.FindMember("op");
        if (itr == obj.MemberEnd()) return JsonPatchError::NotAnOperation;
        if (obj["op"] == "add") return validateOperationAdd(obj);
        return JsonPatchError::UnknownOperation;
    }
}
