#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

// Generic Exception Class
class Exception {
public:
    Exception() {}
};

// Exception Class that represents an invalid node ID
class InvalidNodeId : public Exception {
public:
    InvalidNodeId(unsigned int id) : id(id) {}

    unsigned int id;
};

// Exception Class that represents a Node not found within a Graph
class NodeNotFound : public Exception {
public:
    NodeNotFound(unsigned int id) : id(id) {}

    unsigned int id;
};

// Exception Class that represents an invalid node ID
class GraphLoadFailed : public Exception {
public:
    GraphLoadFailed(const std::string & fileName) : fileName(fileName) {}

    std::string fileName;
};

#endif //EXCEPTIONS_H