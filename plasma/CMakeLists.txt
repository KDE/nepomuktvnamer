# A name for the project
project(plasma-nepomuktvshow)
 
# We add our source code here
set(nepomuktvshow_engine_SRCS
  nepomuktvshowengine.cpp
  nepomuktvshowservice.cpp
  nepomuktvshowsearchjob.cpp)
 
# Now make sure all files get to the right place
kde4_add_plugin(plasma_engine_nepomuktvshow ${nepomuktvshow_engine_SRCS})
target_link_libraries(plasma_engine_nepomuktvshow
                      ${KDE4_KDECORE_LIBS}
                      ${KDE4_KIO_LIBS}
                      ${KDE4_PLASMA_LIBS}
                      ${SOPRANO_LIBRARIES}
                      ${NEPOMUK_CORE_LIBRARY}
                      tvdb)
 
install(TARGETS plasma_engine_nepomuktvshow
        DESTINATION ${PLUGIN_INSTALL_DIR})
 
install(FILES plasma-engine-nepomuktvshow.desktop
        DESTINATION ${SERVICES_INSTALL_DIR})

# install the QML plasmoid
install(DIRECTORY package/
        DESTINATION ${DATA_INSTALL_DIR}/plasma/plasmoids/org.kde.nepomuk.tvshowreleases)
install(FILES package/metadata.desktop
        DESTINATION ${SERVICES_INSTALL_DIR} RENAME plasma-applet-nepomuktvshow.desktop)
install(FILES nepomuktvshow.operations
        DESTINATION ${DATA_INSTALL_DIR}/plasma/services )
