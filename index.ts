import { getMemorySlice } from "./cpplib/Main.wasm";
import { construct } from "wasm-interop/lib/String.js";

const memory = getMemorySlice();
const text = construct(memory);

console.log(text);
