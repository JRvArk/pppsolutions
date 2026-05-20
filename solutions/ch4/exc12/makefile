CXX       := g++
CXXFLAGS  := -std=c++20 -Wall -Werror
DEPFLAGS   = -MMD -MP

TARGET    := main
SRC_DIR   := src
BUILD_DIR := build

SRCS := $(shell find $(SRC_DIR) -name '*.cpp' 2>/dev/null)
ifeq ($(SRCS),)
    SRCS := $(wildcard *.cpp)
    OBJS := $(addprefix $(BUILD_DIR)/,$(SRCS:.cpp=.o))
else
    OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))
endif

DEPS := $(OBJS:.o=.d)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c -o $@ $<

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c -o $@ $<

-include $(DEPS)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)