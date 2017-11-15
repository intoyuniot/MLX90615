/*
 ******************************************************************************

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation, either
 version 3 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, see <http://www.gnu.org/licenses/>.

 This library is MLX90615 temperature sensor module

 ******************************************************************************
 */

#ifndef MLX90615_H
#define MLX90615_H

#include "Arduino.h"

class MLX90615
{
    public:
        MLX90615();
        // 初始化串口
        char begin();
        // 获取温度值
        double getTemperature();

    private:
        unsigned char Re_buf[11], counter;
        unsigned char sign;
        float TO;
};

#endif
