add_executable(solving_nonlinear_equations
        main.cpp
        src/interval.h
        src/algorithm/algorithm.h
        src/algorithm/methods/BisectionMethod.cpp
        src/algorithm/methods/BisectionMethod.h
        src/algorithm/methods/NewtonMethod.cpp
        src/algorithm/methods/NewtonMethod.h
        src/algorithm/methods/ModifiedNewtonMethod.cpp
        src/algorithm/methods/ModifiedNewtonMethod.h
        src/algorithm/methods/SecantMethod.cpp
        src/algorithm/methods/SecantMethod.h)

target_compile_features(solving_nonlinear_equations PRIVATE cxx_std_17)