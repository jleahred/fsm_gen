cmake_minimum_required(VERSION 3.5)

project(fsm LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)





set(
    CXX_FLAGS_
    ${CMAKE_CXX_FLAGS}
                -DASIO_STANDALONE -DUSE_STANDALONE_ASIO  -Werror -Wall  -W  -Wundef  -Wpointer-arith    -Wfloat-equal
                -fexceptions   -Winit-self   -Wconversion     -Wempty-body    -Wignored-qualifiers   -Wmissing-field-initializers
                -Wsign-compare   -Wsign-conversion   -Wtype-limits   -Wuninitialized   -Wno-unused-result
                -Wnon-virtual-dtor  -Wreorder   -Woverloaded-virtual   -Wsign-promo   -Winit-self   -Wignored-qualifiers
                -Wmissing-include-dirs    -Wswitch-enum   -Wswitch-default  -Wshadow   -Wcast-qual   -Wwrite-strings    -Wreturn-type)



# ------------------------------------------------------
# PRJ_FILES

file(GLOB_RECURSE
    PRJ_FILES

    # ------------------------------------------------
    *.cpp
    *.h*
    *.fsm
    # ------------------------------------------------
    )

# PRJ_FILES
# ------------------------------------------------------

add_executable(
    fsm
    ${PRJ_FILES}
)

target_compile_options(${PROJECT_NAME}  PRIVATE  ${CXX_FLAGS_})

install(TARGETS fsm
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
