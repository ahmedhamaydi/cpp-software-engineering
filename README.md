# C++ Software & Systems Engineering Suite

[![Language](https://img.shields.io/badge/Language-C%2B%2B17-00599C.svg?logo=c%2B%2B)](https://isocpp.org/)
[![Focus](https://img.shields.io/badge/Focus-Systems%20%7C%20File%20I%2FO%20%7C%20Circuit%20Simulation-blue.svg)]()
[![Author](https://img.shields.io/badge/Author-Ahmed%20Hamaydi-orange.svg)](https://github.com/ahmedhamaydi)

A collection of **C++ systems engineering modules, data processing engines, and circuit simulators**. Demonstrates stream-based I/O pipelines (`<fstream>`), dynamic memory allocation (`std::vector`), pass-by-reference mechanics, and electrical engineering modeling in modern C++.

---

## 📁 Repository Structure

```text
cpp-software-engineering/
├── data_analysis_engine/
│   ├── statistical_data_engine.cpp     # Flagship file I/O pipeline, sorting, and statistical engine
│   └── sample_dataset.txt              # Sample 100-element dataset for immediate testing
│
├── electronics_and_hardware/
│   ├── circuit_power_analysis.cpp      # Ohm's Law & Joule heating dissipation modeling
│   └── voltage_divider_simulator.cpp   # Two-resistor voltage divider & signal attenuation simulator
│
├── utilities/
│   └── interactive_calculator.cpp      # Procedural control flow & arithmetic console tool
│
├── .gitignore                          # Excludes all .exe, .obj, .pdb, and compiler artifacts
└── README.md                           # Technical documentation and build instructions
```

---

## 🏗️ 1. Flagship: Statistical Dataset Analysis Engine (`statistical_data_engine.cpp`)

Engineered as part of the **Computer Systems & Programming** curriculum at the University of Huddersfield.

### Key Architectural Capabilities:
* **Stream-Based File I/O Pipelines:** Uses `<fstream>` (`ifstream`, `ofstream`) to safely ingest raw numerical records from disk and export formatted reports.
* **Dynamic Memory & Pass-by-Reference:** Employs `std::vector<double>` and `const vector<double>&` parameter passing to eliminate unnecessary memory copying and prevent memory leaks.
* **Robust Input Validation & Fault Tolerance:** Validates file stream readiness, checks dataset emptiness, and flags negative numbers before processing.
* **Statistical Metrics Engine:** Computes descriptive statistics across dynamic datasets:
  * **Mean:** Arithmetic average calculation.
  * **Median:** Robust midpoint computation supporting both even and odd dataset lengths.
  * **Mode:** Multimodal detection algorithm identifying all peak frequency elements.
  * **In-Place Sorting:** Bubble sort implementation ordering vectors with $O(n^2)$ worst-case and $O(1)$ auxiliary space.

---

## ⚡ 2. Hardware & Electrical Circuit Simulators

Bridging **Computer Engineering** and **Electronic Systems**:

### Circuit Power & Dissipation Analysis (`circuit_power_analysis.cpp`)
* Implements mathematical modeling for electrical circuits based on **Ohm's Law** ($V = I \cdot R$) and **Joule's First Law** ($P = I^2 \cdot R$).
* Enforces non-negative parameter boundary checking and prints calculated electrical dissipation metrics.

### Voltage Divider Simulator (`voltage_divider_simulator.cpp`)
* Models signal attenuation and loaded voltage division networks:
  $$\mathcal{V}_o = \mathcal{V}_s \cdot \left(\frac{\mathcal{R}_2}{\mathcal{R}_1 + \mathcal{R}_2}\right)$$
* Calculates the precise circuit attenuation ratio for resistive loads.

---

## 🛠️ 3. Building & Running the Code

### Prerequisites
A modern C++ compiler supporting C++11 or higher (GCC, Clang, or Microsoft Visual C++ MSVC).

### Using GCC / G++ (Linux, Mac, or Windows MinGW)

```bash
# 1. Compile the Statistical Data Engine
g++ -std=c++17 data_analysis_engine/statistical_data_engine.cpp -o stats_engine

# 2. Run the engine (use sample_dataset.txt when prompted)
./stats_engine

# 3. Compile the Circuit Power Simulator
g++ -std=c++17 electronics_and_hardware/circuit_power_analysis.cpp -o circuit_sim
./circuit_sim
```

### Using Microsoft Visual Studio (Developer Command Prompt)

```cmd
cl /EHsc data_analysis_engine\statistical_data_engine.cpp
statistical_data_engine.exe
```

---

## 👨‍💻 Author

**Ahmed Hamaydi**  
*Aspiring Computer Engineer*  
* University of Huddersfield — BEng (Hons) Electronic Engineering & Computer Systems *(Predicted 1st Class)*  
* **GitHub:** [@ahmedhamaydi](https://github.com/ahmedhamaydi)  
* **Email:** [ahmedhamaydi1914@gmail.com](mailto:ahmedhamaydi1914@gmail.com)
