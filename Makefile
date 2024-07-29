include ColorConfig

# Compiler
CXX = g++

# Compiler flags -Wall ➣ enables warnings, -g ➣ adds debugging symbols
CXXFLAGS = -Wall -Og

# Directories
SRC_DIR = src
DATA_DIR = data
INC_DIR = include

# Find all subdirectories under the INC_DIR directory and generate the necessary compiler flags (-I) in prefix of each directory
ALL_INCDIRS = $(shell find $(INC_DIR) -type d | sed 's|^|-I|' | tr '\n' ' ')

# directory where all builed files will be exist
OUTPUT_DIR = Output_Dir


# Executable files name
EXC_NAME = MyProgramRun

# store list of all Sources files (.cpp) in varaible
CPPFILES = $(foreach d, $(SRC_DIR), $(wildcard $(d)/*.cpp))

# store List all Non-source files like (.txt) files in varaible
TEXTFILES = $(foreach d, $(DATA_DIR), $(wildcard $(d)/*.txt))

# transform each cpp file to object file and list them all in varaible
OBJECTS = $(patsubst %.cpp, $(OUTPUT_DIR)/%.o, $(CPPFILES))

#################### BUILED ##############################

# Default rule
all: $(OUTPUT_DIR)/$(EXC_NAME) copy_data

# Build the program (linking step)
$(OUTPUT_DIR)/$(EXC_NAME): $(OBJECTS) 
	@mkdir -p $(OUTPUT_DIR)
	$(CXX) $^ -o $@
	@echo -e "$(BRIGHT_BLUE)Linking completed ☑$(RESET)"

# Compile source files to object files (compilation step)
$(OUTPUT_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(ALL_INCDIRS) -c $< -o $@
	@echo -e "$(BRIGHT_BLUE)Compile .cpp and .h files completed ☑$(RESET)"

# Copy all (.txt) file to Outputdir/data
copy_data:
	@mkdir -p $(OUTPUT_DIR)/$(DATA_DIR)
	@cp $(TEXTFILES) $(OUTPUT_DIR)/$(DATA_DIR)
	@echo -e "$(BRIGHT_BLUE)Copy (.txt) completed ☑$(RESET)"
	
# varaible for run program by calling make
Run:
	./$(OUTPUT_DIR)/$(EXC_NAME)

# Clear
clear:
	@rm -rf $(OUTPUT_DIR) 
	@echo -e "$(RED)Clean completed ☑$(RESET)"
	

# add .PHONY so that the non-targetfile - rules work even if a file with the same name exists.
.PHONY: all clean copy_data
