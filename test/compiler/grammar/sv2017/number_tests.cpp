#include <climits>
#include <unordered_set>

#include <gtest/gtest.h>

#include "../../../../src/compiler/sv2017/ast.h"
#include "../../../../src/compiler/sv2017/grammar_number.hpp"

#include "../grammar_test_utils.hpp"

using namespace svs::grammar::sv2017;
namespace ast = svs::ast::sv2017;

struct z_or_x_production
{
    static constexpr auto rule = dsl::capture(z_or_x);
    static constexpr auto value = lexy::as_string<std::string>;
};

TEST(SV2017NumberTests, ZOrXTests)
{
    EXPECT_PARSE_FAILURE<z_or_x_production>("");

    std::unordered_set<char> valid_characters{'z', 'Z', 'x', 'X'};
    for (char c = CHAR_MIN; c < CHAR_MAX; ++c)
    {
        std::string string(1, c);

        if (valid_characters.find(c) != valid_characters.end())
            EXPECT_PARSE_RESULT<z_or_x_production>(string, string);
        else
            EXPECT_PARSE_FAILURE<z_or_x_production>(string);
    }
}

TEST(SV2017NumberTests, UnbasedUnsizedLiteralTests)
{
    EXPECT_PARSE_FAILURE<unbased_unsized_literal>("");
    EXPECT_PARSE_FAILURE<unbased_unsized_literal>("'");
    EXPECT_PARSE_FAILURE<unbased_unsized_literal>("'a");

    EXPECT_PARSE_RESULT<unbased_unsized_literal>("'0", "0");
    EXPECT_PARSE_RESULT<unbased_unsized_literal>("'1", "1");
    EXPECT_PARSE_RESULT<unbased_unsized_literal>("'x", "x");
    EXPECT_PARSE_RESULT<unbased_unsized_literal>("'X", "X");
    EXPECT_PARSE_RESULT<unbased_unsized_literal>("'z", "z");
    EXPECT_PARSE_RESULT<unbased_unsized_literal>("'Z", "Z");
}

struct z_digit_production
{
    static constexpr auto rule = dsl::capture(z_digit);
    static constexpr auto value = lexy::as_string<std::string>;
};

TEST(SV2017NumberTests, ZDigitTests)
{
    EXPECT_PARSE_FAILURE<z_digit_production>("");

    std::unordered_set<char> valid_characters{'z', 'Z', '?'};
    for (char c = CHAR_MIN; c < CHAR_MAX; ++c)
    {
        std::string string(1, c);

        if (valid_characters.find(c) != valid_characters.end())
            EXPECT_PARSE_RESULT<z_digit_production>(string, string);
        else
            EXPECT_PARSE_FAILURE<z_digit_production>(string);
    }
}

struct x_digit_production
{
    static constexpr auto rule = dsl::capture(x_digit);
    static constexpr auto value = lexy::as_string<std::string>;
};

TEST(SV2017NumberTests, XDigitTests)
{
    EXPECT_PARSE_FAILURE<x_digit_production>("");

    std::unordered_set<char> valid_characters{'x', 'X'};
    for (char c = CHAR_MIN; c < CHAR_MAX; ++c)
    {
        std::string string(1, c);

        auto it = valid_characters.find(c);
        if (it != valid_characters.end())
            EXPECT_PARSE_RESULT<x_digit_production>(string, string);
        else
            EXPECT_PARSE_FAILURE<x_digit_production>(string);
    }
}

struct hex_digit_production
{
    static constexpr auto rule = dsl::capture(hex_digit);
    static constexpr auto value = lexy::as_string<std::string>;
};

TEST(SV2017NumberTests, HexDigitTests)
{
    EXPECT_PARSE_FAILURE<hex_digit_production>("");

    std::unordered_set<char> characters{
        'x', 'X', 'z', 'Z', '?', '0', '1', '2', '3', '4', '5', '6', '7', '8',
        '9', 'a', 'b', 'c', 'd', 'e', 'f', 'A', 'B', 'C', 'D', 'E', 'F',
    };

    for (char c = CHAR_MIN; c < CHAR_MAX; ++c)
    {
        std::string string(1, c);

        if (characters.find(c) != characters.end())
            EXPECT_PARSE_RESULT<hex_digit_production>(string, string);
        else
            EXPECT_PARSE_FAILURE<hex_digit_production>(string);
    }
}

struct octal_digit_production
{
    static constexpr auto rule = dsl::capture(octal_digit);
    static constexpr auto value = lexy::as_string<std::string>;
};

TEST(SV2017NumberTests, OctalDigitTests)
{
    EXPECT_PARSE_FAILURE<octal_digit_production>("");

    std::unordered_set<char> characters{
        'x', 'X', 'z', 'Z', '?', '0', '1', '2', '3', '4', '5', '6', '7',
    };

    for (char c = CHAR_MIN; c < CHAR_MAX; ++c)
    {
        std::string string(1, c);

        if (characters.find(c) != characters.end())
            EXPECT_PARSE_RESULT<octal_digit_production>(string, string);
        else
            EXPECT_PARSE_FAILURE<octal_digit_production>(string);
    }
}

struct binary_digit_production
{
    static constexpr auto rule = dsl::capture(binary_digit);
    static constexpr auto value = lexy::as_string<std::string>;
};

TEST(SV2017NumberTests, BinaryDigitTests)
{
    EXPECT_PARSE_FAILURE<binary_digit_production>("");

    std::unordered_set<char> characters{
        'x', 'X', 'z', 'Z', '?', '0', '1',
    };

    for (char c = CHAR_MIN; c < CHAR_MAX; ++c)
    {
        std::string string(1, c);

        if (characters.find(c) != characters.end())
            EXPECT_PARSE_RESULT<binary_digit_production>(string, string);
        else
            EXPECT_PARSE_FAILURE<binary_digit_production>(string);
    }
}

TEST(SV2017NumberTests, HexBaseTests)
{
    EXPECT_PARSE_FAILURE<hex_base>("");
    EXPECT_PARSE_FAILURE<hex_base>("a");

    EXPECT_PARSE_FAILURE<hex_base>("'");

    EXPECT_PARSE_RESULT<hex_base>("'sh", ast::integral_number_base_info_t{
                                             's',
                                             'h',
                                         });
    EXPECT_PARSE_RESULT<hex_base>("'Sh", ast::integral_number_base_info_t{
                                             'S',
                                             'h',
                                         });
    EXPECT_PARSE_RESULT<hex_base>("'sH", ast::integral_number_base_info_t{
                                             's',
                                             'H',
                                         });
    EXPECT_PARSE_RESULT<hex_base>("'SH", ast::integral_number_base_info_t{
                                             'S',
                                             'H',
                                         });

    EXPECT_PARSE_RESULT<hex_base>("'h", ast::integral_number_base_info_t{
                                            std::nullopt,
                                            'h',
                                        });
    EXPECT_PARSE_RESULT<hex_base>("'H", ast::integral_number_base_info_t{
                                            std::nullopt,
                                            'H',
                                        });
}

TEST(SV2017NumberTests, OctalBaseTests)
{
    EXPECT_PARSE_FAILURE<octal_base>("");
    EXPECT_PARSE_FAILURE<octal_base>("a");

    EXPECT_PARSE_FAILURE<octal_base>("'");

    EXPECT_PARSE_RESULT<octal_base>("'so", ast::integral_number_base_info_t{
                                               's',
                                               'o',
                                           });
    EXPECT_PARSE_RESULT<octal_base>("'So", ast::integral_number_base_info_t{
                                               'S',
                                               'o',
                                           });
    EXPECT_PARSE_RESULT<octal_base>("'sO", ast::integral_number_base_info_t{
                                               's',
                                               'O',
                                           });
    EXPECT_PARSE_RESULT<octal_base>("'SO", ast::integral_number_base_info_t{
                                               'S',
                                               'O',
                                           });

    EXPECT_PARSE_RESULT<octal_base>("'o", ast::integral_number_base_info_t{
                                              std::nullopt,
                                              'o',
                                          });
    EXPECT_PARSE_RESULT<octal_base>("'O", ast::integral_number_base_info_t{
                                              std::nullopt,
                                              'O',
                                          });
}

TEST(SV2017NumberTests, BinaryBaseTests)
{
    EXPECT_PARSE_FAILURE<binary_base>("");
    EXPECT_PARSE_FAILURE<binary_base>("a");

    EXPECT_PARSE_FAILURE<binary_base>("'");

    EXPECT_PARSE_RESULT<binary_base>("'sb", ast::integral_number_base_info_t{
                                                's',
                                                'b',
                                            });
    EXPECT_PARSE_RESULT<binary_base>("'Sb", ast::integral_number_base_info_t{
                                                'S',
                                                'b',
                                            });
    EXPECT_PARSE_RESULT<binary_base>("'sB", ast::integral_number_base_info_t{
                                                's',
                                                'B',
                                            });
    EXPECT_PARSE_RESULT<binary_base>("'SB", ast::integral_number_base_info_t{
                                                'S',
                                                'B',
                                            });

    EXPECT_PARSE_RESULT<binary_base>("'b", ast::integral_number_base_info_t{
                                               std::nullopt,
                                               'b',
                                           });
    EXPECT_PARSE_RESULT<binary_base>("'B", ast::integral_number_base_info_t{
                                               std::nullopt,
                                               'B',
                                           });
}

TEST(SV2017NumberTests, DecimalBaseTests)
{
    EXPECT_PARSE_FAILURE<decimal_base>("");
    EXPECT_PARSE_FAILURE<decimal_base>("a");

    EXPECT_PARSE_FAILURE<decimal_base>("'");

    EXPECT_PARSE_FAILURE<decimal_base>("'");

    EXPECT_PARSE_RESULT<decimal_base>("'sd", ast::integral_number_base_info_t{
                                                 's',
                                                 'd',
                                             });
    EXPECT_PARSE_RESULT<decimal_base>("'Sd", ast::integral_number_base_info_t{
                                                 'S',
                                                 'd',
                                             });
    EXPECT_PARSE_RESULT<decimal_base>("'sD", ast::integral_number_base_info_t{
                                                 's',
                                                 'D',
                                             });
    EXPECT_PARSE_RESULT<decimal_base>("'SD", ast::integral_number_base_info_t{
                                                 'S',
                                                 'D',
                                             });

    EXPECT_PARSE_RESULT<decimal_base>("'d", ast::integral_number_base_info_t{
                                                std::nullopt,
                                                'd',
                                            });
    EXPECT_PARSE_RESULT<decimal_base>("'D", ast::integral_number_base_info_t{
                                                std::nullopt,
                                                'D',
                                            });
}

TEST(SV2017NumberTests, HexValueTests)
{
    EXPECT_PARSE_FAILURE<hex_value>("");
    EXPECT_PARSE_FAILURE<hex_value>("g");

    EXPECT_PARSE_FAILURE<hex_value>("_01dead");

    EXPECT_PARSE_RESULT<hex_value>("01dead", "01dead");
    EXPECT_PARSE_RESULT<hex_value>("01_de_ad", "01_de_ad");
    EXPECT_PARSE_RESULT<hex_value>("ZbeefX", "ZbeefX");
    EXPECT_PARSE_RESULT<hex_value>("Z_be_ef_X", "Z_be_ef_X");
}

TEST(SV2017NumberTests, OctalValueTests)
{
    EXPECT_PARSE_FAILURE<octal_value>("");
    EXPECT_PARSE_FAILURE<octal_value>("g");

    EXPECT_PARSE_FAILURE<octal_value>("_012567");

    EXPECT_PARSE_RESULT<octal_value>("12567", "12567");
    EXPECT_PARSE_RESULT<octal_value>("1_25_67", "1_25_67");
    EXPECT_PARSE_RESULT<octal_value>("Z1024X", "Z1024X");
    EXPECT_PARSE_RESULT<octal_value>("Z_10_2_4X", "Z_10_2_4X");
}

TEST(SV2017NumberTests, BinaryValueTests)
{
    EXPECT_PARSE_FAILURE<binary_value>("");
    EXPECT_PARSE_FAILURE<binary_value>("g");

    EXPECT_PARSE_FAILURE<binary_value>("_010110");

    EXPECT_PARSE_RESULT<binary_value>("010110", "010110");
    EXPECT_PARSE_RESULT<binary_value>("01_0_11_0", "01_0_11_0");
    EXPECT_PARSE_RESULT<binary_value>("Z1010X", "Z1010X");
    EXPECT_PARSE_RESULT<binary_value>("Z_10_1_0X", "Z_10_1_0X");
}

TEST(SV2017NumberTests, UnsignedNumberTests)
{
    EXPECT_PARSE_FAILURE<unsigned_number>("");
    EXPECT_PARSE_FAILURE<unsigned_number>("g");

    EXPECT_PARSE_FAILURE<unsigned_number>("_13734189");

    EXPECT_PARSE_RESULT<unsigned_number>("13734189", "13734189");
    EXPECT_PARSE_RESULT<unsigned_number>("13_73_41_8_9", "13_73_41_8_9");
}

struct exp_production
{
    static constexpr auto rule = dsl::capture(exp_);
    static constexpr auto value = lexy::as_string<std::string>;
};

TEST(SV2017NumberTests, ExponentTests)
{
    EXPECT_PARSE_FAILURE<exp_production>("");

    std::unordered_set<char> characters{'e', 'E'};

    for (char c = CHAR_MIN; c < CHAR_MAX; ++c)
    {
        std::string string(1, c);

        if (characters.find(c) != characters.end())
            EXPECT_PARSE_RESULT<exp_production>(string, string);
        else
            EXPECT_PARSE_FAILURE<exp_production>(string);
    }
}

TEST(SV2017NumberTests, FixedPointNumberTests)
{
    EXPECT_PARSE_FAILURE<fixed_point_number>("");
    EXPECT_PARSE_FAILURE<fixed_point_number>("g");

    EXPECT_PARSE_FAILURE<fixed_point_number>("_1373.4189");
    EXPECT_PARSE_FAILURE<fixed_point_number>("1373._4189");
    EXPECT_PARSE_FAILURE<fixed_point_number>("_1373._4189");

    EXPECT_PARSE_RESULT<fixed_point_number>(
        "1373.4189", ast::fixed_point_number_info_t{"1373", "4189"});
    EXPECT_PARSE_RESULT<fixed_point_number>(
        "13_73_.41_8_9", ast::fixed_point_number_info_t{"13_73_", "41_8_9"});
}

//
// Test visitor base class
//
class test_visitor_t : public ast::visitor_t
{
  public:
    //
    // Run tests on information collected by this visitor.
    //
    virtual void test() = 0;
};

class real_number_test_visitor : public test_visitor_t
{
  private:
    ast::real_number_t _expected;

    std::vector<const ast::number_t *> numbers;
    std::vector<const ast::real_number_t *> real_numbers;

  public:
    real_number_test_visitor(const ast::real_number_t &expected)
        : _expected(expected)
    {
    }

    virtual void test() override
    {
        ASSERT_EQ(numbers.size(), 1);
        ASSERT_EQ(real_numbers.size(), 1);

        const ast::real_number_t *real_number = real_numbers[0];
        EXPECT_EQ(_expected, *real_number);
    }

    void visit(const ast::number_t &number) override
    {
        numbers.push_back(&number);
    }

    void visit(const ast::real_number_t &real_number) override
    {
        real_numbers.push_back(&real_number);
    }
};

template <typename TProduction> void test_real_number_parsing()
{
    EXPECT_PARSE_FAILURE<TProduction>("");
    EXPECT_PARSE_FAILURE<TProduction>("g");

    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "1373.4189", real_number_test_visitor{
                         ast::real_number_t{"1373", "4189", std::nullopt}});

    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "1373e24", real_number_test_visitor{
                       ast::real_number_t{"1373", std::nullopt, "24"}});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "1373E24", real_number_test_visitor{
                       ast::real_number_t{"1373", std::nullopt, "24"}});

    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "1373e+24", real_number_test_visitor{
                        ast::real_number_t{"1373", std::nullopt, "+24"}});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "1373E+25", real_number_test_visitor{
                        ast::real_number_t{"1373", std::nullopt, "+25"}});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "1373e-26", real_number_test_visitor{
                        ast::real_number_t{"1373", std::nullopt, "-26"}});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "1373E-27", real_number_test_visitor{
                        ast::real_number_t{"1373", std::nullopt, "-27"}});

    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "1373.57e+24",
        real_number_test_visitor{ast::real_number_t{"1373", "57", "+24"}});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "1373.25E+25",
        real_number_test_visitor{ast::real_number_t{"1373", "25", "+25"}});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "1373.78e-26",
        real_number_test_visitor{ast::real_number_t{"1373", "78", "-26"}});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "1373.47E-27",
        real_number_test_visitor{ast::real_number_t{"1373", "47", "-27"}});
}

TEST(SV2017NumberTests, RealNumberTests)
{
    test_real_number_parsing<real_number>();
    EXPECT_PARSE_FAILURE<real_number>("1373");
}

TEST(SV2017NumberTests, NonZeroUnsignedNumberTests)
{
    EXPECT_PARSE_FAILURE<non_zero_unsigned_number>("");
    EXPECT_PARSE_FAILURE<non_zero_unsigned_number>("g");

    EXPECT_PARSE_FAILURE<non_zero_unsigned_number>("0114");
    EXPECT_PARSE_RESULT<non_zero_unsigned_number>("114", "114");
    EXPECT_PARSE_RESULT<non_zero_unsigned_number>("1_1_4", "1_1_4");
    EXPECT_PARSE_FAILURE<non_zero_unsigned_number>("_1_1_4");
    EXPECT_PARSE_RESULT<non_zero_unsigned_number>("1_1_4_", "1_1_4_");
}

class integral_number_test_visitor : public test_visitor_t
{
  private:
    ast::integral_number_t _expected;

    std::vector<const ast::number_t *> numbers;
    std::vector<const ast::integral_number_t *> integral_numbers;

  public:
    integral_number_test_visitor(const ast::integral_number_t &expected)
        : _expected(expected)
    {
    }

    virtual void test() override
    {
        ASSERT_EQ(numbers.size(), 1);
        ASSERT_EQ(integral_numbers.size(), 1);

        const ast::integral_number_t *integral_number = integral_numbers[0];
        EXPECT_EQ(_expected, *integral_number);
    }

    void visit(const ast::number_t &number) override
    {
        numbers.push_back(&number);
    }

    void visit(const ast::integral_number_t &integral_number) override
    {
        integral_numbers.push_back(&integral_number);
    }
};

template <typename TProduction> void test_hex_number_parsing()
{
    EXPECT_PARSE_FAILURE<TProduction>("");
    EXPECT_PARSE_FAILURE<TProduction>("t");

    EXPECT_PARSE_FAILURE<TProduction>("'hgdead");
    EXPECT_PARSE_FAILURE<TProduction>("'h gdead");

    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "'h deadbeef9876543210c",
        integral_number_test_visitor{ast::integral_number_t{
            std::nullopt,
            ast::integral_number_base_info_t{std::nullopt, 'h'},
            "deadbeef9876543210c",
        }});

    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "'h deadbeef9876543210c",
        integral_number_test_visitor{ast::integral_number_t{
            std::nullopt,
            ast::integral_number_base_info_t{std::nullopt, 'h'},
            "deadbeef9876543210c",
        }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "'h1b", integral_number_test_visitor{ast::integral_number_t{
                    std::nullopt,
                    ast::integral_number_base_info_t{std::nullopt, 'h'},
                    "1b",
                }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        " 'h1b", integral_number_test_visitor{ast::integral_number_t{
                     std::nullopt,
                     ast::integral_number_base_info_t{std::nullopt, 'h'},
                     "1b",
                 }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "'h 1b", integral_number_test_visitor{ast::integral_number_t{
                     std::nullopt,
                     ast::integral_number_base_info_t{std::nullopt, 'h'},
                     "1b",
                 }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        " 'h 1b", integral_number_test_visitor{ast::integral_number_t{
                      std::nullopt,
                      ast::integral_number_base_info_t{std::nullopt, 'h'},
                      "1b",
                  }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "8'h1b", integral_number_test_visitor{ast::integral_number_t{
                     "8",
                     ast::integral_number_base_info_t{std::nullopt, 'h'},
                     "1b",
                 }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "8 'h1b", integral_number_test_visitor{ast::integral_number_t{
                      "8",
                      ast::integral_number_base_info_t{std::nullopt, 'h'},
                      "1b",
                  }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "8'h 1b", integral_number_test_visitor{ast::integral_number_t{
                      "8",
                      ast::integral_number_base_info_t{std::nullopt, 'h'},
                      "1b",
                  }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "8 'h 1b", integral_number_test_visitor{ast::integral_number_t{
                       "8",
                       ast::integral_number_base_info_t{std::nullopt, 'h'},
                       "1b",
                   }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "'h4ad", integral_number_test_visitor{ast::integral_number_t{
                     std::nullopt,
                     ast::integral_number_base_info_t{std::nullopt, 'h'},
                     "4ad",
                 }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        " 'h4ad", integral_number_test_visitor{ast::integral_number_t{
                      std::nullopt,
                      ast::integral_number_base_info_t{std::nullopt, 'h'},
                      "4ad",
                  }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "'h 4ad", integral_number_test_visitor{ast::integral_number_t{
                      std::nullopt,
                      ast::integral_number_base_info_t{std::nullopt, 'h'},
                      "4ad",
                  }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        " 'h 4ad", integral_number_test_visitor{ast::integral_number_t{
                       std::nullopt,
                       ast::integral_number_base_info_t{std::nullopt, 'h'},
                       "4ad",
                   }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "12'h4ad", integral_number_test_visitor{ast::integral_number_t{
                       "12",
                       ast::integral_number_base_info_t{std::nullopt, 'h'},
                       "4ad",
                   }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "12 'h4ad", integral_number_test_visitor{ast::integral_number_t{
                        "12",
                        ast::integral_number_base_info_t{std::nullopt, 'h'},
                        "4ad",
                    }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "12'h 4ad", integral_number_test_visitor{ast::integral_number_t{
                        "12",
                        ast::integral_number_base_info_t{std::nullopt, 'h'},
                        "4ad",
                    }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "12 'h 4ad", integral_number_test_visitor{ast::integral_number_t{
                         "12",
                         ast::integral_number_base_info_t{std::nullopt, 'h'},
                         "4ad",
                     }});
}

TEST(SV2017NumberTests, HexNumberTests)
{
    test_hex_number_parsing<hex_number>();
}

template <typename TProduction> void test_octal_number_parsing()
{
    EXPECT_PARSE_FAILURE<TProduction>("");
    EXPECT_PARSE_FAILURE<TProduction>("t");

    EXPECT_PARSE_FAILURE<TProduction>("'o8765");
    EXPECT_PARSE_FAILURE<TProduction>("'o 8765");

    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "'o 12345670", integral_number_test_visitor{ast::integral_number_t{
                           std::nullopt,
                           ast::integral_number_base_info_t{std::nullopt, 'o'},
                           "12345670",
                       }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "'o15", integral_number_test_visitor{ast::integral_number_t{
                    std::nullopt,
                    ast::integral_number_base_info_t{std::nullopt, 'o'},
                    "15",
                }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        " 'o15", integral_number_test_visitor{ast::integral_number_t{
                     std::nullopt,
                     ast::integral_number_base_info_t{std::nullopt, 'o'},
                     "15",
                 }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "'o 15", integral_number_test_visitor{ast::integral_number_t{
                     std::nullopt,
                     ast::integral_number_base_info_t{std::nullopt, 'o'},
                     "15",
                 }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        " 'o 15", integral_number_test_visitor{ast::integral_number_t{
                      std::nullopt,
                      ast::integral_number_base_info_t{std::nullopt, 'o'},
                      "15",
                  }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "6'o15", integral_number_test_visitor{ast::integral_number_t{
                     "6",
                     ast::integral_number_base_info_t{std::nullopt, 'o'},
                     "15",
                 }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "6 'o15", integral_number_test_visitor{ast::integral_number_t{
                      "6",
                      ast::integral_number_base_info_t{std::nullopt, 'o'},
                      "15",
                  }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "6'o 15", integral_number_test_visitor{ast::integral_number_t{
                      "6",
                      ast::integral_number_base_info_t{std::nullopt, 'o'},
                      "15",
                  }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "6 'o 15", integral_number_test_visitor{ast::integral_number_t{
                       "6",
                       ast::integral_number_base_info_t{std::nullopt, 'o'},
                       "15",
                   }});

    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "'o423", integral_number_test_visitor{ast::integral_number_t{
                     std::nullopt,
                     ast::integral_number_base_info_t{std::nullopt, 'o'},
                     "423",
                 }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        " 'o423", integral_number_test_visitor{ast::integral_number_t{
                      std::nullopt,
                      ast::integral_number_base_info_t{std::nullopt, 'o'},
                      "423",
                  }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "'o 423", integral_number_test_visitor{ast::integral_number_t{
                      std::nullopt,
                      ast::integral_number_base_info_t{std::nullopt, 'o'},
                      "423",
                  }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        " 'o 423", integral_number_test_visitor{ast::integral_number_t{
                       std::nullopt,
                       ast::integral_number_base_info_t{std::nullopt, 'o'},
                       "423",
                   }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "9'o423", integral_number_test_visitor{ast::integral_number_t{
                      "9",
                      ast::integral_number_base_info_t{std::nullopt, 'o'},
                      "423",
                  }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "9 'o423", integral_number_test_visitor{ast::integral_number_t{
                       "9",
                       ast::integral_number_base_info_t{std::nullopt, 'o'},
                       "423",
                   }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "9'o 423", integral_number_test_visitor{ast::integral_number_t{
                       "9",
                       ast::integral_number_base_info_t{std::nullopt, 'o'},
                       "423",
                   }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "9 'o 423", integral_number_test_visitor{ast::integral_number_t{
                        "9",
                        ast::integral_number_base_info_t{std::nullopt, 'o'},
                        "423",
                    }});
}

TEST(SV2017NumberTests, OctalNumberTests)
{
    test_octal_number_parsing<octal_number>();
}

template <typename TProduction> void test_binary_number_parsing()
{
    EXPECT_PARSE_FAILURE<TProduction>("");
    EXPECT_PARSE_FAILURE<TProduction>("t");

    EXPECT_PARSE_FAILURE<TProduction>("'b2010");
    EXPECT_PARSE_FAILURE<TProduction>("'b 2010");

    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "'b 1011011010",
        integral_number_test_visitor{ast::integral_number_t{
            std::nullopt, ast::integral_number_base_info_t{std::nullopt, 'b'},
            "1011011010"}});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "'b10",
        integral_number_test_visitor{ast::integral_number_t{
            std::nullopt, ast::integral_number_base_info_t{std::nullopt, 'b'},
            "10"}});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        " 'b10",
        integral_number_test_visitor{ast::integral_number_t{
            std::nullopt, ast::integral_number_base_info_t{std::nullopt, 'b'},
            "10"}});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "'b 10",
        integral_number_test_visitor{ast::integral_number_t{
            std::nullopt, ast::integral_number_base_info_t{std::nullopt, 'b'},
            "10"}});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        " 'b 10",
        integral_number_test_visitor{ast::integral_number_t{
            std::nullopt, ast::integral_number_base_info_t{std::nullopt, 'b'},
            "10"}});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "2'b10",
        integral_number_test_visitor{ast::integral_number_t{
            "2", ast::integral_number_base_info_t{std::nullopt, 'b'}, "10"}});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "2 'b10",
        integral_number_test_visitor{ast::integral_number_t{
            "2", ast::integral_number_base_info_t{std::nullopt, 'b'}, "10"}});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "2'b 10",
        integral_number_test_visitor{ast::integral_number_t{
            "2", ast::integral_number_base_info_t{std::nullopt, 'b'}, "10"}});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "2 'b 10",
        integral_number_test_visitor{ast::integral_number_t{
            "2", ast::integral_number_base_info_t{std::nullopt, 'b'}, "10"}});

    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "'b010",
        integral_number_test_visitor{ast::integral_number_t{
            std::nullopt, ast::integral_number_base_info_t{std::nullopt, 'b'},
            "010"}});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        " 'b010",
        integral_number_test_visitor{ast::integral_number_t{
            std::nullopt, ast::integral_number_base_info_t{std::nullopt, 'b'},
            "010"}});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "'b 010",
        integral_number_test_visitor{ast::integral_number_t{
            std::nullopt, ast::integral_number_base_info_t{std::nullopt, 'b'},
            "010"}});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        " 'b 010",
        integral_number_test_visitor{ast::integral_number_t{
            std::nullopt, ast::integral_number_base_info_t{std::nullopt, 'b'},
            "010"}});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "3'b010",
        integral_number_test_visitor{ast::integral_number_t{
            "3", ast::integral_number_base_info_t{std::nullopt, 'b'}, "010"}});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "3 'b010",
        integral_number_test_visitor{ast::integral_number_t{
            "3", ast::integral_number_base_info_t{std::nullopt, 'b'}, "010"}});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "3'b 010",
        integral_number_test_visitor{ast::integral_number_t{
            "3", ast::integral_number_base_info_t{std::nullopt, 'b'}, "010"}});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "3 'b 010",
        integral_number_test_visitor{ast::integral_number_t{
            "3", ast::integral_number_base_info_t{std::nullopt, 'b'}, "010"}});
}

TEST(SV2017NumberTests, BinaryNumberTests)
{
    test_binary_number_parsing<binary_number>();
}

template <typename TProduction> void test_decimal_number_parsing()
{
    EXPECT_PARSE_FAILURE<TProduction>("");
    EXPECT_PARSE_FAILURE<TProduction>("t");

    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "0", integral_number_test_visitor{ast::integral_number_t{
                 std::nullopt,
                 std::nullopt,
                 "0",
             }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "123", integral_number_test_visitor{ast::integral_number_t{
                   std::nullopt,
                   std::nullopt,
                   "123",
               }});

    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "'d0", integral_number_test_visitor{ast::integral_number_t{
                   std::nullopt,
                   ast::integral_number_base_info_t{std::nullopt, 'd'},
                   "0",
               }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "'d123", integral_number_test_visitor{ast::integral_number_t{
                     std::nullopt,
                     ast::integral_number_base_info_t{std::nullopt, 'd'},
                     "123",
                 }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "'d 123", integral_number_test_visitor{ast::integral_number_t{
                      std::nullopt,
                      ast::integral_number_base_info_t{std::nullopt, 'd'},
                      "123",
                  }});

    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20'd123", integral_number_test_visitor{ast::integral_number_t{
                       "20",
                       ast::integral_number_base_info_t{std::nullopt, 'd'},
                       "123",
                   }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20 'd123", integral_number_test_visitor{ast::integral_number_t{
                        "20",
                        ast::integral_number_base_info_t{std::nullopt, 'd'},
                        "123",
                    }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20 'd 123", integral_number_test_visitor{ast::integral_number_t{
                         "20",
                         ast::integral_number_base_info_t{std::nullopt, 'd'},
                         "123",
                     }});

    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20'dx", integral_number_test_visitor{ast::integral_number_t{
                     "20",
                     ast::integral_number_base_info_t{std::nullopt, 'd'},
                     "x",
                 }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20'dX", integral_number_test_visitor{ast::integral_number_t{
                     "20",
                     ast::integral_number_base_info_t{std::nullopt, 'd'},
                     "X",
                 }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20 'dx", integral_number_test_visitor{ast::integral_number_t{
                      "20",
                      ast::integral_number_base_info_t{std::nullopt, 'd'},
                      "x",
                  }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20 'dX", integral_number_test_visitor{ast::integral_number_t{
                      "20",
                      ast::integral_number_base_info_t{std::nullopt, 'd'},
                      "X",
                  }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20 'd x", integral_number_test_visitor{ast::integral_number_t{
                       "20",
                       ast::integral_number_base_info_t{std::nullopt, 'd'},
                       "x",
                   }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20 'd X", integral_number_test_visitor{ast::integral_number_t{
                       "20",
                       ast::integral_number_base_info_t{std::nullopt, 'd'},
                       "X",
                   }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20'dx_", integral_number_test_visitor{ast::integral_number_t{
                      "20",
                      ast::integral_number_base_info_t{std::nullopt, 'd'},
                      "x",
                  }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20'dX_", integral_number_test_visitor{ast::integral_number_t{
                      "20",
                      ast::integral_number_base_info_t{std::nullopt, 'd'},
                      "X",
                  }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20 'dx_", integral_number_test_visitor{ast::integral_number_t{
                       "20",
                       ast::integral_number_base_info_t{std::nullopt, 'd'},
                       "x",
                   }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20 'dX_", integral_number_test_visitor{ast::integral_number_t{
                       "20",
                       ast::integral_number_base_info_t{std::nullopt, 'd'},
                       "X",
                   }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20 'd x_", integral_number_test_visitor{ast::integral_number_t{
                        "20",
                        ast::integral_number_base_info_t{std::nullopt, 'd'},
                        "x",
                    }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20 'd X_", integral_number_test_visitor{ast::integral_number_t{
                        "20",
                        ast::integral_number_base_info_t{std::nullopt, 'd'},
                        "X",
                    }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20'dx__", integral_number_test_visitor{ast::integral_number_t{
                       "20",
                       ast::integral_number_base_info_t{std::nullopt, 'd'},
                       "x",
                   }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20'dX__", integral_number_test_visitor{ast::integral_number_t{
                       "20",
                       ast::integral_number_base_info_t{std::nullopt, 'd'},
                       "X",
                   }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20 'dx__", integral_number_test_visitor{ast::integral_number_t{
                        "20",
                        ast::integral_number_base_info_t{std::nullopt, 'd'},
                        "x",
                    }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20 'dX__", integral_number_test_visitor{ast::integral_number_t{
                        "20",
                        ast::integral_number_base_info_t{std::nullopt, 'd'},
                        "X",
                    }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20 'd x__", integral_number_test_visitor{ast::integral_number_t{
                         "20",
                         ast::integral_number_base_info_t{std::nullopt, 'd'},
                         "x",
                     }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20 'd X__", integral_number_test_visitor{ast::integral_number_t{
                         "20",
                         ast::integral_number_base_info_t{std::nullopt, 'd'},
                         "X",
                     }});

    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20'dz", integral_number_test_visitor{ast::integral_number_t{
                     "20",
                     ast::integral_number_base_info_t{std::nullopt, 'd'},
                     "z",
                 }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20'dZ", integral_number_test_visitor{ast::integral_number_t{
                     "20",
                     ast::integral_number_base_info_t{std::nullopt, 'd'},
                     "Z",
                 }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20'd?", integral_number_test_visitor{ast::integral_number_t{
                     "20",
                     ast::integral_number_base_info_t{std::nullopt, 'd'},
                     "?",
                 }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20 'dz", integral_number_test_visitor{ast::integral_number_t{
                      "20",
                      ast::integral_number_base_info_t{std::nullopt, 'd'},
                      "z",
                  }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20 'dZ", integral_number_test_visitor{ast::integral_number_t{
                      "20",
                      ast::integral_number_base_info_t{std::nullopt, 'd'},
                      "Z",
                  }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20 'd?", integral_number_test_visitor{ast::integral_number_t{
                      "20",
                      ast::integral_number_base_info_t{std::nullopt, 'd'},
                      "?",
                  }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20 'd z", integral_number_test_visitor{ast::integral_number_t{
                       "20",
                       ast::integral_number_base_info_t{std::nullopt, 'd'},
                       "z",
                   }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20 'd Z", integral_number_test_visitor{ast::integral_number_t{
                       "20",
                       ast::integral_number_base_info_t{std::nullopt, 'd'},
                       "Z",
                   }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20 'd ?", integral_number_test_visitor{ast::integral_number_t{
                       "20",
                       ast::integral_number_base_info_t{std::nullopt, 'd'},
                       "?",
                   }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20'dz_", integral_number_test_visitor{ast::integral_number_t{
                      "20",
                      ast::integral_number_base_info_t{std::nullopt, 'd'},
                      "z",
                  }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20'dZ_", integral_number_test_visitor{ast::integral_number_t{
                      "20",
                      ast::integral_number_base_info_t{std::nullopt, 'd'},
                      "Z",
                  }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20'd?_", integral_number_test_visitor{ast::integral_number_t{
                      "20",
                      ast::integral_number_base_info_t{std::nullopt, 'd'},
                      "?",
                  }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20 'dz_", integral_number_test_visitor{ast::integral_number_t{
                       "20",
                       ast::integral_number_base_info_t{std::nullopt, 'd'},
                       "z",
                   }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20 'dZ_", integral_number_test_visitor{ast::integral_number_t{
                       "20",
                       ast::integral_number_base_info_t{std::nullopt, 'd'},
                       "Z",
                   }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20 'd?_", integral_number_test_visitor{ast::integral_number_t{
                       "20",
                       ast::integral_number_base_info_t{std::nullopt, 'd'},
                       "?",
                   }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20 'd z_", integral_number_test_visitor{ast::integral_number_t{
                        "20",
                        ast::integral_number_base_info_t{std::nullopt, 'd'},
                        "z",
                    }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20 'd Z_", integral_number_test_visitor{ast::integral_number_t{
                        "20",
                        ast::integral_number_base_info_t{std::nullopt, 'd'},
                        "Z",
                    }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20 'd ?_", integral_number_test_visitor{ast::integral_number_t{
                        "20",
                        ast::integral_number_base_info_t{std::nullopt, 'd'},
                        "?",
                    }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20'dz__", integral_number_test_visitor{ast::integral_number_t{
                       "20",
                       ast::integral_number_base_info_t{std::nullopt, 'd'},
                       "z",
                   }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20'dZ__", integral_number_test_visitor{ast::integral_number_t{
                       "20",
                       ast::integral_number_base_info_t{std::nullopt, 'd'},
                       "Z",
                   }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20'd?__", integral_number_test_visitor{ast::integral_number_t{
                       "20",
                       ast::integral_number_base_info_t{std::nullopt, 'd'},
                       "?",
                   }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20 'dz__", integral_number_test_visitor{ast::integral_number_t{
                        "20",
                        ast::integral_number_base_info_t{std::nullopt, 'd'},
                        "z",
                    }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20 'dZ__", integral_number_test_visitor{ast::integral_number_t{
                        "20",
                        ast::integral_number_base_info_t{std::nullopt, 'd'},
                        "Z",
                    }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20 'd?__", integral_number_test_visitor{ast::integral_number_t{
                        "20",
                        ast::integral_number_base_info_t{std::nullopt, 'd'},
                        "?",
                    }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20 'd z__", integral_number_test_visitor{ast::integral_number_t{
                         "20",
                         ast::integral_number_base_info_t{std::nullopt, 'd'},
                         "z",
                     }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20 'd Z__", integral_number_test_visitor{ast::integral_number_t{
                         "20",
                         ast::integral_number_base_info_t{std::nullopt, 'd'},
                         "Z",
                     }});
    EXPECT_AST_VISITOR_SUCCESS<TProduction>(
        "20 'd ?__", integral_number_test_visitor{ast::integral_number_t{
                         "20",
                         ast::integral_number_base_info_t{std::nullopt, 'd'},
                         "?",
                     }});
}

TEST(SV2017NumberTests, DecimalNumberTests)
{
    test_decimal_number_parsing<decimal_number>();
}

template <typename TProduction> void test_integral_number_parsing()
{
    test_decimal_number_parsing<TProduction>();
    test_octal_number_parsing<TProduction>();
    test_binary_number_parsing<TProduction>();
    test_hex_number_parsing<TProduction>();
}

TEST(SV2017NumberTests, IntegralNumberTests)
{
    test_integral_number_parsing<integral_number>();
}

TEST(SV2017NumberTests, NumberTests)
{
    test_integral_number_parsing<number>();
    test_real_number_parsing<number>();
}
