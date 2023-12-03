CXX = g++ 
CXXFLAGS = -std=c++17
INCLUDE_FLAGS = -I ~/cpp_libs/catch2/include
LINK_FLAGS = ~/cpp_libs/catch2/lib/libCatch2.a ~/cpp_libs/catch2/lib/libCatch2Main.a

problem1: problem1.cc
	$(CXX) $(CXXFLAGS) $^ -o $@

heaptest: heaptest.cc
	$(CXX) $(CXXFLAGS) $(INCLUDE_FLAGS) $^ -o $@ $(LINK_FLAGS)

problem2: problem2.cc
	$(CXX) $(CXXFLAGS) $^ -o $@

problem4: problem4.cc
	$(CXX) $(CXXFLAGS) $^ -o $@
