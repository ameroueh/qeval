##########################
# Makefile 		 #
##########################

#Gather all the .cpp files
SOURCE_FILES =$(wildcard ./*.cpp) \
	      $(wildcard ./examples/*.cpp) \
	      $(wildcard ./source/algorithms/*.cpp) \
	      $(wildcard ./source/converter/*.cpp) \
	      $(wildcard ./source/exception/*.cpp) \
	      $(wildcard ./source/interpreter/*.cpp) \
	      $(wildcard ./source/qeval/*.cpp) \
	      $(wildcard ./source/random/*.cpp) \
	      $(wildcard ./vectorclass/special/*.cpp) \
#Each .cpp file becomes a .o file    
OBJECT_FILES=$(SOURCE_FILES:.cpp=.o)

#Define flags for g++, in this case just a bunch of -I[include_directory] plus the C++11 specification
CXXFLAGS= -I./source/algorithms -I./source/converter -I./source/exception -I./source/interpreter -I./source/qeval -I./examples -I./vectorclass -I./source/random -I./vectorclass/special -std=c++11 -O3 -flto -mpopcnt -mbmi -mavx2 -mlzcnt -mfma

#Main rule: create the examples file
ex1: $(OBJECT_FILES)
	$(CXX) -flto -pg -o  $@ $^

#Cleanup
.PHONY:clean
clean:
	rm -f $(OBJECT_FILES) ex1
