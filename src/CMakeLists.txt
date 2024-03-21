foreach(LIBRARY_NAME IN LISTS LIBRARY_NAMES)
    add_subdirectory(${LIBRARY_NAME})
endforeach()