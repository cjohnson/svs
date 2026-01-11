// Copyright (c) 2026 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_DATA_DECLARATION_H_
#define SRC_COMPILER_SV2017_AST_DATA_DECLARATION_H_

#include <memory>
#include <vector>

#include "compiler/sv2017/ast/data_type.h"
#include "compiler/sv2017/ast/module_item.h"
#include "compiler/sv2017/ast/variable_decl_assignment.h"
#include "compiler/sv2017/location.hh"

namespace svs::sv2017::ast {

// A data declaration.
class DataDeclaration : public ModuleItem {
 public:
  // Constructs a data declaration with the provided location, data type, and
  // list of variable declaration assignments.
  DataDeclaration(const yy::location& location,
                  std::unique_ptr<DataType> data_type,
                  std::vector<std::unique_ptr<VariableDeclAssignment>>
                      variable_decl_assignments);

  // Accept the provided visitor.
  void Accept(Visitor& visitor) override;

  // The data type.
  inline const std::unique_ptr<DataType>& data_type() { return data_type_; }

  // The list of variable declaration assignments.
  inline const std::vector<std::unique_ptr<VariableDeclAssignment>>&
  variable_decl_assignments() {
    return variable_decl_assignments_;
  }

 private:
  std::unique_ptr<DataType> data_type_;
  std::vector<std::unique_ptr<VariableDeclAssignment>>
      variable_decl_assignments_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_DATA_DECLARATION_H_
