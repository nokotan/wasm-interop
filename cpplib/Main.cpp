
namespace js {
    using ArrayBuffer = __externref_t;

    namespace WebAssembly {
        using Memory = __externref_t;
    }

    __attribute__((import_module("wasm-interop/lib/ArrayBuffer.js"), import_name("slice")))
    extern ArrayBuffer slice(WebAssembly::Memory buffer, int start, int end);
}

__attribute__((import_module("./reflect.js"), import_name("instanceMemory")))
extern js::ArrayBuffer instanceMemory();

const char text[] = "Hello, world!";

__attribute__((visibility("default"), export_name("getMemorySlice")))
js::ArrayBuffer getMemorySlice() {
    const auto memory = instanceMemory();
    return js::slice(memory, (int)(void*)text, (int)(void*)text + 14);
}
