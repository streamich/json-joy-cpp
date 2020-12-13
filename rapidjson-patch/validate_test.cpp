#include "gtest/gtest.h"
#include "validate.h"
#include "errors.h"
#include "rapidjson/document.h"

TEST(ValidateAdd, ReturnsZeroOnValidOperation) {
    const char* json1 = "{\"op\":\"add\",\"path\":\"\",\"value\":null}";
    const char* json2 = "{\"op\":\"add\",\"path\":\"/foo/bar\",\"value\":123}";
    const char* json3 = "{\"op\":\"add\",\"path\":\"/\",\"value\":\"foobar\"}";
    const char* json4 = "{\"op\":\"add\",\"path\":\"\",\"value\":{}}";

    rapidjson::Document d1, d2, d3, d4;
    d1.Parse(json1);
    d2.Parse(json2);
    d3.Parse(json3);
    d4.Parse(json4);

    ASSERT_EQ(rapidjson_patch::Error::NoError, 0);
    ASSERT_EQ(rapidjson_patch::validateOperation(d1), 0);
    ASSERT_EQ(rapidjson_patch::validateOperation(d2), 0);
    ASSERT_EQ(rapidjson_patch::validateOperation(d3), 0);
    ASSERT_EQ(rapidjson_patch::validateOperation(d4), 0);
}

TEST(ValidateAdd, ReturnsErrorOnMissingValue) {
    const char* json = "{\"op\":\"add\",\"path\":\"\"}";
    rapidjson::Document doc;
    doc.Parse(json);
    auto result = rapidjson_patch::validateOperation(doc);
    ASSERT_EQ(result, rapidjson_patch::Error::MissingValue);
}

TEST(ValidateAdd, ReturnsErrorOnInvalidPath) {
    const char* json = "{\"op\":\"add\",\"path\":123,\"value\":{}}";
    rapidjson::Document doc;
    doc.Parse(json);
    auto result = rapidjson_patch::validateOperation(doc);
    ASSERT_EQ(result, rapidjson_patch::Error::OperationInvalidPath);
}

TEST(ValidateAdd, ReturnsErrorOnMissingPath) {
    const char* json = "{\"op\":\"add\",\"value\":{}}";
    rapidjson::Document doc;
    doc.Parse(json);
    auto result = rapidjson_patch::validateOperation(doc);
    ASSERT_EQ(result, rapidjson_patch::Error::OperationMissingPath);
}

TEST(ValidateAdd, ReturnsErrorOnUnknownOperation) {
    const char* json = "{\"op\":\"FOOBAR\",\"path\":\"/\",\"value\":\"foobar\"}";
    rapidjson::Document doc;
    doc.Parse(json);
    auto result = rapidjson_patch::validateOperation(doc);
    ASSERT_EQ(result, rapidjson_patch::Error::UnknownOperation);
}

TEST(ValidateAdd, ReturnsErrorOnInvalidOperationMnemonic) {
    const char* json = "{\"op\":123,\"path\":\"/\",\"value\":\"foobar\"}";
    rapidjson::Document doc;
    doc.Parse(json);
    auto result = rapidjson_patch::validateOperation(doc);
    ASSERT_EQ(result, rapidjson_patch::Error::UnknownOperation);
}

TEST(ValidateAdd, ReturnsErrorOnMissingOperationMnemonic) {
    const char* json = "{\"OP\":\"add\",\"path\":\"/\",\"value\":\"foobar\"}";
    rapidjson::Document doc;
    doc.Parse(json);
    auto result = rapidjson_patch::validateOperation(doc);
    ASSERT_EQ(result, rapidjson_patch::Error::NotAnOperation);
}

TEST(ValidateReplace, ReturnsZeroOnValidOperation) {
    const char* json1 = "{\"op\":\"replace\",\"path\":\"\",\"value\":null}";
    const char* json2 = "{\"op\":\"replace\",\"path\":\"/foo/bar\",\"value\":123}";
    const char* json3 = "{\"op\":\"replace\",\"path\":\"/\",\"value\":\"foobar\"}";
    const char* json4 = "{\"op\":\"replace\",\"path\":\"\",\"value\":{}}";

    rapidjson::Document d1, d2, d3, d4;
    d1.Parse(json1);
    d2.Parse(json2);
    d3.Parse(json3);
    d4.Parse(json4);

    ASSERT_EQ(rapidjson_patch::Error::NoError, 0);
    ASSERT_EQ(rapidjson_patch::validateOperation(d1), 0);
    ASSERT_EQ(rapidjson_patch::validateOperation(d2), 0);
    ASSERT_EQ(rapidjson_patch::validateOperation(d3), 0);
    ASSERT_EQ(rapidjson_patch::validateOperation(d4), 0);
}

TEST(ValidateReplace, ReturnsErrorOnMissingValue) {
    const char* json = "{\"op\":\"replace\",\"path\":\"\"}";
    rapidjson::Document doc;
    doc.Parse(json);
    auto result = rapidjson_patch::validateOperation(doc);
    ASSERT_EQ(result, rapidjson_patch::Error::MissingValue);
}

TEST(ValidateReplace, ReturnsErrorOnInvalidPath) {
    const char* json = "{\"op\":\"replace\",\"path\":123,\"value\":{}}";
    rapidjson::Document doc;
    doc.Parse(json);
    auto result = rapidjson_patch::validateOperation(doc);
    ASSERT_EQ(result, rapidjson_patch::Error::OperationInvalidPath);
}

TEST(ValidateReplace, ReturnsErrorOnMissingPath) {
    const char* json = "{\"op\":\"replace\",\"value\":{}}";
    rapidjson::Document doc;
    doc.Parse(json);
    auto result = rapidjson_patch::validateOperation(doc);
    ASSERT_EQ(result, rapidjson_patch::Error::OperationMissingPath);
}

TEST(ValidateReplace, ReturnsErrorOnUnknownOperation) {
    const char* json = "{\"op\":\"FOOBAR\",\"path\":\"/\",\"value\":\"foobar\"}";
    rapidjson::Document doc;
    doc.Parse(json);
    auto result = rapidjson_patch::validateOperation(doc);
    ASSERT_EQ(result, rapidjson_patch::Error::UnknownOperation);
}

TEST(ValidateReplace, ReturnsErrorOnInvalidOperationMnemonic) {
    const char* json = "{\"op\":123,\"path\":\"/\",\"value\":\"foobar\"}";
    rapidjson::Document doc;
    doc.Parse(json);
    auto result = rapidjson_patch::validateOperation(doc);
    ASSERT_EQ(result, rapidjson_patch::Error::UnknownOperation);
}

TEST(ValidateReplace, ReturnsErrorOnMissingOperationMnemonic) {
    const char* json = "{\"OP\":\"replace\",\"path\":\"/\",\"value\":\"foobar\"}";
    rapidjson::Document doc;
    doc.Parse(json);
    auto result = rapidjson_patch::validateOperation(doc);
    ASSERT_EQ(result, rapidjson_patch::Error::NotAnOperation);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
