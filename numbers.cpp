// Copyright (C) 2022 Devin Jhu All rights reserved
//
// Created by Devin Jhu
// Created on June 2022
// The array average

#include <iostream>
#include <iomanip>
#include <random>
#include <array>


template <int rows, int columns>
float calculations(int (&passedArray)[rows][columns]) {
    // this function finds the average

    int total = 0;
    float numberQuantity = 0;

    for (size_t rowAdder = 0; rowAdder < rows; ++rowAdder) {
        for (size_t columnAdder = 0; columnAdder < columns; ++columnAdder) {
            total += passedArray[rowAdder][columnAdder];
            numberQuantity += 1;
        }
    }

    float average = total / numberQuantity;

    return average;
}


int main() {
    // this function generates a row/column array, then outputs the average

    int randomNumber = 0;
    float average = 0;
    const int rows = 3;
    const int columns = 3;
    int numberArray[rows][columns];

    // random seed
    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne twister
    std::uniform_int_distribution<int> idist(0, 50);  // random from 0 - 50

    std::cout << "This program finds the average of a 2D array.\n" << std::endl;

    // no input is available in c++ for a 2d array

    // process and output
    for (int rowCounter = 0; rowCounter < rows; rowCounter++) {
        for (int columnCounter = 0; columnCounter < columns; columnCounter++) {
            randomNumber = idist(rgen);
            numberArray[rowCounter][columnCounter] = randomNumber;
            std::cout << randomNumber << " ";
        }
        std::cout << std::endl;
    }

    average = calculations(numberArray);

    // output
    std::cout << "\nThe average is " << std::fixed <<
    std::setprecision(2) << std::setfill('0') << average << "." << std::endl;

    std::cout << "\nDone." << std::endl;
}
