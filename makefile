# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -O3 -march=native -flto -std=c++23 -fmodules
# Linker flags
LDFLAGS  = -flto
#source files
SOURCE= $(wildcard */*.cpp)
#Object file target
OBJS = $(SOURCE:.cpp=.o)
#Target
TARGET=Driver
#link file
TARGET_LINK=DRIVER.o
#rules like the ones defined below are important to only compile files that you want rather than
#compiling and linking everything every single time.
#rule to only trigger recompile of .cpp files into object files if the .cpp file in question changes(-c $< specifies -c The_cpp_file -o $@ specifies the respective .o file)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
#the same thing but for the executable being generated upon the object file being changed
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
Print:
	@echo $(SOURCE)
all:
	$(TARGET)
link_file: $(TARGET_LINK)

build:
	$(CXX) $(CXXFLAGS)  -o Driver
# Clean rule to remove build residue
clean:
	rm -f $(OBJS) $(TARGET)
