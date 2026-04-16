// Copyright (c) 2026 Collin Johnson

#ifndef SRC_SIMULATOR_SIMULATOR_H_
#define SRC_SIMULATOR_SIMULATOR_H_

#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace svs::sim {

enum class TwoValuedValue { _1, _0 };

struct Process;

struct Module {
  std::unordered_map<std::string, TwoValuedValue> variables;
  std::unordered_set<std::shared_ptr<Process>> initials;
};

struct Instruction {
  virtual void Execute(std::shared_ptr<Module> module) = 0;
};

struct AssignmentInstruction : Instruction {
  std::string identifier;
  TwoValuedValue value;

  virtual void Execute(std::shared_ptr<Module> module) override {
    auto it = module->variables.find(identifier);
    if (it == module->variables.end())
      throw std::runtime_error{"Variable or net not found!"};

    it->second = value;
  }
};

struct DisplayInstruction : Instruction {
  std::string format;
  std::vector<std::string> params;

  virtual void Execute(std::shared_ptr<Module> module) override {
    std::stringstream ss;

    auto it = format.begin();
    auto id_it = params.begin();
    while (it != format.end()) {
      if (*it == '%') {
        ++it;
        if (it == format.end()) {
          ss << '%';
        } else {
          if (*it == 'd') {
            ++it;

            if (id_it == params.end())
              throw std::runtime_error{"Incorrect number of params"};

            auto var_it = module->variables.find(*id_it);
            ++id_it;

            if (var_it == module->variables.end())
              throw std::runtime_error{"Variable or net not found!"};

            TwoValuedValue value = var_it->second;
            switch (value) {
              case TwoValuedValue::_0:
                ss << 0;
              case TwoValuedValue::_1:
                ss << 1;
            }
          }
        }
      }

      ss << *it;
      ++it;
    }

    std::cout << ss.str() << '\n';
  }
};

struct Process {
  std::vector<std::shared_ptr<Instruction>> instructions;
  std::weak_ptr<Module> module;

  void Execute() {
    for (std::shared_ptr<Instruction> instruction : instructions) {
      instruction->Execute(module.lock());
    }
  }
};

// A simulator
class Simulator {
 public:
  // Constructs a simulator with the provided sv2017 ast and top-level module
  // identifier.
  Simulator();

  // Run the simulation.
  void Run(std::shared_ptr<Module> top_level_module);

 private:
  std::unordered_map<std::string, std::unique_ptr<Module>> modules_;
};

};  // namespace svs::sim

#endif  // SRC_SIMULATOR_SIMULATOR_H_
