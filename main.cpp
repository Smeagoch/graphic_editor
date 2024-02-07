#include <iostream>
#include <memory>
#include "graphic_editor.h"
#include "figure.h"

int main()
{
    std::unique_ptr<primitive> fig1 = std::make_unique<circle>(circle(0,0,0));
    std::unique_ptr<primitive> fig2 = std::make_unique<circle>(circle(1,1,1));
    std::unique_ptr<primitive> fig3 = std::make_unique<circle>(circle(1,1,1));

    document_some_type d;
    document *doc = &d;

    doc->create_doc("/path/document");

    doc->create_primitive(fig1);
    doc->create_primitive(fig2);
    doc->draw_doc();
    doc->remove_primitive(fig3);

    doc->export_to_doc("/path/document");

    return 0;
}
