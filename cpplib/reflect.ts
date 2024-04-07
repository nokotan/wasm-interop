export const memory = new WebAssembly.Memory({ initial: 2 });

export function instanceMemory(): ArrayBuffer {
    return memory.buffer;
}