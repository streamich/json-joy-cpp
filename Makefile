override CXXFLAGS += -lpthread -Wpedantic -Wall -Wextra -Wsign-conversion -Wconversion -std=c++2a -Irapidjson -Irapidjson-patch
override LDFLAGS += -lz

init:
	git submodule init; \
	cd external/gtest; \
	mkdir build; \
	cd build; \
	cmake ..; \
	make

main: rapidjson-patch/main.cpp rapidjson-patch/*.h
	$(CXX) -flto -O3 $(CXXFLAGS) rapidjson-patch/main.cpp -o main $(LDFLAGS)

.PHONY: validate_test
validate_test: rapidjson-patch/validate_test.cpp rapidjson-patch/*.h
	mkdir -p build; \
	$(CXX) -o build/validate_test rapidjson-patch/validate_test.cpp $(CXXFLAGS) -Iexternal/gtest/googletest/include ./external/gtest/build/lib/*.a; \
	./build/validate_test

.PHONY: clean
clean:
	rm -f main; \
	rm -rf build