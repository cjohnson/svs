// Copyright (c) 2026 Collin Johnson

#ifndef SRC_SIMULATOR_SIMULATOR_H_
#define SRC_SIMULATOR_SIMULATOR_H_

#include <iostream>
#include <memory>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace svs::sim {

enum class TwoValuedLogicState { _0, _1 };

class Value {
 public:
  enum class ValueKind { kBit };

  Value(const ValueKind& value_kind) : value_kind_(value_kind) {}

  virtual void Display(std::ostream& os) const = 0;

 private:
  ValueKind value_kind_;
};

class BitValue : public Value {
 public:
  BitValue(const TwoValuedLogicState& state = TwoValuedLogicState::_0)
      : state_(state), Value(Value::ValueKind::kBit) {}

  virtual void Display(std::ostream& os) const override {
    switch (state_) {
      case TwoValuedLogicState::_0:
        os << 0;
      case TwoValuedLogicState::_1:
        os << 1;
    }
  }

 private:
  TwoValuedLogicState state_;
};

class Context {
 public:
  virtual std::shared_ptr<Value> Get(std::string identifier) = 0;
  virtual void Set(std::string identifier, std::shared_ptr<Value> value) = 0;

  virtual void Finish() = 0;
};

struct Process;

struct Module : public Context {
  std::weak_ptr<Context> parent;

  std::unordered_map<std::string, std::shared_ptr<Value>> variables;
  std::unordered_set<std::shared_ptr<Process>> initials;

  virtual std::shared_ptr<Value> Get(std::string identifier) override {
    if (variables.contains(identifier)) {
      return variables[identifier];
    }
    return parent.lock()->Get(identifier);
  }

  virtual void Set(std::string identifier,
                   std::shared_ptr<Value> value) override {
    if (variables.contains(identifier)) {
      variables[identifier] = value;
    } else {
      parent.lock()->Set(identifier, value);
    }
  }

  virtual void Finish() override { parent.lock()->Finish(); }
};

struct Instruction {
  virtual void Execute(std::weak_ptr<Context> context) = 0;
};

struct AssignmentInstruction : Instruction {
  std::string identifier;
  std::shared_ptr<Value> value;

  virtual void Execute(std::weak_ptr<Context> context) override {
    context.lock()->Set(identifier, value);
  }
};

struct DisplayInstruction : Instruction {
  std::string format;
  std::vector<std::string> params;

  virtual void Execute(std::weak_ptr<Context> context) override {
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

            std::shared_ptr<Value> value = context.lock()->Get(*id_it++);
            value->Display(ss);
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
class Simulator : public Context {
 public:
  // Constructs a simulator with the provided sv2017 ast and top-level module
  // identifier.
  Simulator();

  // Run the simulation.
  void Run(std::shared_ptr<Module> top_level_module);

  virtual std::shared_ptr<Value> Get(std::string identifier) override;
  virtual void Set(std::string identifier,
                   std::shared_ptr<Value> value) override;

  virtual void Finish() override;

 private:
  bool finished_;
};

};  // namespace svs::sim

#endif  // SRC_SIMULATOR_SIMULATOR_H_
