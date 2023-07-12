project(Src_lib)

set(HEADER_FILES
        CoordHelper.h
        )

set(SOURCE_FILES
        CoordHelper.cpp
        )

add_library(Src_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})