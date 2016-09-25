cmake_minimum_required(VERSION 2.6)
PROJECT (particle_system)

add_definitions( -DFREEGLUT_EXPORTS -DFREEGLUT_STATIC -D_CRT_SECURE_NO_WARNINGS -std=c++0x)

set(BOX2D_VERSION 2.3.0)

# The Box2D library.
add_subdirectory(Box2D)

file(COPY ${CMAKE_SOURCE_DIR}/data DESTINATION ${CMAKE_SOURCE_DIR}/build/)

find_package(OpenGL REQUIRED)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories (
	${OPENGL_INCLUDE_DIR}
	${SDL2_INCLUDE_DIR}
	${SDLIMAGE2_INCLUDE_DIR}
)

LINK_LIBRARIES(${SDL2_LIBRARY} ${SDLIMAGE2_LIBRARY} ${SDL2MAIN_LIBRARY})

### ANTTWEAKBAR ###

set(ANTTWEAKBAR_SOURCE
	AntTweakBar/src/LoadOGL.cpp
	AntTweakBar/src/LoadOGLCore.cpp
	AntTweakBar/src/TwColors.cpp
	AntTweakBar/src/TwBar.cpp
	AntTweakBar/src/TwEventGLFW.c
	AntTweakBar/src/TwFonts.cpp
	AntTweakBar/src/TwMgr.cpp
	AntTweakBar/src/TwOpenGL.cpp
	AntTweakBar/src/TwOpenGLCore.cpp
	AntTweakBar/src/TwPrecomp.cpp
	AntTweakBar/src/TwEventSDL.c
	AntTweakBar/src/TwEventSDL12.c
	AntTweakBar/src/TwEventSDL13.c
	AntTweakBar/src/TwEventSDL20.c
)
include_directories(
	${CMAKE_SOURCE_DIR}/external/AntTweakBar/src/
)
add_definitions(
	-D_UNIX
)
set(ANTTWEAKBAR_HEADERS
	AntTweakBar/src/AntPerfTimer.h
	AntTweakBar/src/LoadOGL.h
	AntTweakBar/src/LoadOGLCore.h
	AntTweakBar/src/MiniGLFW.h
	AntTweakBar/src/resource.h
	AntTweakBar/src/TwBar.h
	AntTweakBar/src/TwColors.h
	AntTweakBar/src/TwFonts.h
	AntTweakBar/src/TwGraph.h
	AntTweakBar/src/TwMgr.h
	AntTweakBar/src/TwOpenGL.h
	AntTweakBar/src/TwOpenGLCore.h
	AntTweakBar/src/TwPrecomp.h
)

include_directories(
	AntTweakBar/include/
)

add_library( ANTTWEAKBAR_SDL STATIC
	${ANTTWEAKBAR_SOURCE}
	${ANTTWEAKBAR_HEADERS}
)

ADD_EXECUTABLE(main particle_system/main.cpp
		    external/utils.cpp
		    external/utils.h
		    external/gui.cpp
		    external/gui.h
		    external/particle.cpp
		    external/particle.h
		    external/texture.cpp
		    external/texture.h
)

target_link_libraries (
	main
	Box2D
	ANTTWEAKBAR_SDL
	${OPENGL_LIBRARIES}
	${SDL2_LIBRARIES}
	${SDL2IMAGE_LIBRARY} 
	${SDL2MAIN_LIBRARY}
) 
