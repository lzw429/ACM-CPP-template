cmake_minimum_required(VERSION 3.10)
project(ACM_CPP_template)

set(CMAKE_CXX_STANDARD 11)

add_executable(ACM_CPP_template Graph/ForwardStar.h Graph/TopoSort.h Math/Matrix.h Math/GaussElimination.h Math/GCD.h Math/ExtendGCD.h Math/Gray.h Math/BigInteger.h Math/Fraction.h test/POJ-3734.cpp)