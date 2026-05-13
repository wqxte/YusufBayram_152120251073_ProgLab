#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Sensor
{
    int sensor_id;
    float sicaklik;
};

int main()
{

    long long student_id;
    cout << "Enter student number";
    cin >> student_id;

    int N = student_id % 50;
    float E = student_id % 100;

    fstream file("sensors.bin", ios::in | ios::out | ios::binary);

    if (!file)
    {
        return 1;
    }

    Sensor tempSensor;

    file.seekg(N * sizeof(Sensor), ios::beg);
    file.read(reinterpret_cast<char *>(&tempSensor), sizeof(Sensor));

    float firstTemperature = tempSensor.sicaklik;

    tempSensor.sicaklik += E;

    file.seekp(N * sizeof(Sensor), ios::beg);
    file.write(reinterpret_cast<char *>(&tempSensor), sizeof(Sensor));

    file.close();

    string fileName = to_string(student_id) + "_Quiz5.txt";
    ofstream reportFile(fileName);

    if (reportFile.is_open())
    {
        reportFile << "Number: " << student_id << endl;
        reportFile << "Sensor index used in the process: " << N << endl;
        reportFile << "First temperature: " << firstTemperature << " -> New temperature: " << tempSensor.sicaklik << endl;

        reportFile.close();
        cout << "file created: " << fileName << endl;
    }
    else
    {
        cerr << "file coulndt be created" << endl;
    }

    return 0;
}