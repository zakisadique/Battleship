/*
 * part1tests.h
 *
 *  Created on: 24-Dec-2023
 *      Author: zakisadique
 */

#ifndef TESTS_H_
#define TESTS_H_

#include <string>

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue(bool condition, std::string failedMessage);

/**
 * @brief Executes the tests related to part 1.
 */
void part1tests();

/**
 * @brief Executes the tests related to part 2.
 */
void part2tests();

/**
 * @brief Executes the tests related to part 3.
 */
void part3tests();

#endif /* TESTS_H_ */

