#include <iostream>
#include <cmath>

using namespace std;

/**
 * @brief Circuit Power and Heat Dissipation Analysis
 * Computes electrical current, voltage, and Joule heating power dissipation
 * using Ohm's Law and Joule's Law:
 *   V = I * R
 *   P = I^2 * R
 */
int main()
{
    float resistance = 0.0f; // Resistance in Ohms (Ω)
    float current = 0.0f;    // Current in Amperes (A)
    float voltage = 0.0f;    // Voltage in Volts (V)
    float power = 0.0f;      // Power dissipation in Watts (W)

    cout << "====================================================\n";
    cout << "   Circuit Power & Dissipation Analysis (C++)       \n";
    cout << "====================================================\n\n";

    cout << "Please enter Resistance value in ohms (R): ";
    cin >> resistance;

    cout << "Please enter Current value in amps (I): ";
    cin >> current;

    if (resistance < 0 || current < 0) {
        cerr << "Warning: Resistance and current must be non-negative values.\n";
        return 1;
    }

    // Ohm's Law: V = I * R
    voltage = current * resistance;

    // Joule's First Law: P = I^2 * R
    power = pow(current, 2) * resistance;

    cout << "\n---------------- Results ----------------\n";
    cout << "Calculated Voltage (V): " << voltage << " Volts\n";
    cout << "Power Dissipation (P):  " << power << " Watts\n";
    cout << "-----------------------------------------\n";

    return 0;
}
