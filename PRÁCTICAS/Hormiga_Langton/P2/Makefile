TARGET = p2
INC = include
SRC = src
BIN = bin

SOURCE = $(wildcard $(SRC)/*.cpp)
# = = =
# SRC = src/main.cpp src/myMachine.cpp src/myAnt.cpp src/myBoard.cpp

OBJECT = $(patsubst %, $(BIN)/%, $(notdir $(SOURCE:.cpp=.o)))

CXX=g++ 
CXXFLAGS= -g -std=c++11 -I$(INC)


$(BIN)/$(TARGET): $(OBJECT)
	$(CXX) -o $@ $^

run: $(BIN)/
	$(BIN)/$(TARGET)

$(BIN)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY:clean help run
clean: 
	rm -f $(BIN)/$(TARGET) $(OBJECT)

help:
	@echo "$(SOURCE)"
	@echo "$(OBJECT)"