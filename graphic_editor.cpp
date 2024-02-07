#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

#include "graphic_editor.h"

void document_some_type::create_doc(std::string path) {}
void document_some_type::import_from_doc(std::string path) {}
void document_some_type::export_to_doc(std::string path) {}

void document_some_type::create_primitive(std::unique_ptr<primitive> &p)
{
	v.push_back(std::move(p));
}

void document_some_type::remove_primitive(std::unique_ptr<primitive> &p)
{
	auto delete_item = std::find_if(v.begin(), v.end(),
		[&](std::unique_ptr<primitive> &ptr) {return ptr->cmp(p.get());});

	if (delete_item != v.end()) {
		v.erase(delete_item);
	}
}

void document_some_type::draw_doc() 
{
	for (auto p = v.cbegin(); p != v.cend(); ++p)
		(*p)->draw();  
}
