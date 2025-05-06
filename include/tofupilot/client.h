#pragma once

#include <string>
#include <vector>
#include <mutex>
#include <memory>
#include "tofupilot/models.h"

namespace tofupilot {

    /**
     * @brief Client for TofuPilot API
     *
     * Provides an interface to the TofuPilot API for test run creation and management.
     */
    class Client {
    public:
        /**
         * @brief Construct a new Client
         *
         * @param apiKey TofuPilot API key
         * @param baseUrl Base URL for the API (optional)
         */
        explicit Client(const std::string& apiKey, const std::string& baseUrl = "https://www.tofupilot.app/api/v1");

        /**
         * @brief Destroy the Client
         */
        ~Client();

        /**
         * @brief Create a test run
         *
         * @param unitUnderTest The unit being tested
         * @param runPassed Whether the run passed overall
         * @param procedureId ID of the procedure
         * @return std::string The ID of the created run
         */
        std::string createRun(
            const UnitUnderTest& unitUnderTest,
            bool runPassed,
            const std::string& procedureId);

        /**
         * @brief Get runs for a specific unit
         *
         * @param serialNumber Serial number of the unit
         * @return std::string JSON string containing the runs
         */
        std::string getRuns(const std::string& serialNumber);

        /**
         * @brief Delete a run
         *
         * @param runId ID of the run to delete
         * @return true If deletion was successful
         * @return false If deletion failed
         */
        bool deleteRun(const std::string& runId);

    private:
        class Impl;
        std::unique_ptr<Impl> pImpl;

        std::string m_apiKey;
        std::string m_baseUrl;
        mutable std::mutex m_mutex;
    };

} // namespace tofupilot