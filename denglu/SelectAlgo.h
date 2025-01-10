#pragma once
class CSelectAlgo
{
public:
	CSelectAlgo(void);
	~CSelectAlgo(void);
	//����
    double airFlow;
    //ȫѹ
    double totalPressure;
    //���㹦��
    double power;
    // ����ת��
    double rotationSpeed;
    // �����ת��
    double specificSpeed;
    // ��������ˮƽ
    double noiseLevel;
	 // ���������
    void calculateFanSpecs(double diameter, double altitude, double slope);

    // �������
    double calculateAirFlow(double diameter, double slope);

    // ����ȫѹ
    double calculateTotalPressure(double diameter, double altitude);

    // ���㹦��
    double calculatePower(double airFlow, double totalPressure, double efficiency);

    // ����ת��
    double calculateRotationSpeed(double airFlow, double totalPressure);

    // �����ת��
    double calculateSpecificSpeed(double rotationSpeed, double airFlow, double totalPressure);

    // ��������ˮƽ
    double calculateNoiseLevel(double airFlow, double totalPressure);

    // �¶�����
    double temperatureCorrection(double airFlow, double temperature);

    // ��������
    double altitudeCorrection(double totalPressure, double altitude);

    // ϵͳ��������
    double calculateSystemResistance(double diameter, double length, int numberOfBends);

};

