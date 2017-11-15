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


#include "MLX90615.h"


MLX90615::MLX90615()
{

}

char MLX90615::begin()
{
    Serial.begin(115200);
    counter = 0;
    sign = 0;
}


double MLX90615::getTemperature()
{

    unsigned char i=0, sum=0;
    Serial.flush();
    Serial.write(0XA5); //获取温度数据
    Serial.write(0X15);
    Serial.write(0XBA);
    delay(50);

    while (Serial.available())
    {
        Re_buf[counter] = (unsigned char)Serial.read();
        if(counter == 0 && Re_buf[0] != 0x5A) return -1; //检查帧头
        counter++;
        if(counter == 9)  //接收到数据
        {
            counter = 0;  //重新赋值，准备下一帧数据的接收
            sign = 1;
        }
    }

    if(sign)
    {
        sign = 0;
        for (i = 0; i < 8; i++)
            sum += Re_buf[i];
        if(sum == Re_buf[i] )    //检查帧头，帧尾
        {
            TO = (float)(Re_buf[4]<<8|Re_buf[5])/100;
            return TO;
        }
    }

    return -1;
}
