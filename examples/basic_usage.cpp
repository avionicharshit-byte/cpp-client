#include <iostream>
#include "tofupilot/client.h"

int main() {
    // Create client with API key
    tofupilot::Client client("YOUR_API_KEY");
    
    // Create a unit under test
    tofupilot::UnitUnderTest unit;
    unit.serialNumber = "DEVICE-001";
    unit.partNumber = "MODEL-X";
    
    // Create a run
    std::string runId = client.createRun(unit, true, "TEST-PROC-1");
    
    std::cout << "Created run with ID: " << runId << std::endl;
    
    return 0;
}