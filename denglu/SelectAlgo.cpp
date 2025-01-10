#include "StdAfx.h"
#include "SelectAlgo.h"
#include <cmath>


CSelectAlgo::CSelectAlgo(void)
{
}


CSelectAlgo::~CSelectAlgo(void)
{
}

void CSelectAlgo::calculateFanSpecs(double diameter, double altitude, double slope)
{
    // 计算风量
    airFlow = calculateAirFlow(diameter, slope);

    // 计算全压
    totalPressure = calculateTotalPressure(diameter, altitude);

    // 计算功率
    double efficiency = 0.85; // 假设风机效率为85%
    power = calculatePower(airFlow, totalPressure, efficiency);

    // 计算转速
    rotationSpeed = calculateRotationSpeed(airFlow, totalPressure);

    // 计算比转数
    specificSpeed = calculateSpecificSpeed(rotationSpeed, airFlow, totalPressure);

    // 计算噪声水平
    noiseLevel = calculateNoiseLevel(airFlow, totalPressure);

    // 输出结果
    // 这里可以根据需要将结果输出到界面或日志中
}

double CSelectAlgo::calculateAirFlow(double diameter, double slope)
{
    // 根据风管直径和斜井坡度计算风量
    // 这里使用简化的公式，实际应用中可能需要更复杂的计算
    return 3.14 * (diameter / 2) * (diameter / 2) * slope /3600; // 假设单位为 m³/h
}

double CSelectAlgo::calculateTotalPressure(double diameter, double altitude)
{
    // 根据风管直径和海拔高度计算全压
    // 这里使用简化的公式，实际应用中可能需要更复杂的计算
    return 1000 * (diameter / 2) + altitude * 10; // 假设单位为 Pa
}

double CSelectAlgo::calculatePower(double airFlow, double totalPressure, double efficiency)
{
    // 根据风量、全压和效率计算功率
    return (airFlow * totalPressure) / (1000 * efficiency); // 单位为 kW
}

double CSelectAlgo::calculateRotationSpeed(double airFlow, double totalPressure)
{
    // 根据风量和全压计算转速
    // 这里使用简化的公式，实际应用中可能需要更复杂的计算
    return (airFlow * 60) / (3.14 * totalPressure); // 单位为 rpm
}

double CSelectAlgo::calculateSpecificSpeed(double rotationSpeed, double airFlow, double totalPressure)
{
    // 根据转速、风量和全压计算比转数
    return (rotationSpeed * sqrt(airFlow)) / pow(totalPressure, 0.75);
}

double CSelectAlgo::calculateNoiseLevel(double airFlow, double totalPressure)
{
    // 根据风量和全压计算噪声水平
    // 这里使用简化的公式，实际应用中可能需要更复杂的计算
    return 50 + 10 * log10(airFlow) + 2 * log10(totalPressure); // 假设单位为 dB
}

double CSelectAlgo::temperatureCorrection(double airFlow, double temperature)
{
    // 根据温度修正风量
    // 这里使用简化的公式，实际应用中可能需要更复杂的计算
    return airFlow * (1 + (temperature - 20) * 0.01); // 假设基准温度为20°C
}

double CSelectAlgo::altitudeCorrection(double totalPressure, double altitude)
{
    // 根据海拔修正全压
    // 这里使用简化的公式，实际应用中可能需要更复杂的计算
    return totalPressure * (1 - altitude * 0.0001); // 假设海拔单位为米
}

double CSelectAlgo::calculateSystemResistance(double diameter, double length, int numberOfBends)
{
    // 根据管道长度、直径和弯头数量计算系统阻力
    // 这里使用简化的公式，实际应用中可能需要更复杂的计算
    return length * 0.1 + numberOfBends * 5; // 假设单位为 Pa
}