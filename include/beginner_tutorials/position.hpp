/**
* MIT License
*
* Copyright(c) 2021 Abhijit Mahalle
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files(the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
* 
* @file position.hpp
* @author Abhijit Mahalle
* @brief Class for storing frame position
* @version 0.1
* @date 2021-11-15
* 
* @copyright Copyright (c) 2021
* 
*/

#ifndef SRC_BEGINNER_TUTORIALS_INCLUDE_POSITION_HPP_ //NOLINT-CPP
#define SRC_BEGINNER_TUTORIALS_INCLUDE_POSITION_HPP_ //NOLINT-CPP

struct Position {
   /**
    * @brief Constructor for the Position object
    * @param x
    * @param y
    * @param z
    * @param Roll
    * @param Pitch
    * @param Yaw
    * 
    */
 public:
    float x;
    float y;
    float z;
    float roll;
    float pitch;
    float yaw;

    Position(float x, float y, float z, float roll, float pitch, float yaw) :
        x(x), y(y), z(z), roll(roll), pitch(pitch), yaw(yaw) {}

/**
   * @brief Destructor for the Position object
   * 
   */
  ~Position() {}
};
#endif  // SRC_BEGINNER_TUTORIALS_INCLUDE_POSITION_HPP_//NOLINT-CPP
