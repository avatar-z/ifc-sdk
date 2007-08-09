# - Locate OpenTHREADS include paths and libraries
# This module defines:
#  OPENTHREADS_INCLUDE_DIR       - where to find includes.
#  OPENTHREADS_LIBRARIES         - the libraries to link against to use OpenTHREADS.
#  OPENTHREADS_LIBRARIES_DEBUG   - the libraries to link against to use OpenTHREADS debug.
#  OPENTHREADS_LIBRARIES_RELEASE - the libraries to link against to use OpenTHREADS optimized.
#  OPENTHREADS_DEFINITIONS       - definitions to use when compiling code that uses OpenTHREADS.
#  OPENTHREADS_FOUND             - If false, don't try to use Delta3D.
#

FIND_PATH(OPENTHREADS_INCLUDE_DIR OpenThreads/Thread
	PATHS /usr/local/include "$ENV{OPENTHREADS_INCLUDE_DIR}" "$ENV{OPENTHREADS_ROOT}/include" "$ENV{OSG_ROOT}/include" ENV DELTA_INC
	PATH_SUFFIXES include
	)

IF(WIN32)
FIND_LIBRARY(OPENTHREADS_LIBRARY_RELEASE OpenThreadsWin32 
		PATHS /usr/local/lib "$ENV{OPENTHREADS_ROOT}/lib" "$ENV{OPENTHREADS_ROOT}/lib/win32" "$ENV{OSG_ROOT}/lib" "$ENV{OSG_ROOT}/lib/win32" ENV DELTA_LIB
		)
ELSE(WIN32)
FIND_LIBRARY(OPENTHREADS_LIBRARY_RELEASE OpenThreads 
		PATHS /usr/local/lib "$ENV{OPENTHREADS_ROOT}/lib" "$ENV{OPENTHREADS_ROOT}/lib/win32" "$ENV{OSG_ROOT}/lib" "$ENV{OSG_ROOT}/lib/win32" ENV DELTA_LIB
		)
ENDIF(WIN32)

IF(WIN32)
FIND_LIBRARY(OPENTHREADS_LIBRARY_DEBUG OpenThreadsWin32D 
		PATHS /usr/local/lib "$ENV{OPENTHREADS_ROOT}/lib" "$ENV{OPENTHREADS_ROOT}/lib/win32" "$ENV{OSG_ROOT}/lib" "$ENV{OSG_ROOT}/lib/win32" ENV DELTA_LIB
		)
ELSE(WIN32)
FIND_LIBRARY(OPENTHREADS_LIBRARY_DEBUG OpenThreadsD
		PATHS /usr/local/lib "$ENV{OPENTHREADS_ROOT}/lib" "$ENV{OPENTHREADS_ROOT}/lib/win32" "$ENV{OSG_ROOT}/lib" "$ENV{OSG_ROOT}/lib/win32" ENV DELTA_LIB
		)
ENDIF(WIN32)


IF(OPENTHREADS_LIBRARY_DEBUG)
   SET(OPENTHREADS_LIBRARIES 
      optimized ${OPENTHREADS_LIBRARY_RELEASE}
      debug ${OPENTHREADS_LIBRARY_DEBUG} 
   )
ELSE(OPENTHREADS_LIBRARY_DEBUG)
   SET(OPENTHREADS_LIBRARIES         ${OPENTHREADS_LIBRARY_RELEASE})
ENDIF(OPENTHREADS_LIBRARY_DEBUG)

IF(OPENTHREADS_INCLUDE_DIR)
	SET(OPENTHREADS_FOUND "YES" )
ENDIF(OPENTHREADS_INCLUDE_DIR)

MARK_AS_ADVANCED(
   OPENTHREADS_INCLUDE_DIR
   OPENTHREADS_LIBRARY_RELEASE
   OPENTHREADS_LIBRARY_DEBUG
) 