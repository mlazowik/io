#include <system_error>
#include <unistd.h>

#include "descriptor.h"

int Descriptor::getDescriptor() const {
    return this->descriptor;
}

Descriptor::Descriptor(int descriptor) {
    this->descriptor = descriptor;
}

void Descriptor::destroy() {
    if (close(this->descriptor) < 0) {
        throw std::system_error(errno, std::system_category());
    }
}

size_t Descriptor::getChunk(void *buffer, size_t bufferSize) const {
    ssize_t len = read(this->getDescriptor(), buffer, bufferSize);

    if (len < 0) {
        throw std::system_error(errno, std::system_category());
    }

    return (size_t)len;
}

void Descriptor::sendChunk(const void *buffer, size_t bufferSize) const {
    ssize_t len = write(this->getDescriptor(), buffer, bufferSize);

    if (len < 0) {
        throw std::system_error(errno, std::system_category());
    }

    if ((size_t)len != bufferSize) {
        throw std::runtime_error("partial write");
    }
}

bool Descriptor::operator==(const Descriptor &rhs) const {
    return this->getDescriptor() == rhs.getDescriptor();
}

bool Descriptor::operator!=(const Descriptor &rhs) const {
    return !(*this == rhs);
}

bool Descriptor::operator<(const Descriptor &rhs) const {
    return this->getDescriptor() < rhs.getDescriptor();
}

bool Descriptor::operator>(const Descriptor &rhs) const {
    return !(*this < rhs || *this == rhs);
}