COMPILER=g++
LIBS=-lraylib
WARNINGS=-Wall -Wextra
CXXFLAGS=$(WARNINGS) -std=c++17 -Iinclude

SRC=src
BUILD=build
EXEC=chess

MAIN_SRC=main.cpp
BOARD_SRC=$(SRC)/board.cpp

OBJS=$(BUILD)/main.o $(BUILD)/board.o
BIN=$(BUILD)/$(EXEC)

all: $(BIN)

$(BUILD):
	mkdir -p $(BUILD)

$(BUILD)/%.o: $(SRC)/%.cpp | $(BUILD)
	$(COMPILER) $(CXXFLAGS) -c $< -o $@

$(BIN): $(OBJS)
	$(COMPILER) $(OBJS) -o $(BIN) $(LIBS)

run: $(BIN)
	./$(BIN)

clean:
	rm -rf $(BUILD)/*.o $(BIN)
