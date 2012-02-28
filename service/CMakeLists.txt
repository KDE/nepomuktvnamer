project(nepomuktvnamerservice)

set( tvnamerservice_SRCS
  tvnamerservice.cpp
)

kde4_add_plugin(nepomuktvnamerservice ${tvnamerservice_SRCS})

target_link_libraries(nepomuktvnamerservice
  ${KDE4_KDECORE_LIBS}
  ${KDE4_KIO_LIBS}
  ${SOPRANO_LIBRARIES}
  #nepomukcore
  ${NEPOMUK_LIBRARIES}
  nepomukdatamanagement
  )

install(
  FILES nepomuktvnamerservice.desktop
  DESTINATION ${SERVICES_INSTALL_DIR})

install(
  TARGETS nepomuktvnamerservice
  DESTINATION ${PLUGIN_INSTALL_DIR})
# -----------------------------
