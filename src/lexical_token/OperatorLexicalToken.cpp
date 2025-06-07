#include <cassert>
#include <exception>
#include <sstream>
#include <unordered_map>

#include "OperatorLexicalToken.h"

svs::OperatorLexicalToken::OperatorLexicalToken(
    const svs::FilePosition& __file_position,
    const svs::OperatorLexicalToken::Type& __operator_type)
    : svs::LexicalToken(
        svs::LexicalToken::Type::Operator,
        __file_position)
{
    _operator_type = __operator_type;
}

const svs::OperatorLexicalToken::Type svs::OperatorLexicalToken::operator_type() const
{
    return _operator_type;
}

static const inline std::string to_operator_type_name(
    const svs::OperatorLexicalToken::Type& _operator_type)
{
    switch(_operator_type)
    {
    case svs::OperatorLexicalToken::Type::SimpleAssignment: return "SimpleAssignment";
    case svs::OperatorLexicalToken::Type::AdditionAssignment: return "AdditionAssignment";
    case svs::OperatorLexicalToken::Type::SubtractionAssignment: return "SubtractionAssignment";
    case svs::OperatorLexicalToken::Type::MultiplicationAssignment: return "MultiplicationAssignment";
    case svs::OperatorLexicalToken::Type::DivisionAssignment: return "DivisionAssignment";
    case svs::OperatorLexicalToken::Type::ModuloAssignment: return "ModuloAssignment";
    case svs::OperatorLexicalToken::Type::BitwiseAndAssignment: return "BitwiseAndAssignment";
    case svs::OperatorLexicalToken::Type::BitwiseOrAssignment: return "BitwiseOrAssignment";
    case svs::OperatorLexicalToken::Type::BitwiseExclusiveOrAssignment: return "BitwiseExclusiveOrAssignment";
    case svs::OperatorLexicalToken::Type::LogicalLeftShiftAssignment: return "LogicalLeftShiftAssignment";
    case svs::OperatorLexicalToken::Type::LogicalRightShiftAssignment: return "LogicalRightShiftAssignment";
    case svs::OperatorLexicalToken::Type::ArithmeticLeftShiftAssignment: return "ArithmeticLeftShiftAssignment";
    case svs::OperatorLexicalToken::Type::ArithmeticRightShiftAssignment: return "ArithmeticRightShiftAssignment";
    case svs::OperatorLexicalToken::Type::Increment: return "Increment";
    case svs::OperatorLexicalToken::Type::Decrement: return "Decrement";
    case svs::OperatorLexicalToken::Type::Addition: return "Addition";
    case svs::OperatorLexicalToken::Type::Subtraction: return "Subtraction";
    case svs::OperatorLexicalToken::Type::Multiplication: return "Multiplication";
    case svs::OperatorLexicalToken::Type::Division: return "Division";
    }
    throw std::exception();
}

static const inline std::string to_operator_type_syntax(
    const svs::OperatorLexicalToken::Type& _operator_type)
{
    switch(_operator_type)
    {
    case svs::OperatorLexicalToken::Type::SimpleAssignment: return "=";
    case svs::OperatorLexicalToken::Type::AdditionAssignment: return "+=";
    case svs::OperatorLexicalToken::Type::SubtractionAssignment: return "-=";
    case svs::OperatorLexicalToken::Type::MultiplicationAssignment: return "*=";
    case svs::OperatorLexicalToken::Type::DivisionAssignment: return "/=";
    case svs::OperatorLexicalToken::Type::ModuloAssignment: return "%=";
    case svs::OperatorLexicalToken::Type::BitwiseAndAssignment: return "&=";
    case svs::OperatorLexicalToken::Type::BitwiseOrAssignment: return "|=";
    case svs::OperatorLexicalToken::Type::BitwiseExclusiveOrAssignment: return "^=";
    case svs::OperatorLexicalToken::Type::LogicalLeftShiftAssignment: return "<<=";
    case svs::OperatorLexicalToken::Type::LogicalRightShiftAssignment: return ">>=";
    case svs::OperatorLexicalToken::Type::ArithmeticLeftShiftAssignment: return "<<<=";
    case svs::OperatorLexicalToken::Type::ArithmeticRightShiftAssignment: return ">>>=";
    case svs::OperatorLexicalToken::Type::Increment: return "++";
    case svs::OperatorLexicalToken::Type::Decrement: return "--";
    case svs::OperatorLexicalToken::Type::Addition: return "+";
    case svs::OperatorLexicalToken::Type::Subtraction: return "-";
    case svs::OperatorLexicalToken::Type::Multiplication: return "*";
    case svs::OperatorLexicalToken::Type::Division: return "/";
    }
    throw std::exception();
}

const std::string svs::OperatorLexicalToken::to_string() const
{
    std::stringstream ss;

    ss << to_operator_type_name(_operator_type)<< "{\n";
    ss << "  FilePosition=" << file_position().to_string() << ",\n";
    ss << "  Syntax=\"" << to_operator_type_syntax(_operator_type) << "\"}";

    return ss.str();
}

std::unique_ptr<svs::OperatorLexicalToken> svs::OperatorLexicalToken::parse(
    svs::FilePosition& file_position,
    std::string::const_iterator& begin,
    const std::string::const_iterator end)
{
    if (begin == end)
    {
        return nullptr;
    }

    auto it = begin;
    switch(*it)
    {
    case '=':
        ++it;
        begin = it;
        return std::unique_ptr<svs::OperatorLexicalToken>(
            new svs::OperatorLexicalToken(
                file_position,
                svs::OperatorLexicalToken::Type::SimpleAssignment));

    case '+':
        ++it;
        if (it == end)
        {
            begin = it;
            return std::unique_ptr<svs::OperatorLexicalToken>(
                new svs::OperatorLexicalToken(
                    file_position,
                    svs::OperatorLexicalToken::Type::Addition));
        }

        switch (*it)
        {
        case '=':
            ++it;
            begin = it;
            return std::unique_ptr<svs::OperatorLexicalToken>(
                new svs::OperatorLexicalToken(
                    file_position,
                    svs::OperatorLexicalToken::Type::AdditionAssignment));
        default:
            ++it;
            begin = it;
            return std::unique_ptr<svs::OperatorLexicalToken>(
                new svs::OperatorLexicalToken(
                    file_position,
                    svs::OperatorLexicalToken::Type::Addition));
        }

    case '-':
        ++it;
        if (it == end)
        {
            begin = it;
            return std::unique_ptr<svs::OperatorLexicalToken>(
                new svs::OperatorLexicalToken(
                    file_position,
                    svs::OperatorLexicalToken::Type::Subtraction));
        }

        switch (*it)
        {
        case '=':
            ++it;
            begin = it;
            return std::unique_ptr<svs::OperatorLexicalToken>(
                new svs::OperatorLexicalToken(
                    file_position,
                    svs::OperatorLexicalToken::Type::SubtractionAssignment));
        default:
            ++it;
            begin = it;
            return std::unique_ptr<svs::OperatorLexicalToken>(
                new svs::OperatorLexicalToken(
                    file_position,
                    svs::OperatorLexicalToken::Type::Subtraction));
        }

    case '*':
        ++it;
        if (it == end)
        {
            begin = it;
            return std::unique_ptr<svs::OperatorLexicalToken>(
                new svs::OperatorLexicalToken(
                    file_position,
                    svs::OperatorLexicalToken::Type::Multiplication));
        }

        switch (*it)
        {
        case '=':
            ++it;
            begin = it;
            return std::unique_ptr<svs::OperatorLexicalToken>(
                new svs::OperatorLexicalToken(
                    file_position,
                    svs::OperatorLexicalToken::Type::MultiplicationAssignment));
        default:
            ++it;
            begin = it;
            return std::unique_ptr<svs::OperatorLexicalToken>(
                new svs::OperatorLexicalToken(
                    file_position,
                    svs::OperatorLexicalToken::Type::Multiplication));
        }

    case '/':
        ++it;
        if (it == end)
        {
            begin = it;
            return std::unique_ptr<svs::OperatorLexicalToken>(
                new svs::OperatorLexicalToken(
                    file_position,
                    svs::OperatorLexicalToken::Type::Division));
        }

        switch (*it)
        {
        case '=':
            ++it;
            begin = it;
            return std::unique_ptr<svs::OperatorLexicalToken>(
                new svs::OperatorLexicalToken(
                    file_position,
                    svs::OperatorLexicalToken::Type::DivisionAssignment));
        default:
            ++it;
            begin = it;
            return std::unique_ptr<svs::OperatorLexicalToken>(
                new svs::OperatorLexicalToken(
                    file_position,
                    svs::OperatorLexicalToken::Type::Division));
        }

    default:
        return nullptr;
    }
}

static const std::unordered_map<std::string, svs::OperatorLexicalToken::Type> operator_lookup_table
{
    // Assignment Operators
    { "%=", svs::OperatorLexicalToken::Type::ModuloAssignment },
    { "&=", svs::OperatorLexicalToken::Type::BitwiseAndAssignment, },
    { "|=", svs::OperatorLexicalToken::Type::BitwiseOrAssignment },
    { "^=", svs::OperatorLexicalToken::Type::BitwiseExclusiveOrAssignment },
    { "<<=", svs::OperatorLexicalToken::Type::LogicalLeftShiftAssignment },
    { ">>=", svs::OperatorLexicalToken::Type::LogicalRightShiftAssignment },
    { "<<<=", svs::OperatorLexicalToken::Type::ArithmeticLeftShiftAssignment },
    { ">>>=", svs::OperatorLexicalToken::Type::ArithmeticRightShiftAssignment },

    // Increment and Decrement Operators
    { "++", svs::OperatorLexicalToken::Type::Increment, },
    { "--", svs::OperatorLexicalToken::Type::Decrement, },
};
