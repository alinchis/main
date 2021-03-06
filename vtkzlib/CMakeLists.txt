PROJECT(VTKZLIB)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6.1)

INCLUDE_REGULAR_EXPRESSION("^(vtk|deflate|inf|trees|zconf|zlib|zutil).*$")

INCLUDE_DIRECTORIES(${VTKZLIB_SOURCE_DIR})
INCLUDE_DIRECTORIES(${VTKZLIB_BINARY_DIR})

# source files for zlib
SET(ZLIB_SRCS
  adler32.c   gzio.c      inftrees.c  uncompr.c
  compress.c  infblock.c  infutil.c   zutil.c
  crc32.c     infcodes.c 
  deflate.c   inffast.c  
  inflate.c   trees.c
  )

# for windows add the .def and .rc files to the source list if building shared libs
IF(WIN32)
  IF(BUILD_SHARED_LIBS)
    SET(ZLIB_DLL 1)
    IF(NOT UNIX)
      IF(NOT BORLAND)
        IF(NOT MINGW)
          SET(ZLIB_SRCS ${ZLIB_SRCS} zlib.def zlib.rc  )
        ENDIF(NOT MINGW)
      ENDIF(NOT BORLAND) 
    ENDIF(NOT UNIX)   
  ENDIF(BUILD_SHARED_LIBS)
ENDIF(WIN32)

CONFIGURE_FILE(${VTKZLIB_SOURCE_DIR}/.NoDartCoverage
  ${VTKZLIB_BINARY_DIR}/.NoDartCoverage)
CONFIGURE_FILE(${VTKZLIB_SOURCE_DIR}/zlibDllConfig.h.in
  ${VTKZLIB_BINARY_DIR}/vtkzlib/zlibDllConfig.h)


ADD_LIBRARY(vtkzlib ${ZLIB_SRCS})

#INSTALL(TARGETS vtkzlib DESTINATION lib)
#INSTALL(FILES
#  ${VTKZLIB_SOURCE_DIR}/zlib.h
#  ${VTKZLIB_SOURCE_DIR}/zconf.h
#  ${VTKZLIB_BINARY_DIR}/vtkzlib/zlibDllConfig.h
#  ${VTKZLIB_SOURCE_DIR}/vtk_zlib_mangle.h
#  DESTINATION include
#)
