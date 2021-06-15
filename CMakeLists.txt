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
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/include/dmrc_config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/include/dmrc_config.h)

LibImport("dmrc_module" "src/dmrc_module")
ExeImport("test" "dmrc_module")

#ADD_CUSTOM_COMMAND(
#TARGET dmrctest
#PRE_BUILD
#COMMAND ${CMAKE_COMMAND} -E copy_if_different
#${CMAKE_CURRENT_SOURCE_DIR}/config/test.csv
#$<TARGET_FILE_DIR:dmrctest>
#)

#INSTALL(DIRECTORY include/ DESTINATION include)
#INSTALL(TARGETS dmrc
#        RUNTIME DESTINATION bin
#        LIBRARY DESTINATION lib
#        ARCHIVE DESTINATION lib)

#SET(DMRC_LIBS "dmrc")
#MARK_AS_ADVANCED(${DMRC_LIBS})