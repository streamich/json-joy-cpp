#ifndef RAPIDJSON_PATCH_ERRORS_H_
#define RAPIDJSON_PATCH_ERRORS_H_

namespace rapidjson_patch {
    enum Error {
        NoError = 0,
        OperationNotAnObject = 1,
        OperationNotAnOperation = 2,
        OperationUnknown = 3,
        OperationMissingPath = 4,
        OperationInvalidPath = 5,
        OperationMissingFrom = 6,
        OperationInvalidFrom = 7,
        OperationMissingValue = 8,
        PatchNotAnArray = 9,
    };
}

#endif
