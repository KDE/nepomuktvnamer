project(nepomuktvnamer)

##################  Nepomuktvnamer version  ################################
set(CMAKE_NEPOMUKTVNAMER_VERSION_MAJOR 0)
set(CMAKE_NEPOMUKTVNAMER_VERSION_MINOR 2)
set(CMAKE_NEPOMUKTVNAMER_VERSION_RELEASE 0)
set(CMAKE_NEPOMUKTVNAMER_VERSION "${CMAKE_NEPOMUKTVNAMER_VERSION_MAJOR}.${CMAKE_NEPOMUKTVNAMER_VERSION_MINOR}.${CMAKE_NEPOMUKTVNAMER_VERSION_RELEASE}")


set(KDE_MIN_VERSION "4.5.80")  # for the < 4.2 macro
find_package(KDE4 4.5.80 REQUIRED)
find_package(Nepomuk REQUIRED)
find_package(LibTvdb REQUIRED)
set(SDO_MIN_VERSION "0.8.53")
find_package(SharedDesktopOntologies)

include(KDE4Defaults)
include(SopranoAddOntology)

include_directories(
  ${QT_INCLUDES}
  ${KDE4_INCLUDES}
  ${SOPRANO_INCLUDE_DIR}
  ${NEPOMUK_INCLUDE_DIR}
)

add_subdirectory(src)
add_subdirectory(service)
add_subdirectory(kioslave)
