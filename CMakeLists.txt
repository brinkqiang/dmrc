cmake_minimum_required(VERSION 3.2)

PROJECT(dmrc)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
INCLUDE(cmake/ModuleImport.cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
ModuleSetCompileOptions()

SET(DMRC_VERSION_MAJOR "1")
SET(DMRC_VERSION_MINOR "0")
SET(DMRC_VERSION_PATCH "1")
SET(DMRC_VERSION "${DMRC_VERSION_MAJOR}.${DMRC_VERSION_MINOR}.${DMRC_VERSION_PATCH}")

MESSAGE(STATUS "VERSION: ${DMRC_VERSION}")

OPTION(USE_DMRC "use dmrc" OFF)

LibImport("dmrc" "src/dmrc")
ExeImport("test" "dmrc")

#MARK_AS_ADVANCED(${DMRC_LIBS})