import { memory } from "./Main.wasm";

export function instanceMemory(): ArrayBuffer {
    return memory.buffer;
}