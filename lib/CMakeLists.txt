INCLUDE_DIRECTORIES("control")
INCLUDE_DIRECTORIES("view")
ADD_LIBRARY(octopressGuiLib
	./view/postList.cpp
	./view/blogStyle.cpp
	./view/octopress-gui.cpp
)

QT5_USE_MODULES(octopressGuiLib Widgets)