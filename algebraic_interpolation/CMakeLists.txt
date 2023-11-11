add_executable(algebraic_interpolation
        main.cpp
        src/InterpolationCalculator/InterpolationCalculator.cpp
        src/algorithm/IPolynomCalculator.h
        src/algorithm/LagrangeMethod/LagrangeMethod.cpp
        src/algorithm/NewtonMethod/NewtonMethod.cpp)

target_compile_features(algebraic_interpolation PRIVATE cxx_std_17)