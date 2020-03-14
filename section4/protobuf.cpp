// Copyright (c) 2020 by Chrono
//
// sudo apt-get install protobuf-compiler
// sudo apt-get install libprotobuf-dev
// sudo apt-get install libprotoc-dev
//
// g++ protobuf.cpp -std=c++11 -lprotobuf -o a.out;./a.out
// g++ protobuf.cpp -std=c++14 -lprotobuf -o a.out;./a.out
// g++ protobuf.cpp -std=c++14 -lprotobuf -o a.out;./a.out

#include <cassert>

#include <iostream>

// just for convient
//#include "sample.pb.h"
#include "sample.pb.cc"

void case1()
{
    using vendor_t = sample::Vendor;

    vendor_t v;

    assert(!v.IsInitialized());

    v.set_id(1);
    v.set_name("sony");
    v.set_valid(true);

    assert(v.IsInitialized());
    assert(v.has_id() && v.id() == 1);
    assert(v.has_name() && v.name() == "sony");
    assert(v.has_valid() && v.valid());

}

void case2()
{
    auto alloc_vendor = []()
    {
        return new sample::Vendor;
    };

    auto v = alloc_vendor();

    v->set_id(1);
    v->set_name("sony");
    v->set_valid(true);

    using product_t = sample::Product;

    product_t p;

    p.set_id(1);
    p.set_name("walkman");

    assert(p.tag_size() == 0);
    p.add_tag("fashion");
    p.add_tag("type_record");

    assert(!p.has_vendor());
    p.set_allocated_vendor(v);
}

int main()
{
    case1();
    case2();

    using namespace std;

    cout << "protobuf demo" << endl;
}
