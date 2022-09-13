cmake_minimum_required(VERSION 3.17)
project(SemanticRoleLabeling)
set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
set(CONAN_INCLUDE_DIRS_ANNOTATEDTREE "/Users/olcay/.conan/data/AnnotatedTree/1.0.0/_/_/package/e24f3a24ba1e5db53e914b9af88ac8896605cc13/include")

add_library(SemanticRoleLabeling src/AutoProcessor/ParseTree/Propbank/AutoArgument.cpp src/AutoProcessor/ParseTree/Propbank/AutoArgument.h src/AutoProcessor/ParseTree/Propbank/TurkishAutoArgument.cpp src/AutoProcessor/ParseTree/Propbank/TurkishAutoArgument.h src/AutoProcessor/Sentence/Propbank/SentenceAutoArgument.h src/AutoProcessor/Sentence/Propbank/TurkishSentenceAutoArgument.cpp src/AutoProcessor/Sentence/Propbank/TurkishSentenceAutoArgument.h src/AutoProcessor/Sentence/Propbank/SentenceAutoPredicate.cpp src/AutoProcessor/Sentence/Propbank/SentenceAutoPredicate.h src/AutoProcessor/Sentence/Propbank/TurkishSentenceAutoPredicate.cpp src/AutoProcessor/Sentence/Propbank/TurkishSentenceAutoPredicate.h src/AutoProcessor/Sentence/FrameNet/SentenceAutoFramePredicate.cpp src/AutoProcessor/Sentence/FrameNet/SentenceAutoFramePredicate.h src/AutoProcessor/Sentence/FrameNet/TurkishSentenceAutoFramePredicate.h src/AutoProcessor/Sentence/FrameNet/TurkishSentenceAutoFramePredicate.cpp)
target_link_libraries(SemanticRoleLabeling ${CONAN_LIBS})