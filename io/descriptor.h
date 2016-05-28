#ifndef CHAT_DESCRIPTOR_H
#define CHAT_DESCRIPTOR_H

#include <stream/stream.h>

class Descriptor : public Stream {
public:
    Descriptor(int descriptor);
    void destroy();

    int getDescriptor() const;

    size_t getChunk(void *buffer, size_t bufferSize) const;
    void sendChunk(const void *buffer, size_t bufferSize) const;

    bool operator==(const Descriptor &rhs) const;
    bool operator!=(const Descriptor &rhs) const;
    bool operator<(const Descriptor &rhs) const;
    bool operator>(const Descriptor &rhs) const;

protected:
    int descriptor;
};

#endif //CHAT_DESCRIPTOR_H
