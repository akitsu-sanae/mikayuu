TARGET_NAME = libmikayuu.a
CXX = g++
AR = ar
CXXFLAGS = -Wall -Wextra -std=c++14 -s -O2
ARFLAGS = rv

LIBS = -lglfw3 -lopengl32 -lglu32 -lpng
INCLUDE = -I.

SRCDIR = ./src
SRC = $(wildcard $(SRCDIR)/*.cpp)

BUILD_DIR = ./build


TARGET = $(BUILD_DIR)/$(TARGET_NAME)
OBJ = $(addprefix $(BUILD_DIR)/obj/, $(notdir $(SRC:.cpp=.o)))
DEPEND = $(OBJ:.o=.d)


$(TARGET): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^


$(BUILD_DIR)/obj/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE)  $(LIBS) -o $@ -c $<


.PHONY: clean
clean:
	-rm -f $(OBJ) $(DEPEND) $(TARGET)

.PHONY: run
run: $(TARGET)
	$(TARGET)

.PHONY: all
all: clean $(TARGET)

