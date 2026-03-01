#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const int n) {
    value = n << bits;
}

Fixed::Fixed(const float n) {
    value = roundf(n * (1 << bits));
}

Fixed::Fixed(const Fixed &other) {
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other)
        value = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const {
    return value;
}

void Fixed::setRawBits(int const raw) {
    value = raw;
}

float Fixed::toFloat(void) const {
    return (float)value / (1 << bits);
}

int Fixed::toInt(void) const {
    return value >> bits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &f) {
    out << f.toFloat();
    return out;
}

bool Fixed::operator>(const Fixed &other) const {
    return this->value > other.value;
}

bool Fixed::operator<(const Fixed &other) const {
    return this->value < other.value;
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->value >= other.value;
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->value <= other.value;
}

bool Fixed::operator==(const Fixed &other) const {
    return this->value == other.value;
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->value != other.value;
}

Fixed Fixed::operator+(const Fixed &other) const {
    Fixed res;
    res.setRawBits(this->value + other.value);
    return res;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed res;
    res.setRawBits(this->value - other.value);
    return res;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed res;
    long tmp = (long)this->value * (long)other.value;
    res.setRawBits(tmp >> bits);
    return res;
}

Fixed Fixed::operator/(const Fixed &other) const {
    if (other.value == 0)
        return Fixed(0);
    Fixed res;
    long tmp = ((long)this->value << bits);
    res.setRawBits(tmp / other.value);
    return res;
}

Fixed &Fixed::operator++() {
    value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    value++;
    return temp;
}

Fixed &Fixed::operator--() {
    value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    value--;
    return temp;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b) {
    return (a > b) ? a : b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b) {
    return (a < b) ? a : b;
}
