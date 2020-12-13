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

TEST(ValidateReplace, ReturnsErrorOnMissingOperationMnemonic) {
    const char* json = "{\"OP\":\"replace\",\"path\":\"/\",\"value\":\"foobar\"}";
    rapidjson::Document doc;
    doc.Parse(json);
    auto result = rapidjson_patch::validateOperation(doc);
    ASSERT_EQ(result, rapidjson_patch::Error::NotAnOperation);
}

TEST(ValidateTest, ReturnsZeroOnValidOperation) {
    const char* json1 = "{\"op\":\"test\",\"path\":\"\",\"value\":null}";
    const char* json2 = "{\"op\":\"test\",\"path\":\"/foo/bar\",\"value\":123}";
    const char* json3 = "{\"op\":\"test\",\"path\":\"/\",\"value\":\"foobar\"}";
    const char* json4 = "{\"op\":\"test\",\"path\":\"\",\"value\":{}}";

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

TEST(ValidateTest, ReturnsErrorOnMissingValue) {
    const char* json = "{\"op\":\"test\",\"path\":\"\"}";
    rapidjson::Document doc;
    doc.Parse(json);
    auto result = rapidjson_patch::validateOperation(doc);
    ASSERT_EQ(result, rapidjson_patch::Error::MissingValue);
}

TEST(ValidateTest, ReturnsErrorOnInvalidPath) {
    const char* json = "{\"op\":\"test\",\"path\":123,\"value\":{}}";
    rapidjson::Document doc;
    doc.Parse(json);
    auto result = rapidjson_patch::validateOperation(doc);
    ASSERT_EQ(result, rapidjson_patch::Error::OperationInvalidPath);
}

TEST(ValidateTest, ReturnsErrorOnMissingPath) {
    const char* json = "{\"op\":\"test\",\"value\":{}}";
    rapidjson::Document doc;
    doc.Parse(json);
    auto result = rapidjson_patch::validateOperation(doc);
    ASSERT_EQ(result, rapidjson_patch::Error::OperationMissingPath);
}

TEST(ValidateTest, ReturnsErrorOnMissingOperationMnemonic) {
    const char* json = "{\"OP\":\"test\",\"path\":\"/\",\"value\":\"foobar\"}";
    rapidjson::Document doc;
    doc.Parse(json);
    auto result = rapidjson_patch::validateOperation(doc);
    ASSERT_EQ(result, rapidjson_patch::Error::NotAnOperation);
}

TEST(ValidateRemove, ReturnsZeroOnValidOperation) {
    const char* json1 = "{\"op\":\"remove\",\"path\":\"\"}";
    const char* json2 = "{\"op\":\"remove\",\"path\":\"/foo/bar\",\"value\":123}";
    const char* json3 = "{\"op\":\"remove\",\"path\":\"/\",\"value\":\"foobar\"}";

    rapidjson::Document d1, d2, d3;
    d1.Parse(json1);
    d2.Parse(json2);
    d3.Parse(json3);

    ASSERT_EQ(rapidjson_patch::Error::NoError, 0);
    ASSERT_EQ(rapidjson_patch::validateOperation(d1), 0);
    ASSERT_EQ(rapidjson_patch::validateOperation(d2), 0);
    ASSERT_EQ(rapidjson_patch::validateOperation(d3), 0);
}

TEST(ValidateRemove, ReturnsErrorOnInvalidPath) {
    const char* json = "{\"op\":\"remove\",\"path\":123,\"value\":{}}";
    rapidjson::Document doc;
    doc.Parse(json);
    auto result = rapidjson_patch::validateOperation(doc);
    ASSERT_EQ(result, rapidjson_patch::Error::OperationInvalidPath);
}

TEST(ValidateRemove, ReturnsErrorOnMissingPath) {
    const char* json = "{\"op\":\"remove\",\"value\":{}}";
    rapidjson::Document doc;
    doc.Parse(json);
    auto result = rapidjson_patch::validateOperation(doc);
    ASSERT_EQ(result, rapidjson_patch::Error::OperationMissingPath);
}

TEST(ValidateRemove, ReturnsErrorOnUnknownOperation) {
    const char* json = "{\"op\":\"FOOBAR\",\"path\":\"/\",\"value\":\"foobar\"}";
    rapidjson::Document doc;
    doc.Parse(json);
    auto result = rapidjson_patch::validateOperation(doc);
    ASSERT_EQ(result, rapidjson_patch::Error::UnknownOperation);
}

TEST(ValidateRemove, ReturnsErrorOnInvalidOperationMnemonic) {
    const char* json = "{\"op\":123,\"path\":\"/\",\"value\":\"foobar\"}";
    rapidjson::Document doc;
    doc.Parse(json);
    auto result = rapidjson_patch::validateOperation(doc);
    ASSERT_EQ(result, rapidjson_patch::Error::UnknownOperation);
}

TEST(ValidateRemove, ReturnsErrorOnMissingOperationMnemonic) {
    const char* json = "{\"OP\":\"remove\",\"path\":\"/\",\"value\":\"foobar\"}";
    rapidjson::Document doc;
    doc.Parse(json);
    auto result = rapidjson_patch::validateOperation(doc);
    ASSERT_EQ(result, rapidjson_patch::Error::NotAnOperation);
}

TEST(ValidateMove, ReturnsZeroOnValidOperation) {
    const char* json1 = "{\"op\":\"move\",\"path\":\"\",\"from\":\"\"}";
    const char* json2 = "{\"op\":\"move\",\"path\":\"/foo/bar\",\"from\":\"/\"}";
    const char* json3 = "{\"op\":\"move\",\"path\":\"/\",\"value\":\"foobar\",\"from\":\"/foo/bar\"}";

    rapidjson::Document d1, d2, d3;
    d1.Parse(json1);
    d2.Parse(json2);
    d3.Parse(json3);

    ASSERT_EQ(rapidjson_patch::Error::NoError, 0);
    ASSERT_EQ(rapidjson_patch::validateOperation(d1), 0);
    ASSERT_EQ(rapidjson_patch::validateOperation(d2), 0);
    ASSERT_EQ(rapidjson_patch::validateOperation(d3), 0);
}

TEST(ValidateMove, ReturnsErrorOnInvalidPath) {
    const char* json = "{\"op\":\"move\",\"path\":123,\"from\":\"/\"}";
    rapidjson::Document doc;
    doc.Parse(json);
    auto result = rapidjson_patch::validateOperation(doc);
    ASSERT_EQ(result, rapidjson_patch::Error::OperationInvalidPath);
}

TEST(ValidateMove, ReturnsErrorOnMissingPath) {
    const char* json = "{\"op\":\"move\",\"from\":\"/\"}";
    rapidjson::Document doc;
    doc.Parse(json);
    auto result = rapidjson_patch::validateOperation(doc);
    ASSERT_EQ(result, rapidjson_patch::Error::OperationMissingPath);
}

TEST(ValidateMove, ReturnsErrorOnInvalidFrom) {
    const char* json = "{\"op\":\"move\",\"path\":\"/foo/bar\",\"from\":{}}";
    rapidjson::Document doc;
    doc.Parse(json);
    auto result = rapidjson_patch::validateOperation(doc);
    ASSERT_EQ(result, rapidjson_patch::Error::OperationInvalidFrom);
}

TEST(ValidateMove, ReturnsErrorOnMissingFrom) {
    const char* json = "{\"op\":\"move\",\"path\":\"/foo/bar\"}";
    rapidjson::Document doc;
    doc.Parse(json);
    auto result = rapidjson_patch::validateOperation(doc);
    ASSERT_EQ(result, rapidjson_patch::Error::OperationMissingFrom);
}

TEST(ValidateCopy, ReturnsZeroOnValidOperation) {
    const char* json1 = "{\"op\":\"copy\",\"path\":\"\",\"from\":\"\"}";
    const char* json2 = "{\"op\":\"copy\",\"path\":\"/foo/bar\",\"from\":\"/\"}";
    const char* json3 = "{\"op\":\"copy\",\"path\":\"/\",\"value\":\"foobar\",\"from\":\"/foo/bar\"}";

    rapidjson::Document d1, d2, d3;
    d1.Parse(json1);
    d2.Parse(json2);
    d3.Parse(json3);

    ASSERT_EQ(rapidjson_patch::Error::NoError, 0);
    ASSERT_EQ(rapidjson_patch::validateOperation(d1), 0);
    ASSERT_EQ(rapidjson_patch::validateOperation(d2), 0);
    ASSERT_EQ(rapidjson_patch::validateOperation(d3), 0);
}

TEST(ValidateCopy, ReturnsErrorOnInvalidPath) {
    const char* json = "{\"op\":\"copy\",\"path\":123,\"from\":\"/\"}";
    rapidjson::Document doc;
    doc.Parse(json);
    auto result = rapidjson_patch::validateOperation(doc);
    ASSERT_EQ(result, rapidjson_patch::Error::OperationInvalidPath);
}

TEST(ValidateCopy, ReturnsErrorOnMissingPath) {
    const char* json = "{\"op\":\"copy\",\"from\":\"/\"}";
    rapidjson::Document doc;
    doc.Parse(json);
    auto result = rapidjson_patch::validateOperation(doc);
    ASSERT_EQ(result, rapidjson_patch::Error::OperationMissingPath);
}

TEST(ValidateCopy, ReturnsErrorOnInvalidFrom) {
    const char* json = "{\"op\":\"copy\",\"path\":\"/foo/bar\",\"from\":{}}";
    rapidjson::Document doc;
    doc.Parse(json);
    auto result = rapidjson_patch::validateOperation(doc);
    ASSERT_EQ(result, rapidjson_patch::Error::OperationInvalidFrom);
}

TEST(ValidateCopy, ReturnsErrorOnMissingFrom) {
    const char* json = "{\"op\":\"copy\",\"path\":\"/foo/bar\"}";
    rapidjson::Document doc;
    doc.Parse(json);
    auto result = rapidjson_patch::validateOperation(doc);
    ASSERT_EQ(result, rapidjson_patch::Error::OperationMissingFrom);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
