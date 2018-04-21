find_package(Qt5 ${QT_MIN_VERSION} REQUIRED COMPONENTS
                Core
                Widgets)

set(foo_SRCS foo.cpp)

add_executable(foo ${foo_SRCS})

target_link_libraries(foo Qt5::Core Qt5::Widgets)

