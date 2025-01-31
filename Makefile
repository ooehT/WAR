# Compilador
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Diretórios
SRC_DIR = src
BUILD_DIR = build
BIN = main.exe

# Lista de arquivos fonte (.cpp)
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Gerar arquivos objeto (.o) no diretório build/
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

# Regra principal
$(BIN): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regra para compilar os arquivos .cpp em .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar os arquivos compilados
clean:
	rm -rf $(BUILD_DIR) $(BIN)
