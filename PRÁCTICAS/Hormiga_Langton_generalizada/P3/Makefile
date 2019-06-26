TARGET = p3
INC = include
ENTITY = entity
SRC = src/$(ENTITY)
BIN = bin

SOURCE = $(wildcard $(SRC)/*.cpp)
# = = =
# SRC = src/main.cpp src/myMachine.cpp src/myAnt.cpp src/myBoard.cpp

#hace que todo lo que tenga nombre acabado en .cpp en src/entity tenga un .o en bin
OBJECT = $(patsubst %, $(BIN)/%, $(notdir $(SOURCE:.cpp=.o)))
MOBJECT = $(BIN)/main.o

CXX=g++ 
CXXFLAGS= -g -std=c++11 -I$(INC)

all: $(BIN)/$(TARGET)
	

$(BIN)/$(TARGET): $(OBJECT) $(MOBJECT)
	@echo "$(OBJECT)"
	@echo "$(MOBJECT)"
	$(CXX) -o $@ $^

$(BIN)/$(MOBJECT):
	$(CXX) $(CXXFLAGS) -o $@ -c ./src/main.cpp

run: $(BIN)/
	$(BIN)/$(TARGET)

$(BIN)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY:clean help run cleanall
clean: 
	rm -f $(BIN)/$(TARGET)

cleanall:
	rm -f $(BIN)/$(TARGET) $(BIN)/$(OBJECT)

help:
	@echo "$(SOURCE)"
	@echo "$(OBJECT)"