cmake_minimum_required(VERSION 3.22)
project(catboost_inference_example)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CATBOOST_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/catboost)

message("CATBOOST_ROOT: ${CATBOOST_ROOT}")

find_library(CATBOOST_MODEL_LIB
  NAMES catboostmodel
  PATHS ${CATBOOST_ROOT}/build_/catboost/libs/model_interface
  NO_DEFAULT_PATH)

if(NOT CATBOOST_MODEL_LIB)
  message(FATAL_ERROR "catboostmodel not found")
endif()

add_executable(main main.cpp)

message("CATBOOST_MODEL_LIB ${CATBOOST_MODEL_LIB}")

target_link_libraries(main PRIVATE ${CATBOOST_MODEL_LIB})

target_include_directories(
  main
  PRIVATE
  ${CATBOOST_ROOT}
  # ${CMAKE_CURRENT_SOURCE_DIR}/catboost
)


# cmake_minimum_required(VERSION 3.14)
# project(catboost_shap_example)

# set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# # Replace this path with your actual catboost repo path
# set(CATBOOST_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/catboost)

# # Include paths
# include_directories(
#   ${CATBOOST_ROOT}
#   # ${CATBOOST_ROOT}/contrib/libs/cxxsupp/libcxx/include
#   # ${CATBOOST_ROOT}/build_
#   # ${CATBOOST_ROOT}/build_/contrib/libs/cxxsupp/libcxx/include
#   # ${CATBOOST_ROOT}/build_/contrib/libs
#   # ${CATBOOST_ROOT}/build_/contrib/libs/libdivide
#   # ${CATBOOST_ROOT}/build_/contrib/libs/double-conversion
#   # ${CATBOOST_ROOT}/build_/contrib/libs/cxxsupp
#   # ${CATBOOST_ROOT}/build_/contrib/libs/fast_double_parser
#   # ${CATBOOST_ROOT}/build_/contrib/libs/libc_compat
#   # ${CATBOOST_ROOT}/build_/catboost/libs
#   # ${CATBOOST_ROOT}/build_/util
#   # ${CATBOOST_ROOT}
# )

# # Link CatBoost model and fstr libraries
# # link_directories(
# #   ${CATBOOST_ROOT}/build_
# # )

# add_executable(main main.cpp)

# # target_link_libraries(main PRIVATE
# #   catboostmodel
# #   # catboost-libs-fstr
# #   # catboost-libs-data
# # )