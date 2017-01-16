aux_source_directory(Util SRC_LIST)

file(GLOB_RECURSE HEADERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)

foreach(HEADER ${HEADERS})
  string(REGEX MATCH "(.*)[/\\]" DIR ${HEADER})
  install(FILES ${HEADER} DESTINATION include/midi/${DIR})
endforeach(HEADER HEADERS)

#add_library(spacy_music_music ${SRC_LIST})

include(GenerateExportHeader)

#set_property(TARGET spacy_music PROPERTY VERSION ${SPACY_MUSIC_VERSION})
#set_property(TARGET spacy_music PROPERTY SOVERSION ${SPACY_MUSIC_MAJOR_VERSION})
#set_property(TARGET spacy_music PROPERTY INTERFACE_SpacyMusic_MAJOR_VERSION ${SPACY_MUSIC_MAJOR_VERSION})
#set_property(TARGET spacy_music APPEND PROPERTY COMPATIBLE_INTERFACE_STRING spacy_music_MAJOR_VERSION)

#install (TARGETS spacy_music EXPORT SpacyMusicTargets
#         LIBRARY DESTINATION lib
#         ARCHIVE DESTINATION lib
#         RUNTIME DESTINATION bin
#         INCLUDES DESTINATION include)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/cmake/SpacyMusicConfigVersion.cmake"
  VERSION ${SPACY_MUSIC_VERSION}
  COMPATIBILITY AnyNewerVersion
)

#export(EXPORT SpacyMusicTargets
#  FILE "${CMAKE_CURRENT_BINARY_DIR}/cmake/SpacyMusicTargets.cmake"
#  NAMESPACE SpacyMusic::
#)

configure_file(../cmake/SpacyMusicConfig.cmake
  "${CMAKE_CURRENT_BINARY_DIR}/cmake/SpacyMusicConfig.cmake"
  COPYONLY
)

set(ConfigPackageLocation lib/cmake/SpacyMusic)
#install(EXPORT SpacyMusicTargets
#  FILE
#    SpacyMusicTargets.cmake
#  NAMESPACE
#    SpacyMusic::
#  DESTINATION
#    ${ConfigPackageLocation}
#)
install(
  FILES
    ../cmake/SpacyMusicConfig.cmake
    "${CMAKE_CURRENT_BINARY_DIR}/cmake/SpacyMusicConfigVersion.cmake"
  DESTINATION
    ${ConfigPackageLocation}
  COMPONENT
    Devel
)
