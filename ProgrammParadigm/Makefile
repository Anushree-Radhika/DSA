# Compiler and tools
CXX = g++
CXXFLAGS = -c
AR = ar

# Final executable name
TARGET = project

# Object files
ARRAY_OBJ = ppl1r_array.o
STRING_OBJ = ppl1r_string.o

# Static libraries
ARRAY_LIB = libarray.a
STRING_LIB = libstring.a

# Default rule
all: $(TARGET)

# Compile array module
ppl1r_array.o: ppl1r_array.cpp ppl1r_array.h
	$(CXX) $(CXXFLAGS) ppl1r_array.cpp

# Compile string module
ppl1r_string.o: ppl1r_string.cpp ppl1r_string.h
	$(CXX) $(CXXFLAGS) ppl1r_string.cpp

# Create array static library
$(ARRAY_LIB): $(ARRAY_OBJ)
	$(AR) rcs $(ARRAY_LIB) $(ARRAY_OBJ)

# Create string static library
$(STRING_LIB): $(STRING_OBJ)
	$(AR) rcs $(STRING_LIB) $(STRING_OBJ)

# Link everything
$(TARGET): ppl1r_part3_main.cpp $(ARRAY_LIB) $(STRING_LIB)
	$(CXX) ppl1r_part3_main.cpp -L. -larray -lstring -o $(TARGET)

# Clean rule
clean:
	rm -f *.o *.a $(TARGET)
