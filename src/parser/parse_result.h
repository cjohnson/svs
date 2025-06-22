#ifndef SVS_PARSE_RESULT_H_
#define SVS_PARSE_RESULT_H_

#include <cassert>
#include <string>

namespace svs
{

/**
 * The result of a parsing attempt.
 */
template<typename T>
class ParseResult
{
public:
    /**
     * Creates a successful parsing attempt result.
     *
     * Keyword arguments:
     * __value: The value created from the successful parsing attempt.
     * __next: The iterator pointing to the next part of the string that is now unconsumed.
     */
    static ParseResult<T> succeed(
        const T& __value,
        const std::string::const_iterator& __next)
    {
        svs::ParseResult<T> result;
        result._success = true;
        result._value = __value;
        result._next = __next;

        return result;
    }

    /**
     * Creates a failed parsing attempt result.
     */
    static ParseResult<T> fail()
    {
        svs::ParseResult<T> result;
        result._success = false;

        return result;
    }

    /**
     * Returns whether or not the parsing attempt succeeded:
     * the status of the parsing attempt result.
     */
    bool succeeded() const
    {
        return _success;
    }

    /**
     * Returns the value created from the successful parsing attempt.
     */
    T value() const
    {
        assert(_success);
        return _value;
    }

    /**
     * Returns the iterator pointing to the next part of the string that is now unconsumed on
     * a successful parsing attempt.
     */
    std::string::const_iterator next() const
    {
        assert(_success);
        return _next;
    }

private:
    /**
     * Constructs the result of a parsing attempt.
     */
    ParseResult()
    {}

    /**
     * Whether or not the parsing attempt succeeded.
     */
    bool _success;

    /**
     * The value created from the successful parsing attempt.
     */
    T _value;

    /**
     * The iterator pointing to the next, yet unparsed part of the string after a
     * successful parsing attempt.
     */
    std::string::const_iterator _next;
};

}

#endif // SVS_PARSE_RESULT_H_

