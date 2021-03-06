cmake_minimum_required(VERSION 3.1)

option(BuildTest "BuildTest" ON)
option(Coverage "Coverage" OFF)

# The version number
set (SPACY_MUSIC_MAJOR_VERSION 0)
set (SPACY_MUSIC_MINOR_VERSION 1)
set (SPACY_MUSIC_PATCH_VERSION 0)
set (SPACY_MUSIC_VERSION ${SPACY_MUSIC_MAJOR_VERSION}.${SPACY_MUSIC_MINOR_VERSION}.${SPACY_MUSIC_PATCH_VERSION})

# Set path to cmake scripts
set(CMAKE_MODULE_PATH
    ${CMAKE_MODULE_PATH}
    ${CMAKE_SOURCE_DIR}/cmake
    )

# Do not allow in-source builds
include(ConfigSafeGuards)

project(SpacyMusic)

set(DOC_DIR "doc" CACHE STRING "Output directory for the doxygen documentation")

if(Coverage)
  set(CMAKE_BUILD_TYPE Debug)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -coverage")
endif()
  
# Set compiler flags
set(CMAKE_CXX_STANDARD 14)
 
# set up include-directories
include_directories("${PROJECT_SOURCE_DIR}")

add_subdirectory(SpacyMusic)
if(BuildTest)
  add_subdirectory(Tests)
endif()

# add a target to generate API documentation with Doxygen
#find_package(Doxygen)
#if(DOXYGEN_FOUND)
#configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
#add_custom_target(doc
#${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
#WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#COMMENT "Generating API documentation with Doxygen" VERBATIM
#)
#endif(DOXYGEN_FOUND)
