################################################################################
## Fichero «Makefile» para el programa del trabajo obligatorio
################################################################################

################################################################################
## Declaracion de variables del fichero «Makefile»

## DIRECTORIOS
SOURCE_DIR = src
BUILD_DIR = build
BIN_DIR = bin

VPATH = $(SOURCE_DIR) 

## COMPILADOR Y OPCIONES DE COMPILACIÓN:
CXX = g++
CXXFLAGS = -g -Wall -Wextra 


## FICHEROS OBJETO (RESULTADOS INTERMEDIOS DE COMPILACIÓN):
OBJECTS =  $(addprefix $(BUILD_DIR)/, main.o opciones.o temperaturas.o)

################################################################################
## Reglas del fichero «Makefile»

















all: $(OBJECTS) | $(BIN_DIR)
	$(CXX) -g $^ -o $(BIN_DIR)/gestor 

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@  

$(BUILD_DIR)/main.o: opciones.hpp temperaturas.hpp 
$(BUILD_DIR)/opciones.o: opciones.hpp temperaturas.hpp
$(BUILD_DIR)/temperaturas.o: temperaturas.hpp


$(BIN_DIR):
	mkdir $(BIN_DIR)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

clean:
ifeq ($(OS),Windows_NT)
	if exist $(BIN_DIR) rmdir /S /Q $(BIN_DIR)
	if exist $(BUILD_DIR) rmdir /S /Q $(BUILD_DIR)
else
	rm -f $(OBJECTS) $(BIN_DIR)/*
endif
