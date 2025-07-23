// include/keyboard.hpp
#pragma once
#include <SFML/Window/Keyboard.hpp>
#include <unordered_map>
#include <string>

namespace keyboard {
    inline bool is_a_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::A); }
    inline bool is_b_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::B); }
    inline bool is_c_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::C); }
    inline bool is_d_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::D); }
    inline bool is_e_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::E); }
    inline bool is_f_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::F); }
    inline bool is_g_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::G); }
    inline bool is_h_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::H); }
    inline bool is_i_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::I); }
    inline bool is_j_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::J); }
    inline bool is_k_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::K); }
    inline bool is_l_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::L); }
    inline bool is_m_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::M); }
    inline bool is_n_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::N); }
    inline bool is_o_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::O); }
    inline bool is_p_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::P); }
    inline bool is_q_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Q); }
    inline bool is_r_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::R); }
    inline bool is_s_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::S); }
    inline bool is_t_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::T); }
    inline bool is_u_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::U); }
    inline bool is_v_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::V); }
    inline bool is_w_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::W); }
    inline bool is_x_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::X); }
    inline bool is_y_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Y); }
    inline bool is_z_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Z); }
    inline bool is_num0_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Num0); }
    inline bool is_num1_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Num1); }
    inline bool is_num2_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Num2); }
    inline bool is_num3_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Num3); }
    inline bool is_num4_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Num4); }
    inline bool is_num5_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Num5); }
    inline bool is_num6_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Num6); }
    inline bool is_num7_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Num7); }
    inline bool is_num8_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Num8); }
    inline bool is_num9_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Num9); }
    inline bool is_escape_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Escape); }
    inline bool is_lcontrol_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::LControl); }
    inline bool is_lshift_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::LShift); }
    inline bool is_lalt_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt); }
    inline bool is_lsystem_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem); }
    inline bool is_rcontrol_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::RControl); }
    inline bool is_rshift_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::RShift); }
    inline bool is_ralt_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt); }
    inline bool is_rsystem_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::RSystem); }
    inline bool is_menu_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Menu); }
    inline bool is_lbracket_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::LBracket); }
    inline bool is_rbracket_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::RBracket); }
    inline bool is_semicolon_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Semicolon); }
    inline bool is_comma_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Comma); }
    inline bool is_period_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Period); }
    inline bool is_quote_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Quote); }
    inline bool is_slash_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Slash); }
    inline bool is_backslash_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Backslash); }
    inline bool is_tilde_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Tilde); }
    inline bool is_equal_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Equal); }
    inline bool is_hyphen_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Hyphen); }
    inline bool is_space_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Space); }
    inline bool is_enter_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Enter); }
    inline bool is_backspace_pressed() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace); }
} // namespace keyboard