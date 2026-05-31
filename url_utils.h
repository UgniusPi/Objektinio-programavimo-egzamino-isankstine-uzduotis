#pragma once

/**
 * @file url_utils.h
 * @brief Pagalbinės funkcijos URL adresų išgavimui iš teksto.
 */

#include <string>
#include <vector>

/**
 * @brief Iš tekstinio įrašo ištraukia visus aptiktus URL adresus.
 * @param text Įvesties tekstas.
 * @return Vektorius rastų URL adresų (eilės tvarka).
 */
std::vector<std::string> extractUrls(const std::string& text);
