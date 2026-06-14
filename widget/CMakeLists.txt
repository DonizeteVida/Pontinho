add_library(widget INTERFACE)
target_link_libraries(
    widget
    INTERFACE
    yogacore
    assets)
target_include_directories(
    widget
    INTERFACE
    src)