SET(PROJECT_EXAMPLE_NAME readWrite)

PROJECT(${PROJECT_EXAMPLE_NAME}_app)

FILE(GLOB PROJECT_SOURCES "*.cpp")

FILE(GLOB PROJECT_INCLUDES "*.h")

ADD_EXECUTABLE(${PROJECT_EXAMPLE_NAME}_app ${PROJECT_SOURCES} ${PROJECT_INCLUDES})

TARGET_LINK_LIBRARIES(${PROJECT_EXAMPLE_NAME}_app ifc2x3)

SET_TARGET_PROPERTIES(${PROJECT_EXAMPLE_NAME}_app PROPERTIES PROJECT_LABEL "Example Ifc2x3 SDK - ${PROJECT_EXAMPLE_NAME}")

