#include "rapidjson/document.h"
#include "errors.h"

namespace rapidjson_patch {
    Error validateOperationAdd(rapidjson::GenericObject<false, rapidjson::Value>& obj) {
        rapidjson::Value::ConstMemberIterator itr = obj.FindMember("path");
        auto end = obj.MemberEnd();
        if (itr == end) return Error::OperationMissingPath;
        if (!itr->value.IsString()) return Error::OperationInvalidPath;
        if (obj.FindMember("value") == end) return Error::OperationMissingValue;
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
        if (!doc.IsObject()) return Error::OperationNotAnObject;
        auto obj = doc.GetObject();
        rapidjson::Value::ConstMemberIterator itr = obj.FindMember("op");
        if (itr == obj.MemberEnd()) return Error::OperationNotAnOperation;
        if (obj["op"] == "add") return validateOperationAdd(obj);
        if (obj["op"] == "replace") return validateOperationAdd(obj);
        if (obj["op"] == "remove") return validateOperationRemove(obj);
        if (obj["op"] == "move") return validateOperationMove(obj);
        if (obj["op"] == "copy") return validateOperationMove(obj);
        if (obj["op"] == "test") return validateOperationAdd(obj);
        return Error::OperationUnknown;
    }

    Error validatePatch(rapidjson::Value& arr) {
        if (!arr.IsArray()) return Error::PatchNotAnArray;
        Error err = Error::NoError;
        for (rapidjson::SizeType i = 0; i < arr.Size(); i++) {
            err = validateOperation(arr[i]);
            if (err != Error::NoError) return err;
        }
        return Error::NoError;
    }
}
