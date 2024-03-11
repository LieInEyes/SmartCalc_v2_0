cmake_minimum_required(VERSION 3.22.1)
project(SmartCalc_v2_0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include_directories(src)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        PrintSupport
        REQUIRED)

add_executable(SmartCalc_v2_0
        src/main/main.cc
        src/backend/back/model_calculator.cc
        src/backend/back/model_calculator.h
        src/backend/validator/valid_user_input.cc
        src/backend/validator/valid_user_input.h
        src/controller/controller.cc
        src/controller/controller.h
        src/backend/back/reverse_polish_notation.cc
        src/backend/back/reverse_polish_notation.h
        src/backend/back/modify_input.cc
        src/backend/back/modify_input.h
        src/frontend/main_window/view.cc
        src/frontend/main_window/view.h
        src/frontend/main_window/view.ui
        src/frontend/credit_calculator/creditcalc.cc
        src/frontend/credit_calculator/creditcalc.h
        src/frontend/credit_calculator/creditcalc.ui
        src/frontend/deposit_calculator/depositcalc.cc
        src/frontend/deposit_calculator/depositcalc.h
        src/frontend/deposit_calculator/depositcalc.ui
        src/frontend/window_input_x/randomx.cc
        src/frontend/window_input_x/randomx.h
        src/frontend/window_input_x/randomx.ui
        src/frontend/graph/model_graph.cc
        src/frontend/graph/model_graph.h
        src/frontend/graph/model_graph.ui
        src/qcustomplot.cc
        src/qcustomplot.h
        )

target_link_libraries(SmartCalc_v2_0
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::PrintSupport
        )
