CXX = c++ 
CXXFLAGS = -std=c++20
INCLUDEFLAGS = -I ~/cpp-libs/catch2/include
LINKFLAGS = ~/cpp-libs/catch2/lib/libCatch2.a ~/cpp-libs/catch2/lib/libCatch2Main.a

merge-sort: merge-sort.cc
	$(CXX) $(CXXFLAGS) $(INCLUDEFLAGS) $^ -o $@ $(LINKFLAGS)

clean:
	rm merge-sort
