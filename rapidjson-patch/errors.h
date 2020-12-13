#ifndef RAPIDJSON_PATCH_ERRORS_H_
#define RAPIDJSON_PATCH_ERRORS_H_

namespace rapidjson_patch {
    enum Error {
        NoError = 0,
        NotAnObject = 1,
        NotAnOperation = 2,
        UnknownOperation = 3,
        OperationMissingPath = 4,
        OperationInvalidPath = 5,
        OperationMissingFrom = 6,
        OperationInvalidFrom = 7,
        MissingValue = 8,
    };
}

#endif
