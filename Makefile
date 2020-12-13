override CXXFLAGS += -lpthread -Wpedantic -Wall -Wextra -Wsign-conversion -Wconversion -std=c++2a -Irapidjson -Irapidjson-patch
override LDFLAGS += -lz

main: rapidjson-patch/main.cpp
	$(CXX) -flto -O3 $(CXXFLAGS) rapidjson-patch/main.cpp -o main $(LDFLAGS)

clean:
	rm -f main