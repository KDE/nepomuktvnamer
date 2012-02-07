project(kioslave-nepomuk-tvshow)

set(kio_tvshow_PART_SRCS
  kio_tvshow.cpp)

kde4_add_plugin(kio_tvshow ${kio_tvshow_PART_SRCS})
target_link_libraries(kio_tvshow
  ${KDE4_KIO_LIBS}
  ${NEPOMUK_LIBRARIES}
  ${NEPOMUK_QUERY_LIBRARIES}
  ${SOPRANO_LIBRARIES}
)

kde4_add_plugin(nepomuktvshowthumbnail tvshowthumbcreator.cpp)
target_link_libraries(nepomuktvshowthumbnail
  ${KDE4_KIO_LIBS}
  ${NEPOMUK_LIBRARIES}
  ${SOPRANO_LIBRARIES})

install(TARGETS kio_tvshow nepomuktvshowthumbnail DESTINATION ${PLUGIN_INSTALL_DIR})
install(FILES tvshow.protocol nepomuktvshowthumbnail.desktop DESTINATION  ${SERVICES_INSTALL_DIR})
