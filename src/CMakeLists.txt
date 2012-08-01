include_directories(
  ${CMAKE_BINARY_DIR}
)

configure_file(nepomuktvnamer-config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/nepomuktvnamer-config.h)

set( nepomuktvnamer_BIN_SRCS
  main.cpp
  tvnamer.cpp
  tvshowfilenameanalyzer.cpp
)

kde4_add_executable(nepomuktvnamer ${nepomuktvnamer_BIN_SRCS})

target_link_libraries(nepomuktvnamer
  ${QT_QTGUI_LIBRARY}
  ${KDE4_KDEUI_LIBS}
  ${KDE4_KIO_LIBS}
  ${SOPRANO_LIBRARIES}
  ${LIBTVDB_LIBRARIES}
  ${NEPOMUK_CORE_LIBRARY}
)

install(TARGETS nepomuktvnamer ${INSTALL_TARGETS_DEFAULT_ARGS})
install(FILES nepomuktvnamer.desktop DESTINATION ${SERVICES_INSTALL_DIR}/ServiceMenus)
