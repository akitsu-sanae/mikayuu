TARGET_NAME = libmikayuu.a
CXX = clang++
AR = ar
CXXFLAGS = -Wall -Wextra -std=c++14 -O2

INCLUDE = -I./mikayuu

SRCDIR = ./src
SRC = $(wildcard $(SRCDIR)/*.cpp)

BUILD_DIR = ./build
TARGET = $(BUILD_DIR)/$(TARGET_NAME)

OBJ = $(addprefix $(BUILD_DIR)/obj/, $(notdir $(SRC:.cpp=.o)))
DEPEND = $(OBJ:.o=.d)


$(TARGET): $(OBJ)
	$(AR) rv $@ $^


$(BUILD_DIR)/obj/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<


.PHONY: clean
clean:
	-rm -f $(OBJ) $(DEPEND) $(TARGET)

run: $(TARGET)
	$(TARGET)

