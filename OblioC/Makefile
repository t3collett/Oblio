CC= gcc
CXX_DEBUG_FLAGS=-g

BIN_PATH=./bin/
BLD_PATH=./build/
SRC_PATH=./src/
TST_PATH=./test/

EXEC=$(BIN_PATH)oblio
DEBUG_TARGET=$(BIN_PATH)dbg_oblio
SOURCES=$(wildcard $(SRC_PATH)*.c)
OBJECTS=$(SOURCES:$(SRC_PATH)%.c=$(BLD_PATH)%.o)

.phony: clean debug run all

all: $(EXEC)


	
$(EXEC): $(BIN_PATH) $(OBJECTS)
	$(CC) -o $(EXEC) $(OBJECTS)

$(BLD_PATH)%.o: $(SRC_PATH)%.c $(BLD_PATH)
	$(CC) -c $< -o $@

$(BIN_PATH) : 
	@umask 0; mkdir -p "$(BIN_PATH)"

$(BLD_PATH) :
	@umask 0; mkdir -p "$(BLD_PATH)"

clean :
	@rm -rf "$(BIN_PATH)" "$(BLD_PATH)"

debug : $(BIN_PATH) $(SOURCES)
	$(CC) -o $(DEBUG_TARGET) $(SOURCES) $(CXX_DEBUG_FLAGS)

run : $(EXEC)
	$(EXEC)
