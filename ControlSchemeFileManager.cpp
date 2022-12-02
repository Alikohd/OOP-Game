#include "ControlSchemeFileManager.h"

#include <fstream>
#include <sstream>
#include <utility>

#include "Logger.h"

ControlSchemeFileManager::ControlSchemeFileManager(std::string filename)
        : _filename(std::move(filename)) {}

ControlScheme ControlSchemeFileManager::scan() {
    std::ifstream file(_filename);
    if (!file.good()) {
        Logger::getInstance() << LoggerMessage{"Cannot open control scheme file!",
                                               Logger::Error};
        auto scheme = defaultScheme();
        save(scheme);
        return scheme;
    }

    std::unordered_map<char, Command> map;
    std::string line;
    // errors if file broken control
    while (std::getline(file, line)) {
        map.insert(proceedLine(line));
    }
    file.close();

    ControlScheme scheme{map};
    bool fixed = fixScheme(scheme);

    if (fixed) {
        save(scheme);
    }
    return scheme;
}

void ControlSchemeFileManager::save(const ControlScheme& control_scheme) {
    std::ofstream file(_filename);
    if (!file.good()) {
        Logger::getInstance() << LoggerMessage{
                "Cannot create file with control scheme!", Logger::Error};
        return;
    }

    for (const auto& pair : control_scheme.data) {
        auto command_str = encodeCommand(pair.second);
        std::stringstream line{};
        line << pair.first << '\t' << command_str << '\n';
        file << line.str();
    }
    file.close();
}

ControlScheme ControlSchemeFileManager::defaultScheme() {
    return _default_scheme;
}

bool ControlSchemeFileManager::fixScheme(ControlScheme& control_scheme) {
    bool flag = false;

    std::unordered_map<Command, bool> checked{};
    auto& map = control_scheme.data;
    for (const auto& pair : map) {
        if (pair.second == Command::Undefined) {
            map.erase(pair.first);
            flag = true;
            continue;
        }
        checked[pair.second] = true;
    }
    for (const auto& pair : _default_scheme.data) {
        if (checked[pair.second]) {
            continue;
        }
        flag = true;
        map[pair.first] = pair.second;
    }

    return flag;
}

std::pair<char, Command> ControlSchemeFileManager::proceedLine(
        const std::string& line) {
    const char kDelimiter = '\t';
    std::stringstream ss{line};
    std::string key_str;
    std::string command_str;
    std::getline(ss, key_str, kDelimiter);
    std::getline(ss, command_str, kDelimiter);

    char key = key_str.at(0);
    Command command = decodeCommand(command_str);

    std::pair<char, Command> pair{key, command};
    return pair;
}

std::string ControlSchemeFileManager::encodeCommand(Command command) {
    for (const auto& pair : _command_string_map) {
        if (pair.second == command) {
            return pair.first;
        }
    }
    return "Undefined";
}

Command ControlSchemeFileManager::decodeCommand(const std::string& str) {
    if (!_command_string_map.contains(str)) {
        return Command::Undefined;
    }
    return _command_string_map[str];
}