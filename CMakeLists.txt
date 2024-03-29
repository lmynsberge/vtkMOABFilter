
# create a plugin that implements an object panel for a source proxy

CMAKE_MINIMUM_REQUIRED(VERSION 2.4)

IF(NOT ParaView_BINARY_DIR)
  FIND_PACKAGE(ParaView REQUIRED)
  INCLUDE(${PARAVIEW_USE_FILE})
ENDIF(NOT ParaView_BINARY_DIR)

IF(PARAVIEW_BUILD_QT_GUI)
  QT4_WRAP_CPP(MOC_SRCS MyToolBarActions.h
                        tablemodel.h
                        modelwidget.h
                        adddialog.h
                        qtuple.h)

  # we implement a pqConePanel.h for the ConeSource
  ADD_PARAVIEW_ACTION_GROUP(IFACES IFACE_SRCS CLASS_NAME MyToolBarActions
                            GROUP_NAME "ToolBar/MyActions")

  # create a plugin for this panel
  ADD_PARAVIEW_PLUGIN(GUIMyToolBar "1.0"
                      GUI_INTERFACES ${IFACES}
                      SOURCES MyToolBarActions.cxx 
                              tablemodel.cxx
                              modelwidget.cxx
                              adddialog.cxx 
                      ${MOC_SRCS} ${IFACE_SRCS})
ENDIF(PARAVIEW_BUILD_QT_GUI)
