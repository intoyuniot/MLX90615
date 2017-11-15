// 本程序使用MLX90615红外体温模块，获取人体体温，并重串口输出数据
// 本程序使用的是Serial
// 连接说明：
// MLX90615                     Atom
// 1.VIN                        +3.3V
// 2.GND                        GND
// 3.RX                         A3(TX)
// 4.TX                         A2(RX)
#include <MLX90615.h>

MLX90615 bodyTemp; // 定义传感器变量
void setup()
{
    Serial.begin(115200);
    bodyTemp.begin(); // 初始化
}

void loop()
{
    double temp = bodyTemp.getTemperature(); // 获取温度传感器的温度
    if (temp != -1)
    {
        Serial.print(temp); // 串口输出温度数据
    }
    delay(2000);  // 延迟2s
}
