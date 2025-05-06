#pragma once

#include <string>
#include <vector>
#include <optional>

namespace tofupilot {

    /**
     * @brief Represents a measurement outcome in TofuPilot
     */
    enum class MeasurementOutcome {
        PASS,
        FAIL,
        UNSET
    };

    /**
     * @brief Represents a phase outcome in TofuPilot
     */
    enum class PhaseOutcome {
        PASS,
        FAIL,
        SKIP,
        ERROR
    };

    /**
     * @brief Represents a file attachment
     */
    struct FileInfo {
        std::string filename;
        std::string filepath;
    };

    /**
     * @brief Represents a sub-unit in TofuPilot
     */
    struct SubUnit {
        std::string serialNumber;
    };

    /**
     * @brief Represents a unit under test in TofuPilot
     */
    struct UnitUnderTest {
        std::string serialNumber;
        std::optional<std::string> partNumber;
        std::optional<std::string> revision;
        std::optional<std::string> batchNumber;
    };

} // namespace tofupilot