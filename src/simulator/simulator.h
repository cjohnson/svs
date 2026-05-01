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

struct SimulationContext {
  virtual TwoValuedValue GetVariable(std::string identifier) = 0;
  virtual void SetVariable(std::string identifier, TwoValuedValue value) = 0;

  virtual void Finish() = 0;
};

struct Process;

struct Module : public SimulationContext {
  std::weak_ptr<SimulationContext> parent;

  std::unordered_map<std::string, TwoValuedValue> variables;
  std::unordered_set<std::shared_ptr<Process>> initials;

  virtual TwoValuedValue GetVariable(std::string identifier) override {
    if (variables.contains(identifier)) {
      return variables[identifier];
    }

    return parent.lock()->GetVariable(identifier);
  }

  virtual void SetVariable(std::string identifier,
                           TwoValuedValue value) override {
    if (variables.contains(identifier)) {
      variables[identifier] = value;
      return;
    }

    parent.lock()->SetVariable(identifier, value);
  }

  virtual void Finish() override { parent.lock()->Finish(); }
};

struct Instruction {
  virtual void Execute(std::weak_ptr<SimulationContext> context) = 0;
};

struct AssignmentInstruction : Instruction {
  std::string identifier;
  TwoValuedValue value;

  virtual void Execute(std::weak_ptr<SimulationContext> context) override {
    context.lock()->SetVariable(identifier, value);
  }
};

struct DisplayInstruction : Instruction {
  std::string format;
  std::vector<std::string> params;

  virtual void Execute(std::weak_ptr<SimulationContext> context) override {
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

            TwoValuedValue value = context.lock()->GetVariable(*id_it);
            ++id_it;

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
class Simulator : public SimulationContext {
 public:
  // Constructs a simulator with the provided sv2017 ast and top-level module
  // identifier.
  Simulator();

  // Run the simulation.
  void Run(std::shared_ptr<Module> top_level_module);

  virtual TwoValuedValue GetVariable(std::string identifier) override;
  virtual void SetVariable(std::string identifier,
                           TwoValuedValue value) override;

  virtual void Finish() override;

 private:
  bool finished_;
};

};  // namespace svs::sim

#endif  // SRC_SIMULATOR_SIMULATOR_H_
