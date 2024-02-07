#ifndef GRAPHIC_EDITOR_H
#define GRAPHIC_EDITOR_H

#include <iostream>
#include <memory>
#include <vector>

#include "figure.h"

class document {
public:
    virtual void create_doc(std::string) = 0;
    virtual void import_from_doc(std::string) = 0;
    virtual void export_to_doc(std::string) = 0;

    virtual void create_primitive(std::unique_ptr<primitive>&) = 0;
    virtual void remove_primitive(std::unique_ptr<primitive>&) = 0;
    virtual void draw_doc() = 0;

    virtual ~document() = default;
};

class document_some_type : public document {
private:
    std::vector<std::unique_ptr<primitive>> v;
public:
    document_some_type() {};

    void create_doc(std::string) override;
    void import_from_doc(std::string) override;
    void export_to_doc(std::string) override;

    void create_primitive(std::unique_ptr<primitive>&) override;
    void remove_primitive(std::unique_ptr<primitive>&) override;
    void draw_doc() override;
};

#endif /* GRAPHIC_EDITOR_H */