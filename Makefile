.PHONY: format

SRC_DIR=ColorCpp
CLASS_FILES=${SRC_DIR}/*.cpp
HEADER_FILES=${SRC_DIR}/*.hpp
SOURCE_FILES=${HEADER_FILES} ${CLASS_FILES}

all: color

format:
	clang-format -style=google -i ${SOURCE_FILES}

color: ${SOURCE_FILES}
	${CXX} -std=c++2a -Wall -o color ${CLASS_FILES}

clean:
	rm color
