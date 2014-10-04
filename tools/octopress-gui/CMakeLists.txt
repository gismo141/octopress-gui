INCLUDE_DIRECTORIES("../../include")

SET( _MOC_HDRS
	../../include/view/blogStyle.h
	../../include/view/postList.h
	../../include/view/octopress-gui.h)

QT5_WRAP_CPP( _MOC_SRCS ${_MOC_HDRS} )

IF( APPLE )
	ADD_EXECUTABLE(
		${PROGNAME} MACOSX_BUNDLE main.cpp ${_SRCS} ${_MOC_SRCS}
	)
    ADD_CUSTOM_COMMAND( TARGET ${PROGNAME} POST_BUILD
    	COMMAND mkdir ARGS -p
    	${CMAKE_CURRENT_BINARY_DIR}/${PROGNAME}.app/Contents/Resources
    	COMMAND cp ARGS
    	../../../${MACOSX_BUNDLE_ICON_FILE}
    	${CMAKE_CURRENT_BINARY_DIR}/${PROGNAME}.app/Contents/Resources
    	COMMAND cp ARGS
    	../../../*.md
    	${CMAKE_CURRENT_BINARY_DIR}/${PROGNAME}.app/Contents/Resources
    )
ELSE( APPLE )
	ADD_EXECUTABLE(
		${PROGNAME} main.cpp ${_SRCS} ${_MOC_SRCS}
	)
ENDIF( APPLE )

TARGET_LINK_LIBRARIES(${PROGNAME} ${QT_LIBRARIES} octopressGuiLib)
QT5_USE_MODULES(${PROGNAME} Widgets)