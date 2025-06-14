enable_language(CUDA)
uipc_add_backend(jgs2)

find_package(TBB CONFIG REQUIRED)

# basic setup
target_link_libraries(jgs2 PUBLIC
    muda
    cublas
    cusparse
    cusolver
    uipc_geometry
)

target_link_libraries(jgs2 PRIVATE
    TBB::tbb TBB::tbbmalloc TBB::tbbmalloc_proxy)

if(NOT DEFINED CMAKE_CUDA_ARCHITECTURES)
    set(CMAKE_CUDA_ARCHITECTURES "native")
endif()

target_compile_features(jgs2 PUBLIC cxx_std_20)
uipc_info("CMAKE_CUDA_ARCHITECTURES: ${CMAKE_CUDA_ARCHITECTURES}")
target_include_directories(jgs2 PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
set_target_properties(jgs2 PROPERTIES
    CUDA_SEPARABLE_COMPILATION ON
    CUDA_RESOLVE_DEVICE_SYMBOLS ON
    CUDA_ARCHITECTURES ${CMAKE_CUDA_ARCHITECTURES}
    CUDA_STANDARD_REQUIRED ON
    CUDA_STANDARD 20
)


# source files in this directory
file(GLOB_RECURSE SOURCES "*.h" "*.cpp" "*.cu" "*.inl")
target_sources(jgs2 PRIVATE ${SOURCES})

if(MSVC)
    # Disable some warnings 
    # C4819: The file contains a character that cannot be represented in the current code page
    # target_compile_options(jgs2 PRIVATE $<$<COMPILE_LANGUAGE:CUDA>:-Xcompiler=/wd4819>)
endif()

# ------------------------------------------------------------------------------
# setup source group for the IDE
# ------------------------------------------------------------------------------
file(GLOB_RECURSE SOURCE_GROUP_FILES "*.h" "*.cpp" "*.cu" "*.inl")
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/.." FILES ${SOURCE_GROUP_FILES})
