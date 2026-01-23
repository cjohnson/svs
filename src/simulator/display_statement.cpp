// Copyright (c) 2026 Collin Johnson

#include "simulator/display_statement.h"

#include <iostream>
#include <mutex>

using DisplayStatement = svs::sim::DisplayStatement;

std::mutex display_mutex;

DisplayStatement::DisplayStatement() : Statement() {}

void DisplayStatement::Execute() {
  std::lock_guard<std::mutex> guard{display_mutex};
  std::cout << "Executing a display statement\n";
}
