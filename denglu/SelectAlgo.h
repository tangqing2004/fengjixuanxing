#pragma once
class CSelectAlgo
{
public:
	CSelectAlgo(void);
	~CSelectAlgo(void);
	//风量
    double airFlow;
    //全压
    double totalPressure;
    //计算功率
    double power;
    // 计算转速
    double rotationSpeed;
    // 计算比转数
    double specificSpeed;
    // 计算噪声水平
    double noiseLevel;
	 // 计算风机规格
    void calculateFanSpecs(double diameter, double altitude, double slope);

    // 计算风量
    double calculateAirFlow(double diameter, double slope);

    // 计算全压
    double calculateTotalPressure(double diameter, double altitude);

    // 计算功率
    double calculatePower(double airFlow, double totalPressure, double efficiency);

    // 计算转速
    double calculateRotationSpeed(double airFlow, double totalPressure);

    // 计算比转数
    double calculateSpecificSpeed(double rotationSpeed, double airFlow, double totalPressure);

    // 计算噪声水平
    double calculateNoiseLevel(double airFlow, double totalPressure);

    // 温度修正
    double temperatureCorrection(double airFlow, double temperature);

    // 海拔修正
    double altitudeCorrection(double totalPressure, double altitude);

    // 系统阻力计算
    double calculateSystemResistance(double diameter, double length, int numberOfBends);

};

