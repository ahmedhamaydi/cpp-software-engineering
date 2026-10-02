#include <iostream>

using namespace std;

/**
 * @brief Voltage Divider & Signal Attenuation Simulator
 * Computes the output voltage (Vo) across resistor R2 in a two-resistor divider circuit:
 *   Vo = Vs * (R2 / (R1 + R2))
 */
int main()
{
    float sourceVoltage = 0.0f; // Source voltage in Volts (Vs)
    float r1 = 0.0f;            // Resistor 1 in Ohms (R1)
    float r2 = 0.0f;            // Resistor 2 in Ohms (R2)
    float outputVoltage = 0.0f; // Output voltage in Volts (Vo)

    cout << "====================================================\n";
    cout << "     Voltage Divider Circuit Simulator (C++)        \n";
    cout << "====================================================\n\n";

    cout << "Please enter Source Voltage (Vs) in volts: ";
    cin >> sourceVoltage;

    cout << "Please enter Resistance 1 (R1) in ohms: ";
    cin >> r1;

    cout << "Please enter Resistance 2 (R2) in ohms: ";
    cin >> r2;

    if (r1 <= 0 || r2 <= 0) {
        cerr << "Error: Resistance values must be greater than zero.\n";
        return 1;
    }

    // Voltage divider transfer function
    outputVoltage = sourceVoltage * (r2 / (r1 + r2));

    cout << "\n---------------- Simulation Results ----------------\n";
    cout << "Input Voltage (Vs):        " << sourceVoltage << " V\n";
    cout << "Total Resistance (R1+R2):  " << (r1 + r2) << " Ohms\n";
    cout << "Voltage Divider Output (Vo): " << outputVoltage << " V\n";
    cout << "Attenuation Ratio:         " << (outputVoltage / sourceVoltage) << "\n";
    cout << "----------------------------------------------------\n";

    return 0;
}
