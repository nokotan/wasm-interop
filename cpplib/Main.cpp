
namespace js {

    using CArrayBuffer = __externref_t;
    using CString = __externref_t;
    using CAny = __externref_t;

    namespace WebAssembly {
        using Memory = __externref_t;
    }

    namespace ArrayBuffer {
        __attribute__((import_module("wasm-interop/lib/ArrayBuffer.js"), import_name("slice")))
        extern CArrayBuffer slice(CArrayBuffer buffer, void* start, void* end);
    }

    namespace String {
        __attribute__((import_module("wasm-interop/lib/String.js"), import_name("construct")))
        extern CString construct(CArrayBuffer buffer);
    }

    namespace Console {
        __attribute__((import_module("wasm-interop/lib/Console.js"), import_name("log")))
        extern void log(CAny value);
    }

    __attribute__((import_module("./reflect.js"), import_name("instanceMemory")))
    extern CArrayBuffer instanceMemory();
}

const char text[] = "Hello, world!";

static __externref_t table[0];

__attribute__((address_space(1), visibility("default"))) __externref_t put;

__attribute__((visibility("default")))
extern "C" void _start() {
    const auto memory = js::instanceMemory();
    const auto textMemory = js::ArrayBuffer::slice(memory, (void*)text, (void*)(text + 14));
    const auto text = js::String::construct(textMemory);

    js::Console::log(text);
}
