#pragma once

/**
 * @file text_utils.h
 * @brief Teksto apdorojimo pagalbinės funkcijos.
 *
 * Funkcijos skirtos žodžių normalizavimui (pašalinus skyrybą ir paverčiant mažosiomis).
 */

#include <string>

/**
 * @brief Pašalina skyrybos ženklus ir paverčia žodį mažosiomis raidėmis.
 * @param word Įvestas žodis.
 * @return Normalizuotas žodis (tik raides ir skaitmenis, mažosiomis).
 */
std::string normalizeWord(const std::string& word);
