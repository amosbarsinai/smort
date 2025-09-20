// src/bindings.cpp
#include <pybind11/pybind11.h>
#include "window.hpp"
#include "error.hpp"
#include "keyboard.hpp"
#include "common.hpp"
#include "image.hpp"

namespace py = pybind11;

pybind11::object pySmortImageError;
pybind11::object pySmortRuntimeError;

PYBIND11_MODULE(_smort, m) {
    pySmortRuntimeError = pybind11::register_exception<SmortRuntimeError>(m, "RuntimeError");
    pySmortImageError = pybind11::register_exception<SmortImageError>(m, "ImageError");

    py::class_<Window>(m, "Window")
        .def(py::init<const std::string&, int, int, bool>(),
             py::arg("title") = "My Nice Little Window",
             py::arg("width") = 800,
             py::arg("height") = 600,
             py::arg("handles_updates") = true)
        .def("clear", &Window::clear)
        .def("tick", &Window::tick)
        .def("is_open", &Window::is_open)

        .def("fill", py::overload_cast<float, float, float>(&Window::fill))
        .def("fill", py::overload_cast<int, int, int>(&Window::fill))

        .def("blit", py::overload_cast<const std::string&, float, float>(&Window::blit))
        .def("blit", py::overload_cast<const std::string&, float, float, float, float>(&Window::blit))

        .def("blit", py::overload_cast<Image&, float, float>(&Window::blit))
        .def("blit", py::overload_cast<Image&, float, float, float, float>(&Window::blit))

        .def("close", &Window::close)

        .def("smort", &Window::smort)

        .def("__str__", &Window::to_string)

        .def_property("width", &Window::get_width, &Window::set_width)
        .def_property("height", &Window::get_height, &Window::set_height)
        .def_property("size", &Window::get_size, &Window::set_size)
        ;

    py::class_<Image>(m, "Image")
        .def(py::init<const std::string&>())
        .def_property_readonly("width", &Image::get_width)
        .def_property_readonly("height", &Image::get_height)
        .def_property_readonly("size", &Image::get_size)

        .def("__str__", &Image::to_string)
        ;

    py::class_<Vector2>(m, "Vector2")
        .def(py::init<int, int>())
        .def_readwrite("x", &Vector2::x)
        .def_readwrite("y", &Vector2::y)

        .def("__str__", &Vector2::to_string)
        ;

    auto keyboard = m.def_submodule("keyboard", "Keyboard input handling");
    keyboard.def("is_a_pressed", &keyboard::is_a_pressed);
    keyboard.def("is_b_pressed", &keyboard::is_b_pressed);
    keyboard.def("is_c_pressed", &keyboard::is_c_pressed);
    keyboard.def("is_d_pressed", &keyboard::is_d_pressed);
    keyboard.def("is_e_pressed", &keyboard::is_e_pressed);
    keyboard.def("is_f_pressed", &keyboard::is_f_pressed);
    keyboard.def("is_g_pressed", &keyboard::is_g_pressed);
    keyboard.def("is_h_pressed", &keyboard::is_h_pressed);
    keyboard.def("is_i_pressed", &keyboard::is_i_pressed);
    keyboard.def("is_j_pressed", &keyboard::is_j_pressed);
    keyboard.def("is_k_pressed", &keyboard::is_k_pressed);
    keyboard.def("is_l_pressed", &keyboard::is_l_pressed);
    keyboard.def("is_m_pressed", &keyboard::is_m_pressed);
    keyboard.def("is_n_pressed", &keyboard::is_n_pressed);
    keyboard.def("is_o_pressed", &keyboard::is_o_pressed);
    keyboard.def("is_p_pressed", &keyboard::is_p_pressed);
    keyboard.def("is_q_pressed", &keyboard::is_q_pressed);
    keyboard.def("is_r_pressed", &keyboard::is_r_pressed);
    keyboard.def("is_s_pressed", &keyboard::is_s_pressed);
    keyboard.def("is_t_pressed", &keyboard::is_t_pressed);
    keyboard.def("is_u_pressed", &keyboard::is_u_pressed);
    keyboard.def("is_v_pressed", &keyboard::is_v_pressed);
    keyboard.def("is_w_pressed", &keyboard::is_w_pressed);
    keyboard.def("is_x_pressed", &keyboard::is_x_pressed);
    keyboard.def("is_y_pressed", &keyboard::is_y_pressed);
    keyboard.def("is_z_pressed", &keyboard::is_z_pressed);
    keyboard.def("is_num0_pressed", &keyboard::is_num0_pressed);
    keyboard.def("is_num1_pressed", &keyboard::is_num1_pressed);
    keyboard.def("is_num2_pressed", &keyboard::is_num2_pressed);
    keyboard.def("is_num3_pressed", &keyboard::is_num3_pressed);
    keyboard.def("is_num4_pressed", &keyboard::is_num4_pressed);
    keyboard.def("is_num5_pressed", &keyboard::is_num5_pressed);
    keyboard.def("is_num6_pressed", &keyboard::is_num6_pressed);
    keyboard.def("is_num7_pressed", &keyboard::is_num7_pressed);
    keyboard.def("is_num8_pressed", &keyboard::is_num8_pressed);
    keyboard.def("is_num9_pressed", &keyboard::is_num9_pressed);
    keyboard.def("is_escape_pressed", &keyboard::is_escape_pressed);
    keyboard.def("is_lcontrol_pressed", &keyboard::is_lcontrol_pressed);
    keyboard.def("is_lshift_pressed", &keyboard::is_lshift_pressed);
    keyboard.def("is_lalt_pressed", &keyboard::is_lalt_pressed);
    keyboard.def("is_lsystem_pressed", &keyboard::is_lsystem_pressed);
    keyboard.def("is_rcontrol_pressed", &keyboard::is_rcontrol_pressed);
    keyboard.def("is_rshift_pressed", &keyboard::is_rshift_pressed);
    keyboard.def("is_ralt_pressed", &keyboard::is_ralt_pressed);
    keyboard.def("is_rsystem_pressed", &keyboard::is_rsystem_pressed);
    keyboard.def("is_menu_pressed", &keyboard::is_menu_pressed);
    keyboard.def("is_lbracket_pressed", &keyboard::is_lbracket_pressed);
    keyboard.def("is_rbracket_pressed", &keyboard::is_rbracket_pressed);
    keyboard.def("is_semicolon_pressed", &keyboard::is_semicolon_pressed);
    keyboard.def("is_comma_pressed", &keyboard::is_comma_pressed);
    keyboard.def("is_period_pressed", &keyboard::is_period_pressed);
    keyboard.def("is_quote_pressed", &keyboard::is_quote_pressed);
    keyboard.def("is_slash_pressed", &keyboard::is_slash_pressed);
    keyboard.def("is_backslash_pressed", &keyboard::is_backslash_pressed);
    keyboard.def("is_tilde_pressed", &keyboard::is_tilde_pressed);
    keyboard.def("is_equal_pressed", &keyboard::is_equal_pressed);
    keyboard.def("is_hyphen_pressed", &keyboard::is_hyphen_pressed);
    keyboard.def("is_space_pressed", &keyboard::is_space_pressed);
    keyboard.def("is_enter_pressed", &keyboard::is_enter_pressed);
    keyboard.def("is_backspace_pressed", &keyboard::is_backspace_pressed);
}
