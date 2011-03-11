project(nepomuktvnamer)

##################  Nepomuktvnamer version  ################################
set(CMAKE_NEPOMUKTVNAMER_VERSION_MAJOR 0)
set(CMAKE_NEPOMUKTVNAMER_VERSION_MINOR 1)
set(CMAKE_NEPOMUKTVNAMER_VERSION_RELEASE 0)
set(CMAKE_NEPOMUKTVNAMER_VERSION "${CMAKE_NEPOMUKTVNAMER_VERSION_MAJOR}.${CMAKE_NEPOMUKTVNAMER_VERSION_MINOR}.${CMAKE_NEPOMUKTVNAMER_VERSION_RELEASE}")


set(KDE_MIN_VERSION "4.5.80")  # for the < 4.2 macro
find_package(KDE4 4.5.80 REQUIRED)
find_package(Nepomuk REQUIRED)
find_package(LibTvdb REQUIRED)

include(KDE4Defaults)
include(SopranoAddOntology)

include_directories(
  ${QT_INCLUDES}
  ${KDE4_INCLUDES}
  ${SOPRANO_INCLUDE_DIR}
  ${NEPOMUK_INCLUDE_DIR}
  ${nepomuktvnamer_BINARY_DIR}
)

configure_file(nepomuktvnamer-config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/nepomuktvnamer-config.h)

set( nepomuktvnamer_BIN_SRCS
  main.cpp
  tvnamer.cpp
  tvshowfilenameanalyzer.cpp
)

kde4_add_executable(nepomuktvnamer ${nepomuktvnamer_BIN_SRCS})

target_link_libraries(nepomuktvnamer
  ${NEPOMUK_LIBRARIES}
  ${QT_QTGUI_LIBRARY}
  ${KDE4_KDEUI_LIBS}
  ${KDE4_KIO_LIBS}
  ${SOPRANO_LIBRARIES}
  ${NEPOMUK_QUERY_LIBRARIES}
  ${LIBTVDB_LIBRARIES}
  nepomukdatamanagement
)

install(TARGETS nepomuktvnamer ${INSTALL_TARGETS_DEFAULT_ARGS})
install(PROGRAMS nepomuktvnamer.desktop DESTINATION ${XDG_APPS_INSTALL_DIR})
