# Compiler
CXX = g++
#Archiving (didnt use tar below because I want to be able to link it easily)
AR=ar
# Compiler flags
CXXFLAGS = -O3 -march=native -flto -std=c++23 -fmodules
# Linker flags
LDFLAGS  = -flto
#source files
BASE=/HDD_partitions/personal_files/Projects/file_explorer
DRIVER=$(BASE)/main_driver
CLONE=$(BASE)/ls_and_tree_clone
CLONE_EXTENSION=$(CLONE)/extending_this_module
C_HEADERS=$(BASE)/C_headers
#specifying files explicitly to mantain order so that the build order remains correct
SOURCE=$(C_HEADERS)/posix.cpp $(CLONE_EXTENSION)/print_content.cpp $(CLONE)/ls_command_clone.cpp $(CLONE_EXTENSION)/middle_man.cpp $(DRIVER)/driver.cpp
#Object file target
OBJS = $(SOURCE:.cpp=.o)
#Target
TARGET=Driver
#link file
TARGET_AR=DRIVER.a
#rules like the ones defined below are important to only compile files that you want rather than
#compiling and linking everything every single time.
#rule to only trigger recompile of .cpp files into object files if the .cpp file in question changes(-c $< specifies -c The_cpp_file -o $@ specifies the respective .o file)
%.o: %.cpp
	@echo "compiling $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@
#the same thing but for the executable being generated upon the object file being changed
$(TARGET): $(OBJS)
	@echo "linking files: $<"
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
#note, I dont really need to pass u in the line below (my makefile takes care of it already) but I did anyway.
$(TARGET_AR): $(OBJS)
	@echo "adding files to archive: $<"
	$(AR) rcu $@ $(OBJS)
Print:
	@echo $(SOURCE)
all:
	$(TARGET)
archive_file:
	$(TARGET_AR)
build:
	$(CXX) $(CXXFLAGS)  -o Driver
# Clean rule to remove all
clean:
	rm -f $(OBJS) $(TARGET)
#clean to only remove build residue
clean_residue:
	rm -f $(OBJS)
