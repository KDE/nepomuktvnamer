kde4_add_plugin( nepomuktvseriesduplicatescleaner tvseriesduplicatescleaningjob.cpp)

target_link_libraries( nepomuktvseriesduplicatescleaner
  nepomukcore
  nepomukcleaner
  ${KDE4_KIO_LIBS}
)

kde4_add_plugin( nepomuktvseasonduplicatescleaner tvseasonduplicatescleaningjob.cpp)

target_link_libraries( nepomuktvseasonduplicatescleaner
  nepomukcore
  nepomukcleaner
  ${KDE4_KIO_LIBS}
)

install(
  FILES nepomuktvseriesduplicatescleaner.desktop nepomuktvseasonduplicatescleaner.desktop
  DESTINATION ${SERVICES_INSTALL_DIR})

install(
  TARGETS nepomuktvseriesduplicatescleaner nepomuktvseasonduplicatescleaner
  DESTINATION ${PLUGIN_INSTALL_DIR})
