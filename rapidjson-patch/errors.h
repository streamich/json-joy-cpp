namespace rapidjson_patch {
    enum JsonPatchError {
        NoError = 0,
        NotAnObject = 1,
        NotAnOperation = 2,
        UnknownOperation = 3,
        OperationMissingPath = 4,
        OperationInvalidPath = 5,
        MissingValue = 6,
    };
}
