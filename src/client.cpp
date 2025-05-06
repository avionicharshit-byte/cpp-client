#include "tofupilot/client.h"

namespace tofupilot {

    class Client::Impl {
    public:
        Impl(const std::string& apiKey, const std::string& baseUrl)
            : m_apiKey(apiKey), m_baseUrl(baseUrl) {}

        std::string m_apiKey;
        std::string m_baseUrl;
    };

    Client::Client(const std::string& apiKey, const std::string& baseUrl)
        : pImpl(std::make_unique<Impl>(apiKey, baseUrl)) {
    }

    Client::~Client() = default;

    std::string Client::createRun(
        const UnitUnderTest& unitUnderTest,
        bool runPassed,
        const std::string& procedureId) {

        // Simple implementation placeholder
        // Will be expanded in later commits
        return "run-id-placeholder";
    }

    std::string Client::getRuns(const std::string& serialNumber) {
        // Simple implementation placeholder
        return "{}";
    }

    bool Client::deleteRun(const std::string& runId) {
        // Simple implementation placeholder
        return true;
    }

} // namespace tofupilot