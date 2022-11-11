
# Add the assignment entrypoints using our libs and src code.
foreach(entrypoint IN LISTS assignment_entrypoints)
    add_executable(${entrypoint} ${entry_dir}/${entrypoint}.cpp)
    target_link_libraries(${entrypoint} PRIVATE libs src)
endforeach()