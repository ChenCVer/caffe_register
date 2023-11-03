set(target ${CMAKE_PROJECT_NAME})


set(SRC_LIST
    main.cpp
    module_factory.hpp    
    module_factory.cpp
    common_net.cpp    
    face_detect.cpp
    face_headpose.cpp
)


set(sources ${SRC_LIST})

add_executable(${target} ${sources})

install(TARGETS ${target}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}  COMPONENT dev
        ARCHIVE DESTINATION ${CMAKE_INSTALL_BINDIR}  COMPONENT dev
        LIBRARY DESTINATION ${CMAKE_INSTALL_BINDIR}  COMPONENT dev
        )